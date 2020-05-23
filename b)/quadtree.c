#include <stdio.h>
#include <stdlib.h>
#include "battleship.h"


Coordinate* new_coord(int a, int b) {
	Coordinate* c = (Coordinate *) malloc(sizeof(Coordinate*)*64);
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

	struct node *new = malloc(sizeof(struct node)*64);

	new -> tag = isInternal;
	new -> NW = NULL;
	new -> NE = NULL;
	new -> SW = NULL;
	new -> SE = NULL;

	new -> c = NULL;
	new -> peca = NULL;

	return new;
}

struct node* new_leaf(Coordinate *coord, piece *boat){

	struct node *new = malloc(sizeof(struct node)*64);

	new -> tag = isLeaf;
	new -> c = coord;
	new -> peca = boat;

	new -> NW = NULL;
	new -> NE = NULL;
	new -> SW = NULL;
	new -> SE = NULL;
	new -> field_shot = 0;

	return new;

}


struct node* insert(struct node* root, struct node* coord, double l1,double l2){

	if(root==NULL){
		root = coord;
		return root;
	}

	if(root->tag == isInternal){

		if( coord->c->x < l1 && coord->c->y < l2)
			root->NW = insert(root->NW,coord,l1/2,l2/2);

		if( coord->c->x < l1 && coord->c->y  >= l2)
			root->NE = insert(root->NE,coord,l1/2,l2+l2/2);

		if( coord->c->x >= l1 && coord->c->y  < l2)
			root->SW = insert(root->SW,coord,l1+l1/2,l2/2);

		if( coord->c->x >= l1 && coord->c->y  >= l2)
			root->SE = insert(root->SE,coord,l1+l1/2,l2+l2/2);
	}


	if(root->tag == isLeaf){

		struct node *new = malloc(sizeof(struct node)*64);
		new = new_node();
		struct node *temp = malloc(sizeof(struct node)*64);
		temp = new_leaf(root->c,root->peca);
		root = new;
		insert(root,temp,l1,l2);
		insert(root,coord,l1,l2);

	}
	return root;

}



bool contains(struct node* root, int x1, int y1, double l1,double l2){

	if(root==NULL) return false;

	double xx = x1;
	double yy = y1;


	if(root->tag == isInternal){

		if( x1 < l1 && y1 < l2)
			return contains(root->NW,x1,y1,l1/2,l2/2);

		if( x1 < l1 && y1 >= l2)
			return contains(root->NE,x1,y1,l1/2,l2+l2/2);

		if( x1 >= l1 && y1 < l2)
			return contains(root->SW,x1,y1,l1+l1/2,l2/2);

		if( x1 >= l1 && y1 >= l2)
			return contains(root->SE,x1,y1,l1+l1/2,l2+l2/2);
	}

	if(root->tag == isLeaf){
		if(root->c->x == x1 && root->c->y == y1)
			return true;
	}
	return false;
}



bool contains2(struct node* root, int x1, int y1, double l1,double l2){

	if(root==NULL) return false;

	double xx = x1;
	double yy = y1;


	if(root->tag == isInternal){

		if( x1 < l1 && y1 < l2)
			return contains2(root->NW,x1,y1,l1/2,l2/2);

		if( x1 < l1 && y1 >= l2)
			return contains2(root->NE,x1,y1,l1/2,l2+l2/2);

		if( x1 >= l1 && y1 < l2)
			return contains2(root->SW,x1,y1,l1+l1/2,l2/2);

		if( x1 >= l1 && y1 >= l2)
			return contains2(root->SE,x1,y1,l1+l1/2,l2+l2/2);
	}

	if(root->tag == isLeaf){
		if(root->c->x == x1 && root->c->y == y1){
			if(root->field_shot == 2){
				//printf("Shot already taken!\n");
				return false;
			}
			else {
				root->field_shot = 2;
				printf("Shot hit!\n");
				alterar_bitmap(root, x1, y1);
				//print_bitmapas(root->peca->mb);
				if(afundado(root->peca->mb)) printf("The ship sunk!\n");
				printf("\n");
				return true;
			}
		}

	}

	return false;
}

int return_fieldShot(struct node* root, int x1, int y1, double l1,double l2){

	if(root==NULL) return 0;

	double xx = x1;
	double yy = y1;


	if(root->tag == isInternal){

		if( x1 < l1 && y1 < l2)
			return return_fieldShot(root->NW,x1,y1,l1/2,l2/2);

		if( x1 < l1 && y1 >= l2)
			return return_fieldShot(root->NE,x1,y1,l1/2,l2+l2/2);

		if( x1 >= l1 && y1 < l2)
			return return_fieldShot(root->SW,x1,y1,l1+l1/2,l2/2);

		if( x1 >= l1 && y1 >= l2)
			return return_fieldShot(root->SE,x1,y1,l1+l1/2,l2+l2/2);
	}

	if(root->tag == isLeaf){
		if(root->c->x == x1 && root->c->y == y1){
			return root->field_shot;
		}
	}
	return 1;
}


//ineficiente, percorre a arvore toda (para teste apenas)
bool contains_inef(struct node *root, int x1, int y1){

	if(root==NULL) return false;

    if(root!=NULL) // checking if the root is not null
    {
    	if(root->tag==isLeaf) {
	        if( (root->c->x == x1) && (root->c->y == y1)){
				return true;
	        }
		}
    }

    return contains_inef(root->NW,x1,y1) || contains_inef(root->NE,x1,y1) || contains_inef(root->SW,x1,y1) || contains_inef(root->SE,x1,y1);

}



int number_leaves(struct node* root){

	int cont=0;

	if(root == NULL) return 0;
	
	if(root->tag==isLeaf) cont=1;

	return cont + number_leaves(root->NW) + number_leaves(root->NE) + number_leaves(root->SW) + number_leaves(root->SE);

}

int contador=1;

void inorder(struct node *root)
{
    if(root!=NULL) // checking if the root is not null
    {		
	        inorder(root->NW);
	        inorder(root->NE);
	        if(root->tag==isLeaf) {printf(" %d : (%d,%d) \n", contador, root->c->x,root->c->y); contador++;}
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
	struct node *new_root = malloc(sizeof(struct node)*64);
	new_root = new_node();
	return new_root;
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
