#ifndef _battleship_h_
#define _battleship_h_

#include <stdio.h>
#include <stdlib.h>

/***** Structures *****/
typedef struct Coordinate {
	int x;
	int y;
} Coordinate;

typedef struct {

	char **matriz;
	int lin, col;

} game;

typedef struct Peca {

	Coordinate c;
	int n;
	int o;
	game m1;
	int cont;

} peca;


// Coordinates

// Constructures

Coordinate* new_coord(int a, int b);

void print_tabuleiro(game *board);
void create_matriz(game *board);


//funcoes que fazem print dos exemplos das peças
void print_barcoQuad();
void print_barcoRect();
void print_barcoT();
void print_barcoU();
void print_barcoL();

#endif
