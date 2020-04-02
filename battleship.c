#include "battleship.h"

// Criar nova coordenada
Coordinate* new_coord(int a, int b) {
	Coordinate* c = (Coordinate *) malloc(sizeof(Coordinate*));
	c -> x = a;
	c -> y = b;
	return c;
}


//print da matriz
void print_tabuleiro(game *board){

	for(int i=0; i < board->lin ; i++){
		for(int j=0; j< board->col;j++){
			printf(" %c ", board -> matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


//Criar matriz
void create_matriz(game *board) {

	for(int i=0; i < board->lin ; i++){
		for(int j=0; j< board->col;j++){
			board -> matriz[i][j] = '.';
		}
	}

	//print_tabuleiro(board);

}

void create_matrix(int n ){
	char matrix[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==0 && j==0)
				matrix[i][j] = '-';
			else 
				matrix[i][j]='-';
		}


	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%c ", matrix[i][j] );
		}
			printf("\n");
		}

}

void instructions(){
 	printf("ola!\n");
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
}


//criar bitmap 
bitmap create_rect0(Coordinate ini, game *board) {

	bitmap matriz;

for(int i=0; i < 5; i++){
		for(int j=0; j< 5;j++){
				matriz.m[i][j] = '0';
				board -> matriz[i + ini.x][j + ini.y] = '0';
				
			}
		}

	for(int i=0; i < 2; i++){
		for(int j=0; j< 3;j++){
				matriz.m[i][j] = '1';
				board -> matriz[i + ini.x][j + ini.y] = '1';
		}
	}

	return matriz;

	print_tabuleiro(board);
}

bitmap create_square0(Coordinate ini,game *board){
	
	bitmap matriz;

for(int i=0; i < 5; i++){
		for(int j=0; j< 5;j++){
				matriz.m[i][j] = '0';
				board -> matriz[i + ini.x][j + ini.y] = '0';
				
			}
		}

	for(int i=0; i < 2; i++){
		for(int j=0; j< 2;j++){
				matriz.m[i][j] = '1';
				board -> matriz[i + ini.x][j + ini.y] = '1';
		}
	}

	return matriz;

	print_tabuleiro(board);

}
