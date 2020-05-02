_________________________________________________________________________________________

	READ ME 				
_________________________________________________________________________________________

Este trabalho foi elaborado pelo grupo TP1_F, composto por:

• Ricardo Miguel Anjo Noronha Ribeiro, 201705837 
• Sara Raquel Gonçalves de Sá, 201804838

_________________________________________________________________________________________

	TÓPICOS
_________________________________________________________________________________________

	1) COMPILAÇÃO

	2) MENUS & UTILIZAÇÃO DO JOGO

	3) ESTRUTURA

_________________________________________________________________________________________

 1) COMPILAÇÃO
_________________________________________________________________________________________

Para compilar o jogo:

-> gcc -o game battleship.h battleship.c bitmaps.c menus.c main.c

-> utilizar a makefile

e depois executar com ./game

_________________________________________________________________________________________

2) MENUS & UTILIZAÇÃO DO JOGO
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
orientação (0, 90, 180, 270). Depois de escolher todos os barcos e posições para o
jogador 1, repete-se o mesmo processo para o jogador 2.

Após completar toda a configuração dos barcos, o jogo está pronto a começar e aparece
o menu menu_game(char p[]) que recebe o nome do jogador para apresentá-lo no menu.

O menu é composto por:
1) Take a shot
2) See your board
3) See your shots
4) Help
5) Quit

O ponto 1) leva para a opção de escolher as coordenadas para disparar no tabuleiro de 
jogo do adversário. Vai receber uma mensagem quanto ao resultado do tiro (Missed shot,
Shot already taken, Shot hit).

O ponto 2) serve para ver o próprio tabuleiro e ver onde já foi atingido. No caso de já
ter sido atingido, aparece um X vermelho na posição.

O ponto 3) serve para ver os tiros que já foram dados no adversário. São representados
com um 2 em verde caso tenha acertado e um 1 vermelho caso tenha falhado.

O ponto 4) serve para apresentar um menu de ajuda com as regras e a utilização do jogo.

O ponto 5) serve para desistir do jogo e dar a vitória ao adversário.

O jogo termina quando um dos jogadores tiver sido acertado em todas as posições do barco.

_________________________________________________________________________________________

3) ESTRUTURA
_________________________________________________________________________________________

O battleship é composto por um zip com 7 ficheiros:

• battleship.h -> header que contém as structs e as declarações das funções de todos os ficheiros
• battleship.c -> funções relativas ao tabuleiro de jogo
• bitmaps.c    -> funções ligadas aos bitmaps
• menus.c      -> menus utilizados ao longo do jogo
• main.c       -> main do jogo
• makefile     -> makefile para compilar o jogo
• README.txt   -> ficheiro de instruções

__________________________________

3.1) EXPLICAÇÃO SUCINTA DO CÓDIGO
__________________________________

Grande parte das explicações foi colocada aqui para não serem demasiados comentários no código do jogo.
Os comentários nos ficheiros são mais diretos, enquanto que aqui aprofundamos um pouco mais o que cada
função faz.

 ____________
|            |
|battleship.h|  -> header que contém as structs e as declarações das funções de todos os ficheiros
|____________|

As structs são: 

- Coordinate, contendo ints x e y para utilizar na colocação dos barcos, nos tiros e em
diversas outras funções de inserir barcos;

- bitmap, que contém apenas uma matriz do tipo char 5x5 para representar o bitmap dos barcos.

- piece, que representa os barcos. Cada piece tem uma Coordinate c, que é a posição central
do barco, um int que representa a orientação/rotação do barco, um bitmap* mb que é um
apontador para um bitmap que vai armazenar o bitmap desse barco/peça. Por último, tem um shot
count que armazena o número de vezes que foi acertado.

- Cell, que contém um apontador do tipo piece e um int field_shot. O field_shot tem os valores
0, 1 e 2. Estes valores correspondem a: não há tiro nessa posição, já houve um tiro mas não
acertou em nenhum barco e houve tiro e acertou num barco do adversário, respetivamente.

- game, que corresponde ao tabuleiro de jogo. É composta por um int size, que é o tamanho
do jogo NxN (entre 20 e 40) e um Cell** board que corresponde a uma matriz do tipo Cell.

O resto do battleship.h contém as declarações das funções do jogo que vão ser explicadas
nos ficheiros.

 ____________
|            |
|battleship.c|  -> funções relativas ao tabuleiro de jogo
|____________|

As funções do battleship são:

Coordinate* new_coord(int a, int b) -> cria coordenadas novas

void print_tabuleiro (game *tabuleiro)
- Esta função apresenta o tabuleiro para o jogador específico, ou seja, mostra a posição dos barcos
e as posições onde foi acertado.

void print_tabuleiroAdversario(game *tabuleiro)
- Esta matriz, apesar de fazer print do tabuleiro, faz apenas print dos field_shots do adversário.
Isto significa que mostra ao jogador os tiros feitos e se acertou com 2 (a verde) e se falhou com
1 (a vermelho).

void create_matriz (game *tabuleiro)
- Cria a matriz de jogo, coloca o apontador de todas as posições a NULL e o field_shot a 0.

bool pode_inserir(Coordinate c, piece boat, game* tabuleiro)
- Esta função verifica se pode inserir um barco na posição escolhida. Caso o barco esteja fora
do tabuleiro ou esteja numa posição já ocupada por outro barco, retorna falso. Caso contrário, retorna 
true.

void inserir_barco(Coordinate c, piece* boat, game* tabuleiro)
- Esta função utiliza a função pode_inserir para verificar se pode inserir o barco. Caso possa,
coloca os apontadores do tabuleiro a apontar para o barco. Caso não possa, pede ao utilizador
coordenadas novas para tentar colocar o barco noutra posição.

bool pode_inserirRANDOMS(Coordinate c, piece boat, game* tabuleiro) &
void inserir_barcoRANDOMS(Coordinate c, piece* boat, game* tabuleiro)

- Ao contrário das funções anteriores, estas são quase iguais mas para o caso de usar o modo
random do jogo. O que foi alterado nestas funções foram os printfs e scanfs a pedir um novo
input, que no caso dos randoms não é necessário.

bool acertou(Coordinate cord, game* tabuleiro)

- Esta função verifica o resultado do tiro. Se acertou, se falhou ou se já tinha feito esse tiro.
Se o tiro for numa posição em que o field_shot não é 0, então é porque já dispararam nessa posição e retorna falso.
Se o tiro for numa posição onde o apont == NULL, é porque não existe barco nessa posição e retorna falso.
Se nenhuma destas condições se verificarem, então acertou num barco e retorna true.

bool isFinished(game* tabuleiro)
- A função verifica se o jogo já terminou para o tabuleiro de um jogador. A verificação é feita
ao ver se existe alguma posição em que o apont != NULL e nessa posição o field_shot == 0, ou seja,
se existe um barco nessa posição que ainda não foi acertado.

int return_randoms(int lower, int upper)
- Esta função apenas cria um número aleatório utilizado na versão random do jogo.

 ____________
|            |
|  bitmaps.c |  -> funções ligadas aos bitmaps
|____________|

bitmap create_rect(), bitmap create_quad(), bitmap create_barcoT(), bitmap create_barcoL(),
bitmap create_barcoU()
- Estas funções criam os bitmaps dos barcos, quando o utilizador os escolhe na main.c

bitmap rotate_90(bitmap matriz), bitmap rotate_180(bitmap matriz), bitmap rotate_270(bitmap matriz)
- Estas funções tratam das rotações dos barcos, também de acordo com o que o utilizador escolher.

void print_bitmap(bitmap matriz), void print_bitmapas(bitmap* matriz)
-Estas funções foram usadas para testar ao longo do jogo se o bitmap estava a ser criado e alterado
de forma correta.

bitmap switch_function(int opcao,int orientação), bitmap switch_functionRANDOMS(int opção,int orientação)
- O conteúdo destas funções estava inicialmente na main.c mas decidimos criar as funções para ter
um código mais simples na main. A primeira função recebe os valores que o utilizador recebeu como
input e escolhe qual o bitmap correto a retornar. No caso da segunda função, foi necessário alterar
por se tratar de números aleatórios. A única diferença é no valor da orientação/rotação,
que nos utilizadores corresponde a 0, 90, 180 e 270 e nos randoms corresponde a 0, 1,2 e 3.

 ____________
|            |
|  menus.c   |  -> menus utilizados ao longo do jogo
|____________|

Este ficheiro não necessita de muita explicação, tem apenas os menus que acontecem ao longo do jogo.
A única função a explicar será a void press_any_key() que é utilizada ao longo dos menus.c e da main.c
para o jogador clicar numa tecla para continuar a ação, dando assim tempo para ver o que está no ecrã
antes de efetuar um system ("clear").

FIM
_________________________________________________________________________________________
