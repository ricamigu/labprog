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

/*typedef struct {

	char **bit;
	int lin,col;

} bitmap;

*/

typedef struct {

	char m[5][5];

} bitmap;

typedef struct Peca {

	Coordinate c;
	int o;
	bitmap m1;
	int shot_count;

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
void put_QuadH(game *board, int x, int y, int n);




// funcoes que colocam as peças no board
bitmap create_rect0(Coordinate ini, game *board);
bitmap create_square0(Coordinate ini,game*board);
#endif