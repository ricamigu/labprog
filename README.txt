_________________________________________________________________________________________

	READ ME 				
_________________________________________________________________________________________

Este trabalho foi feito pelo grupo TP1_F, composto por:

• Ricardo Miguel Anjo Noronha Ribeiro, 201705837 
• Sara Raquel Gonçalves de Sá, 201804838

_________________________________________________________________________________________

	TOPICOS
_________________________________________________________________________________________

	1) COMPILAÇÃO

	2) ESTRUTURA

	3) MENUS

_________________________________________________________________________________________

 1) COMPILAÇÃO
_________________________________________________________________________________________


Para compilar o jogo:

-> gcc -o game battleship.h battleship.c bitmaps.c menus.c main.c

-> utilizar a makefile

_________________________________________________________________________________________

2) ESTRUTURA
_________________________________________________________________________________________

O battleship é composto por um zip com 7 ficheiros:

• battleship.h -> header que contém as funções dos restantes ficheiros
• battleship.c -> funções relativas ao tabuleiro de jogo
• bitmaps.c    -> funções ligadas aos bitmaps
• menus.c      -> menus utilizados ao longo do jogo
• main.c       -> main do jogo
• makefile     -> makefile para compilar o jogo
• README.txt   -> ficheiro de instruções

_________________________________________________________________________________________

3) MENUS & UTILIZAÇÃO DO JOGO
_________________________________________________________________________________________

O primeiro menu no jogo é o menu_inicial() com 3 instruções:

1) Play game
2) Instructions
3) Quit

O ponto 1) leva-nos para o jogo, o 3) termina o jogo e o 2) leva-nos para 
o menu_inicial_instructions() que contém instruções do jogo e algumas regras 
fundamentais para os inputs corretos.

Ao prosseguir o ponto 1), vai aparecer opções para escolher o nome dos jogadores
e o tamanho do tabuleiro (entre 20 e 40).

De seguida irá aparecer o menu menu_rand() com duas opções:

1) Classic Game
2) Random Game

o ponto 1) leva-nos para o jogo "normal" em que introduzimos todos os valores para
a posição e orientação dos barcos, enquanto que o 2) insere tudo isso aleatoriamente.

O ponto 1) leva-nos então para um input para escolher o número de barcos para o jogo
e, em seguida, o menu print_menuB(), que apresenta os 5 tipos de barcos que temos:

• Quadrado
• Retângulo
• Em forma de T
• Em forma de L
• Em forma de U

Depois de escolher o tipo de barco (note-se que é necessário escolher um barco de cada
tipo) e em seguida pedido as coordenadas do ponto central do bitmap do barco e a sua
orientação (0, 90, 270, 360). Depois de escolher todos os barcos e posições para o
jogador 1, repete-se o mesmo processo para o jogador 2.

Após completar toda a configuração dos barcos, o jogo está pronto a começar e aparece
o menu menu_game(char p[]) que recebe o nome do jogador para apresentá-lo no menu.
O menu é composto por:

1) Take a shot
2) See your board
3) See your shots
4) Help
5) Quit

o ponto 1) leva para a opção de escolher as coordenadas para disparar no tabuleiro de 
jogo do adversário. Vai receber uma mensagem quanto ao resultado do tiro (Missed shot,
Shot already taken, Shot hit).

o ponto 2) serve para ver o próprio tabuleiro e ver onde já foi atingido. No caso de já
ter sido atingido, aparece um X vermelho na posição.

o ponto 3) serve para ver os tiros que já foram dados no adversário. São representados
com um 2 em verde caso tenha acertado e um 1 vermelho caso tenha falhado.

o ponto 4) serve para apresentar um menu de ajuda com as regras e a utilização do jogo.

o ponto 5) serve para desistir do jogo e dar a vitória ao adversário.

O jogo termina quando um dos jogadores tiver sido acertado em todas as posições do barco.

FIM
_________________________________________________________________________________________
