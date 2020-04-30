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


//print da matriz com os barcos do jogador
void print_tabuleiro(game *tabuleiro){

	printf("\n");
	for(int i=0; i < tabuleiro->size ; i++){
		if(i<10) printf(" %d",i);
		if(i>=10) printf("%d",i);
		for(int j=0; j< tabuleiro->size;j++){
			if(tabuleiro -> board[i][j].apont == NULL){																		//se a posição é NULL, dá print de um 0 azul 
				printf("\033[1;34m");
				printf(" 0 ");
				printf("\033[0m");
			}
			else if((tabuleiro -> board[i][j].field_shot == 2)) {printf("\033[0;31m"); printf(" X "); printf("\033[0m");}	// se a coord foi acertada, dá print de um X vermelho
			else {printf(" 1 ");}																							// posicao dos barcos
		}
		printf("\n");
	}
	printf("##");																											// numeração das coordenadas
	for(int j=0;j<tabuleiro->size;j++){
		if(j<10) printf(" %d ", j);
		if(j>=10) printf(" %d",j);
	}
	printf("\n");
}

//print da matriz com os shots feitos no tabuleiro do adversario
void print_tabuleiroAdversario(game *tabuleiro){

	for(int i=0; i < tabuleiro->size ; i++){
		if(i<10) printf(" %d",i);
		if(i>=10) printf("%d",i);
		for(int j=0; j< tabuleiro->size;j++){
			if(tabuleiro -> board[i][j].field_shot == 0){ printf("\033[1;34m"); printf(" 0 "); printf("\033[0m");
			}
			else if((tabuleiro -> board[i][j].field_shot == 2)) {printf("\033[0;32m"); printf(" 2 "); printf("\033[0m");}
			else if((tabuleiro -> board[i][j].field_shot == 1)) {printf("\033[0;31m"); printf(" 1 "); printf("\033[0m");}
		}
		printf("\n");
	}
	printf("##");
	for(int j=0;j<tabuleiro->size;j++){
		if(j<10) printf(" %d ", j);
		if(j>=10) printf(" %d",j);
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
		Coordinate* ab = (Coordinate *) malloc(sizeof(Coordinate*));
		x = return_randoms(3,tabuleiro -> size -4);
		y = return_randoms(3,tabuleiro -> size -4);
		ab = new_coord(x,y);
		boat -> c = *ab;
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

/*
	if((cord.x > tabuleiro -> size) || (cord.y > tabuleiro -> size) || (cord.x < 0) || (cord.y < 0)){
		printf("\nShot out of bounds!");
		return false;
	}

*/
	if(((tabuleiro -> board[cord.x][cord.y].field_shot) == 2) || ((tabuleiro -> board[cord.x][cord.y].field_shot) == 1) ) {
		printf("Shot already taken!\n");
		return false;
	}



	if(tabuleiro -> board[cord.x][cord.y].apont == NULL){
		printf("\nMissed shot!\n");
		tabuleiro -> board[cord.x][cord.y].field_shot = 1;
		return false;
	}


	int xa = (tabuleiro -> board[cord.x][cord.y].apont) -> c.x;
	int ya = (tabuleiro -> board[cord.x][cord.y].apont) -> c.y;
 	//(((tabuleiro -> board[cord.x][cord.y].apont) -> mb->m[i][j] == '2') || (tabuleiro -> board[cord.x][cord.y].apont) -> mb->m[i][j] == '3'))


	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if((i+xa-2 == cord.x) && (j+ya-2 ==cord.y) && ((tabuleiro -> board[cord.x][cord.y].apont) -> mb->m[i][j] == '1')){
				(tabuleiro -> board[cord.x][cord.y].apont) -> mb->m[i][j] = '2';
				(tabuleiro -> board[cord.x][cord.y].apont) -> shot_count++;
				(tabuleiro -> board[cord.x][cord.y].field_shot) = 2;
				printf("Shot hit!\n");
				return true;
			}/*
			if((i+xa-2 == cord.x) && (j+ya-2 ==cord.y) && ((tabuleiro -> board[cord.x][cord.y].apont) -> mb->m[i][j] == '0')){
				(tabuleiro -> board[cord.x][cord.y].apont) -> mb->m[i][j] = '3';
				(tabuleiro -> board[cord.x][cord.y].field_shot) = 1;
				printf("Missed shot, but you're close!\n");
				return false;
			}*/
		}
		//printf("%d\n",i);
	}

	tabuleiro -> board[cord.x][cord.y].field_shot = 2;
	printf("Shot hit!\n");

	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if((i+xa-2 == cord.x) && (j+ya-2 ==cord.y))
				(tabuleiro -> board[cord.x][cord.y].apont) -> mb->m[i][j] = '2';
		}
	}
	return true;
}

bool isFinished(game* tabuleiro){

	/*
	for(int i=0; i < tabuleiro->size ; i++){
		for(int j=0; j< tabuleiro->size;j++){
			if(tabuleiro -> board[i][j].apont != NULL)
				return false;
		}
	}
	*/

	for(int i=0; i < tabuleiro->size ; i++){
		for(int j=0; j< tabuleiro->size;j++){
			if(tabuleiro -> board[i][j].apont != NULL && tabuleiro -> board[i][j].field_shot==0)
				return false;
		}
	}

	return true;
}

bool afundado(Coordinate cord, game* tabuleiro){

	//printf("(x,y) = (%d,%d)\n", cord.x,cord.y);

	
	for(int i=0; i<5; i++){
		for(int j=0;j<5;j++){
			//printf(" %c ",(tabuleiro -> board[cord.x][cord.y].apont) -> mb->m[i][j]);
			if((tabuleiro -> board[cord.x][cord.y].apont) -> mb->m[i][j] == '1') return false;
		}
		printf("\n");
	}


	printf("\nThe boat has sunk!\n");
	return true;
}


void anular(game* tabuleiro){

	for(int i=0; i < tabuleiro->size ; i++){
		for(int j=0; j< tabuleiro->size;j++){
			tabuleiro -> board[i][j].apont = NULL;
			tabuleiro -> board[i][j].field_shot = 0;
		}
	}
}



// rands
int return_randoms(int lower, int upper){

	int num = (rand() % (upper + 1 - lower)) + lower;
	return num;
}

