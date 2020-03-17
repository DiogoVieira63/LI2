#include "c_dados.h"
#include "logica_prog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

void mostrar_tabuleiro(ESTADO *e) {
    char nr = '8'; 
    int linha = 1;
    printf ("| \t  a b c d e f g h\t|\n");
    while (linha <= 8) {
        int coluna = 1;
        printf("|\t%c|",nr);
        while (coluna <= 8) {
            if (linha == 1 && coluna == 8) putchar('2'); // colocar o 2 no canto superior direito
            else if (linha == 8 && coluna == 1) putchar('1'); //colocar o 1 no canto inferior esquerdo
                else {
                    COORDENADA c = {coluna,linha};
                    CASA atual = obter_estado_casa (e,c);
                    if (atual == VAZIO) putchar('.');
                    else if (atual == PRETA) putchar('#');
                         else putchar('*');
                    }
                    coluna++;
                    putchar(' ');//não sei se é necessário.
                }
                printf ("\t|\n");
                linha++;
                nr--;
            }
}

void print_linha (){
printf (" -------------------------------\n");
}

//Função que recebe o nr do jogador que ganhou para imprimir a mensagem de vencedor
void display_gameover (int n){
printf ("|-------------------------------|\n");
printf ("|-PARABÉNS, JOGADOR %d!GANHASTE!-|\n",n);
printf ("|-------------------------------|\n");
}

void print_erro (int n){
if (n == 1) printf ("ERRO: Coordenada inválida\n");
else printf ("ERRO: Jogada Inválida \n");
}

int interpretador(ESTADO *e) {
    printf (" ---------JOGO RASTROS----------\n");
    mostrar_tabuleiro (e);
    while (1){
        char linha[BUF_SIZE];
        char col[2], lin[2];
        print_linha ();
        printf ("->JOGADA %d - ",e->num_jogadas+1);
        printf ("Jogador ");
        if (e->jogador_atual == 1) putchar ('1');
        else putchar ('2');
        putchar (':');
        if(fgets(linha, BUF_SIZE, stdin) == NULL)return 0;
        if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {COORDENADA coord = {*col -'a'+1, 9-(*lin -'1'+1)};
        print_linha ();
        if (jogar(e, coord)) mostrar_tabuleiro(e);
        if (fim_do_jogo (e)) break;
        }
        else {
            print_linha ();
            print_erro (1);
            }
        }
    return 1;
}