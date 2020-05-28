#include <stdio.h>
#include <stdlib.h>
#include "battleship.h"

// cria nova coordenada
Coordinate* new_coord(int a, int b) {
	Coordinate* c = (Coordinate *) malloc(sizeof(Coordinate*));
	c -> x = a;
	c -> y = b;
	return c;
}

// cria nova coordenada do tipo double
CoordinateD new_coordD(double a, double b) {
	CoordinateD c;
	c.x = a;
	c.y = b;
	return c;
}

// inicialização dos nós internos da árvore
struct node* new_node(){

	struct node *new = malloc(sizeof(struct node)*64);

	new -> tag = isInternal;
	new -> NW = NULL;
	new -> NE = NULL;
	new -> SW = NULL;
	new -> SE = NULL;

	new -> c = NULL;
	new -> peca = NULL;

	return new;
}

//inicialização dos nós folha da árvore
struct node* new_leaf(Coordinate *coord, piece *boat){

	struct node *new = malloc(sizeof(struct node)*64);

	new -> tag = isLeaf;
	new -> c = coord;
	new -> peca = boat;

	new -> NW = NULL;
	new -> NE = NULL;
	new -> SW = NULL;
	new -> SE = NULL;
	new -> field_shot = 0;

	return new;

}

//funcao de insert da árvore
struct node* insert(struct node* root, struct node* coord, double l1,double l2){

	// caso nao exista nenhum ponto no quadrante, insere
	if(root==NULL){
		root = coord;
		return root;
	}

	// caso seja um nó interno, é necessário ver em que quadrante va inserir
	if(root->tag == isInternal){

		//NW
		if( coord->c->x < l1 && coord->c->y < l2)
			root->NW = insert(root->NW,coord,l1/2,l2/2);

		//NE
		if( coord->c->x < l1 && coord->c->y  >= l2)
			root->NE = insert(root->NE,coord,l1/2,l2+l2/2);

		//SW
		if( coord->c->x >= l1 && coord->c->y  < l2)
			root->SW = insert(root->SW,coord,l1+l1/2,l2/2);

		//SE
		if( coord->c->x >= l1 && coord->c->y  >= l2)
			root->SE = insert(root->SE,coord,l1+l1/2,l2+l2/2);
	}

	// se o quadrante já contiver um nó folha, é necessário substituir esse nó por um interno e colocar as coordenadas nas posições corretas
	if(root->tag == isLeaf){

		struct node *new = malloc(sizeof(struct node)*64);
		new = new_node();
		struct node *temp = malloc(sizeof(struct node)*64);
		temp = new_leaf(root->c,root->peca);
		root = new;
		insert(root,temp,l1,l2);
		insert(root,coord,l1,l2);

	}
	return root;

}


// funcao que verifica se a árvore contem uma coordenada dada
bool contains(struct node* root, int x1, int y1, double l1,double l2){

	// nao encontrou
	if(root==NULL) return false;

	double xx = x1;
	double yy = y1;

	// vai verificar o quadrante que tem de verificar a seguir
	if(root->tag == isInternal){

		if( x1 < l1 && y1 < l2)
			return contains(root->NW,x1,y1,l1/2,l2/2);

		if( x1 < l1 && y1 >= l2)
			return contains(root->NE,x1,y1,l1/2,l2+l2/2);

		if( x1 >= l1 && y1 < l2)
			return contains(root->SW,x1,y1,l1+l1/2,l2/2);

		if( x1 >= l1 && y1 >= l2)
			return contains(root->SE,x1,y1,l1+l1/2,l2+l2/2);
	}

	// caso seja um nó folha e não é NULL, vai verificar se as coordenadas são iguais
	if(root->tag == isLeaf){
		if(root->c->x == x1 && root->c->y == y1)
			return true;
	}
	return false;
}


// verifica se o ponto existe e modifica o field_shot (utilizado na funcao shoot)
bool contains2(struct node* root, int x1, int y1, double l1,double l2){

	if(root==NULL) return false;

	double xx = x1;
	double yy = y1;


	if(root->tag == isInternal){

		if( x1 < l1 && y1 < l2)
			return contains2(root->NW,x1,y1,l1/2,l2/2);

		if( x1 < l1 && y1 >= l2)
			return contains2(root->NE,x1,y1,l1/2,l2+l2/2);

		if( x1 >= l1 && y1 < l2)
			return contains2(root->SW,x1,y1,l1+l1/2,l2/2);

		if( x1 >= l1 && y1 >= l2)
			return contains2(root->SE,x1,y1,l1+l1/2,l2+l2/2);
	}

	if(root->tag == isLeaf){
		if(root->c->x == x1 && root->c->y == y1){
			if(root->field_shot == 2){
				//printf("Shot already taken!\n");
				return false;
			}
			else {
				root->field_shot = 2;
				printf("Shot hit!\n");
				printf("\n");
				return true;
			}
		}

	}

	return false;
}

// retorna o field_shot de uma posição (utilizado no print da árvore no formato de matriz)
int return_fieldShot(struct node* root, int x1, int y1, double l1,double l2){

	if(root==NULL) return 0;

	double xx = x1;
	double yy = y1;


	if(root->tag == isInternal){

		if( x1 < l1 && y1 < l2)
			return return_fieldShot(root->NW,x1,y1,l1/2,l2/2);

		if( x1 < l1 && y1 >= l2)
			return return_fieldShot(root->NE,x1,y1,l1/2,l2+l2/2);

		if( x1 >= l1 && y1 < l2)
			return return_fieldShot(root->SW,x1,y1,l1+l1/2,l2/2);

		if( x1 >= l1 && y1 >= l2)
			return return_fieldShot(root->SE,x1,y1,l1+l1/2,l2+l2/2);
	}

	if(root->tag == isLeaf){
		if(root->c->x == x1 && root->c->y == y1){
			return root->field_shot;
		}
	}
	return 1;
}


//ineficiente, percorre a arvore toda (para teste apenas)
bool contains_inef(struct node *root, int x1, int y1){

	if(root==NULL) return false;

    if(root!=NULL) // checking if the root is not null
    {
    	if(root->tag==isLeaf) {
	        if( (root->c->x == x1) && (root->c->y == y1)){
				return true;
	        }
		}
    }

    return contains_inef(root->NW,x1,y1) || contains_inef(root->NE,x1,y1) || contains_inef(root->SW,x1,y1) || contains_inef(root->SE,x1,y1);

}


// retorna o número de folhas
int number_leaves(struct node* root){

	int cont=0;

	if(root == NULL) return 0;
	
	if(root->tag==isLeaf) cont=1;

	return cont + number_leaves(root->NW) + number_leaves(root->NE) + number_leaves(root->SW) + number_leaves(root->SE);

}

// dá print dos nós da árvore (teste)
int contador=1;
void inorder(struct node *root)
{
    if(root!=NULL) // checking if the root is not null
    {		
	        inorder(root->NW);
	        inorder(root->NE);
	        if(root->tag==isLeaf) {printf(" %d : (%d,%d) \n", contador, root->c->x,root->c->y); contador++;}
	        inorder(root->SW);
	        inorder(root->SE);
    }
}


// dá print da árvore toda (teste)
void print_tree(struct node* root){

	if(root==NULL) { printf(" N "); return; }

	if(root->tag==isInternal) printf(" I ");

	if(root->tag==isLeaf) printf( "(%d,%d)", root->c->x,root->c->y );

	printf("NW: "); print_tree(root->NW);
	printf("NE: "); print_tree(root->NE);
	printf("SW: "); print_tree(root->SW);
	printf("SE: "); print_tree(root->SE);

}

// limpa a root da árvore (teste)
struct node* clear_tree(struct node *root){
	struct node *new_root = malloc(sizeof(struct node)*64);
	new_root = new_node();
	return new_root;
}

// apaga a árvore toda
void delete_tree(struct node *root){

    if(root!=NULL){
	        delete_tree(root->NW);
	        delete_tree(root->NE);
	        delete_tree(root->SW);
	        delete_tree(root->SE);
	        free(root);
    }
}

// verifica se pode inserir um barco
bool pode_inserir_quad(struct node* root, piece boat, int size){

  int xx = boat.c.x-2;
  int yy = boat.c.y-2;

  // caso o barco esteja fora dos limites
  if(xx < 0 || yy < 0 || xx>=size || yy>=size){
  	printf("\033[0;31m"); printf("\nError: "); printf("\033[0m");printf("Invalid coordinate, out of bounds!");
  	return false;
  }


  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
        if(boat.mb -> m[i][j] == '1'){
          if (contains(root, xx+i, yy+j, size/2,size/2)){
          	// caso o barco fique sobreposto com outro já existente
          	printf("\033[0;31m"); printf("\nError: "); printf("\033[0m");printf("Invalid coordinate, boat already there!");
          	return false;
          }
        }
    }
  }

  return true;
}

void inserir_barco_quad(struct node* root, piece *boat, int size){

	if(pode_inserir_quad(root, *boat, size)){

		for(int i=0; i<5; i++){
	    	for(int j=0; j<5; j++){
	       		if(boat-> mb -> m[i][j] == '1'){
	       			Coordinate *a = (Coordinate *) malloc(sizeof(Coordinate*)*64);
	       			a = new_coord(boat->c.x-2+i, boat->c.y-2+j);
	       			struct node* leaf = malloc(sizeof(struct node)*64);
	       			leaf = new_leaf(a,boat);
	        		insert(root, leaf, size/2,size/2);

	        	}
	    	}
	  	}
	}

	else {
		// caso nao possa inserir, volta a pedir coordenadas ao jogador
		int x1,y1;
		printf("\n\nCoordinate for the boat again: ");
		printf("\nx: ");
		scanf("%d", &x1);
		printf("y: ");
		scanf("%d", &y1);
		Coordinate* a  = (Coordinate *) malloc(sizeof(Coordinate*)*64);
		a = new_coord(x1,y1);
		boat->c = *a;
		inserir_barco_quad(root, boat, size);
	}

	//inorder(root);
	printf("\n");
}

// funcao igual à pode_inserir_quad, mas não utiliza printfs porque trata-se do modo random
bool pode_inserirRANDOMS_quad(struct node* root, piece boat, int size){

  int xx = boat.c.x-2;
  int yy = boat.c.y-2;

  if(xx < 0 || yy < 0 || xx>=size || yy>=size){
  	return false;
  }

  //CoordinateD meio = new_coordD(size/2,size/2);

  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
        if(boat.mb -> m[i][j] == '1'){
          if (contains(root, xx+i, yy+j,size/2,size/2)){
          	return false;
          }
        }
    }
  }

  return true;
}

// funcao igual à inserir_barco_quad, mas não utiliza printfs nem scanfs porque trata-se do modo random
void inserir_barcoRANDOMS_quad(struct node* root, piece *boat, int size){

	if(pode_inserirRANDOMS_quad(root, *boat, size)){

		for(int i=0; i<5; i++){
	    	for(int j=0; j<5; j++){
	       		if(boat-> mb -> m[i][j] == '1'){

	       			Coordinate *a = (Coordinate *) malloc(sizeof(Coordinate*)*64);
	       			a = new_coord(boat->c.x-2+i, boat->c.y-2+j);
	       			//CoordinateD meio = new_coordD(size/2,size/2);
	       			struct node* leaf = malloc(sizeof(struct node)*64);
	       			leaf = new_leaf(a,boat);
	        		insert(root, leaf, size/2,size/2);
	        	}
	    	}
	  	}
	}

	else {
		// caso nao possa inserir, volta a criar coordenadas aleatórias
		int x1,y1;
		x1 = return_randoms(2,size-3);
		y1 = return_randoms(2,size-3);
		Coordinate* a  = (Coordinate *) malloc(sizeof(Coordinate*)*64);
		a = new_coord(x1,y1);
		boat->c = *a;
		inserir_barcoRANDOMS_quad(root, boat, size);
	}
}

// verifica se o tiro acertou ou não num barco.
bool shoot(struct node* root, Coordinate *coord, double l1,double l2){

	if(contains2(root,coord->x,coord->y,l1,l2)) return true;

	printf("Missed shot!\n");
	return false;
}


//funcao que "transforma" a árvore numa matriz para representar
void matriz_jogador(struct node *root, int size){

	for(int i=0; i < size; i++){
		if(i<10) printf(" %d",i);																						//
		if(i>=10) printf("%d",i);
		for(int j=0; j<size; j++){
			if(!contains(root, i, j, size/2,size/2)){
				printf("\033[1;34m");
				printf(" 0 ");
				printf("\033[0m");
			}
			else if( return_fieldShot(root,i,j,size/2,size/2) == 2) {printf("\033[0;31m"); printf(" X "); printf("\033[0m");}
			else { printf(" 1 ");}
		}
		printf("\n");
	}

	printf("##");
	for(int j=0;j<size;j++){
		if(j<10) printf(" %d ", j);
		if(j>=10) printf(" %d",j);
	}
	printf("\n");

}

// funcao que verifica se o jogo já acabou
bool isFinished_quad(struct node *root, int shots_hit){

	// se o número de folhas da árvore for igual ao número de tiros diferentes acertados nessa árvore, retorna true
	if(number_leaves(root) == shots_hit)
		return true;

	return false;

}
