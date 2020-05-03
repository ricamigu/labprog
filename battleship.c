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
		if(i<10) printf(" %d",i);																						//
		if(i>=10) printf("%d",i);
		for(int j=0; j< tabuleiro->size;j++){
			if(tabuleiro -> board[i][j].apont == NULL){																	//se a posição é NULL, dá print de um 0 azul 
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

//print da matriz com os shots feitos no tabuleiro do adversário
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
}

// função para verificar se pode inserir um barco
bool pode_inserir(Coordinate c, piece boat, game* tabuleiro){

	int xx = c.x -2;
	int yy = c.y -2;

	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			// a posicao que encontrou está fora do tabuleiro
			if(((boat.mb -> m[i][j] == '1') && (((i+xx) < 0 || (i+xx) > tabuleiro->size) || ((j+yy)<0 || (j+yy > tabuleiro->size))))){
				printf("\033[0;31m"); printf("\nError: "); printf("\033[0m");printf("Invalid coordinate, out of bounds!");
				return false;
			}
			//a posicao que encontrou já tem um barco
			if((boat.mb -> m[i][j] == '1' && (tabuleiro -> board[i+xx][j+yy].apont != NULL))){
				printf("\033[0;31m"); printf("\nError: "); printf("\033[0m"); printf("Invalid coordinate, boat already there!");
				return false;
			}
		}
	}

	return true;
}

// função para verificar se pode inserir mas para a versão random (sem prints)
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

//função para inserir barcos para a versão random (sem prints e sem scanfs, em vez disso tem o uso dos random numbers)
void inserir_barcoRANDOMS(Coordinate c, piece* boat, game* tabuleiro){

	//utiliza a função para verificar se pode inserir
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



//função para inserir barcos no tabuleiro
void inserir_barco(Coordinate c, piece* boat, game* tabuleiro){

	//utiliza a funcao para verificar se pode inserir
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
		printf("\nx: ");
		scanf("%d", &x);
		printf("y: ");
		scanf("%d", &y);
		a = new_coord(x,y);
		boat -> c = *a;
		inserir_barco(boat -> c, boat, tabuleiro);						// volta a tentar inserir o barco com as posicoes novas
	}
}

// função para testar se acertou num barco
bool acertou(Coordinate cord, game* tabuleiro){

	//já disparou nesta posição
	if(((tabuleiro -> board[cord.x][cord.y].field_shot) == 2) || ((tabuleiro -> board[cord.x][cord.y].field_shot) == 1) ) {		
		printf("Shot already taken!\n");																						
		return false;
	}
	// falhou o tiro
	if(tabuleiro -> board[cord.x][cord.y].apont == NULL){
		printf("\nMissed shot!\n");																								
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
			}
		}
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

// função para verificar se o jogo ja acabou
bool isFinished(game* tabuleiro){

	for(int i=0; i < tabuleiro->size ; i++){
		for(int j=0; j< tabuleiro->size;j++){
			if(tabuleiro -> board[i][j].apont != NULL && tabuleiro -> board[i][j].field_shot==0)	//se apont != null e field_shot==0 significa que há uma posicao que contem um barco que nao foi acertada, entao o jogo ainda nao acabou 
				return false;
		}
	}

	return true;
}

// função para colocar o tabuleiro todo a null 
void anular(game* tabuleiro){

	for(int i=0; i < tabuleiro->size ; i++){
		for(int j=0; j< tabuleiro->size;j++){
			tabuleiro -> board[i][j].apont = NULL;
			tabuleiro -> board[i][j].field_shot = 0;
		}
	}
}
