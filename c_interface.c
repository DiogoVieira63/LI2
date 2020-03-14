#include "c_dados.h"
#include "logica_prog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

void mostrar_tabuleiro(ESTADO *e) {
    int linha = 1;
    while (linha <= 8) {
        int coluna = 1;
        while (coluna <= 8) {
            if (linha == 1 && coluna == 8) putchar('2'); // colocar o 2 no canto superior direito
            else if (linha == 8 && coluna == 1) putchar('1'); //colocar o 1 no canto inferior esquerdo
                else {
                    CASA atual = e->tab[coluna][linha];
                    if (atual == VAZIO) putchar('.');
                    else if (atual == PRETA) putchar('#');
                         else putchar('*');
                    }
                    coluna++;
                    putchar(' ');//não sei se é necessário.
                }
                putchar('\n');
                linha++;
            }
}

int interpretador(ESTADO *e) {
printf ("-JOGO RASTROS-\n");
while (1){
char linha[BUF_SIZE];
char col[2], lin[2];
printf ("JOGADA %d - ",e->num_jogadas+1);
printf ("Jogador ");
if (e->jogador_atual == 1) putchar ('1');
else putchar ('2');
putchar (':');
if(fgets(linha, BUF_SIZE, stdin) == NULL)return 0;
if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {COORDENADA coord = {*col -'a'+1, 9-(*lin -'1'+1)};
if (jogar(e, coord)) mostrar_tabuleiro(e);
if (fim_do_jogo (e)) break;
}
else (printf ("Coordenada inválida\n"));
}
return 1;
}