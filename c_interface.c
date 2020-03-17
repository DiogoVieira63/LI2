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
                    COORDENADA c = {coluna,linha};
                    CASA atual = obter_estado_casa (e,c);
                    putchar (atual);
                    coluna++;
                    putchar(' ');//não sei se é necessário.
                }
                printf ("\t|\n");
                linha++;
                nr--;
            }
}

void gravar_tabuleiro(ESTADO *e,FILE *fp) {
    char nr = '8'; 
    int linha = 1;
    fp = fopen ("tab_gr.txt", "w+");
    while (linha <= 8) {
        int coluna = 1;
        while (coluna <= 8) {
                COORDENADA c = {coluna,linha};
                CASA atual = obter_estado_casa (e,c);
                fputc(atual,fp);
                coluna++;
                fputc(' ',fp);//não sei se é necessário.
        }
            fprintf (fp,"\n");
            linha++;
            nr--;
        }
        fclose(fp);
}

void print_linha (){
    printf (" -------------------------------\n");
}

//Função que recebe o nr do jogador que ganhou para imprimir a mensagem de vencedor
void display_gameover (int n,ESTADO *e){
printf ("|-------------------------------|\n");
if (n==1)printf ("  PARABÉNS, %s!GANHASTE!\n",e->nomes.jogador1);
else printf ("  PARABÉNS, %s!GANHASTE!\n",e->nomes.jogador2);
printf ("|-------------------------------|\n");
}

void print_erro (int n){
    if (n == 1) printf ("ERRO: Coordenada inválida\n");
    else printf ("ERRO: Jogada Inválida \n");
}

void print_mensagem (){
 printf ("Tabuleiro gravado em tab_gr.txt\n");
}

char* nomes (int n,char nome []){
    if (n==1) printf("Escolha o nome \n(max10 e sem espaços)\n");
    printf("Jogador %d:",n);
    scanf("%10s",nome);
    return nome;
}

int interpretador(ESTADO *e) {
    FILE *fp;
    printf (" ---------JOGO RASTROS----------\n");
    mostrar_tabuleiro (e);
    char linha1[BUF_SIZE];    
    if(fgets(linha1, BUF_SIZE, stdin) == NULL)return 0; // necessário para que o input seja nulo ao entrar no while
    while (1){
        char linha[BUF_SIZE];
        char col[2], lin[2];
        print_linha ();
        printf ("->JOGADA %d - ",e->num_jogadas+1);
        if (e->jogador_atual == 1) printf ("%s",e->nomes.jogador1);
        else printf ("%s",e->nomes.jogador2);
        putchar (':');
        if(fgets(linha, BUF_SIZE, stdin) == NULL)return 0;
        if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {COORDENADA coord = {*col -'a'+1, 9-(*lin -'1'+1)};
        print_linha ();
        if (jogar(e, coord)) mostrar_tabuleiro(e);
        if (fim_do_jogo (e)) break;
        }
        else { if (sscanf (linha, "%[gr]",linha) ==1) {
            gravar_tabuleiro (e,fp);
            print_linha ();
            print_mensagem ();
        }
        else {
            print_linha ();
            print_erro (1);
            }
        }
        }
    return 1;
}
