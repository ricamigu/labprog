#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h> 
#include "battleship.h"

// função que verifica se o input foi um int
void verificar_int(){
	for(int c; (c = getchar()) != '\n' && c != EOF ;);
}

// função que gera os números random
int return_randoms(int lower, int upper){
	int num = (rand() % (upper + 1 - lower)) + lower;
	return num;
}


int main(){

	char p1[20], p2[20];
	int score1=0, score2=0;

	int n,b;
	int x1, x2, vh;
	int minicial;

	//menu inicial
	while(minicial != 1){
		menu_inicial();
		printf("> ");
		scanf("%d",&minicial);
		verificar_int();
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
	verificar_int();

	while(n > 40 || n < 20){
		printf("\nThe size of the board must be between 20x20 and 40x40.");
		printf("\nEnter the size of board (N*N): ");
		scanf("%d",&n);
		verificar_int();
	}

	struct node *rootp1;
	rootp1 = new_node();

	struct node *rootp2;
	rootp2 = new_node();


	printf("\n");
	system("clear");


	//matrizes de representação do jogo
	char player1[n][n];
	char player2[n][n];

	int rand;
 	menu_rand();
 	scanf("%d",&rand);
 	verificar_int();

 	while(rand!=1 && rand != 2){
 		printf("\033[0;31m"); printf("\nError: "); printf("\033[0m"); printf("Invalid option!\n> ");
 		scanf("%d",&rand);
 		verificar_int();
 	}

 	// FAZER DEPOIS PARTE DOS RANDOMS AQUI


 	//modo random
 	if(rand==2){

 		int minR = 5; 
 		int maxR = (n*n)/(5*5);
 		srand(time(0));

 		int randB = return_randoms(minR,maxR);

 		Coordinate* aa = (Coordinate *) malloc(sizeof(Coordinate*));
	 	piece boatR1[randB+1],boatR2[randB+1];
	 	piece *boatsR1 = (piece *) malloc(sizeof(piece*));
	 	piece *boatsR2 = (piece *) malloc(sizeof(piece*));
	 	bitmap mapasR1[randB+1];
	 	bitmap mapasR2[randB+1];

	 	//RANDOM PLAYER 1
	 	for(int i=1; i<=randB; i++){

	 			int optR = return_randoms(1,5);				// criar numeros random para todos os parametros de inserir o barco
		 		int xR = return_randoms(4,(n-4));
			 	int yR = return_randoms(4,(n-4));
				aa = new_coord(xR,yR);
				boatsR1[i].c = *aa;
				int vhR = return_randoms(0,3);
				boatsR1[i].o = vhR;

				if(i<=5) optR = i;						   // usado para garantir que tem pelo menos 1 barco de cada tipo

				mapasR1[i] = switch_functionRANDOMS(optR,boatsR1[i].o);
				boatsR1[i].mb = &mapasR1[i];
				inserir_barcoRANDOMS(rootp1, &boatsR1[i], n);

		}

	 	// RANDOMS PLAYER 2
	 	for(int j=1; j<=randB; j++){
	 			int optR2 = return_randoms(1,5);			// criar numeros random para todos os parametros de inserir o barco
	 			int xR2 = return_randoms(3,(n-4));
	 			int yR2 = return_randoms(3,(n-4));
		 		aa = new_coord(xR2,yR2);
		 		boatsR2[j].c = *aa;
		 		int vhR2 = return_randoms(0,3);
		 		boatsR2[j].o = vhR2;

		 		if(j<=5) optR2 = j;						  // usado para garantir que tem pelo menos 1 barco de cada tipo

				mapasR2[j] = switch_functionRANDOMS(optR2,boatsR2[j].o);
				boatsR2[j].mb = &mapasR2[j];
				inserir_barcoRANDOMS(rootp2, &boatsR2[j], n);
		}

		matriz_jogador(rootp1, n);


 	}

 	else {

	 	// modo normal

	 	system("clear");


	 	int maxB = (n*n)/(5*5);
		int opt;
		printf("Enter the number of boats: ");
		scanf("%d", &b);

		while(b <= 4 || b > maxB){
			verificar_int();
			printf("\033[0;31m"); printf("\nError: "); printf("\033[0m");
			printf("Invalid number of boats! The number of boats should be between 5 and %d.\nEnter the number of boats: ", maxB);
			scanf("%d", &b);
		}

		Coordinate* a = (Coordinate *) malloc(sizeof(Coordinate*));
		piece boat1[b+1],boat2[b+1];
		piece *boats1 = (piece *) malloc(sizeof(piece*));
		piece *boats2 = (piece *) malloc(sizeof(piece*));
		bitmap mapass[b+1];

		//ciclo para criar os barcos P1
		int soma1=0;
		int s1=0,s2=0,s3=0,s4=0,s5=0;


		printf("\nPlayer %s\n",p1);

		while(soma1<5){

			for(int i=1; i<=b; i++){

				printf("\nChoose the type of boat\n");
				print_menuB();	//menu dos barcos em menus.c
				printf("> ");
				scanf("%d", &opt);
				verificar_int();

				while(opt<=0 || opt >5){
					printf("\033[0;31m"); printf("\nError: "); printf("\033[0m");
					printf("Invalid boat type! Choose a boat between 1 and 5.\n");
					printf("> ");
					scanf("%d", &opt);
					verificar_int();
				}

				//testar se o tabuleiro tem 5 barcos diferentes
				if(opt==1) s1 = 1; 
				if(opt==2) s2 = 1; 
				if(opt==3) s3 = 1; 
				if(opt==4) s4 = 1; 
				if(opt==5) s5 = 1;

				printf("\n\nPlayer %s coordinate for boat %d: ", p1, i);
				printf("\nx: ");
				scanf("%d", &x1);
				verificar_int();
				printf("y: ");
				scanf("%d", &x2);
				verificar_int();
				while(x1<0 || x1>39 || x2<0 || x2>39){
					printf("\nError: "); printf("\033[0m"); printf("Invalid option!\n");
					printf("\nx: ");
					scanf("%d", &x1);
					verificar_int();
					printf("y: ");
					scanf("%d", &x2);
					verificar_int();
				}
				
				a = new_coord(x1,x2);
				boats1[i].c = *a;
				printf("\nChoose boat rotation (0, 90, 180, 270): ");
				scanf("%d", &vh);
				verificar_int();

				while(vh != 0 && vh != 90 && vh != 180 && vh != 270 && vh<0 && vh>270){
					printf("\033[0;31m"); printf("\nError: "); printf("\033[0m");
					printf("Invalid rotation type! Rotation values must be 0, 90, 180 or 270.\n");
					printf("> ");
					scanf("%d", &vh);
					verificar_int();
				}

				boats1[i].o = vh;
				//boats1[i].field_shot = 0;
				mapass[i] = switch_function(opt,boats1[i].o);
				boats1[i].mb = &mapass[i];
				inserir_barco(rootp1, &boats1[i], n);
			}
			soma1 = s1+s2+s3+s4+s5;
				if(soma1 < 5) {
					printf("\033[0;31m"); printf("\nError: "); printf("\033[0m");													
					printf("You must choose one boat from each type!\n");	 	// se nao tiver os 5 tipos de barcos diferentes,
					delete_tree(rootp1);
					rootp1 = clear_tree(rootp1);											// repor a tree
			}
		}

		matriz_jogador(rootp1, n);
	

		//p2
		bitmap mapas2[b+1];

		int soma2=0;
	 	int ss1=0,ss2=0,ss3=0,ss4=0,ss5=0;

	 	printf("\nPlayer %s\n", p2);

	 	while(soma2<5){
			//ciclo para criar os barcos P2
			for(int i=1; i<=b; i++){

		 		printf("\nChoose the type of boat\n");
				print_menuB();	//menu dos barcos em menus.c
				printf("> ");
				scanf("%d", &opt);
				
				while(opt<=0 || opt >5){
					verificar_int();
					printf("\033[0;31m"); printf("\nError: "); printf("\033[0m");
					printf("Invalid boat type! Choose a boat between 1 and 5.\n");
					printf("> ");
					scanf("%d", &opt);
				}

				if(opt==1) ss1 = 1; 
				if(opt==2) ss2 = 1; 
				if(opt==3) ss3 = 1; 
				if(opt==4) ss4 = 1; 
				if(opt==5) ss5 = 1;

				printf("\n\nPlayer %s coordinate for boat %d: ", p2, i);
				printf("\nx: ");
		 		scanf("%d", &x1);
		 		printf("y: ");
		 		scanf("%d", &x2);
		 		while(x1<0 || x1>39 || x2<0 || x2>39){
			 			verificar_int();
						printf("\nError: "); printf("\033[0m"); printf("Invalid option!\n");
						printf("\nx: ");
			 			scanf("%d", &x1);
			 			printf("y: ");
			 			scanf("%d", &x2);
			 		}
		 		a = new_coord(x1,x2);

		 		boats2[i].c = *a;
		 		printf("\nChoose boat rotation (0, 90, 180, 270): ");
		 		scanf("%d", &vh);
				
				while(vh != 0 && vh != 90 && vh != 180 && vh != 270 && vh<0 && vh>270){
						verificar_int();
						printf("\033[0;31m"); printf("\nError: "); printf("\033[0m");
						printf("Invalid rotation type! Rotation values must be 0, 90, 180 or 270.\n");
						printf("> ");
						scanf("%d", &vh);
				}

		 		boats2[i].o = vh;
		 		//boats2[i].shot_count = 0;

				mapas2[i] = switch_function(opt,boats2[i].o);
				boats2[i].mb = &mapas2[i];
				inserir_barco(rootp2, &boats2[i], n);
			}
			soma2 = ss1+ss2+ss3+ss4+ss5;
			if(soma2 < 5) {
				printf("\033[0;31m"); printf("\nError: "); printf("\033[0m");
				printf("You must choose one boat from each type!\n");
				delete_tree(rootp2);
				clear_tree(rootp2);	
			}
		}
	}

	return EXIT_SUCCESS;
}