#include "battleship.h"
#include <stdbool.h>


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
			if(tabuleiro -> board[i][j].apont == NULL)
				printf(" . ");
			else if((tabuleiro -> board[i][j].field_shot == 1)) printf(" x ");
			else 
			{
				printf(" 1 ");
			}
		}
		printf("\n");
	}
	printf("\n");
}


//Criar matriz
void create_matriz(game *tabuleiro) {

	//char b;
	//char *a = (char * )malloc (sizeof(char *));
	//a = &b;

	for(int i=0; i < tabuleiro->size ; i++){
		for(int j=0; j< tabuleiro->size;j++){
			tabuleiro -> board[i][j].apont = NULL;
			tabuleiro -> board[i][j].field_shot = 0;
		}
	}

	print_tabuleiro(tabuleiro);

}


bool pode_inserir(Coordinate c, piece boat, game* tabuleiro){


	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if((boat.mb -> m[i][j] == '1' && (tabuleiro -> board[i + c.x - 2][j + c.y-2].apont != NULL))){
				printf("\nInvalid coordinate.\n");
				return false;
			}
		}
	}

	return true;
}


//inserir na matriz de jogo
void inserir_barco(Coordinate c, piece* boat, game* tabuleiro){


	if(pode_inserir(c, *boat, tabuleiro)){

		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if( boat -> mb -> m[i][j] == '1' ){
					tabuleiro -> board[i + c.x - 2][j + c.y-2].apont = boat;
				}
			}
		}
	}

	else {

		int x,y;
		Coordinate* a = (Coordinate *) malloc(sizeof(Coordinate*));
		printf("\n\nCoordinate for the boat again: ");
		scanf("%d", &x);
		scanf("%d", &y);
		a = new_coord(x,y);
		boat -> c = *a;
		inserir_barco(boat -> c, boat, tabuleiro);
	}
}


bool acertou(Coordinate cord, game* tabuleiro){

	int xa = (tabuleiro -> board[cord.x][cord.y].apont) -> c.x;
	int ya = (tabuleiro -> board[cord.x][cord.y].apont) -> c.y;

	printf("\n (%d,%d)\n", xa, ya);
 
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			//(tabuleiro -> board[cord.x][cord.y].apont) -> mbb -> m[i][j] = '2';
			if((i+xa-2 == cord.x) && (j+ya-2 ==cord.y) && ((tabuleiro -> board[cord.x][cord.y].apont) -> mb->m[i][j] == '1')){
				(tabuleiro -> board[cord.x][cord.y].apont) -> mb->m[i][j] = '2';
				(tabuleiro -> board[cord.x][cord.y].apont) -> shot_count++;
				//printf(" %c ", (tabuleiro -> board[cord.x][cord.y].apont) -> mb->m[i][j]);
				(tabuleiro -> board[cord.x][cord.y].field_shot) = 1;
				return true;
			}
			//else printf(" %c ", (tabuleiro -> board[cord.x][cord.y].apont) -> mb->m[i][j]);
		}
		printf("\n");
	}
	return false;
}


/*


bool acertou(Coordinate c, game* tabuleiro){

	int xa = (c.x)%5;
	int ya = (c.y)%5;

	if(tabuleiro -> board[c.x][c.y].apont != NULL){
		tabuleiro -> board[c.x][c.y].apont = NULL;
		return true;
	}
	return false;
}






bitmap create_quad0(Coordinate ini, game *tabuleiro) {

	bitmap matriz;
	char *a = (char * )malloc (2058*sizeof(char *));
	char *b = (char * )malloc (sizeof(char *));
	int k=0;

	for(int i=0; i < 5 ; i++){
		for(int j=0; j< 5;j++){
			if(i<3 && j<3) {
				matriz.m[i][j] = '1';
				b = &matriz.m[i][j];
				//printf(" %c ", *b);
				a[k] = *b;
				//int* b = &matriz.m[i][j];
				tabuleiro -> board[i + ini.x][j + ini.y].apont = &a[k];

			}
			else {
				matriz.m[i][j] = '0';
				b = &matriz.m[i][j];
				//printf(" %c ", *b);
				a[k] = *b;
				//int *b = &matriz.m[i][j];
				tabuleiro -> board[i + ini.x][j + ini.y].apont = &a[k];

			}
			k++;
		}
		//printf("\n");
	}

	//print_tabuleiro(tabuleiro);

	return matriz;
}
*/ 	