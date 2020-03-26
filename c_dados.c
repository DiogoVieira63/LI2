#include "c_dados.h"
#include "c_interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void tab_inicial (CASA tab [8][8]){
    for (int linha = 1;linha <= 8;linha++){
    int coluna = 1;
        while (coluna <= 8) {
            tab [linha] [coluna++] = VAZIO;
        }
    }  
    tab [5][4]= BRANCA; 
    tab [1][8]= POS1;
    tab [8][1]= POS2;
}

void init_jogadas (ESTADO *e){
    int i = 0;
    COORDENADA c = {0,0};
    while (i < 64 ){
        e->jogadas [i] = c;
        i++;
    }
}

//Esta função deverá criar um estado vazio (com o tabuleiro inicializado)
ESTADO *inicializar_estado() {
ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
e->jogador_atual = 1;
e->num_jogadas = 0;
tab_inicial (e->tab);
init_jogadas (e);
e->ultima_jogada.linha = 4;
e->ultima_jogada.coluna = 5;
return e;
}

int obter_num_jogadas (ESTADO *e){
    return e->num_jogadas;
}

char* obter_nome_jogador (ESTADO *e,int n){
    if ( n == 1) return e->nomes.jogador1;
    else return e->nomes.jogador2;
}

CASA obter_estado_casa(ESTADO *e, COORDENADA c){
    return e->tab[c.coluna][c.linha];
}
int obter_jogador_atual (ESTADO *e){
    return e->jogador_atual;
}


void alterar_estado_casa (ESTADO *e,COORDENADA c){
    int col = c.coluna, lin = c.linha;
    CASA atual = (e->tab[col][lin] );
    switch (atual){
    case VAZIO:
        e->tab[col][lin] = BRANCA;
        break;
    case BRANCA:
        e->tab[col][lin] = PRETA;
        break;
    case PRETA:
        e->tab[col][lin] = PRETA;
        break;
    }
}

void modificar_casa (ESTADO *e,COORDENADA c,CASA casa){
    int col = c.coluna, lin = c.linha;
    e->tab [col][lin] = casa;
}

void alterar_num_jogadas (ESTADO *e){
    e->num_jogadas++;
}

void alterar_jogador_atual (ESTADO *e){
    if (e->jogador_atual == 1)e->jogador_atual++;
    else e->jogador_atual--;
}

void guardar_jogada (ESTADO *e,COORDENADA c){
int nr = e->num_jogadas;
e->jogadas[nr] = c;
}

void modificar_jogador_atual (ESTADO *e,int n){
    e->jogador_atual = n;
}

void modificar_num_jogadas (ESTADO *e, int n){
    e->num_jogadas = n;
}

COORDENADA obter_ultima_jogada (ESTADO *e){
    return e->ultima_jogada;
}

void modificar_ultima_jogada (ESTADO *e,COORDENADA c){
    e->ultima_jogada = c;
}

COORDENADA obter_jogada (ESTADO *e,int n){
    return e->jogadas[n];
}

void muda_vitorias (ESTADO *e, int n){
    if (n == 1) e->vitorias.j1+=1;
    else e->vitorias.j2+=1;
}

void init_estado (ESTADO *e){
    COORDENADA c = {5,4};
    init_jogadas (e);
    tab_inicial(e->tab);
    modificar_num_jogadas (e,0);
    modificar_ultima_jogada (e,c);
    modificar_jogador_atual (e,1);
}

int obter_vitoria (ESTADO *e, int n){
    if (n==1)return e->vitorias.j1;
    else return e->vitorias.j2;
}