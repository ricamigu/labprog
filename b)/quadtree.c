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

struct node* new_leaf(Coordinate *coord){

	struct node *new = malloc(sizeof(struct node));

	new -> tag = isLeaf;
	new -> c = coord;
	//new -> peca = barco;

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
			struct node *temp; temp = new_leaf(root->c);
			root = new;
			insert(root, coord, particao, limxi, limxs, limyi, limys);
			insert(root, temp, particao, limxi, limxs, limyi, limys);
	}
	

	return root;
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

int number_nodes(struct node* root){

	if(root == NULL) return 0;

	return 1 +number_nodes(root->NW) + number_nodes(root->NE) + number_nodes(root->SW) + number_nodes(root->SE);

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