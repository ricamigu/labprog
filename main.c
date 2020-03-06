#include <stdio.h>
#include <stdlib.h>
#include "battleship.h"

void create_matrix(int n);

int main(){
	char p1[20],p2[20];
	//int ship1,ship2;
	int n;
	printf("-----------------------\n");
	printf("|   Battleship Game   |\n");
	printf("-----------------------\n\n");
	printf("Welcome to the game!\n\n");
	printf("Enter first player :\n");
	scanf("%s",p1);
	printf("Enter second player:\n");
	scanf("%s",p2);
	printf("Enter the size of board (n*n):\n");
	scanf("%d",&n);



	// matrizes inicial
	game m1 , m2 ,m3 ,m4;

	game *p1m1= &m1;
	p1m1-> lin = n;
	p1m1 -> col =n;

	p1m1 -> matriz = (char ** )malloc (sizeof(char *) * p1m1-> lin);
	for(int i=0;i< p1m1 -> lin; i++) {
 		p1m1 -> matriz[i] = (char *) malloc(sizeof(char)* p1m1 -> lin);
 	}

 	game *p1m2= &m2;
	p1m2-> lin = n;
	p1m2 -> col =n;

	p1m2 -> matriz = (char ** )malloc (sizeof(char *) * p1m2-> lin);
	for(int i=0;i< p1m2 -> lin; i++) {
 		p1m2 -> matriz[i] = (char *) malloc(sizeof(char)* p1m2 -> lin);
 	}

 	game *p2m1= &m3;
	p2m1-> lin = n;
	p2m1 -> col =n;

	p2m1 -> matriz = (char ** )malloc (sizeof(char *) * p2m1-> lin);
	for(int i=0;i< p2m1 -> lin; i++) {
 		p2m1 -> matriz[i] = (char *) malloc(sizeof(char)* p2m1 -> lin);
 	}

 	game *p2m2= &m4;
	p2m2-> lin = n;
	p2m2 -> col =n;

	p2m2 -> matriz = (char ** )malloc (sizeof(char *) * p2m2-> lin);
	for(int i=0;i< p2m2 -> lin; i++) {
 		p2m2 -> matriz[i] = (char *) malloc(sizeof(char)* p2m2 -> lin);
 	}

 	create_matriz(p1m1);

	//create_matrix(n);
	//printf("Put Ships on board:\n");
	//scanf("%d",&ship1);
	//scanf("%d",&ship2);

	return 0;
}


/*
void create_matrix(int n ){
	char matrix[n+1][n+1];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<n+1;j++){
			if(i==0 && j==0)
				matrix[i][j] = '#';
			else if(i==0)
				matrix[i][j] = j + '0';
			else if(j==0 && i!=0)
				matrix[i][j] = i + '0';
			else 
				matrix[i][j]='-';
		}
	}
	for(int i=0;i<n+1;i++){
		for(int j=0;j<n+1;j++){
			printf("%c ", matrix[i][j] );
		}
			printf("\n");
		}
}
*/

//void Ship_on_board(matrix[i][j],Coordinate)

