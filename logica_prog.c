#include "logica.h"
#include <stdio.h>
#include <stdlib.h>

int jogar(ESTADO *e, COORDENADA c) {
    int m,n;
    m = e->ultima_jogada.coluna;
    n = e->ultima_jogada.linha;
    if (((abs (m - c.coluna) == 1) && (abs (n - c.linha) == 1)) || ((abs (m - c.coluna) == 0) && (abs (n - c.linha) == 1)) || ((abs (m - c.coluna) == 1) && (abs (n - c.linha) == 0))) {
        if (c == VAZIO) { //Ainda falta corrigir o erro nesta linha.
            printf("jogar %d %d\n", c.coluna, c.linha);
            return 1;
        }
    }
    return 0;
}
