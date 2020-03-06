#include <stdio.h>
void create_matrix(int n);

int main(){
	char p1[60],p2[60];
	int ship1,ship2;
	int n ;
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

	create_matrix(n);
	//printf("Put Ships on board:\n");
	//scanf("%d",&ship1);
	//scanf("%d",&ship2);

	return 0;
}

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

//void Ship_on_board(matrix[i][j],Coordinate)