#include "battleship.h"
#include <stdbool.h>
#include <time.h> 

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


bool pode_inserirRANDOMS(struct node* root, piece boat, int size){

  int xx = boat.c.x-2;
  int yy = boat.c.y-2;

  if(xx < 0 || yy < 0 || xx>=size || yy>=size){
  	return false;
  }

  CoordinateD meio = new_coordD(size/2,size/2);

  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
        if(boat.mb -> m[i][j] == '1'){
          if (containsC(root, xx+i, yy+j, meio, 0, size, 0, size)){
          	return false;
          }
        }
    }
  }

  return true;
}

void inserir_barcoRANDOMS(struct node* root, piece *boat, int size){

	if(pode_inserirRANDOMS(root, *boat, size)){

		for(int i=0; i<5; i++){
	    	for(int j=0; j<5; j++){
	       		if(boat-> mb -> m[i][j] == '1'){

	       			Coordinate *a = new_coord(boat->c.x-2+i, boat->c.y-2+j);
	       			CoordinateD meio = new_coordD(size/2,size/2);
	       			struct node* leaf = new_leaf(a,boat);
	        		insert(root, leaf, meio, 0, size, 0, size);
	        	}
	    	}
	  	}
	}

	else {
		// caso nao possa inserir, volta a pedir coordenadas ao jogador
		int x1,y1;
		x1 = return_randoms(3,size-4);
		y1 = return_randoms(3,size-4);
		Coordinate* a  = new_coord(x1,y1);
		boat->c = *a;
		inserir_barcoRANDOMS(root, boat, size);
	}
}


//funcao que "transforma" a árvore numa matriz para representar
void matriz_jogador(struct node *root, int size){

	inorder(root);

	CoordinateD meio = new_coordD(size/2,size/2);

	for(int i=0; i < size; i++){
		if(i<10) printf(" %d",i);																						//
		if(i>=10) printf("%d",i);
		for(int j=0; j<size; j++){
			if(!containsC(root, i, j, meio, 0, size, 0, size)){
				printf("\033[1;34m");
				printf(" 0 ");
				printf("\033[0m");
			}
			else { printf(" 1 "); }
		}
		printf("\n");
	}


	printf("##");
	for(int j=0;j<size;j++){
		if(j<10) printf(" %d ", j);
		if(j>=10) printf(" %d",j);
	}
	printf("\n");

}