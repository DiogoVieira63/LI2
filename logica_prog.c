#include "logica.h"
#include <stdio.h>
#include <stdlib.h>

int jogar(ESTADO *e, COORDENADA c) {
    int m,n;
    m = e->ultima_jogada.coluna;
    n = e->ultima_jogada.linha;
    CASA peca.atual = e->tab [m][n]; 
    if ((abs (c.linha-n) <= 1) && (abs (c.coluna -m) <= 1) && !(c.linha == n && c.coluna == m)){
            CASA peca.destino = e->tab [c.coluna][c.linha];
            if (peca.destino == VAZIA) {
                peca.destino = BRANCA;
                peca.atual = PRETA;
                m = c.coluna;
                n = c.linha;
            }
            else printf ("Jogada Impoossível.");
            printf("jogar %d %d\n", c.coluna, c.linha);
            return 1;
        }
    }
    return 0;
}