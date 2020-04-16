#include "battleship.h"

void print_menuB(bitmap a, bitmap b, bitmap c, bitmap d, bitmap e){

	printf("\n---------------");
 	printf("\n|  1. Square  |");
 	printf("\n---------------");
	printf("\n");
	for(int i=0; i<5;i++){
            for(int j=0;j<5;j++){
                  if(j==2) printf(" 1 ");
                  else printf(" 0 ");
            }
        printf("\n");
    }

    printf("\n");
	printf("\n----------------");
 	printf("\n| 2. Rectangle |");
 	printf("\n----------------");
	printf("\n");
	for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                  if( (i>=1 && i<=3) && (j>=1 && j<=3) ) printf(" 1 ");
                  else printf(" 0 ");
            }
        printf("\n");    
    }

    printf("\n");
	printf("\n--------------");
 	printf("\n| 3. T Shape |");
 	printf("\n--------------");
	printf("\n");
	for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                  if(i==0 || j==2) printf(" 1 ");
                  else printf(" 0 ");
            }
        printf("\n");
    }

    printf("\n");
	printf("\n---------------");
 	printf("\n| 4. L Shape  |");
 	printf("\n---------------");
	printf("\n");
	for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                  if(i==4 || j==0) printf(" 1 ");
                  else printf(" 0 ");
            }
        printf("\n");
    }

    printf("\n");
	printf("\n---------------");
 	printf("\n| 5. U Shape  |");
 	printf("\n---------------");
	printf("\n");
	for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                  if(i==4 || j==0 || j==4) printf(" 1 ");
                  else printf(" 0 ");
            }
        printf("\n");
    }
}
