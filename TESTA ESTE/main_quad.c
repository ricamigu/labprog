#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h> 
#include "battleship.h"

int n;
// função que verifica se o input foi um int
void verificar_int(){
	for(int c; (c = getchar()) != '\n' && c != EOF ;);
}

// função que gera os números random
int return_randoms(int lower, int upper){
	int num = (rand() % (upper + 1 - lower)) + lower;
	return num;
}


void print_shots(char m[n][n]){

	for(int i=0;i<n;i++){
		if(i<10) printf(" %d",i);																						//
		if(i>=10) printf("%d",i);
		for(int j=0;j<n;j++){
			if(m[i][j] == '0'){
				printf("\033[1;34m");
				printf(" %c ", m[i][j]);
				printf("\033[0m");
			}
			else if(m[i][j]=='1'){
				printf("\033[0;31m"); 
				printf(" %c ", m[i][j]); 
				printf("\033[0m");

		}
		else { printf("\033[0;32m"); 
				printf(" %c ", m[i][j]); 
				printf("\033[0m");
			}
		}
		printf("\n");
	}

	printf("##");																											
	for(int j=0;j<n;j++){
		if(j<10) printf(" %d ", j);
		if(j>=10) printf(" %d",j);
	}
	printf("\n");
}


int main(){

	char p1[20], p2[20];
	int score1=0, score2=0;

	int b;
	int x1, x2, vh;
	int minicial;

	//menu inicial
	while(minicial != 1){
		menu_inicial_quad();
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

	struct node *rootp1 = malloc(sizeof(struct node)*64);
	rootp1 = new_node();

	struct node *rootp2 = malloc(sizeof(struct node)*64);
	rootp2 = new_node();


	printf("\n");
	system("clear");

	char player1[n][n];
	char player2[n][n];
	int shots_hit1=0;
	int shots_hit2=0;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			player1[i][j] = '0';
			player2[i][j] = '0';
		}
	}


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
 		int maxR = (n*n)/(5*5)-5;
 		srand(time(0));

 		int randB = return_randoms(minR,maxR);

 		Coordinate* aa = (Coordinate *) malloc(sizeof(Coordinate*)*64);
	 	piece boatR1[randB+1],boatR2[randB+1];
	 	piece *boatsR1 = (piece *) malloc(sizeof(piece*)*64);
	 	piece *boatsR2 = (piece *) malloc(sizeof(piece*)*64);
	 	bitmap mapasR1[randB+1];
	 	bitmap mapasR2[randB+1];

	 	//RANDOM PLAYER 1
	 	for(int i=1; i<=randB; i++){

	 			int optR = return_randoms(1,5);				// criar numeros random para todos os parametros de inserir o barco
		 		int xR = return_randoms(5,(n-5));
			 	int yR = return_randoms(5,(n-5));
				aa = new_coord(xR,yR);
				boatsR1[i].c = *aa;
				int vhR = return_randoms(0,3);
				boatsR1[i].o = vhR;

				if(i<=5) optR = i;						   // usado para garantir que tem pelo menos 1 barco de cada tipo

				mapasR1[i] = switch_functionRANDOMS(optR,boatsR1[i].o);
				boatsR1[i].mb = &mapasR1[i];
				inserir_barcoRANDOMS_quad(rootp1, &boatsR1[i], n);

		}

	 	// RANDOMS PLAYER 2
	 	for(int j=1; j<=randB; j++){
	 			int optR2 = return_randoms(1,5);			// criar numeros random para todos os parametros de inserir o barco
	 			int xR2 = return_randoms(2,(n-3));
	 			int yR2 = return_randoms(2,(n-3));
		 		aa = new_coord(xR2,yR2);
		 		boatsR2[j].c = *aa;
		 		int vhR2 = return_randoms(0,3);
		 		boatsR2[j].o = vhR2;

		 		if(j<=5) optR2 = j;						  // usado para garantir que tem pelo menos 1 barco de cada tipo

				mapasR2[j] = switch_functionRANDOMS(optR2,boatsR2[j].o);
				boatsR2[j].mb = &mapasR2[j];
				inserir_barcoRANDOMS_quad(rootp2, &boatsR2[j], n);
		}

		bool gameOverR = false;
		bool shotp1R, shotp2R;
		Coordinate* c1R = (Coordinate *) malloc(sizeof(Coordinate*)*64);
		Coordinate* c2R = (Coordinate *) malloc(sizeof(Coordinate*)*64);
		int xp1R,yp1R,xp2R,yp2R;
		int optmR1=0, optmR2=0;

		

		while(!gameOverR){	// ciclo que so acaba quando o jogo está terminado

			while(optmR1!=1){

				menu_game(p1);
				scanf("%d",&optmR1);
				verificar_int();
				if(optmR1<1 || optmR1>5){ optmR1=0; printf("\033[0;31m"); printf("\nError: "); printf("\033[0m"); printf("Invalid option!\n"); }
				if(optmR1==2) { system("clear"); matriz_jogador(rootp1,n); press_any_key(); system("clear"); }
				if(optmR1==3) { system("clear"); print_shots(player1); press_any_key(); system("clear");}
				if(optmR1==4) { menu_help(); system("clear"); }
				if(optmR1==5) { printf("\nPlayer %s wins!\n", p2); return EXIT_SUCCESS;}
 			}
 			optmR1=0;

			printf("\nPlayer %s choose a coordinate to shoot: ", p1);
			printf("\nx: ");
			scanf("%d", &xp1R);
			verificar_int();
			printf("y: ");
			scanf("%d", &yp1R);
			verificar_int();
			while(xp1R < 0 || xp1R > n-1 || yp1R < 0 || yp1R > n-1){	//testar se a coordenada está dentro do tabuleiro
				printf("\033[0;31m"); printf("\nError: "); printf("\033[0m");
				printf("Invalid Coordinate!\n");
				printf("\nx: ");
				scanf("%d", &xp1R);
				verificar_int();
				printf("y: ");
				scanf("%d", &yp1R);
				verificar_int();
			}

			while( player1[xp1R][yp1R] != '0'){
					printf("Shot already taken!\n");
					printf("\nx: ");
					scanf("%d", &xp1R);
					verificar_int();
					printf("y: ");
					scanf("%d", &yp1R);
					verificar_int();
				}

			c1R = new_coord(xp1R,yp1R);
			shotp1R = shoot(rootp2,c1R,n/2,n/2);

			if(shotp1R) {
				score1+=10;
				player1[c1R->x][c1R->y] = '2';
				shots_hit1++;
			}
			else { if(player1[c1R->x][c1R->y] == '0') player1[c1R->x][c1R->y] = '1'; }

			if(isFinished_quad(rootp2,shots_hit1)){		// testar se o jogo acabou e p1 ganhou
				printf("Player %s wins with %d points!\n", p1, score1);
				gameOverR=true;
			}

			if(!gameOverR){

				while(optmR2!=1){

					menu_game(p2);
					scanf("%d",&optmR2);
					verificar_int();
					if(optmR2<1 || optmR2 > 5) { optmR2=0; printf("\033[0;31m"); printf("\nError: "); printf("\033[0m"); printf("Invalid option!\n");}
					if(optmR2==2) { system("clear"); matriz_jogador(rootp2,n); press_any_key(); system("clear");}
					if(optmR2==3) { system("clear"); print_shots(player2); press_any_key();system("clear"); }
					if(optmR2==4) { menu_help(); }
					if(optmR2==5) { printf("\nPlayer %s wins!\n", p1); return EXIT_SUCCESS;}

	 			}
	 			optmR2=0;

				printf("\nPlayer %s choose a coordinate to shoot: ", p2);
				printf("\nx: ");
				scanf("%d", &xp2R);
				printf("y: ");
				scanf("%d", &yp2R);
				while(xp2R < 0 || xp2R > n-1 || yp2R < 0 || yp2R > n-1){
					verificar_int();
					printf("\033[0;31m"); printf("\nError: "); printf("\033[0m");
					printf("Invalid Coordinate!\n");
					printf("\nx: ");
					scanf("%d", &xp2R);
					printf("y: ");
					scanf("%d", &yp2R);
				}

				while( player2[xp2R][yp2R] != '0'){
					printf("Shot already taken!\n");
					printf("\nx: ");
					scanf("%d", &xp2R);
					verificar_int();
					printf("y: ");
					scanf("%d", &yp2R);
					verificar_int();
				}

				c2R = new_coord(xp2R,yp2R);
				shotp2R = shoot(rootp1,c2R,n/2,n/2);

				if(shotp2R) {
					score2+=10;
					player2[c2R->x][c2R->y] = '2';
					shots_hit2++;
				}
				else { if(player2[c2R->x][c2R->y] == '0') player2[c2R->x][c2R->y] = '1'; }

				if(isFinished_quad(rootp1,shots_hit2)){		// testar se o jogo acabou e p1 ganhou
					printf("Player %s wins with %d points!\n", p2, score2);
					gameOverR=true;
				}
			}
 	}
 }// fim do random

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

		Coordinate* a = (Coordinate *) malloc(sizeof(Coordinate*)*64);
		piece boat1[b+1],boat2[b+1];
		piece *boats1 = (piece *) malloc(sizeof(piece*)*64);
		piece *boats2 = (piece *) malloc(sizeof(piece*)*64);
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
				inserir_barco_quad(rootp1, &boats1[i], n);
			}
			soma1 = s1+s2+s3+s4+s5;
				if(soma1 < 5) {
					printf("\033[0;31m"); printf("\nError: "); printf("\033[0m");													
					printf("You must choose one boat from each type!\n");	 	// se nao tiver os 5 tipos de barcos diferentes,
					delete_tree(rootp1);
					rootp1 = clear_tree(rootp1);											// repor a tree
			}
		}

		//bool acertou = false;
		//acertou = shoot(rootp1, 5,5,n/2,n/2);
		//if(acertou) {printf("ACERTOU!\n");}
		//else {printf("nope\n");}
		//printf("\n\n");
		//print_m(p1m, rootp1);

		//matriz_jogador(rootp1, n);
	

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
				inserir_barco_quad(rootp2, &boats2[i], n);
			}
			soma2 = ss1+ss2+ss3+ss4+ss5;
			if(soma2 < 5) {
				printf("\033[0;31m"); printf("\nError: "); printf("\033[0m");
				printf("You must choose one boat from each type!\n");
				delete_tree(rootp2);
				clear_tree(rootp2);	
			}
		}

		bool gameOver = false;
		bool shotp1, shotp2;
		Coordinate* c1 = (Coordinate *) malloc(sizeof(Coordinate*)*64);
		Coordinate* c2 = (Coordinate *) malloc(sizeof(Coordinate*)*64);
		int xp1,yp1,xp2,yp2;
		int optm1=0, optm2=0;

		

		while(!gameOver){	// ciclo que so acaba quando o jogo está terminado

			while(optm1!=1){

				menu_game(p1);
				scanf("%d",&optm1);
				verificar_int();
				if(optm1<1 || optm1>5){ optm1=0; printf("\033[0;31m"); printf("\nError: "); printf("\033[0m"); printf("Invalid option!\n"); }
				if(optm1==2) { system("clear"); matriz_jogador(rootp1,n); press_any_key(); system("clear"); }
				if(optm1==3) { system("clear"); print_shots(player1); press_any_key(); system("clear");}
				if(optm1==4) { menu_help(); system("clear"); }
				if(optm1==5) { printf("\nPlayer %s wins!\n", p2); return EXIT_SUCCESS;}
 			}
 			optm1=0;

			printf("\nPlayer %s choose a coordinate to shoot: ", p1);
			printf("\nx: ");
			scanf("%d", &xp1);
			verificar_int();
			printf("y: ");
			scanf("%d", &yp1);
			verificar_int();
			while(xp1 < 0 || xp1 > n-1 || yp1 < 0 || yp1 > n-1){	//testar se a coordenada está dentro do tabuleiro
				printf("\033[0;31m"); printf("\nError: "); printf("\033[0m");
				printf("Invalid Coordinate!\n");
				printf("\nx: ");
				scanf("%d", &xp1);
				verificar_int();
				printf("y: ");
				scanf("%d", &yp1);
				verificar_int();
			}	

			while( player1[xp1][yp1] != '0'){
				printf("Shot already taken!\n");
				printf("\nx: ");
				scanf("%d", &xp1);
				verificar_int();
				printf("y: ");
				scanf("%d", &yp1);
				verificar_int();
			}

			c1 = new_coord(xp1,yp1);
			shotp1 = shoot(rootp2,c1,n/2,n/2);

			if(shotp1) {
				score1+=10;
				player1[c1->x][c1->y] = '2';
				shots_hit1++;
			}
			else { if(player1[c1->x][c1->y] == '0') player1[c1->x][c1->y] = '1'; }

			if(isFinished_quad(rootp2,shots_hit1)){		// testar se o jogo acabou e p1 ganhou
				printf("Player %s wins with %d points!\n", p1, score1);
				gameOver=true;
			}

			if(!gameOver){

				while(optm2!=1){

					menu_game(p2);
					scanf("%d",&optm2);
					verificar_int();
					if(optm2<1 || optm2 > 5) { optm2=0; printf("\033[0;31m"); printf("\nError: "); printf("\033[0m"); printf("Invalid option!\n");}
					if(optm2==2) { system("clear"); matriz_jogador(rootp2,n); press_any_key(); system("clear");}
					if(optm2==3) { system("clear"); print_shots(player2); press_any_key();system("clear"); }
					if(optm2==4) { menu_help(); }
					if(optm2==5) { printf("\nPlayer %s wins!\n", p1); return EXIT_SUCCESS;}

	 			}
	 			optm2=0;

				printf("\nPlayer %s choose a coordinate to shoot: ", p2);
				printf("\nx: ");
				scanf("%d", &xp2);
				printf("y: ");
				scanf("%d", &yp2);
				while(xp2 < 0 || xp2 > n-1 || yp2 < 0 || yp2 > n-1){
					verificar_int();
					printf("\033[0;31m"); printf("\nError: "); printf("\033[0m");
					printf("Invalid Coordinate!\n");
					printf("\nx: ");
					scanf("%d", &xp2);
					printf("y: ");
					scanf("%d", &yp2);
				}

				while( player2[xp2][yp2] != '0'){
					printf("Shot already taken!\n");
					printf("\nx: ");
					scanf("%d", &xp2);
					verificar_int();
					printf("y: ");
					scanf("%d", &yp2);
					verificar_int();
				}

				c2 = new_coord(xp2,yp2);
				shotp2 = shoot(rootp1,c2,n/2,n/2);

				if(shotp2) {
					score1+=10;
					player2[c2->x][c2->y] = '2';
					shots_hit2++;
				}
				else { if(player2[c2->x][c2->y] == '0') player2[c2->x][c2->y] = '1'; }

				if(isFinished_quad(rootp1,shots_hit2)){		// testar se o jogo acabou e p1 ganhou
					printf("Player %s wins with %d points!\n", p2, score2);
					gameOver=true;
				}
			}
 		}
	}

	/*
	printf("\n\n");
	matriz_jogador(rootp1,n);
	printf("\n\n");
	matriz_jogador(rootp2, n);
	*/

	delete_tree(rootp1);
	delete_tree(rootp2);

	return EXIT_SUCCESS;
}