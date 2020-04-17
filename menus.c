#include "battleship.h"

void print_menuB(){

	printf("\n---------------");
 	printf("\n|  1. Square  |");
 	printf("\n---------------");
	printf("\n");
	for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                  if( (i>=1 && i<=3) && (j>=1 && j<=3) ) printf(" 1 ");
                  else printf(" 0 ");
            }
        printf("\n");    
    }

    printf("\n");
	printf("\n----------------");
 	printf("\n| 2. Rectangle |");
 	printf("\n----------------");
	printf("\n");
    	for(int i=0; i<5;i++){
            for(int j=0;j<5;j++){
                  if(j==2) printf(" 1 ");
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




void menu_inicial(){

  printf("\n\n");
  printf("----------------------------------------------------------------------------\n");
  printf("|                              Battleship Game                             |\n");
  printf("----------------------------------------------------------------------------\n");
  printf("| 1) Play Game                                                             |\n");
  printf("|                                                                          |\n");
  printf("| 2) Instructions                                                          |\n");
  printf("|                                                                          |\n");
  printf("| 3) Quit                                                                  |\n");
  printf("----------------------------------------------------------------------------\n");
 
}


void menu_inicial_instructions(){

  printf("----------------------------------------------------------------------------\n");
  printf("|                              Instructions                                |\n");
  printf("----------------------------------------------------------------------------\n");
  // por completar
  int ch;
  printf("Press any key to continue...\n");
  ch = getchar();
  scanf("%c", &ch);
}


void menu_rand(){

  printf("----------------------------------------------------------------------------\n");
  printf("|                              Game Options                                |\n");
  printf("----------------------------------------------------------------------------\n");
  printf("| 1) Classic Game                                                          |\n");
  printf("|                                                                          |\n");
  printf("| 2) Random Game                                                           |\n");
  printf("----------------------------------------------------------------------------\n");

}