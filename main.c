#include <stdio.h>
#include <stdlib.h>
#include "battleship.h"


int main(){
	char p1[20],p2[20];
	
	int n,b;
	int x1, x2, tam,vh;
	Coordinate p;
	int menuinicial;

	printf("\n\n");
	printf("+---------------------+\n");
	printf("|   Battleship Game   |\n");
	printf("+---------------------+\n");

	printf("+---------------------+\n");
	printf("|   1-Start Game      |\n");
	printf("|---------------------|\n");
	printf("|   2-Instructions    |\n");
	printf("|---------------------|\n");
	printf("|   3-Leave Game      |\n");
	printf("+---------------------+\n");
	
	printf("\n> ");
	scanf("%d",&menuinicial);
	switch(menuinicial){
		case 1:
			break;
		case 2:
			instructions();
			break;
		case 3:
			return 0;
	}
	printf("Welcome to the game!\n\n");
	printf("Enter first player name: ");
	scanf("%s",p1);
	printf("\nEnter second player name: ");
	scanf("%s",p2);
	printf("\nEnter the size of board (N*N) entre 20 e 40 : ");
	scanf("%d",&n);
	while(n<20 || n>40)  {
		printf("Insert a valid size\n");
		scanf("%d",&n);
	}
	create_matrix(n);
	printf("\n");
	

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

//------------------------------------------------------------------------------------------------
/*// matrizes iniciais
	bitmap m1 , m2 ,m3 ,m4;

	
	bitmap *p1m1= &m1;
	p1m1-> lin = 5;
	p1m1 -> col = 5;

	p1m1 -> bit = (char ** )malloc (sizeof(char *) * p1m1-> lin);
	for(int i=0;i< p1m1 -> lin; i++) {
 		p1m1 -> bit = (char *) malloc(sizeof(char)* p1m1 -> lin);
 	}

 	
 	bitmap *p1m2= &m2;
	p1m2-> lin = 5;
	p1m2 -> col =5;

	p1m2 -> matriz = (char ** )malloc (sizeof(char *) * p1m2-> lin);
	for(int i=0;i< p1m2 -> lin; i++) {
 		p1m2 -> bit = (char *) malloc(sizeof(char)* p1m2 -> lin);
 	}


 	bitmap *p2m1= &m3;
	p2m1-> lin = 5;
	p2m1 -> col = 5;

	p2m1 -> bitmap = (char ** )malloc (sizeof(char *) * p2m1-> lin);
	for(int i=0;i< p2m1 -> lin; i++) {
 		p2m1 -> bit = (char *) malloc(sizeof(char)* p2m1 -> lin);
 	}


 	
 	bitmap *p2m2= &m4;
	p2m2-> lin = 5;
	p2m2 -> col =5;

	p2m2 -> bitmap = (char ** )malloc (sizeof(char *) * p2m2-> lin);
	for(int i=0;i< p2m2 -> lin; i++) {
 		p2m2 -> bit = (char *) malloc(sizeof(char)* p2m2 -> lin);
 	}

 	create_matriz(p1m1);
 	create_matriz(p1m2);
 	create_matriz(p2m1);
 	create_matriz(p2m2);



*/
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
		while(opt!=1 && opt!=2 && opt!=3 && opt!=4 && opt!=5){
			printf("Choose a valid option\n");
			printf("> ");
 			scanf("%d", &opt);
 		}
 		printf("Choose the coordinates for your boat\n");
		printf("\n\nPlayer %s coordinate x for boat %d: ", p1, i);
 		scanf("%d", &x1);
 		while(x1<0 || x1>n) {
 			printf("Choose a valid option\n");
 			printf("x: ");
 			scanf("%d", &x1);
 		}
 		printf("\n\nPlayer %s coordinate y for boat %d: ", p1, i);
 		scanf("%d", &x2);
 		while(x2<0 || x2>n) {
 			printf("Choose a valid option\n");
 			printf("y: ");
 			scanf("%d", &x2);
 		}
 		a = new_coord(x1,x2);
 		boats1[i].c = *a;
 		//printf("\nPlace Horizontally(0) or Vertically(1): ");
 		printf("\nChoose boat rotation (0, 90, 180, 270): ");
 		scanf("%d", &vh);
 		while(vh!=0 && vh!=90 && vh!=180 && vh!=270) {
 			printf("Choose a valid option\n");
 			scanf("%d", &vh);
 		}
 		boats1[i].o = vh;
 		boats1[i].shot_count = 0;
		system("clear");

		int c;
		switch(opt){ 
			case 1: boats1[i].m1 = create_square0(boats1[i].c, p1m1);
					print_tabuleiro(p1m1);
					printf("Press 1 to continue\n");
					scanf("%d",&c);
					while(c!=1){
						printf("Press 1 to continue\n");
						scanf("%d",&c);
					}
					break;
			case 2: boats1[i].m1 = create_rect0(boats1[i].c, p1m1);
					print_tabuleiro(p1m1);
					printf("Press 1 to continue\n");
					scanf("%d",&c);
					while(c!=1){
						printf("Press 1 to continue\n");
						scanf("%d",&c);
					}	
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