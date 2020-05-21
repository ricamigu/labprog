#include <stdio.h>
#include <stdlib.h>
#include "battleship.h"


Coordinate* new_coord(int a, int b) {
	Coordinate* c = (Coordinate *) malloc(sizeof(Coordinate*));
	c -> x = a;
	c -> y = b;
	return c;
}

CoordinateD new_coordD(double a, double b) {
	CoordinateD c;
	c.x = a;
	c.y = b;
	return c;
}


struct node* new_node(){

	struct node *new = malloc(sizeof(struct node));

	new -> tag = isInternal;
	new -> NW = NULL;
	new -> NE = NULL;
	new -> SW = NULL;
	new -> SE = NULL;

	return new;
}

struct node* new_leaf(Coordinate *coord, piece *boat){

	struct node *new = malloc(sizeof(struct node));

	new -> tag = isLeaf;
	new -> c = coord;
	new -> peca = boat;

	return new;

}

struct node* insert(struct node *root, struct node *coord, CoordinateD particao, double limxi, double limxs, double limyi, double limys){

	if(root==NULL) {
		root = coord;
		return root;
	}

	double xx = coord->c->x;
	double yy = coord->c->y;

	if(root -> tag == isInternal){
		//NW
		if( (xx <= particao.x) && (yy <= particao.y)){
			//printf("NW\n");
			CoordinateD temp = particao;
			particao.x = (limxi+particao.x)/2;
			particao.y = (limyi+particao.y)/2;
			limxs = temp.x; limys = temp.y;
			root->NW = insert(root->NW, coord, particao, limxi, limxs, limyi, limys);
		}

		//NE
		else if(( xx <= particao.x) && (yy > particao.y)){
			CoordinateD temp = particao;
			particao.x = (limxi+particao.x)/2; 
			particao.y = (particao.y+limys)/2;
			limxs = temp.x; limyi = temp.y;
			root->NE = insert(root->NE, coord, particao, limxi, limxs, limyi, limys);
		}
		//SW
		else if(( xx > particao.x) && (yy <= particao.y)){
			CoordinateD temp = particao;
			particao.x = (particao.x+limxs)/2; 
			particao.y = (limyi+particao.y)/2;
			limxi = temp.x; limys = temp.y;
			root->SW = insert(root->SW, coord, particao, limxi, limxs, limyi, limys);
		}
		//SE
		else if( (xx > particao.x) && (yy > particao.y) ){
			CoordinateD temp = particao;
			particao.x = (particao.x+limxs)/2;
			particao.y = (particao.y+limys)/2;
			limxi = temp.x; limyi = temp.y;
			root->SE = insert(root->SE, coord, particao, limxi, limxs, limyi, limys);
		}
	}

	
	if(root->tag == isLeaf){
			struct node *new; new = new_node();
			struct node *temp; temp = new_leaf(root->c,root->peca);
			root = new;
			insert(root, temp, particao, limxi, limxs, limyi, limys);
			insert(root, coord, particao, limxi, limxs, limyi, limys);
	}

	return root;
}

//teste
bool contains(struct node *root, struct node *coord, CoordinateD particao, double limxi, double limxs, double limyi, double limys){

	double xx = coord->c->x;
	double yy = coord->c->y;

	if(root==NULL) return false;

	if(root -> tag == isInternal){
		//NW
		if( (xx <= particao.x) && (yy <= particao.y)){
			//printf("NW\n");
			CoordinateD temp = particao;
			particao.x = (limxi+particao.x)/2;
			particao.y = (limyi+particao.y)/2;
			limxs = temp.x; limys = temp.y;
			return contains(root->NW, coord, particao, limxi, limxs, limyi, limys);
		}

		//NE
		else if(( xx <= particao.x) && (yy > particao.y)){
			CoordinateD temp = particao;
			particao.x = (limxi+particao.x)/2; 
			particao.y = (particao.y+limys)/2;
			limxs = temp.x; limyi = temp.y;
			return contains(root->NE, coord, particao, limxi, limxs, limyi, limys);
		}
		//SW
		else if(( xx > particao.x) && (yy <= particao.y)){
			CoordinateD temp = particao;
			particao.x = (particao.x+limxs)/2; 
			particao.y = (limyi+particao.y)/2;
			limxi = temp.x; limys = temp.y;
			return contains(root->SW, coord, particao, limxi, limxs, limyi, limys);
		}
		//SE
		else if( (xx > particao.x) && (yy > particao.y) ){
			CoordinateD temp = particao;
			particao.x = (particao.x+limxs)/2;
			particao.y = (particao.y+limys)/2;
			limxi = temp.x; limyi = temp.y;
			return contains(root->SE, coord, particao, limxi, limxs, limyi, limys);
		}
	}
	
	if(root->tag == isLeaf) {
		if(root->c->x == coord->c->x && root->c->y == coord->c->y)
			return true;
	}

	return false;

}


bool containsC(struct node *root, int x1, int y1, CoordinateD particao, double limxi, double limxs, double limyi, double limys){

	double xx = x1;
	double yy = y1;

	if(root==NULL) return false;

	if(root -> tag == isInternal){
		//NW
		if( (xx <= particao.x) && (yy <= particao.y)){
			//printf("NW\n");
			CoordinateD temp = particao;
			particao.x = (limxi+particao.x)/2;
			particao.y = (limyi+particao.y)/2;
			limxs = temp.x; limys = temp.y;
			return containsC(root->NW, x1, y1, particao, limxi, limxs, limyi, limys);
		}

		//NE
		else if(( xx <= particao.x) && (yy > particao.y)){
			CoordinateD temp = particao;
			particao.x = (limxi+particao.x)/2; 
			particao.y = (particao.y+limys)/2;
			limxs = temp.x; limyi = temp.y;
			return containsC(root->NE, x1, y1, particao, limxi, limxs, limyi, limys);
		}
		//SW
		else if(( xx > particao.x) && (yy <= particao.y)){
			CoordinateD temp = particao;
			particao.x = (particao.x+limxs)/2; 
			particao.y = (limyi+particao.y)/2;
			limxi = temp.x; limys = temp.y;
			return containsC(root->SW, x1, y1, particao, limxi, limxs, limyi, limys);
		}
		//SE
		else if( (xx > particao.x) && (yy > particao.y) ){
			CoordinateD temp = particao;
			particao.x = (particao.x+limxs)/2;
			particao.y = (particao.y+limys)/2;
			limxi = temp.x; limyi = temp.y;
			return containsC(root->SE, x1, y1, particao, limxi, limxs, limyi, limys);
		}
	}
	
	if(root->tag == isLeaf) {
		if(root->c->x == x1 && root->c->y == y1)
			return true;
	}

	return false;

}


bool pode_inserir(struct node* root, piece boat, int size){

  int xx = boat.c.x-2;
  int yy = boat.c.y-2;

  if(xx < 0 || yy < 0 || xx>=size || yy>=size){
  	printf("\033[0;31m"); printf("\nError: "); printf("\033[0m");printf("Invalid coordinate, out of bounds!");
  	return false;
  }

  CoordinateD meio = new_coordD(size/2,size/2);

  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
        if(boat.mb -> m[i][j] == '1'){
          if (containsC(root, xx+i, yy+j, meio, 0, size, 0, size)){
          	printf("\033[0;31m"); printf("\nError: "); printf("\033[0m");printf("Invalid coordinate, boat already there!");
          	return false;
          }
          //printf("point (%d,%d) ", xx+i,yy+j);
        }
    }
  }

  return true;
}

void inserir_barco(struct node* root, piece *boat, int size){

	if(pode_inserir(root, *boat, size)){

		for(int i=0; i<5; i++){
	    	for(int j=0; j<5; j++){
	       		if(boat-> mb -> m[i][j] == '1'){

	       			Coordinate *a = new_coord(boat->c.x-2+i, boat->c.y-2+j);
	       			CoordinateD meio = new_coordD(size/2,size/2);
	       			struct node* leaf = new_leaf(a,boat);
	        		insert(root, leaf, meio, 0, size, 0, size);

	          		//printf("point (%d,%d) ", xx+i,yy+j);
	        	}
	    	}
	  	}
	}

	else {
		// caso nao possa inserir, volta a pedir coordenadas ao jogador
		int x1,y1;
		printf("\n\nCoordinate for the boat again: ");
		printf("\nx: ");
		scanf("%d", &x1);
		printf("y: ");
		scanf("%d", &y1);
		Coordinate* a  = new_coord(x1,y1);
		boat->c = *a;
		inserir_barco(root, boat, size);
	}
}

//insert(struct node *root, struct node *coord, CoordinateD particao, double limxi, double limxs, double limyi, double limys)








//ineficiente, percorre a arvore toda (para teste apenas)
bool contains2(struct node *root, struct node *coord){

	if(root==NULL) return false;

    if(root!=NULL) // checking if the root is not null
    {
    	if(root->tag==isLeaf) {
	        if( (root->c->x == coord->c->x) && (root->c->y == coord->c->y)){
				return true;
	        }
		}
    }

    return contains2(root->NW,coord) || contains2(root->NE,coord) || contains2(root->SW,coord) || contains2(root->SE,coord);

}





int number_nodes(struct node* root){

	if(root == NULL) return 0;

	return 1 +number_nodes(root->NW) + number_nodes(root->NE) + number_nodes(root->SW) + number_nodes(root->SE);

}


void inorder(struct node *root)
{
    if(root!=NULL) // checking if the root is not null
    {
	        inorder(root->NW);
	        inorder(root->NE);
	        if(root->tag==isLeaf) printf(" (%d,%d) \n", root->c->x,root->c->y);
	        inorder(root->SW);
	        inorder(root->SE);
    }

}



void print_tree(struct node* root){

	if(root==NULL) { printf(" N "); return; }

	if(root->tag==isInternal) printf(" I ");

	if(root->tag==isLeaf) printf( "(%d,%d)", root->c->x,root->c->y );

	printf("NW: "); print_tree(root->NW);
	printf("NE: "); print_tree(root->NE);
	printf("SW: "); print_tree(root->SW);
	printf("SE: "); print_tree(root->SE);

}



struct node* clear_tree(struct node *root){

	return root = new_node();

}
