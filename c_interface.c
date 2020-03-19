#include "c_dados.h"
#include "logica_prog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024
//Imprimir o tabuleiro no ecrã ou num ficheiro
void print_tabuleiro(ESTADO *e,FILE *filename) {
    int i = 0; //Quando é para gravar num ficheiro
    if (filename == stdout) i = 1; // Quando é para imprimir no ecrã
    char nr = '8'; 
    if (i) fprintf (filename,"| \t  a b c d e f g h\t|\n");
    for (int linha = 1;linha <= 8;linha++) {
        if (i) fprintf(filename,"|\t%c|",nr);
        for (int coluna = 1;coluna <= 8;coluna++) {
                    COORDENADA c = {coluna,linha};
                    CASA atual = obter_estado_casa (e,c);
                    fputc (atual,filename);
                    if (i) fputc(' ',filename);//não sei se é necessário.
                }
                if (i) fprintf (filename,"\t|");
                fputc('\n',filename);
                nr--;
            }
}

//Convesor de char em CASA, função auxiliar para a ler_tabuleiro
CASA char_to_peca (char n){
    switch (n){
        case '#': 
        return PRETA;
        break;
        case '*':
        return BRANCA;
        break;
        case '.': 
        return VAZIO;
        break;
        case '1':
        return POS1;
        break;
        case '2':
        return POS2;
        break;
    }
}


//Função que, caso o ficheiro exista,lê o que está no ficheiro e chama funções para alterar o estado conforme o tabuleiro do ficheiro.
//Caso não exista, dá return 0
int ler_tabuleiro (ESTADO *e,char *filename){
    int contagem = 0;
    FILE *fp;
    char str[8]; 
    char peca;
    fp = fopen (filename, "r");
    if (fp == NULL) return 0;
    else{
    for (int linha = 1; linha <= 8; linha++){
        int coluna = 1;
        while (coluna <= 8){
            if(fgets(str,8, fp) == NULL) break;
            else {
            for (int i = 0;str[i];i++){
            CASA atual = char_to_peca (str[i]);
            COORDENADA c ={coluna,linha};
            if (atual == BRANCA) {
                e->ultima_jogada = c;
                contagem++;
            }
            if (atual == PRETA) contagem++;
            modificar_casa (e,c,atual);
            coluna++;
            }
            }
        }
    }
    if (contagem%2 == 0) modificar_jogador_atual (e,2);
    else modificar_jogador_atual (e,1);
    modificar_num_jogadas (e,contagem);
    fclose(fp);
    }
    return 1;
}

void print_linha (){
    printf (" -------------------------------\n");
}

//Função que recebe o nr do jogador que ganhou  e o estado para imprimir a mensagem de vencedor
void display_gameover (int n,ESTADO *e){
printf ("|-------------------------------|\n");
if (n==1)printf ("  PARABÉNS, %s!GANHASTE!\n",e->nomes.jogador1);
else printf ("  PARABÉNS, %s!GANHASTE!\n",e->nomes.jogador2);
printf ("|-------------------------------|\n");
}

//Função que dado um int, imprime uma mensagem de erro
void print_erro (int n){
    printf ("ERRO: ");
    if (n == 1) printf ("Coordenada inválida\n");
    else printf ("Jogada Inválida \n");
}

//Imprime uma mensagem no ecrã, conforme o int que recebe
void print_mensagem (int n,char *filename){
if (n==1)printf ("Tabuleiro gravado em %s\n",filename);
else if ( n==2)printf("Tabuleiro lido do ficheiro %s\n",filename);
else printf ("Ficheiro %s não existe\n",filename);
}

//Função que dado o nr do jogador, e uma string. Faz scanf do nome que o utilzador responder e coloca na string.
char* nomes (int n,char nome []){
    if (n==1) printf("Escolha o nome \n(max10 e sem espaços)\n");
    printf("Jogador %d:",n);
    scanf("%10s",nome);
    return nome;
}

void prompt (ESTADO *e){
    int nr = obter_num_jogadas (e), jog = obter_jogador_atual(e);
    printf ("#%d-> JOGADA %d - ",nr,nr/2);
    char * player = obter_nome_jogador (e,jog);
    printf ("(J%d)%s",jog,player);
    putchar (':');
}

int interpretador(ESTADO *e) {
    int i = 1;
    FILE *fp;
    fp = stdout;
    printf (" ---------JOGO RASTROS----------\n");
    print_tabuleiro (e,fp);
    char linha1[BUF_SIZE]; 
    char filename [BUF_SIZE];   
    if(fgets(linha1, BUF_SIZE, stdin) == NULL)return 0; // necessário para que o input seja nulo ao entrar no while
    while (i){
        fp = stdout;
        char linha[BUF_SIZE];
        char col[2], lin[2];
        print_linha ();
        prompt (e);
        if(fgets(linha, BUF_SIZE, stdin) == NULL)return 0;
        if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) { //comando para efetuar uma jogada
        COORDENADA coord = {*col -'a'+1, 9-(*lin -'1'+1)}; 
        print_linha ();
        if (jogar(e, coord)) print_tabuleiro(e,fp);
        if (fim_do_jogo (e)) i = 0;
        }
        else { 
            if (sscanf (linha, "gr %s",filename) ==1) {//comando para gravar o tabuleiro num ficheiro
            fp = fopen (filename, "w+");
            print_tabuleiro (e,fp);
            fclose (fp);
            print_linha ();
            print_mensagem (1,filename);
        }
        else { 
            if (sscanf (linha, "ler %s",filename) ==1) {//comando para ler o tabuleiro de um ficheiro
            if (ler_tabuleiro (e,filename)){
            print_linha ();
            print_mensagem (2,filename);
            print_linha ();
            print_tabuleiro (e,stdout);
            }
            else {
                print_linha ();
                print_mensagem (3,filename);
            }
            }
            else {
                if (strlen(linha) == 2 && sscanf (linha, "%[Q]",linha) ==1) i = 0; // comando para dar QUIT do jogo
            else {
            print_linha ();
            print_erro (1);
            }
            }
            }
        }
        }
    return 1;
}