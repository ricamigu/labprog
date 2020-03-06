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


// Coordinates

// Constructures

Coordinate* new_coord(int a, int b);

void print_tabuleiro(game *board);
void create_matriz(game *board);

#endif
