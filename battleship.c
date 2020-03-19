#include "battleship.h"



// Criar nova coordenada
Coordinate* new_coord(int a, int b) {
	Coordinate* c = (Coordinate *) malloc(sizeof(Coordinate*));
	c -> x = a;
	c -> y = b;
	return c;
}

//print da matriz
void print_tabuleiro(game *board){

	for(int i=0; i < board->lin ; i++){
		for(int j=0; j< board->col;j++){
			printf(" %c ", board -> matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


//Criar matriz
void create_matriz(game *board) {

	for(int i=0; i < board->lin ; i++){
		for(int j=0; j< board->col;j++){
			board -> matriz[i][j] = '.';
		}
	}

	//print_tabuleiro(board);

}



// TIPOS DE BARCOS
void print_barcoQuad(){

	printf("\n-------------");
 	printf("\n| 1. Square |");
 	printf("\n-------------");
	printf("\n");
	
	for(int i=0; i < 2 ; i++){
		printf("| ");
		for(int j=0; j< 2;j++){
			printf(" x ");
		}
		printf(" |");
		printf("\n");
	}
	printf("\n");

}

void print_barcoRect(){

	printf("\n----------------");
 	printf("\n| 2. Rectangle |");
 	printf("\n----------------");
	printf("\n");

	for(int i=0; i < 2 ; i++){
		printf("| ");
		for(int j=0; j< 3;j++){
			printf(" x ");
		}
		printf(" |");
		printf("\n");
	}
	printf("\n");
}

void print_barcoT(){

	printf("\n--------------");
 	printf("\n| 3. T Shape |");
 	printf("\n--------------");
	printf("\n");

	for(int i=0; i < 3 ; i++){
		printf("| ");
		for(int j=0; j< 3;j++){
			if(i==0) printf(" x ");
			else if(j==1) printf(" x ");
			else printf("   ");
		}
		printf(" |");
		printf("\n");
	}
	printf("\n");
}

void print_barcoU(){

	printf("\n--------------");
 	printf("\n| 4. U Shape |");
 	printf("\n--------------");
	printf("\n");

	for(int i=0; i < 3 ; i++){
		printf("| ");
		for(int j=0; j< 3;j++){
			if((j==0) || j==2)printf(" x ");
			else if(i==2) printf(" x ");
			else printf("   ");
		}
		printf(" |");
		printf("\n");
	}
	printf("\n");
}

void print_barcoL(){

	printf("\n--------------");
 	printf("\n| 4. L Shape |");
 	printf("\n--------------");
	printf("\n");

	for(int i=0; i<3;i++){
		printf("| ");
		for(int j=0; j<3;j++){
			if(j==0) printf(" x ");
			else if(i==2) printf("x ");
			else printf("  ");
		}
		printf(" |");
		printf("\n");
	}
	printf("\n");
}
