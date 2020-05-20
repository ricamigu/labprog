#include <stdio.h>
#include <stdlib.h>
#include "battleship.h"


int main(){


	struct node *root;
	root = new_node();

	/*

	Coordinate *a = new_coord(5,5);
	Coordinate *aa = new_coord(5,3);
	Coordinate *aaa = new_coord(5,4);
	Coordinate *b = new_coord(5,6);
	Coordinate *bb = new_coord(5,7);

	struct node *leaf1;
	struct node *leaf2;
	struct node *leaf3;
	struct node *leaf4;
	struct node *leaf5;
	leaf1 = new_leaf(a);
	leaf1 = new_leaf(aa);
	leaf1 = new_leaf(aaa);
	leaf1 = new_leaf(b);
	leaf1 = new_leaf(bb);
	
	*/
	CoordinateD partir = new_coordD(20,20);

	Coordinate *a = new_coord(5,15);
	Coordinate *b = new_coord(10,30);
	Coordinate *c = new_coord(31,10);
	Coordinate *d = new_coord(30,30);

	struct node *leaf1; struct node *leaf2; struct node *leaf3; struct node *leaf4;
	leaf1 = new_leaf(a); leaf2 = new_leaf(b); leaf3 = new_leaf(c); leaf4 = new_leaf(d);

	Coordinate *e = new_coord(0,0);
	struct node *leaf5; leaf5 = new_leaf(e);

	Coordinate *f = new_coord(25,15);
	struct node *leaf6; leaf6 = new_leaf(f);

	Coordinate *centro = new_coord(20,20);
	struct node *leafcentro; leafcentro = new_leaf(centro);

	insert(root, leaf1, partir, 0, 40, 0, 40);
	insert(root, leaf2, partir, 0, 40, 0, 40);
	insert(root, leaf3, partir, 0, 40, 0, 40);
	insert(root, leaf4, partir, 0, 40, 0, 40);
	insert(root, leaf5, partir, 0, 40, 0, 40);
	insert(root, leaf6, partir, 0, 40, 0, 40);
	insert(root, leafcentro, partir, 0, 40, 0, 40);

	//printf("particao: (%f,%f)\n", partir->x,partir->y);

	inorder(root);

	print_tree(root); printf("\n");

	printf("\nnos: %d\n", number_nodes(root));

	/*
	//printf("ola");
	printf("NW (%d,%d)\n", root->NW->c->x,root->NW->c->y);
	printf("NE (%d,%d)\n", root->NE->c->x,root->NE->c->y);
	printf("SW (%d,%d)\n", root->SW->c->x,root->SW->c->y);
	printf("SE (%d,%d)\n", root->SE->c->x,root->SE->c->y);
	*/

	return 0;
}