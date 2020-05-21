#ifndef _battleship_h_
#define _battleship_h_
#define _battleship_c_
#define _bitmaps_c_
#define _menus_c_
#define _QDtree_c_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/***** Estruturas *****/
//Coordenadas
typedef struct Coordinate {
	int x;
	int y;
} Coordinate;

typedef struct {
	double x;
	double y;
} CoordinateD;

//bitmap dos barcos
typedef struct {

	char m[5][5];

} bitmap;

//peça/barco
typedef struct {

	Coordinate c;
	int o;
	bitmap* mb;
	//int field_shot;

} piece;


/*
//Cell
typedef struct {

	piece* apont;
	int field_shot;

} Cell;

//tabuleiro
typedef struct {

	int size;
	Cell** board;

} game;
*/

enum treetag { isLeaf, isInternal} tag;

struct node {
	enum treetag tag;
	
	//leaf
	Coordinate *c;
	piece *peca;
	//int field_shot;

	//internal
	struct node *NW;
	struct node *NE;
	struct node *SW;
	struct node *SE;

} node;


//variável global
extern char p1[20],p2[20];
extern int score1,score2;

/***** Construtores *****/

//menus.c
void menu_inicial();
void print_menuB();
void menu_inicial_instructions();
void menu_rand();
void menu_game();
void menu_help();
void press_any_key();

//bitmaps.c
void print_bitmap(bitmap matriz);
// funções que criam bitmaps
bitmap create_rect();
bitmap create_quad();
bitmap create_barcoT();
bitmap create_barcoL();
bitmap create_barcoU();
//funções que rodam o bitmap
bitmap rotate_90(bitmap matriz);
bitmap rotate_180(bitmap matriz);
bitmap rotate_270(bitmap matriz);
bitmap switch_function(int opcao,int orientacao);
bitmap switch_functionRANDOMS(int opcao,int orientacao);
//tests
void print_bitmapas(bitmap* matriz);

//random numbers
int return_randoms(int lower, int higher);


//quadtree
Coordinate* new_coord(int a, int b);
CoordinateD new_coordD(long double a, long double b);
struct node* new_node();
struct node* new_leaf(Coordinate *coord, piece *boat);
struct node* insert(struct node *root, struct node *coord, CoordinateD particao, long double limxi, long double limxs, long double limyi, long double limys);
bool contains(struct node *root, struct node *coord, CoordinateD particao, long double limxi, long double limxs, long double limyi, double limys);
bool containsC(struct node *root, int x1, int y1, CoordinateD particao, long double limxi, long double limxs, long double limyi, long double limys);
bool contains2(struct node *root, int x1, int y1);
void inorder(struct node *root);
int number_leaves(struct node* root);
void print_tree(struct node* root);
bool pode_inserir(struct node* root, piece boat, int size);
void inserir_barco(struct node* root, piece *boat, int size);
bool pode_inserirRANDOMS(struct node* root, piece boat, int size);
void inserir_barcoRANDOMS(struct node* root, piece *boat, int size);
struct node* clear_tree(struct node *root);
void delete_tree(struct node *root);
void matriz_jogador(struct node *root, int size);
struct node* find(struct node *root, int x, int y, CoordinateD particao, long double limxi, long double limxs, long double limyi, long double limys);
int return_field_shot(struct node *root, int x1, int y1, CoordinateD particao, long double limxi, long double limxs, long double limyi, long double limys);
bool shoot(struct node *root, int x1, int y1, CoordinateD particao, long double limxi, long double limxs, long double limyi, long double limys);
#endif
