# GUIÃO 5

Para este guião, tivemos de criar os módulos para o projeto. Dividimos os módulos em 3 partes:

- #### CAMADA DE DADOS

Este módulo contém a função que inicializa o estado como também toda a infomação relativamente à organização do ESTADO e os seus constituintes. Colocamos também neste módulo as funções que alteram os constituintes do ESTADO.

- #### LÓGICA DO PROGRAMA

Neste módulo está tudo aquilo relacionado com a lógica do jogo faz parte a função jogar, que recebe um ESTADO e uma COORDENADA,e se a jogada for válida, executa a jogada e altera devidamente o ESTADO. Caso contrário, chama uma função para imprimir uma mensagem de erro.

- #### CAMADA DE INTERFACE

Neste módulo, está tudo aquilo que o utilizador vê no ecrã. Este módulo tem a função de imprimir o que faz parte do jogo, desde o tabuleiro a mensagens de erro. Tem também o interpretador que recebe a infotmação do utilizar e consoante a mesma, chama a função jogar, se o utilizador tiver introduzido uma coordenada válida, ou seja, uma letra entre [a-h] e um número entre [1-8].
