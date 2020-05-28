#include "battleship.h"

//menu de apresentação dos barcos
void print_menuB(){

	printf("\n*-------------*");
 	printf("\n|  1. Square  |");
 	printf("\n*-------------*");
	printf("\n");
	for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                  if( (i>=1 && i<=3) && (j>=1 && j<=3) ) printf(" 1 ");
                  else printf(" 0 ");
            }
        printf("\n");    
    }

    printf("\n");
	printf("\n*--------------*");
 	printf("\n| 2. Rectangle |");
 	printf("\n*--------------*");
	printf("\n");
    	for(int i=0; i<5;i++){
            for(int j=0;j<5;j++){
                  if(j==2) printf(" 1 ");
                  else printf(" 0 ");
            }
        printf("\n");
    }


    printf("\n");
	printf("\n*------------*");
 	printf("\n| 3. T Shape |");
 	printf("\n*------------*");
	printf("\n");
	for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                  if(i==0 || j==2) printf(" 1 ");
                  else printf(" 0 ");
            }
        printf("\n");
    }

    printf("\n");
	printf("\n*-------------*");
 	printf("\n| 4. L Shape  |");
 	printf("\n*-------------*");
	printf("\n");
	for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                  if(i==4 || j==0) printf(" 1 ");
                  else printf(" 0 ");
            }
        printf("\n");
    }

    printf("\n");
	printf("\n*-------------*");
 	printf("\n| 5. U Shape  |");
 	printf("\n*-------------*");
	printf("\n");
	for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                  if(i==4 || j==0 || j==4) printf(" 1 ");
                  else printf(" 0 ");
            }
        printf("\n");
    }
}

void press_any_key(){
	char ch;
    printf("Press any key to continue...");
    ch = getchar();
    scanf("%c", &ch);
}



void menu_inicial_matrix(){

	system("clear");
	printf("*--------------------------------------------------------------------------*\n");
	printf("|                        Battleship Game - Matrix                          |\n");
	printf("*--------------------------------------------------------------------------*\n");
	printf("| 1) Play Game                                                             |\n");
	printf("|                                                                          |\n");
	printf("| 2) Instructions                                                          |\n");
	printf("|                                                                          |\n");
	printf("| 3) Quit                                                                  |\n");
	printf("*--------------------------------------------------------------------------*\n");
 
}

void menu_inicial_quad(){

    system("clear");
    printf("*--------------------------------------------------------------------------*\n");
    printf("|                        Battleship Game - QuadTree                        |\n");
    printf("*--------------------------------------------------------------------------*\n");
    printf("| 1) Play Game                                                             |\n");
    printf("|                                                                          |\n");
    printf("| 2) Instructions                                                          |\n");
    printf("|                                                                          |\n");
    printf("| 3) Quit                                                                  |\n");
    printf("*--------------------------------------------------------------------------*\n");
 
}


void menu_inicial_instructions(){

	system("clear");
    printf("*---------------------------------------------------------------------------------------------------------------------------------------------------*\n");
    printf("|                                                                Instructions                                                                       |\n");
    printf("*---------------------------------------------------------------------------------------------------------------------------------------------------*\n");
    printf("|                                                                                                                                                   |\n");
    printf("| Welcome to The Battleship Game!                                                                                                                   |\n");
    printf("|                                                                                                                                                   |\n");
    printf("| The game's goal is to hit all the opponent's boats and sink them. The game ends when a player sinks all the opponent's boats.                     |\n");
    printf("|                                                                                                                                                   |\n");
    printf("| During the game you have an option to play the Classic Game or Random Game.                                                                       |\n");
    printf("| Classic Game: You choose the number of boats, the positions to place them and the rotation.                                                       |\n");
    printf("| Random Game: The game itself chooses randomly the number of boats, rotation and positions to place them.                                          |\n");
    printf("|                                                                                                                                                   |\n");
    printf("| Rules:                                                                                                                                            |\n");
    printf("| The allowed game size should be between 20x20 to 40x40 (always squares).                                                                          |\n");
    printf("| The maximum number of boats is given by game_size / 5*5, so if you choose a game size of 20*20 = 400, the max number of boats is 400/25 = 16.     |\n");
    printf("| There are 5 types of boats: Square, Rectangle, T-Shape, L-Shape, U-Shape.                                                                         |\n");
    printf("| Each player must choose one boat of every type. Since we have 5 different types of boats, this means we have a minimum of 5 boats in the game.    |\n");
    printf("|                                                                                                                                                   |\n");
    printf("|                                                                                                                                                   |\n");
    printf("| During the game:                                                                                                                                  |\n");
    printf("| This explanation will be available during the game aswell if you need it.                                                                         |\n");
    printf("|                                                                                                                                                   |\n");
    printf("| During the game you will have 5 options:                                                                                                          |\n");
    printf("| 1. Take a shot (To shoot at the opponent's boats);                                                                                                |\n");
    printf("| 2. See your board (to see your board and your boats);                                                                                             |\n");
    printf("| 3. See your shots (to see your opponent's board and your shots);                                                                                  |\n");
    printf("| 4. Help (which will take you to the help menu explaining this part of the instructions);                                                          |\n");
    printf("| 5. Quit (well, as the name says, to quit the game and give the victory to your opponent).                                                         |\n");
    printf("|                                                                                                                                                   |\n");
    printf("| When you are viewing your board (2.) you will see your boats with a 1 and the positions they were hit with"); printf("\033[0;31m"); printf(" X "); printf("\033[0m");printf("                                     |\n");
    printf("| When you are viewing your shots (3.) you will see the shots you made with");printf("\033[0;32m"); printf(" 2 ");printf("\033[0m");printf("if you hit the opponent's boat and");printf("\033[0;31m"); printf(" 1 ");printf("\033[0m");printf("if you miss the shot.            |\n");
    printf("|                                                                                                                                                   |\n");
    printf("| Score System:                                                                                                                                     |\n");
    printf("|                                                                                                                                                   |\n");
    printf("| Each player gets 10 points for every hit.                                                                                                         |\n");
    printf("*---------------------------------------------------------------------------------------------------------------------------------------------------*\n");
	
	press_any_key();
}


void menu_rand(){

	//system("clear");
	printf("*--------------------------------------------------------------------------*\n");
	printf("|                              Game Options                                |\n");
	printf("*--------------------------------------------------------------------------*\n");
	printf("| 1) Classic Game                                                          |\n");
	printf("|                                                                          |\n");
	printf("| 2) Random Game                                                           |\n");
	printf("*--------------------------------------------------------------------------*\n");
	printf("> ");
}

void menu_game(char p[]){

	printf("*--------------------------------------------------------------------------*\n");
	printf("                             %s's turn                                    \n",p);
	printf("*--------------------------------------------------------------------------*\n");
	printf("| 1) Take a shot                                                           |\n");
	printf("|                                                                          |\n");
	printf("| 2) See your board                                                        |\n");
	printf("|                                                                          |\n");
	printf("| 3) See your shots                                                        |\n");
	printf("|                                                                          |\n");
	printf("| 4) Help                                                                  |\n");
	printf("|                                                                          |\n");
	printf("| 5) Quit                                                                  |\n");
	printf("*--------------------------------------------------------------------------*\n");
	printf("> ");
}


void menu_help(){

	system("clear");
    printf("*---------------------------------------------------------------------------------------------------------------------------------------------------*\n");
    printf("|                                                                     Help                                                                          |\n");
    printf("*---------------------------------------------------------------------------------------------------------------------------------------------------*\n");
    printf("| During the game you have 5 options:                                                                                                               |\n");
    printf("| 1. Take a shot (To shoot at the opponent's boats). You must choose a coordinate according to the board size;                                      |\n");
    printf("| 2. See your board (to see your board and your boats);                                                                                             |\n");
    printf("| 3. See your shots (to see your opponent's board and your shots);                                                                                  |\n");
    printf("| 4. Help (which will take you here);                                                                                                               |\n");
    printf("| 5. Quit (well, as the name says, to quit the game and give the victory to your opponent).                                                         |\n");
    printf("|                                                                                                                                                   |\n");
    printf("| When you are viewing your board (2.) you will see your boats with a 1 and the positions they were hit with"); printf("\033[0;31m"); printf(" X "); printf("\033[0m");printf("                                     |\n");
    printf("| When you are viewing your shots (3.) you will see the shots you made with");printf("\033[0;32m"); printf(" 2 ");printf("\033[0m");printf("if you hit the opponent's boat and");printf("\033[0;31m"); printf(" 1 ");printf("\033[0m");printf("if you miss the shot.            |\n");
	printf("|                                                                                                                                                   |\n");
    printf("| Score System:                                                                                                                                     |\n");
    printf("|                                                                                                                                                   |\n");
    printf("| Each player gets 10 points for every hit.                                                                                                         |\n");
    printf("*---------------------------------------------------------------------------------------------------------------------------------------------------*\n");
	press_any_key();


}
