#ifndef _battleship_h_
#define _battleship_h_
#define _battleship_c_
#define _bitmaps_c_
#define _menus_c_
#define _quadtree_c_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/***** Estruturas *****/
//Coordenadas
typedef struct Coordinate {
	int x;
	int y;
} Coordinate;

// Criar nova coordenada

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
	int shot_count;

} piece;

/*
typedef struct {

	char pos;
	int field_shot;

} Cell;*/
typedef struct {

	piece* apont;
	int field_shot;

} Cell;

typedef struct {

	int size;
	Cell** board;

} game;



//Cell
/*

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
	int field_shot;

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
void menu_matriz_ou_quad();

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
//funcao que alteram os bitmaps
void alterar_bitmap(struct node* leaf, int x1, int y1);
//tests
void print_bitmapas(bitmap* matriz);
bool afundado(bitmap* matriz);

//random numbers
int return_randoms(int lower, int higher);


//battleship.c
void print_tabuleiro(game *board);
void print_tabuleiroAdversario(game *tabuleiro);
void create_matriz(game *board);
void anular(game* tabuleiro);
//função que insere barco
void inserir_barco(Coordinate c, piece* boat, game* tabuleiro);
//verifica se é possível inserir um barco
bool pode_inserir(Coordinate c, piece boat, game* tabuleiro);
//função para verificar onde o tiro foi dado
bool acertou(Coordinate c, game* tabuleiro);
bool pode_inserirRANDOMS(Coordinate c, piece boat, game* tabuleiro);
void inserir_barcoRANDOMS(Coordinate c, piece* boat, game* tabuleiro);
bitmap switch_functionRANDOMS(int opcao,int orientacao);
//verificar se o tabuleiro foi acertado em todas as posições de barcos
bool isFinished(game* tabuleiro);


//quadtree
Coordinate* new_coord(int a, int b);
CoordinateD new_coordD(double a, double b);
struct node* new_node();
struct node* new_leaf(Coordinate *coord, piece *boat);
bool contains(struct node* root, int x1, int y1, double l1,double l2);
bool contains2(struct node* root, int x1, int y1, double l1,double l2);
bool contains_inef(struct node *root, int x1, int y1);
int return_fieldShot(struct node* root, int x1, int y1, double l1,double l2);
void inorder(struct node *root);
int number_leaves(struct node* root);
void print_tree(struct node* root);
void delete_tree(struct node *root);
struct node* clear_tree(struct node *root);
struct node* insert(struct node* root, struct node* coord, double l1, double l2);
bool pode_inserir_quad(struct node* root, piece boat, int size);
void inserir_barco_quad(struct node* root, piece *boat, int size);
bool pode_inserirRANDOMS_quad(struct node* root, piece boat, int size);
void inserir_barcoRANDOMS_quad(struct node* root, piece *boat, int size);
bool shoot(struct node* root, Coordinate *coord, double l1,double l2);
bool isFinished_quad(struct node *root, int shots_hit);
void matriz_jogador(struct node *root, int size);

#endif
