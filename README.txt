
BEM VINDO AO BATTLESHIP GAME!

Neste documento de texto vou-lhe explicar como jogar o jogo da batalha naval criado por nós e para que fique esclarecido em relação a tudo.

A primeira coisa que vai ter de fazer para tere acesso ao jogo é compilá-lo através de gcc -Wall -o battleship battleship.c battleship.h menus.c bitmpas.c main.c e ja está (eu sei que é muita coisa mas vai valer a pena)!
Depois o que vai ter de fazer é correr o programa e para isso basta fazer: ./battleship 
Posteriormente a isto tudo vai deparar-se com um menu onde te são apresentadas 3 alternativas: 1) Iniciares o jogo, 2) Ires para o menu das instruçoes e por fim 3) Saires do jogo. 

Clique em 1 para começar o jogo. 
Insira o nome do primeiro jogador. 
Insira o nome do segundo jogador.
Insira o tamanho do tabuleiro (N*N) em que pretende jogar (este tem de ser entre 20*20 e 40*40).
Escolha 1 para jogar o jogo tradicional o 2 para jogar o jogo aleatoriamente. 
Se escolher 1:
Insira o número de barcos entre 5 e 16. 
É apresentado um nenu de todos os tipos de barcos, neste caso, barco quadrado, barco retangulo, barco em forma de T, barco em forma de de L e barco em forma de U e obrigatoriamente tem que escolher um barco de cada tipo. 
Escolha um tipo e depois as respetivas coordenadas para esse barco, a sua rotação tem se ser entre 0 e 270 e assim sucessivamente para todos os barcos que escolheu.
De seguida, será a vez do jogador 2 fazer exatamente a mesma coisa para os seus barcos.
Posteriormente vai ser apresentado outro menu para os dois jogadores começarem a jogar ao mesmo tempo, um contra o outro.
Vai ter de escolher entre 4 opções:
1) tente acertar no barco do adversario , ou seja, dá um tiro e tenta a tua sorte 
2) ver o seu tabuleiro
3) ver os seus tiros anteriores
4) sair do jogo 
Chegados a esta fase, é a altura perfeita para dar asas à sua imaginação e tentar vencer o jogo.
À medida que vai jogando, vai sendo informado quando erra ou acerta um tiro, quando afunda um barco do adversário, quando coloca uma coordenada inválida ou quando acerta no mesmo lugar mais que uma vez.
Quando acerta o barco do adversário passa cada posição no tabuleiro de 0 para 2 e quando erra fica com o número 1.
Vence o jogador que conseguir acertar em todos os barcos do adversário, sendo o objetivo principal do jogo afundar todos os barcos do adversário.

Se escolher 2, a única coisa diferente do jogo tradicional é que neste os tabuleiros de cada jogador são escolhidos aleatoriamente, sendo a forma de jogar igual.

Aproveite e divirta-se!


//Em primeiro lugar vais ter de escolher entre// 
//1) Iniciares o jogo//
//2) Ires para o menu das instruçoes// 
//3) Saires do jogo//


