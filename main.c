#include <stdio.h>
#include <stdlib.h>
#include "battleship.h"


int main(){
	char p1[20],p2[20];
	
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

	// matrizes iniciais
	game m1 , m2 ,m3 ,m4;

	//matriz de representacao do tabuleiro do p1
	game *p1m1= &m1;
	p1m1-> lin = n;
	p1m1 -> col =n;

	p1m1 -> matriz = (char ** )malloc (sizeof(char *) * p1m1-> lin);
	for(int i=0;i< p1m1 -> lin; i++) {
 		p1m1 -> matriz[i] = (char *) malloc(sizeof(char)* p1m1 -> lin);
 	}

 	//matriz de representacao dos "hits" do p1 no p2
 	game *p1m2= &m2;
	p1m2-> lin = n;
	p1m2 -> col =n;

	p1m2 -> matriz = (char ** )malloc (sizeof(char *) * p1m2-> lin);
	for(int i=0;i< p1m2 -> lin; i++) {
 		p1m2 -> matriz[i] = (char *) malloc(sizeof(char)* p1m2 -> lin);
 	}


 	//matriz de representacao do tabuleiro do p2
 	game *p2m1= &m3;
	p2m1-> lin = n;
	p2m1 -> col =n;

	p2m1 -> matriz = (char ** )malloc (sizeof(char *) * p2m1-> lin);
	for(int i=0;i< p2m1 -> lin; i++) {
 		p2m1 -> matriz[i] = (char *) malloc(sizeof(char)* p2m1 -> lin);
 	}


 	//matriz de representacao dos "hits" do p2 no p1
 	game *p2m2= &m4;
	p2m2-> lin = n;
	p2m2 -> col =n;

	p2m2 -> matriz = (char ** )malloc (sizeof(char *) * p2m2-> lin);
	for(int i=0;i< p2m2 -> lin; i++) {
 		p2m2 -> matriz[i] = (char *) malloc(sizeof(char)* p2m2 -> lin);
 	}

 	create_matriz(p1m1);
 	create_matriz(p1m2);
 	create_matriz(p2m1);
 	create_matriz(p2m2);


 	//-----------------------------------------------------------------------
 	
 	int opt;
 	printf("Enter the number of boats: ");
 	scanf("%d", &b);
 	//peca* boats1[b+1];
 	//peca* boats2[b+1];
 	Coordinate* a = (Coordinate *) malloc(sizeof(Coordinate*));
 	peca *boats1 = (peca *) malloc(b * sizeof(peca*));
 	peca *boats2 = (peca *) malloc(b * sizeof(peca*));

 	//ciclo para criar as peças
 	for(int i=1; i<=b; i++){
 		printf("Choose the type of boat\n");
 		print_barcoQuad();
		print_barcoRect();
		print_barcoT();
		print_barcoU();
		print_barcoL();
		printf("> ");

		scanf("%d", &opt);
		printf("\n\nPlayer %s coordinate for boat %d: ", p1, i);
 		scanf("%d", &x1);
 		scanf("%d", &x2);
 		a = new_coord(x1,x2);
 		boats1[i].c = *a;
 		printf("\nSize of boat %d: ", i);
 		scanf("%d", &tam);
 		boats1[i].n = tam;
 		printf("\nPlace Horizontally(0) or Vertically(1): ");
 		scanf("%d", &vh);
 		boats1[i].o = vh;
		system("clear");

		switch(opt){
			case 1: print_barcoQuad();
					break;
			case 2: print_barcoRect();
					break;
			case 3: print_barcoT();
					break;
			case 4: print_barcoU();
					break;
			case 5: print_barcoL();
					break;
		}
	}

	/*
	for(int i=1; i<=b; i++){
		printf("\n(%d,%d)", boats1[i].c.x, boats1[i].c.y);
	}
	*/

	//create_matrix(n);
	//printf("Put Ships on board:\n");
	//scanf("%d",&ship1);
	//scanf("%d",&ship2);

	return 0;
}