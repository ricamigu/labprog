#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "battleship.h"


int main(){
	char p1[20],p2[20];	
	//bitmap quad,rect,bT,bL,bU;
 	//quad = create_quad();
 	//rect = create_rect();
 	//bT = create_barcoT();
 	//bU = create_barcoL();
 	//bL = create_barcoU();

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
 	create_matriz(p2m);
 	
 	int opt;
 	printf("Enter the number of boats: ");
 	scanf("%d", &b);
 	bool pode = false;

 	Coordinate* a = (Coordinate *) malloc(sizeof(Coordinate*));
 	//piece boat1, boat2;
 	piece boat1[b+1],boat2[b+1];

 	//piece *boats1 = &boat1;
 	//piece *boats2 = &boat2;
 	piece *boats1 = (piece *) malloc(sizeof(piece*));
 	piece *boats2 = (piece *) malloc(sizeof(piece*));

 	bitmap mapass[b+1];
 	//bitmap* mapas;

 	//ciclo para criar os barcos
 	for(int i=1; i<=b; i++){

 			//boats1[i] = boat1[i];
	 		printf("\nChoose the type of boat\n");
			print_menuB();	//menu dos barcos em menus.c
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


		switch(opt){
			case 1: switch(boats1[i].o){
						case 0: mapass[i] = create_quad();
								boats1[i].mb = &mapass[i];
								inserir_barco(boats1[i].c, &boats1[i], p1m);
								break;
						case 90: mapass[i] = rotate_90(create_quad());
								 boats1[i].mb = &mapass[i];
								 inserir_barco(boats1[i].c, &boats1[i], p1m);		
								 break;
						case 180: 
								 //mapas[i] = rotate_180(create_quad());
								 //boats1[i].mb = &mapas[i];
								  mapass[i] = rotate_180(create_quad());
								  boats1[i].mb = &mapass[i];
								  inserir_barco(boats1[i].c, &boats1[i], p1m);
								  break;
						case 270: 
								 mapass[i] = rotate_270(create_quad());
								 boats1[i].mb = &mapass[i];
								  inserir_barco(boats1[i].c, &boats1[i], p1m);
								  break;
					}
					break;

			case 2: switch(boats1[i].o){
						case 0: //boats1[i].mb = create_rect();
								mapass[i] = create_rect();
								boats1[i].mb = &mapass[i];
								inserir_barco(boats1[i].c, &boats1[i], p1m);
								break;
						case 90: //boats1[i].mb = rotate_90(create_rect());
								mapass[i] = rotate_90(create_rect());
								boats1[i].mb = &mapass[i];
								 inserir_barco(boats1[i].c, &boats1[i], p1m);
								 break;
						case 180: //boats1[i].mb = rotate_180(create_rect());
								 mapass[i] = rotate_180(create_rect());
								 boats1[i].mb = &mapass[i];
								 inserir_barco(boats1[i].c, &boats1[i], p1m);
								 break;
						case 270: //boats1[i].mb = rotate_270(create_rect());
								 mapass[i] = rotate_270(create_rect());
								 boats1[i].mb = &mapass[i];
								 inserir_barco(boats1[i].c, &boats1[i], p1m);
								 break;
					}
					break;

			case 3: switch(boats1[i].o){
						case 0: //boats1[i].mb = create_barcoT();
								mapass[i] = create_barcoT();
								boats1[i].mb = &mapass[i];
								inserir_barco(boats1[i].c, &boats1[i], p1m);
								break;
						case 90: //boats1[i].mb = rotate_90(create_barcoT());
								 mapass[i] = rotate_90(create_barcoT());
								 boats1[i].mb = &mapass[i];
								 inserir_barco(boats1[i].c, &boats1[i], p1m);
								 break;
						case 180: //boats1[i].mb = rotate_180(create_barcoT());
								 mapass[i] = rotate_180(create_barcoT());
								 boats1[i].mb = &mapass[i];
								 inserir_barco(boats1[i].c, &boats1[i], p1m);
								 break;
						case 270: //boats1[i].mb = rotate_270(create_barcoT());
								 mapass[i] = rotate_270(create_barcoT());
								 boats1[i].mb = &mapass[i];
								 inserir_barco(boats1[i].c, &boats1[i], p1m);
								 break;
					}
					break;

			case 4: switch(boats1[i].o){
						case 0: //boats1[i].mb = create_barcoL();
								mapass[i] = create_barcoL();
								boats1[i].mb = &mapass[i];
								inserir_barco(boats1[i].c, &boats1[i], p1m);
								break;
						case 90: //boats1[i].mb = rotate_90(create_barcoL());
								 mapass[i] = rotate_90(create_barcoL());
								 boats1[i].mb = &mapass[i];
								 inserir_barco(boats1[i].c, &boats1[i], p1m);
								 break;
						case 180: //boats1[i].mb = rotate_180(create_barcoL());
								 mapass[i] = rotate_180(create_barcoL());
								 boats1[i].mb = &mapass[i];
								 inserir_barco(boats1[i].c, &boats1[i], p1m);
								 break;
						case 270: //boats1[i].mb = rotate_270(create_barcoL());
								 mapass[i] = rotate_270(create_barcoL());
								 boats1[i].mb = &mapass[i];
								 inserir_barco(boats1[i].c, &boats1[i], p1m);
								 break;
					}
					break;

			case 5: switch(boats1[i].o){
						case 0: //boats1[i].mb = rotate_90(create_quad());
								 //boats1[i].mbb = &boats1[i].mb;
								 mapass[i] = create_barcoU();
								 boats1[i].mb = &mapass[i];
								inserir_barco(boats1[i].c, &boats1[i], p1m);
								break;
						case 90: //boats1[i].mb = rotate_90(create_quad());
								 //boats1[i].mbb = &boats1[i].mb;
								 mapass[i] = rotate_90(create_barcoU());
								 boats1[i].mb = &mapass[i];
								 inserir_barco(boats1[i].c, &boats1[i], p1m);
								 break;
						case 180: //boats1[i].mb = rotate_90(create_quad());
								 //boats1[i].mbb = &boats1[i].mb;
								 mapass[i] = rotate_180(create_barcoU());
								 boats1[i].mb = &mapass[i];
								 inserir_barco(boats1[i].c, &boats1[i], p1m);
								 break;
						case 270://boats1[i].mb = rotate_90(create_quad());
								 //boats1[i].mbb = &boats1[i].mb;
								 mapass[i] = rotate_270(create_barcoU());
								 boats1[i].mb = &mapass[i];
								 inserir_barco(boats1[i].c, &boats1[i], p1m);
								 break;
					}
					break;
				default: printf("Invalid boat!\n");
						 i--;
						 break;
			}

			print_tabuleiro(p1m);
		}


	
	//Coordinate* cc = (Coordinate *) malloc(sizeof(Coordinate*));
	//cc = new_coord(20,19);	//  20 19 coordenada de teste ao inserir tipo U em (22,17)
	//acertou(*cc, p1m);

/*
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){

				printf(" %c ", boats1[1].mb -> m[i][j]);

			}
			printf("\n");
		}


		print_tabuleiro(p1m);

*/

		bitmap mapas2[b+1];

		for(int i=1; i<=b; i++){

 			//boats1[i] = boat1[i];
	 		printf("\nChoose the type of boat\n");
			print_menuB();	//menu dos barcos em menus.c
			printf("> ");
			scanf("%d", &opt);
			printf("\n\nPlayer %s coordinate for boat %d: ", p2, i);
	 		scanf("%d", &x1);
	 		scanf("%d", &x2);
	 		a = new_coord(x1,x2);

	 		boats2[i].c = *a;
	 		printf("\nChoose boat rotation (0, 90, 180, 270): ");
	 		scanf("%d", &vh);
	 		boats2[i].o = vh;
	 		boats2[i].shot_count = 0;


		switch(opt){
			case 1: switch(boats2[i].o){
						case 0: mapas2[i] = create_quad();
								boats2[i].mb = &mapas2[i];
								inserir_barco(boats2[i].c, &boats2[i], p2m);
								break;
						case 90: mapas2[i] = rotate_90(create_quad());
								 boats2[i].mb = &mapas2[i];
								 inserir_barco(boats2[i].c, &boats2[i], p2m);		
								 break;
						case 180: 
								 //mapas[i] = rotate_180(create_quad());
								 //boats1[i].mb = &mapas[i];
								  mapas2[i] = rotate_180(create_quad());
								  boats2[i].mb = &mapas2[i];
								  inserir_barco(boats2[i].c, &boats2[i], p2m);
								  break;
						case 270: 
								 mapas2[i] = rotate_270(create_quad());
								 boats2[i].mb = &mapas2[i];
								  inserir_barco(boats2[i].c, &boats2[i], p2m);
								  break;
					}
					break;

			case 2: switch(boats2[i].o){
						case 0: //boats1[i].mb = create_rect();
								mapas2[i] = create_rect();
								boats2[i].mb = &mapas2[i];
								inserir_barco(boats2[i].c, &boats2[i], p2m);
								break;
						case 90: //boats1[i].mb = rotate_90(create_rect());
								mapas2[i] = rotate_90(create_rect());
								boats2[i].mb = &mapas2[i];
								 inserir_barco(boats2[i].c, &boats2[i], p2m);
								 break;
						case 180: //boats1[i].mb = rotate_180(create_rect());
								 mapas2[i] = rotate_180(create_rect());
								 boats2[i].mb = &mapas2[i];
								 inserir_barco(boats2[i].c, &boats2[i], p2m);
								 break;
						case 270: //boats1[i].mb = rotate_270(create_rect());
								 mapas2[i] = rotate_270(create_rect());
								 boats2[i].mb = &mapas2[i];
								 inserir_barco(boats2[i].c, &boats2[i], p2m);
								 break;
					}
					break;

			case 3: switch(boats2[i].o){
						case 0: //boats1[i].mb = create_barcoT();
								mapas2[i] = create_barcoT();
								boats2[i].mb = &mapas2[i];
								inserir_barco(boats2[i].c, &boats2[i], p2m);
								break;
						case 90: //boats1[i].mb = rotate_90(create_barcoT());
								 mapas2[i] = rotate_90(create_barcoT());
								 boats2[i].mb = &mapas2[i];
								 inserir_barco(boats2[i].c, &boats2[i], p2m);
								 break;
						case 180: //boats1[i].mb = rotate_180(create_barcoT());
								 mapas2[i] = rotate_180(create_barcoT());
								 boats2[i].mb = &mapas2[i];
								 inserir_barco(boats2[i].c, &boats2[i], p2m);
								 break;
						case 270: //boats1[i].mb = rotate_270(create_barcoT());
								 mapas2[i] = rotate_270(create_barcoT());
								 boats2[i].mb = &mapas2[i];
								 inserir_barco(boats2[i].c, &boats2[i], p2m);
								 break;
					}
					break;

			case 4: switch(boats2[i].o){
						case 0: //boats1[i].mb = create_barcoL();
								mapas2[i] = create_barcoL();
								boats2[i].mb = &mapas2[i];
								inserir_barco(boats2[i].c, &boats2[i], p2m);
								break;
						case 90: //boats1[i].mb = rotate_90(create_barcoL());
								 mapas2[i] = rotate_90(create_barcoL());
								 boats2[i].mb = &mapas2[i];
								 inserir_barco(boats2[i].c, &boats2[i], p2m);
								 break;
						case 180: //boats1[i].mb = rotate_180(create_barcoL());
								 mapas2[i] = rotate_180(create_barcoL());
								 boats2[i].mb = &mapas2[i];
								 inserir_barco(boats2[i].c, &boats2[i], p2m);
								 break;
						case 270: //boats1[i].mb = rotate_270(create_barcoL());
								 mapas2[i] = rotate_270(create_barcoL());
								 boats2[i].mb = &mapas2[i];
								 inserir_barco(boats2[i].c, &boats2[i], p2m);
								 break;
					}
					break;

			case 5: switch(boats2[i].o){
						case 0: //boats1[i].mb = rotate_90(create_quad());
								 //boats1[i].mbb = &boats1[i].mb;
								 mapas2[i] = create_barcoU();
								 boats2[i].mb = &mapas2[i];
								inserir_barco(boats2[i].c, &boats2[i], p2m);
								break;
						case 90: //boats1[i].mb = rotate_90(create_quad());
								 //boats1[i].mbb = &boats1[i].mb;
								 mapas2[i] = rotate_90(create_barcoU());
								 boats2[i].mb = &mapas2[i];
								 inserir_barco(boats2[i].c, &boats2[i], p2m);
								 break;
						case 180: //boats1[i].mb = rotate_90(create_quad());
								 //boats1[i].mbb = &boats1[i].mb;
								 mapas2[i] = rotate_180(create_barcoU());
								 boats2[i].mb = &mapas2[i];
								 inserir_barco(boats2[i].c, &boats2[i], p2m);
								 break;
						case 270://boats1[i].mb = rotate_90(create_quad());
								 //boats1[i].mbb = &boats1[i].mb;
								 mapas2[i] = rotate_270(create_barcoU());
								 boats2[i].mb = &mapas2[i];
								 inserir_barco(boats2[i].c, &boats2[i], p2m);
								 break;
					}
					break;
			default: printf("Invalid boat!\n");
					 i--;
					 break;
			}

			print_tabuleiro(p2m);
		}
	

	print_tabuleiro(p1m);
	print_tabuleiro(p2m);

	return 0;

}


