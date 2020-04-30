# GUIÃO 9

Neste guião foi-nos pedido para que implementássemos duas tarefas:

## 1. Criar um módulo  de listas ligadas genérico

Para isto, definimos uma LISTA da seguinte forma:

```c
typedef struct nodo {
   void* valor;
   struct nodo *proximo;
} NODO, *LISTA; 
```

O **valor** contém toda a informação do nodo e o **próximo** é o apontador para o nodo seguinte.

A informação que pretendemos guardar vai ter o nome de DADOS, e está definido da seguinte forma:

```c
typedef struct info{
   COORDENADA coord;
   double dist;
   int casas_livres;
}info, *DADOS;
```
Como vemos acima, guarda a informação relativamente:

- À COORDENADA, a qual a informação a seguir vai corresponder
- À distância, mais particularmente, a distância da COORDENADA à casa vencedora
- Ao número de casas livres disponíveis na COORDENADA


No seguimento da criação deste módulo, foi-nos pedido para criamos as seguintes funções, de modo a facilitar o processo:

```c
LISTA criar_lista();
LISTA insere_cabeca(LISTA L, void *valor);
void *devolve_cabeca(LISTA L);
LISTA proximo(LISTA L);
LISTA remove_cabeca(LISTA L);
int lista_esta_vazia(LISTA L);
```

## 2. Implementação do comando jog

O comando jog tem como função, efetuar uma jogada pelo jogador atual.

Para isso, a primeira coisa que fizemos foi criar a função:

```c
LISTA posicoes_possiveis (ESTADO *e);
```

Que cria uma LISTA, com todas as posições possíveis de se jogar.

Agora o objetivo é escolher a melhor posição para se jogar e para isso, criamos a função:

```c
COORDENADA melhor_jogada (LISTA l, ESTADO *e);
```

Esta função decide a COORDENADA em que jogar, passando por estes processos:

- Se houver uma posição que me faça ganhar o jogo, essa é a posição escolhida.

```c 
int can_I_win (DADOS dados,ESTADO *e)
```
- Se na posição onde jogarmos, o adversário tiver hipótese de vencer. Essa posição é ignorada.
```c
int can_he_win  (ESTADO *e)
```
- Escolher a posição mais perto da casa vencedora (comparando as distancias guardadas em cada nodo dos DADOS).











