#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "battleship.h"


int main(){


	struct node *root;
	root = new_node();


	piece *pec;

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

	Coordinate *a = new_coord(10,10);
	Coordinate *b = new_coord(10,30);
	Coordinate *c = new_coord(30,10);
	Coordinate *d = new_coord(30,30);

	struct node *leaf1; struct node *leaf2; struct node *leaf3; struct node *leaf4;
	leaf1 = new_leaf(a,pec); leaf2 = new_leaf(b,pec); leaf3 = new_leaf(c,pec); leaf4 = new_leaf(d,pec);

	Coordinate *e = new_coord(1,1);
	struct node *leaf5; leaf5 = new_leaf(e,pec);

	Coordinate *f = new_coord(25,15);
	struct node *leaf6; leaf6 = new_leaf(f,pec);

	Coordinate *centro = new_coord(20,20);
	struct node *leafcentro; leafcentro = new_leaf(centro,pec);

	Coordinate *um = new_coord(5,5);
	struct node *leafum; leafum = new_leaf(um,pec);

	/*
	insert(root, leaf1, partir, 0, 40, 0, 40);
	insert(root, leaf2, partir, 0, 40, 0, 40);
	insert(root, leaf3, partir, 0, 40, 0, 40);
	insert(root, leaf4, partir, 0, 40, 0, 40);
	insert(root, leaf5, partir, 0, 40, 0, 40);
	insert(root, leaf6, partir, 0, 40, 0, 40);
	insert(root, leafcentro, partir, 0, 40, 0, 40);
	insert(root, leafum, partir, 0, 40, 0, 40);
	*/



	insert2(root, leaf1,20,20);
	insert2(root, leaf2, 20,20);
	insert2(root, leaf3, 20,20);
	insert2(root, leaf4, 20,20);
	//insert2(root, leaf5, 20,20);
	//insert2(root, leaf6, 20,20);
	//insert2(root, leafcentro, 20,20);
	insert2(root, leafum, 20,20);





	//printf("particao: (%f,%f)\n", partir->x,partir->y);

	//inorder(root);

	print_tree(root); printf("\n");

	//printf("\nnos: %d\n", number_nodes(root));
	
	Coordinate *nexiste = new_coord(32,31);
	/*struct node *leafnexiste = new_leaf(nexiste,pec);
	*/
	printf("Contains: ");
	bool cont=false;
	//cont = contains(root, leaf5, partir, 0, 40, 0 , 40);
	cont = contains22(root, 32,31,20,20);
	//cont = containsC(root, 0,0, partir, 0,40,0,40);
	if(cont==true) printf("exists!");

	/*
	//printf("ola");
	printf("NW (%d,%d)\n", root->NW->c->x,root->NW->c->y);
	printf("NE (%d,%d)\n", root->NE->c->x,root->NE->c->y);
	printf("SW (%d,%d)\n", root->SW->c->x,root->SW->c->y);
	printf("SE (%d,%d)\n", root->SE->c->x,root->SE->c->y);
	*/

	return 0;
}