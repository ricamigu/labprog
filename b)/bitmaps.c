#include "battleship.h"

//criar o bitmap do retângulo
bitmap create_rect() {

      bitmap matriz;

      for(int i=0; i<5;i++){
            for(int j=0;j<5;j++){
                  if(j==2) matriz.m[i][j] = '1';
                  else matriz.m[i][j] = '0';
            }
      }

      return matriz;
}

//criar o bitmap do quadrado
bitmap create_quad(){

      bitmap matriz;
      
      for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                  if( (i>=1 && i<=3) && (j>=1 && j<=3) ) matriz.m[i][j] = '1';
                  else matriz.m[i][j] = '0';
            }
      }
      return matriz;
}

//criar o bitmap do T
bitmap create_barcoT(){
      
      bitmap matriz;
      
      for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                  if(i==0 || j==2) matriz.m[i][j] = '1';
                  else matriz.m[i][j] = '0';
            }
      }
      return matriz;
}

//criar o bitmap do L
bitmap create_barcoL(){
      
      bitmap matriz;
      
      for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                  if(i==4 || j==0) matriz.m[i][j] = '1';
                  else matriz.m[i][j] = '0';
            }
      }
      return matriz;
}

//criar o bitmap do U
bitmap create_barcoU(){
      
      bitmap matriz;
      
      for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                  if(i==4 || j==0 || j==4) matriz.m[i][j] = '1';
                  else matriz.m[i][j] = '0';
            }
      }
      return matriz;
}

//rodar 90 graus um bitmap
bitmap rotate_90(bitmap matriz){

      bitmap rot;
      int x=0;
      int y=4;

      for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                  rot.m[x][y] = matriz.m[i][j];
                  x++;
            }
            x=0;
            y--;
      }

      return rot;
}

//rodar 180 graus o bitmap
bitmap rotate_180(bitmap matriz){

      bitmap rot;
      int x=4;

      for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                  rot.m[x][j] = matriz.m[i][j];
            }
            x--;
      }

      return rot;
}

//rodar 270 graus o bitmap
bitmap rotate_270(bitmap matriz){

      bitmap rot;
      int x=4;
      int y=0;

      for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                  rot.m[x][y] = matriz.m[i][j];
                  x--;
            }
            x=4;
            y++;
      }

      return rot;
}




//print do bitmap
void print_bitmap(bitmap matriz){

      for(int i=0; i<5;i++){
            for(int j=0;j<5;j++){
                  printf(" %c ", matriz.m[i][j]);
            }
            printf("\n");
      }
      printf("\n");
}

//teste
void print_bitmapas(bitmap* matriz){

      for(int i=0; i<5;i++){
            for(int j=0;j<5;j++){
                  printf(" %c ", matriz -> m[i][j]);
            }
            printf("\n");
      }
      printf("\n");
}

//função switch para selecionar a opção do jogador quanto ao barco e à rotação do mesmo
bitmap switch_function(int opcao,int orientacao){

      bitmap mapas;
      switch(opcao){
            case 1: switch(orientacao){
                  case 0: mapas = create_quad();
                          break;
                  case 90: mapas = rotate_90(create_quad()); 
                          break;
                  case 180: mapas = rotate_180(create_quad());
                          break;
                  case 270: mapas = rotate_270(create_quad());
                          break;
            }
            break;
            case 2: switch(orientacao){
                  case 0: mapas = create_rect();
                          break;
                  case 90: mapas = rotate_90(create_rect()); 
                          break;
                  case 180: mapas = rotate_180(create_rect());
                          break;
                  case 270: mapas = rotate_270(create_rect());
                          break;
            }
            break;
            case 3: switch(orientacao){
                  case 0: mapas = create_barcoT();
                          break;
                  case 90: mapas = rotate_90(create_barcoT()); 
                          break;
                  case 180: mapas = rotate_180(create_barcoT());
                          break;
                  case 270: mapas = rotate_270(create_barcoT());
                          break;
            }
            break;
            case 4: switch(orientacao){
                  case 0: mapas = create_barcoL();
                          break;
                  case 90: mapas = rotate_90(create_barcoL()); 
                          break;
                  case 180: mapas = rotate_180(create_barcoL());
                          break;
                  case 270: mapas = rotate_270(create_barcoL());
                          break;
            }
            break;
            case 5: switch(orientacao){
                  case 0: mapas = create_barcoU();
                          break;
                  case 90: mapas = rotate_90(create_barcoU()); 
                          break;
                  case 180: mapas = rotate_180(create_barcoU());
                          break;
                  case 270: mapas = rotate_270(create_barcoU());
                          break;
            }
            break;
      }
      return mapas;
}

// função para escolher um barco e orientação random
bitmap switch_functionRANDOMS(int opcao,int orientacao){

	  bitmap mapas;
	  
      switch(opcao){
            case 1: switch(orientacao){
                  case 0: mapas = create_quad();
                          break;
                  case 1: mapas = rotate_90(create_quad()); 
                          break;
                  case 2: mapas = rotate_180(create_quad());
                          break;
                  case 3: mapas = rotate_270(create_quad());
                          break;
            }
            break;
            case 2: switch(orientacao){
                  case 0: mapas = create_rect();
                          break;
                  case 1: mapas = rotate_90(create_rect()); 
                          break;
                  case 2: mapas = rotate_180(create_rect());
                          break;
                  case 3: mapas = rotate_270(create_rect());
                          break;
            }
            break;
            case 3: switch(orientacao){
                  case 0: mapas = create_barcoT();
                          break;
                  case 1: mapas = rotate_90(create_barcoT()); 
                          break;
                  case 2: mapas = rotate_180(create_barcoT());
                          break;
                  case 3: mapas = rotate_270(create_barcoT());
                          break;
            }
            break;
            case 4: switch(orientacao){
                  case 0: mapas = create_barcoL();
                          break;
                  case 1: mapas = rotate_90(create_barcoL()); 
                          break;
                  case 2: mapas = rotate_180(create_barcoL());
                          break;
                  case 3: mapas = rotate_270(create_barcoL());
                          break;
            }
            break;
            case 5: switch(orientacao){
                  case 0: mapas = create_barcoU();
                          break;
                  case 1: mapas = rotate_90(create_barcoU()); 
                          break;
                  case 2: mapas = rotate_180(create_barcoU());
                          break;
                  case 3: mapas = rotate_270(create_barcoU());
                          break;
            }
            break;
      }

      return mapas;
}
