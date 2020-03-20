# Estrutura do ESTADO

O ESTADO permite-nos guardar a informação relativamente ao jogo. Guarda informação dos seus constituintes:

### 1. O Tabuleiro 
```c
CASA tab[8][8]
```

O Tabueleiro é constituído por 8 linhas e 8 colunas.

Por isso, a informação guardada do mesmo funciona como uma matriz (8x8).

E cada unidade corresponde a uma **CASA**, que está definida da seguinte forma:
```c
typedef enum {VAZIO ='.',
             BRANCA ='*', 
              PRETA = '#',
              POS1 = '1',
              POS2 = '2'} CASA;
```

##### 1. VAZIO
Quando a casa ainda não foi preenchida e por isso é uma opção válida como destino para a peça Branca.

##### 2. PRETA
Quando a casa já foi preenchida pela peça Branca, o que siginifica que não se pode voltar lá.

##### 3. BRANCA 
Só exite uma destas. Pois, é ela que é movimentada pelos dois jogadores. Alterando a CASA para PRETA sempre que é movimentada.
##### 4. POS1 
CASA vencedora para o Jogador 1.
##### 5. POS2 
CASA vencedora para o Jogador 2.

### 2. As Jogadas 
As jogadas efetuadas pelos jogadores
```c
JOGADAS jogadas
```
Sendo que, pode haver um máximo de 32 jogadas por jogador:
```c
typedef JOGADA JOGADAS[32];
```
E uma **JOGADA** está definida da seguinte forma:
```c
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
    } JOGADA;
```
### 3. A última jogada
```c
COORDENADA ultima_jogada;
```
Vai corresponder à posição atual da peça BRANCA.

Sendo que uma **COORDENADA** é definida da seguinte forma:
```c
typedef struct {
    int coluna;
    int linha;
    } COORDENADA;
```

### 4. O número de jogadas
```c
int num_jogadas;
```
O número total de jogadas até ao momento.

### 5. O jogador atual
```c
int jogador_atual;
```
Varia entre 1 e 2, para saber qual o jogador atual a jogar.

### 6. Os nomes
```c
NOMES nomes;
```
Os nomes introduzidos por cada jogador no ínicio do jogo.
Sendo que, **NOMES** está definido da seguinte forma:
```c
typedef struct {
    char jogador1 [11];
    char jogador2 [11];
    } NOMES;
```
Permite um máximo de 10 letras para cada nome.
