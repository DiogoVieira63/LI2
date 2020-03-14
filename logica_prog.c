#include "c_dados.h"
#include <stdio.h>
#include <stdlib.h>

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
            printf("jogar %c%d\n", converter (c.coluna), 9-(c.linha));//ajustado conforme o interpretador, em atualização
            return 1;
        }
    else (printf ("Jogada Impossível \n"));
    return 0;
}

