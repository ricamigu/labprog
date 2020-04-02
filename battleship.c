#include "battleship.h"



// Criar nova coordenada
Coordinate* new_coord(int a, int b) {
	Coordinate* c = (Coordinate *) malloc(sizeof(Coordinate*));
	c -> x = a;
	c -> y = b;
	return c;
}


//print da matriz
void print_tabuleiro(game *tabuleiro){

	for(int i=0; i < tabuleiro->size ; i++){
		for(int j=0; j< tabuleiro->size;j++){
			printf(" %s ", tabuleiro -> board[i][j].apont);
		}
		printf("\n");
	}
	printf("\n");
}


//Criar matriz
void create_matriz(game *tabuleiro) {

	char b = '~';
	char* a = &b;


	for(int i=0; i < tabuleiro->size ; i++){
		for(int j=0; j< tabuleiro->size;j++){
			tabuleiro -> board[i][j].apont = a;
			tabuleiro -> board[i][j].field_shot = 0;
		}
	}

	print_tabuleiro(tabuleiro);

}



// TIPOS DE BARCOS
void print_barcoQuad(){

	printf("\n-------------");
 	printf("\n| 1. Square |");
 	printf("\n-------------");
	printf("\n");
	
	for(int i=0; i < 2 ; i++){
		printf("| ");
		for(int j=0; j< 2;j++){
			printf(" x ");
		}
		printf(" |");
		printf("\n");
	}
	printf("\n");

}

void print_barcoRect(){

	printf("\n----------------");
 	printf("\n| 2. Rectangle |");
 	printf("\n----------------");
	printf("\n");

	for(int i=0; i < 2 ; i++){
		printf("| ");
		for(int j=0; j< 3;j++){
			printf(" x ");
		}
		printf(" |");
		printf("\n");
	}
	printf("\n");
}

void print_barcoT(){

	printf("\n--------------");
 	printf("\n| 3. T Shape |");
 	printf("\n--------------");
	printf("\n");

	for(int i=0; i < 3 ; i++){
		printf("| ");
		for(int j=0; j< 3;j++){
			if(i==0) printf(" x ");
			else if(j==1) printf(" x ");
			else printf("   ");
		}
		printf(" |");
		printf("\n");
	}
	printf("\n");
}

void print_barcoU(){

	printf("\n--------------");
 	printf("\n| 4. U Shape |");
 	printf("\n--------------");
	printf("\n");

	for(int i=0; i < 3 ; i++){
		printf("| ");
		for(int j=0; j< 3;j++){
			if((j==0) || j==2)printf(" x ");
			else if(i==2) printf(" x ");
			else printf("   ");
		}
		printf(" |");
		printf("\n");
	}
	printf("\n");
}

void print_barcoL(){

	printf("\n--------------");
 	printf("\n| 5. L Shape |");
 	printf("\n--------------");
	printf("\n");

	for(int i=0; i<3;i++){
		printf("| ");
		for(int j=0; j<3;j++){
			if(j==0) printf(" x ");
			else if(i==2) printf("x ");
			else printf("  ");
		}
		printf(" |");
		printf("\n");
	}
	printf("\n");
}

/*
void put_QuadH(game *board, int x, int y, int n) {

	if(x+n>board -> lin)
		return;

	for(int i=0; i < board->lin ; i++){
		for(int j=0; j< board->col;j++){
			if(i>=x && i<=x+n) board -> matriz[i][j] = '#';
			else if(j>=y && j<=y+n) board -> matriz[i][j] = '#';
			else board -> matriz[i][j] = '.';
		}
	}
	//print_tabuleiro(board);
}*/

/*
//criar bitmap
bitmap create_rect0(Coordinate ini, game *board) {

	bitmap matriz;

	for(int i=0; i < 5 ; i++){
		for(int j=0; j< 5;j++){
			if(i==0) {
				matriz.m[i][j] = '1';
				board -> matriz[i + ini.x][j + ini.y] = '1';
			}
			else {
				matriz.m[i][j] = '0';
				board -> matriz[i + ini.x][j + ini.y] = '0';
			}
		}
	}

	return matriz;

	print_tabuleiro(board);
}*/