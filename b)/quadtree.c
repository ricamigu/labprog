#include <stdio.h>
#include <stdlib.h>
#include "battleship.h"


Coordinate* new_coord(int a, int b) {
	Coordinate* c = (Coordinate *) malloc(sizeof(Coordinate*));
	c -> x = a;
	c -> y = b;
	return c;
}

CoordinateD new_coordD(long double a, long double b) {
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
	//new -> field_shot = 0;

	return new;

}

struct node* insert(struct node *root, struct node *coord, CoordinateD particao, long double limxi, long double limxs, long double limyi, long double limys){

	if(root==NULL) {
		root = coord;
		return root;
	}

	long double xx = coord->c->x;
	long double yy = coord->c->y;

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



bool containsC(struct node *root, int x1, int y1, CoordinateD particao, long double limxi, long double limxs, long double limyi, long double limys){

	long double xx = x1;
	long double yy = y1;

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



//ineficiente, percorre a arvore toda (para teste apenas)
bool contains2(struct node *root, int x1, int y1){

	if(root==NULL) return false;

    if(root!=NULL) // checking if the root is not null
    {
    	if(root->tag==isLeaf) {
	        if( (root->c->x == x1) && (root->c->y == y1)){
				return true;
	        }
		}
    }

    return contains2(root->NW,x1,y1) || contains2(root->NE,x1,y1) || contains2(root->SW,x1,y1) || contains2(root->SE,x1,y1);

}


//teste
int number_leaves(struct node* root){

	int cont=0;

	if(root == NULL) return 0;
	
	if(root->tag==isLeaf) cont=1;

	return cont + number_leaves(root->NW) + number_leaves(root->NE) + number_leaves(root->SW) + number_leaves(root->SE);

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


void delete_tree(struct node *root){

    if(root!=NULL){
	        delete_tree(root->NW);
	        delete_tree(root->NE);
	        delete_tree(root->SW);
	        delete_tree(root->SE);
	        free(root);
    }
}


struct node* find(struct node *root, int x1, int y1, CoordinateD particao, long double limxi, long double limxs, long double limyi, long double limys){

	long double xx = x1;
	long double yy = y1;

	if(root -> tag == isInternal){
		//NW
		if( (xx <= particao.x) && (yy <= particao.y)){
			//printf("NW\n");
			CoordinateD temp = particao;
			particao.x = (limxi+particao.x)/2;
			particao.y = (limyi+particao.y)/2;
			limxs = temp.x; limys = temp.y;
			root->NW = find(root->NW, x1, y1, particao, limxi, limxs, limyi, limys);
		}

		//NE
		else if(( xx <= particao.x) && (yy > particao.y)){
			CoordinateD temp = particao;
			particao.x = (limxi+particao.x)/2; 
			particao.y = (particao.y+limys)/2;
			limxs = temp.x; limyi = temp.y;
			root->NE = find(root->NE, x1,y1, particao, limxi, limxs, limyi, limys);
		}
		//SW
		else if(( xx > particao.x) && (yy <= particao.y)){
			CoordinateD temp = particao;
			particao.x = (particao.x+limxs)/2; 
			particao.y = (limyi+particao.y)/2;
			limxi = temp.x; limys = temp.y;
			root->SW = find(root->SW, x1,y1, particao, limxi, limxs, limyi, limys);
		}
		//SE
		else if( (xx > particao.x) && (yy > particao.y) ){
			CoordinateD temp = particao;
			particao.x = (particao.x+limxs)/2;
			particao.y = (particao.y+limys)/2;
			limxi = temp.x; limyi = temp.y;
			root->SE = find(root->SE, x1,y1, particao, limxi, limxs, limyi, limys);
		}
	}
	
	if(root->tag == isLeaf){
		return root;
	}

}