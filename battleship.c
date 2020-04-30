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
			else if((tabuleiro -> board[i][j].field_shot == 2)) {printf("\033[0;31m"); printf(" X "); printf("\033[0m");}	// se a coord foi acertada pelo outro jogador, dá print de um X vermelho
			else {printf(" 1 ");}																							// posicao dos barcos
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

//print da matriz com os shots feitos no tabuleiro do adversario
void print_tabuleiroAdversario(game *tabuleiro){

	for(int i=0; i < tabuleiro->size ; i++){
		if(i<10) printf(" %d",i);
		if(i>=10) printf("%d",i);
		for(int j=0; j< tabuleiro->size;j++){
			if(tabuleiro -> board[i][j].field_shot == 0){ printf("\033[1;34m"); printf(" 0 "); printf("\033[0m");					// no shot
			}
			else if((tabuleiro -> board[i][j].field_shot == 2)) {printf("\033[0;32m"); printf(" 2 "); printf("\033[0m");}			// shot hit
			else if((tabuleiro -> board[i][j].field_shot == 1)) {printf("\033[0;31m"); printf(" 1 "); printf("\033[0m");}			// missed shot
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





//Criar matriz de jogo
void create_matriz(game *tabuleiro) {

	for(int i=0; i < tabuleiro->size ; i++){
		for(int j=0; j< tabuleiro->size;j++){
			tabuleiro -> board[i][j].apont = NULL;
			tabuleiro -> board[i][j].field_shot = 0;
		}
	}

	//print_tabuleiro(tabuleiro);

}

// funcao para verificar se pode inserir um barco
bool pode_inserir(Coordinate c, piece boat, game* tabuleiro){

	int xx = c.x -2;
	int yy = c.y -2;

	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){

			if(((boat.mb -> m[i][j] == '1') && (((i+xx) < 0 || (i+xx) > tabuleiro->size) || ((j+yy)<0 || (j+yy > tabuleiro->size))))){
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

// funcao para verificar se pode inserir mas para a versao random (sem prints)
bool pode_inserirRANDOMS(Coordinate c, piece boat, game* tabuleiro){

	int xx = c.x -2;
	int yy = c.y -2;

	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){

			if(((boat.mb -> m[i][j] == '1') && (((i+xx) < 0 || (i+xx) > tabuleiro->size) || ((j+yy)<0 || (j+yy > tabuleiro->size))))){
				return false;
			}
			if((boat.mb -> m[i][j] == '1' && (tabuleiro -> board[i+xx][j+yy].apont != NULL))){
				return false;
			}
		}
	}

	return true;
}

//funcao para inserir barcos para a versao random (sem prints e sem scanfs, em vez disso tem o uso dos random numbers)
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
		Coordinate* ab = (Coordinate *) malloc(sizeof(Coordinate*));	// caso nao possa inserir, escolhe x e y random
		x = return_randoms(3,tabuleiro -> size -4);
		y = return_randoms(3,tabuleiro -> size -4);
		ab = new_coord(x,y);
		boat -> c = *ab;
		inserir_barcoRANDOMS(boat -> c, boat, tabuleiro);				// volta a tentar inserir o barco com posicoes novas
	}
}



//funcao para inserir barcos no tabuleiro
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
		Coordinate* a = (Coordinate *) malloc(sizeof(Coordinate*));		// caso nao possa inserir, volta a pedir coordenadas ao jogador
		printf("\n\nCoordinate for the boat again: ");
		scanf("%d", &x);
		scanf("%d", &y);
		a = new_coord(x,y);
		boat -> c = *a;
		inserir_barco(boat -> c, boat, tabuleiro);						// volta a tentar inserir o barco com as posicoes novas
	}
}

// funcao para testar se acertou num barco
bool acertou(Coordinate cord, game* tabuleiro){

	if(((tabuleiro -> board[cord.x][cord.y].field_shot) == 2) || ((tabuleiro -> board[cord.x][cord.y].field_shot) == 1) ) {		
		printf("Shot already taken!\n");																						// ja disparou nessa posicao
		return false;
	}

	if(tabuleiro -> board[cord.x][cord.y].apont == NULL){
		printf("\nMissed shot!\n");																								// falhou o tiro
		tabuleiro -> board[cord.x][cord.y].field_shot = 1;
		return false;
	}


	int xa = (tabuleiro -> board[cord.x][cord.y].apont) -> c.x;
	int ya = (tabuleiro -> board[cord.x][cord.y].apont) -> c.y;


	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){																									
			if((i+xa-2 == cord.x) && (j+ya-2 ==cord.y) && ((tabuleiro -> board[cord.x][cord.y].apont) -> mb->m[i][j] == '1')){	// acertou num barco
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

	tabuleiro -> board[cord.x][cord.y].field_shot = 2;																			// acertou num barco
	printf("Shot hit!\n");

	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if((i+xa-2 == cord.x) && (j+ya-2 ==cord.y))
				(tabuleiro -> board[cord.x][cord.y].apont) -> mb->m[i][j] = '2';
		}
	}
	return true;
}

// funcao para verificar se o jogo ja acabou
bool isFinished(game* tabuleiro){

	for(int i=0; i < tabuleiro->size ; i++){
		for(int j=0; j< tabuleiro->size;j++){
			if(tabuleiro -> board[i][j].apont != NULL && tabuleiro -> board[i][j].field_shot==0)	//se apont != null e field_shot==0 significa que há uma posicao que contem um barco que nao foi acertada, entao o jogo ainda nao acabou 
				return false;
		}
	}

	return true;
}

/*
//funcao para testar se um barco foi afundado
bool afundado(Coordinate cord, game* tabuleiro){

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
*/

// funcao para colocar o tabuleiro todo a null 
void anular(game* tabuleiro){

	for(int i=0; i < tabuleiro->size ; i++){
		for(int j=0; j< tabuleiro->size;j++){
			tabuleiro -> board[i][j].apont = NULL;
			tabuleiro -> board[i][j].field_shot = 0;
		}
	}
}



// funcao que gera os numeros random
int return_randoms(int lower, int upper){

	int num = (rand() % (upper + 1 - lower)) + lower;
	return num;
}

