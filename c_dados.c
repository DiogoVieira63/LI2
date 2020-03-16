#include "c_dados.h"
#include <stdio.h>
#include <stdlib.h>


void tab_inicial (CASA tab [8][8]){
int linha = 1;
while (linha <= 8){
int coluna = 1;
while (coluna <= 8) tab [linha] [coluna++] = VAZIO;
linha++;
}
tab [5][4]= BRANCA; 
}

//Esta função deverá criar um estado vazio (com o tabuleiro inicializado)
ESTADO *inicializar_estado() {
ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
e->jogador_atual = 1;
e->num_jogadas = 0; 
/*
e->jogadas->jogador1.linha = 0;
e->jogadas->jogador1.coluna = 0;
e->jogadas->jogador2.linha = 0;
e->jogadas->jogador2.coluna = 0;
*/
tab_inicial (e->tab);
e->ultima_jogada.linha = 4;
e->ultima_jogada.coluna = 5;
return e;
}

CASA obter_estado_casa(ESTADO *e, COORDENADA c){
return e->tab[c.coluna][c.linha];
}

ESTADO* alterar_estado_casa (ESTADO *e,COORDENADA c){
int li = c.linha,col = c.coluna;
if (e->tab [col][li] == VAZIO) e->tab [col][li] = BRANCA;
else e->tab [col][li] = PRETA;
return e;
}

ESTADO* alterar_num_jogadas (ESTADO *e){
e->num_jogadas++;
return e;
}

ESTADO* alterar_jogador_atual (ESTADO *e){
if (e->jogador_atual == 1)e->jogador_atual++;
else e->jogador_atual--;
return e;
}

ESTADO* guardar_jogada (ESTADO *e,COORDENADA c){
int nr = e->num_jogadas;
JOGADA jog = e->jogadas[nr];
int atual = e->jogador_atual;
if (atual == 1) jog.jogador1 = c;
else  jog.jogador2 = c;
return e;
}
