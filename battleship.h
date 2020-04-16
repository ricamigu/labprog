#ifndef _battleship_h_
#define _battleship_h_
#define _bitmaps_c_
#define _menus_c_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/***** Structures *****/
typedef struct Coordinate {
	int x;
	int y;
} Coordinate;

typedef struct {

	char m[5][5];

} bitmap;

typedef struct {

	Coordinate c;
	int o;
	bitmap* mb;
	//bitmap* mbb;
	int shot_count;

} piece;

typedef struct {

	piece* apont;
	int field_shot;

} Cell;

typedef struct {

	int size;
	Cell** board;

} game;



//variavel global
//extern bitmap quad,rect,bT,bL,bU;
//extern char p1[20],p2[20];

// Constructures
Coordinate* new_coord(int a, int b);

//battleship.c
void print_tabuleiro(game *board);
void create_matriz(game *board);

//menus
void print_menuB(bitmap a, bitmap b, bitmap c, bitmap d, bitmap e);

//bitmaps.c
void print_bitmap(bitmap matriz);

// funcoes que criam bitmaps
bitmap create_rect();
bitmap create_quad();
bitmap create_barcoT();
bitmap create_barcoL();
bitmap create_barcoU();

//funcoes que rodam o bitmap
bitmap rotate_90(bitmap matriz);
bitmap rotate_180(bitmap matriz);
bitmap rotate_270(bitmap matriz);

//funcao que insere barco
void inserir_barco(Coordinate c, piece* boat, game* tabuleiro);

//verifica se é possível inserir um barco
bool pode_inserir(Coordinate c, piece boat, game* tabuleiro);


//test
bool acertou(Coordinate c, game* tabuleiro);
void print_bitmapas(bitmap* matriz);

#endif
