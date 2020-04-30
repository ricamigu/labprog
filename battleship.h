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
extern char p1[20],p2[20];
extern int score1,score2;

// Constructures
Coordinate* new_coord(int a, int b);

//battleship.c
void print_tabuleiro(game *board);
void print_tabuleiroAdversario(game *tabuleiro);
void create_matriz(game *board);
void anular(game* tabuleiro);

//menus
void menu_inicial();
void print_menuB();
void menu_inicial_instructions();
void menu_rand();
void menu_game();
void menu_help();
void press_any_key();

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


//funcao para verificar onde o tiro foi dado
bool acertou(Coordinate c, game* tabuleiro);

//tests
void print_bitmapas(bitmap* matriz);
bitmap switch_function(int opcao,int orientacao);

//random numbers
int return_randoms(int lower, int higher);
bool pode_inserirRANDOMS(Coordinate c, piece boat, game* tabuleiro);
void inserir_barcoRANDOMS(Coordinate c, piece* boat, game* tabuleiro);
bitmap switch_functionRANDOMS(int opcao,int orientacao);

//verificar se o tabuleiro foi acertado em todas as posicoes de barcos
bool isFinished(game* tabuleiro);

//bool afundado(Coordinate cord, game* tabuleiro);



#endif
