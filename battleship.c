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