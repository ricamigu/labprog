#include "battleship.h"
#include <stdbool.h>
#include <time.h> 

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
			if(tabuleiro -> board[i][j].apont == NULL){
				printf("\033[1;34m");
				printf(" 0 ");
				printf("\033[0m");
			}
			else if((tabuleiro -> board[i][j].field_shot == 2)) printf(" 2 ");
			else if((tabuleiro -> board[i][j].field_shot == 1)) printf(" X ");
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

	for(int i=0; i < tabuleiro->size ; i++){
		for(int j=0; j< tabuleiro->size;j++){
			tabuleiro -> board[i][j].apont = NULL;
			tabuleiro -> board[i][j].field_shot = 0;
		}
	}

	//print_tabuleiro(tabuleiro);

}

bool pode_inserir(Coordinate c, piece boat, game* tabuleiro){

	int xx = c.x -2;
	int yy = c.y -2;

	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){

			if(((boat.mb -> m[i][j] == '1') && (((i+xx) < 0 || (i+xx) > tabuleiro->size) || ((j+yy)<0 || (j+yy > tabuleiro->size))))){
				//printf("\n %c (%d,%d)", boat.mb -> m[i][j], i+xx, j+yy);
				printf("\nFora do tabuleiro\n");
				return false;
			}
			if((boat.mb -> m[i][j] == '1' && (tabuleiro -> board[i+xx][j+yy].apont != NULL))){
				printf("\nInvalid coordinate.\n");
				return false;
			}
		}
	}

	return true;
}


bool pode_inserirRANDOMS(Coordinate c, piece boat, game* tabuleiro){

	int xx = c.x -2;
	int yy = c.y -2;

	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){

			if(((boat.mb -> m[i][j] == '1') && (((i+xx) < 0 || (i+xx) > tabuleiro->size) || ((j+yy)<0 || (j+yy > tabuleiro->size))))){
				//printf("\n %c (%d,%d)", boat.mb -> m[i][j], i+xx, j+yy);
				return false;
			}
			if((boat.mb -> m[i][j] == '1' && (tabuleiro -> board[i+xx][j+yy].apont != NULL))){
				return false;
			}
		}
	}

	return true;
}

void inserir_barcoRANDOMS(Coordinate c, piece* boat, game* tabuleiro){

	if(pode_inserirRANDOMS(c, *boat, tabuleiro)){

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
		x = return_randoms(2,tabuleiro -> size -2);
		y = return_randoms(2,tabuleiro -> size -2);
		a = new_coord(x,y);
		boat -> c = *a;
		inserir_barcoRANDOMS(boat -> c, boat, tabuleiro);
	}
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

	if(tabuleiro -> board[cord.x][cord.y].apont == NULL){
		printf("\nMissed shot!\n");
		return false;
	}

	int xa = (tabuleiro -> board[cord.x][cord.y].apont) -> c.x;
	int ya = (tabuleiro -> board[cord.x][cord.y].apont) -> c.y;
 
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if((i+xa-2 == cord.x) && (j+ya-2 ==cord.y) && ((tabuleiro -> board[cord.x][cord.y].apont) -> mb->m[i][j] == '1')){
				(tabuleiro -> board[cord.x][cord.y].apont) -> mb->m[i][j] = '2';
				(tabuleiro -> board[cord.x][cord.y].apont) -> shot_count++;
				(tabuleiro -> board[cord.x][cord.y].field_shot) = 2;
				return true;
			}
			if((i+xa-2 == cord.x) && (j+ya-2 ==cord.y) && ((tabuleiro -> board[cord.x][cord.y].apont) -> mb->m[i][j] == '0')){
				(tabuleiro -> board[cord.x][cord.y].apont) -> mb->m[i][j] = '3';
				(tabuleiro -> board[cord.x][cord.y].field_shot) = 1;
				printf("Missed shot!\n");
				return false;
			}
			if(((i+xa-2 == cord.x) && (j+ya-2 ==cord.y)) && (((tabuleiro -> board[cord.x][cord.y].apont) -> mb->m[i][j] == '2') || (tabuleiro -> board[cord.x][cord.y].apont) -> mb->m[i][j] == '3')){
				printf("Shot already taken!\n");
				return false;
			}
		}
		printf("\n");
	}

	return false;
}




// rands
int return_randoms(int lower, int upper){

	int num = (rand() % (upper + 1 - lower)) + lower;
	return num;
}

