#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "battleship.h"


int main(){
	char p1[20],p2[20];	
	bitmap quad,rect,bT,bL,bU;
 	quad = create_quad();
 	rect = create_rect();
 	bT = create_barcoT();
 	bU = create_barcoL();
 	bL = create_barcoU();

	int n,b;
	int x1, x2, tam, vh;
	Coordinate p;

	printf("\n\n");
	printf("-----------------------\n");
	printf("|   Battleship Game   |\n");
	printf("-----------------------\n\n");
	printf("Welcome to the game!\n\n");
	printf("Enter first player name: ");
	scanf("%s",p1);
	printf("\nEnter second player name: ");
	scanf("%s",p2);
	printf("\nEnter the size of board (N*N): ");
	scanf("%d",&n);
	printf("\n");
	system("clear");


	//matrizes do jogo
	game m1, m2;

	//matriz do jogador 1
	game *p1m = &m1;
	p1m -> size = n;

	p1m -> board = (Cell ** )malloc (sizeof(Cell *) * p1m-> size);
	for(int i=0;i< p1m -> size; i++) {
 		p1m -> board[i] = (Cell *) malloc(sizeof(Cell)* p1m -> size);
 	}

 	//matriz do 2 jogador
 	game *p2m= &m2;
	p2m-> size = n;

	p2m -> board = (Cell ** )malloc (sizeof(Cell *) * p2m-> size);
	for(int i=0;i< p2m -> size; i++) {
 		p2m -> board[i] = (Cell *) malloc(sizeof(Cell)* p2m -> size);
 	}

 	create_matriz(p1m);

 	
 	int opt;
 	printf("Enter the number of boats: ");
 	scanf("%d", &b);
 	bool pode = false;

 	Coordinate* a = (Coordinate *) malloc(sizeof(Coordinate*));
 	piece *boats1 = (piece *) malloc((b+1)* sizeof(piece*));
 	piece *boats2 = (piece *) malloc((b+1) * sizeof(piece*));

 	//ciclo para criar os barcos
 	for(int i=1; i<=b; i++){

	 		printf("\nChoose the type of boat\n");
			print_menuB(quad, rect, bT, bU, bL);	//menu dos barcos em menus.c
			printf("> ");
			scanf("%d", &opt);
			printf("\n\nPlayer %s coordinate for boat %d: ", p1, i);
	 		scanf("%d", &x1);
	 		scanf("%d", &x2);
	 		a = new_coord(x1,x2);
	 		boats1[i].c = *a;
	 		printf("\nChoose boat rotation (0, 90, 180, 270): ");
	 		scanf("%d", &vh);
	 		boats1[i].o = vh;
	 		boats1[i].shot_count = 0;
/*
	 		switch(opt){
	 			case 1: pode_inserir(boats1[i].c);
	 					break;
	 			case 2: break;
	 			case 3: break;
	 			case 4: break;
	 			case 5: break;
	 		}
		
		}*/


		switch(opt){
			case 1: switch(boats1[i].o){
						case 0: boats1[i].mb = create_quad();
								inserir_barco(boats1[i].c, boats1[i], p1m);
								pode = true;
								break;
						case 90: boats1[i].mb = rotate_90(create_quad());
								 inserir_barco(boats1[i].c, boats1[i], p1m);		
								 break;
						case 180: boats1[i].mb = rotate_180(create_quad());
								  inserir_barco(boats1[i].c, boats1[i], p1m);
								  break;
						case 270: boats1[i].mb = rotate_270(create_quad());
								  inserir_barco(boats1[i].c, boats1[i], p1m);
								  break;
					}
					print_tabuleiro(p1m);
					break;

			case 2: switch(boats1[i].o){
						case 0: boats1[i].mb = create_rect();
								inserir_barco(boats1[i].c, boats1[i], p1m);
								break;
						case 90: boats1[i].mb = rotate_90(create_rect());
								 inserir_barco(boats1[i].c, boats1[i], p1m);
								 break;
						case 180: boats1[i].mb = rotate_180(create_rect());
								 inserir_barco(boats1[i].c, boats1[i], p1m);
								 break;
						case 270: boats1[i].mb = rotate_270(create_rect());
								 inserir_barco(boats1[i].c, boats1[i], p1m);
								 break;
					}
					print_tabuleiro(p1m);
					break;

			case 3: switch(boats1[i].o){
						case 0: boats1[i].mb = create_barcoT();
								inserir_barco(boats1[i].c, boats1[i], p1m);
								break;
						case 90: boats1[i].mb = rotate_90(create_barcoT());
								 inserir_barco(boats1[i].c, boats1[i], p1m);
								 break;
						case 180: boats1[i].mb = rotate_180(create_barcoT());
								 inserir_barco(boats1[i].c, boats1[i], p1m);
								 break;
						case 270: boats1[i].mb = rotate_270(create_barcoT());
								 inserir_barco(boats1[i].c, boats1[i], p1m);
								 break;
					}
					print_tabuleiro(p1m);
					break;

			case 4: switch(boats1[i].o){
						case 0: boats1[i].mb = create_barcoL();
								inserir_barco(boats1[i].c, boats1[i], p1m);
								break;
						case 90: boats1[i].mb = rotate_90(create_barcoL());
								 inserir_barco(boats1[i].c, boats1[i], p1m);
								 break;
						case 180: boats1[i].mb = rotate_180(create_barcoL());
								 inserir_barco(boats1[i].c, boats1[i], p1m);
								 break;
						case 270: boats1[i].mb = rotate_270(create_barcoL());
								 inserir_barco(boats1[i].c, boats1[i], p1m);
								 break;
					}
					print_tabuleiro(p1m);
					break;

			case 5: switch(boats1[i].o){
						case 0: boats1[i].mb = create_barcoU();
								inserir_barco(boats1[i].c, boats1[i], p1m);
								break;
						case 90: boats1[i].mb = rotate_90(create_barcoU());
								 inserir_barco(boats1[i].c, boats1[i], p1m);
								 break;
						case 180: boats1[i].mb = rotate_180(create_barcoU());
								 inserir_barco(boats1[i].c, boats1[i], p1m);
								 break;
						case 270: boats1[i].mb = rotate_270(create_barcoU());
								 inserir_barco(boats1[i].c, boats1[i], p1m);
								 break;
					}
					print_tabuleiro(p1m);
					break;
			}
		}
	
		return 0;

	}
