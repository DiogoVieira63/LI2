#include "c_dados.h"
#include <stdio.h>
#include <stdlib.h>

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

int jogar(ESTADO *e, COORDENADA c) {
    int m,n;
    m = e->ultima_jogada.coluna;
    n = e->ultima_jogada.linha; 
    CASA peca_atual = e->tab [m][n]; 
    if ((abs (c.linha-n) <= 1) && (abs (c.coluna -m) <= 1) && !(c.linha == n && c.coluna == m)){
            CASA peca_destino = e->tab [c.coluna][c.linha];
            if (peca_destino == VAZIO) {
            alterar_estado_casa (e,c);
            alterar_estado_casa (e,e->ultima_jogada);
            alterar_num_jogadas (e);
            alterar_jogador_atual (e);
            e->ultima_jogada =c;
            }
            else printf ("Jogada Impoossível. \n");
            printf("jogar %d %d\n", c.coluna, c.linha);
            return 1;
        }
    else (printf ("Jogada Impossível \n"));
    return 0;
}