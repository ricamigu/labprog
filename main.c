#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h> 
#include "battleship.h"

int main(){

	char p1[20],p2[20];	
	int score1 = 0;
	int score2 = 0;

	int n,b;
	int x1, x2, tam, vh;
	Coordinate p;
	int minicial;

	while(minicial != 1){
		menu_inicial();
		printf("> ");
		scanf("%d",&minicial);
		if(minicial == 2) menu_inicial_instructions();
		else if(minicial == 3) { printf("Goodbye!\n"); return EXIT_SUCCESS;}
	}

	printf("\n");
	printf("Enter first player name: ");
	scanf("%s",p1);
	printf("\nEnter second player name: ");
	scanf("%s",p2);
	printf("\nEnter the size of board (N*N between 20x20 to 40x40): ");
	scanf("%d",&n);
	while(n > 40 || n < 20){
		printf("\nError! The size of the board must be between 20x20 and 40x40.");
		printf("\nEnter the size of board (N*N): ");
		scanf("%d",&n);
	}

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

 	//print_tabuleiro(p1m);
 	//print_tabuleiro(p2m);

 	int rand;
 	menu_rand();
 	scanf("%d",&rand);


 	if(rand == 2){

 		int minR = 1; 
 		int maxR = (n*n)/(5*5);
 		srand(time(0));

 		int randB = return_randoms(minR,maxR);
 		//printf("randB = %d\n", randB);
 		Coordinate* aa = (Coordinate *) malloc(sizeof(Coordinate*));
	 	//piece boat1, boat2;
	 	piece boatR1[randB+1],boatR2[randB+1];

	 	//piece *boats1 = &boat1;
	 	//piece *boats2 = &boat2;
	 	piece *boatsR1 = (piece *) malloc(sizeof(piece*));
	 	piece *boatsR2 = (piece *) malloc(sizeof(piece*));

	 	bitmap mapasR1[randB+1];
	 	bitmap mapasR2[randB+1];

	 	//int cont1=1,cont2=1,conta=1;

	 	//RANDOMS PLAYER 1
	 	for(int i=1; i<=randB; i++){

	 			//printf("cont1: %d\n",cont1);

	 			int optR = return_randoms(1,5);
		 		int xR = return_randoms(3,(n-3));
			 	int yR = return_randoms(3,(n-3));
			 	//printf("%d: (%d,%d) ", cont1,xR,yR);
				aa = new_coord(xR,yR);
				boatsR1[i].c = *aa;
				int vhR = return_randoms(0,3);
				boatsR1[i].o = vhR;
				boatsR1[i].shot_count = 0;

				mapasR1[i] = switch_functionRANDOMS(optR,boatsR1[i].o);
				boatsR1[i].mb = &mapasR1[i];
				inserir_barcoRANDOMS(boatsR1[i].c, &boatsR1[i], p1m);
				//printf("  %d : (%d,%d)\n", cont1,boatsR1[i].c.x,boatsR1[i].c.y);
				//print_tabuleiro(p1m);
				//cont1++;
		}

		//print_tabuleiro(p1m);

	 	// RANDOMS PLAYER 2
	 	for(int j=1; j<=randB; j++){
	 		//printf("cont2: %d\n", cont2);
	 		//printf("%d ola \n", i);
	 			int optR2 = return_randoms(1,5);
	 			int xR2 = return_randoms(3,(n-3));
	 			int yR2 = return_randoms(3,(n-3));
	 			//printf("%d : (%d,%d)\n", cont2,xR2,yR2);
		 		aa = new_coord(xR2,yR2);
		 		boatsR2[j].c = *aa;
		 		int vhR2 = return_randoms(0,3);
		 		boatsR2[j].o = vhR2;
		 		boatsR2[j].shot_count = 0;

				mapasR2[j] = switch_functionRANDOMS(optR2,boatsR2[j].o);
				boatsR2[j].mb = &mapasR2[j];
				inserir_barcoRANDOMS(boatsR2[j].c, &boatsR2[j], p2m);
				//cont2++;
				//print_tabuleiro(p2m);
			}
		//print_tabuleiro(p1m);
		//print_tabuleiro(p2m);
 	} // fim do random

 	else {

 		int maxB = (n*n)/(5*5);
	 	int opt;
	 	printf("Enter the number of boats: ");
	 	scanf("%d", &b);

	 	if(b <= 0 || b > maxB){
		 	while(b <= 0 || b > maxB){
		 		printf("Invalid number of boats! Max number of boats is %d. Enter the number of boats: ", maxB);
		 		scanf("%d", &b);
		 	}
		}

	 	Coordinate* a = (Coordinate *) malloc(sizeof(Coordinate*));
	 	piece boat1[b+1],boat2[b+1];

	 	piece *boats1 = (piece *) malloc(sizeof(piece*));
	 	piece *boats2 = (piece *) malloc(sizeof(piece*));

	 	bitmap mapass[b+1];

	 	//ciclo para criar os barcos P1
	 	for(int i=1; i<=b; i++){

		 		printf("\nChoose the type of boat\n");
				print_menuB();	//menu dos barcos em menus.c
				printf("> ");
				scanf("%d", &opt);
				if(opt<=0 || opt >5){
					while(opt<=0 || opt >5){
						printf("\nInvalid boat type! Choose a boat between 1 and 5.\n");
						printf("> ");
						scanf("%d", &opt);
					}
				}

				printf("\n\nPlayer %s coordinate for boat %d: ", p1, i);
		 		scanf("%d", &x1);
		 		scanf("%d", &x2);
		 		a = new_coord(x1,x2);

		 		boats1[i].c = *a;
		 		printf("\nChoose boat rotation (0, 90, 180, 270): ");
		 		scanf("%d", &vh);
		 		if(vh != 0 && vh != 90 && vh != 180 && vh != 270){
					while(vh != 0 && vh != 90 && vh != 180 && vh != 270){
						printf("\nInvalid rotation type! Rotation values must be 0, 90, 180 or 270.\n");
						printf("> ");
						scanf("%d", &vh);
					}
				}

		 		boats1[i].o = vh;
		 		boats1[i].shot_count = 0;

		 		mapass[i] = switch_function(opt,boats1[i].o);
				boats1[i].mb = &mapass[i];
				inserir_barco(boats1[i].c, &boats1[i], p1m);
				//print_tabuleiro(p1m);
			}

		bitmap mapas2[b+1];

		//ciclo para criar os barcos P2
		for(int i=1; i<=b; i++){

 			//boats1[i] = boat1[i];
	 		printf("\nChoose the type of boat\n");
			print_menuB();	//menu dos barcos em menus.c
			printf("> ");
			scanf("%d", &opt);
			if(opt<=0 || opt >5){
					while(opt<=0 || opt >5){
						printf("\nInvalid boat type! Choose a boat between 1 and 5.\n");
						printf("> ");
						scanf("%d", &opt);
					}
			}

			printf("\n\nPlayer %s coordinate for boat %d: ", p2, i);
	 		scanf("%d", &x1);
	 		scanf("%d", &x2);
	 		a = new_coord(x1,x2);

	 		boats2[i].c = *a;
	 		printf("\nChoose boat rotation (0, 90, 180, 270): ");
	 		scanf("%d", &vh);
	 		if(vh != 0 && vh != 90 && vh != 180 && vh != 270){
					while(vh != 0 && vh != 90 && vh != 180 && vh != 270){
						printf("\nInvalid rotation type! Rotation values must be 0, 90, 180 or 270.\n");
						printf("> ");
						scanf("%d", &vh);
					}
			}
	 		boats2[i].o = vh;
	 		boats2[i].shot_count = 0;

			mapas2[i] = switch_function(opt,boats2[i].o);
			boats2[i].mb = &mapas2[i];
			inserir_barco(boats2[i].c, &boats2[i], p2m);

			//print_tabuleiro(p2m);

		} // fim do manual

		//começar a jogar

		bool gameOver = false;
		bool shotp1, shotp2;
		Coordinate* c1 = (Coordinate *) malloc(sizeof(Coordinate*));
		Coordinate* c2 = (Coordinate *) malloc(sizeof(Coordinate*));
		int xp1,yp1,xp2,yp2;

		while(!gameOver){

			print_tabuleiro(p1m);
			print_tabuleiroAdversario(p1m);

			printf("\nPlayer %s choose a coordinate to fire: ", p1);
			scanf("%d", &xp1);
			scanf("%d", &yp1);
			c1 = new_coord(xp1,yp1);
			shotp1 =acertou(*c1,p1m);

			if(shotp1){
				score1+=10;
				if(afundado(*c1,p1m)) {
					score1 += 50;
					//anular(*c1,p1m);
				}
			}

			/*
			printf("\nPlayer %s choose a coordinate to fire: ", p2);
			scanf("%d", &xp2);
			scanf("%d", &yp2);
			c2 = new_coord(xp2,yp2);
			shotp2 = acertou(*c2,p1m);

			if(shotp2){
				score2+=10;
				if(afundado(*c2,p1m)) score2 += 50;
			}
			*/

			if(isFinished(p1m)){
				printf("Player %s wins with %d points!", p2, score1);
				gameOver=true;
			}

			if(isFinished(p2m)){
				printf("Player %s wins with %d points!\n", p1, score1);
				gameOver=true;
			}
		}
	} 

	//system("clear");
	print_tabuleiro(p1m);
	//print_tabuleiro(p2m);

/*

	Coordinate* cc = (Coordinate *) malloc(sizeof(Coordinate*));
	cc = new_coord(20,19);	//  20 19 coordenada de teste ao inserir tipo U em (22,17)
	acertou(*cc, p1m);


		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){

				printf(" %c ", boats1[1].mb -> m[i][j]);

			}
			printf("\n");
		}

	print_tabuleiro(p1m);

*/
	return EXIT_SUCCESS;

}


