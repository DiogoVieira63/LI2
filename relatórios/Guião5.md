# GUIÃO 5

Para este guião, tivemos de criar os módulos para o projeto. Dividimos os módulos em 3 partes:

- ## [CAMADA DE DADOS](https://github.com/JoseDiogoMartinsVieira/LI2PL3G2/blob/master/c_dados.c)

Este módulo contém a função que inicializa o estado:
```c
ESTADO *inicializar_estado()
```
como também toda a infomação relativamente à organização do ESTADO e os seus constituintes.

Colocamos também neste módulo as funções que obtém e alteram os constituintes do ESTADO.

- ### Funções que obtém os constituintes do estado:
#### 1.  O estado de uma casa
```c
CASA obter_estado_casa (ESTADO *e, COORDENADA c)
```
#### 2. A coordenada da úlitma jogada
```c
COORDENADA obter_ultima_jogada (ESTADO *e)
``` 
#### 3. O jogador atua
```c
int obter_jogador_atual (ESTADO *e)
```
#### 4. O nome do jogador
```c
char* obter_nome_jogador (ESTADO *e,int n)
```
#### 5. O número de jogadas
```c
int obter_num_jogadas (ESTADO *e)
```

- ### Funções que alteram constituintes do estado, segundo a lógica natural do jogo:

#### 1. O Jogador atual
```c
void alterar_jogador_atual (ESTADO *e)
```
#### 2. O nr de jogadas
```c
void alterar_num_jogadas (ESTADO *e) 
```
#### 3. O estado de uma casa
```c
void alterar_estado_casa (ESTADO *e,COORDENADA c)
```

- ### Funções que modificam constituintes do estado, para o constituinte recebido no segundo argumento:

#### 1. O estado de uma casa
```c
void modificar_casa (ESTADO *e,COORDENADA c,CASA casa)
```
#### 2. O jogador atual
```c
void modificar_jogador_atual (ESTADO *e,int n)
```
#### 3. O número de jogadas
```c
void modificar_num_jogadas (ESTADO *e, int n)
```
#### 4. A última jogada
```
void modificar_ultima_jogada (ESTADO *e,COORDENADA c)
```

- ## [LÓGICA DO PROGRAMA](https://github.com/JoseDiogoMartinsVieira/LI2PL3G2/blob/master/logica_prog.c)

Neste módulo está tudo aquilo relacionado com a lógica do jogo,faz parte a função:
```c
int jogar (ESTADO *e, COORDENADA c)
```


- ## [CAMADA DE INTERFACE](https://github.com/JoseDiogoMartinsVieira/LI2PL3G2/blob/master/c_interface.c)

Neste módulo, encontra-se a função que permite a interação com o utilizador:
### O Interpretador
Vai recolher a informação escrita pelo o utilizador e consoante a mesma, vai chamar as funções de direito.

### Tudo o  que o utlizador vê no ecrã:

#### 1. O tabuleiro
```c
void mostar_tabueiro (ESTADO *e)
```

#### 2. As mensagens de erro
```c
void print_erro (int n)
```


