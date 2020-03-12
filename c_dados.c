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


// Estruturas de dados (devem ser colocadas no módulo correto da camada dos dados)
    
