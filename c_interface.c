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
void print_coordenada (COORDENADA c,FILE *filename);

// NOT WORKING
/*
void ler_jogadas (FILE *fp, ESTADO *e,int n){
    int nr = (n+1)/2, i = 0;
    char str [10];
    init_jogadas (e);
    while (nr){
        modificar_num_jogadas (e,i);
        if ((n - i) > 1)fgets(str,10, fp);
        else fgets(str,7, fp);
        int k =4;
        printf("str = %s\n",str);
        printf("str[4]=%c  str[5]=%c str[7]=%c str[8]=%c \n",str[4],str[5],str[7],str[8]);
        while (n-i){
        COORDENADA c = {str[k]- 'a'+1,9-(str[k+1]-'1'+1)};
        guardar_jogada (e,c);
        k+=3;
        i++;
        }
        nr--;
    }
}
*/

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
                modificar_ultima_jogada (e,c);
            }
            if (atual == PRETA) contagem++;
            modificar_casa (e,c,atual);
            coluna++;
            }
            }
        }
    }
//    ler_jogadas (fp,e,contagem);
    if (contagem%2 == 0) modificar_jogador_atual (e,2); 
    else modificar_jogador_atual (e,1);
    modificar_num_jogadas (e,contagem);
    fclose(fp);
    }
    return 1;
}

char int_to_char (int n){
    char letra = 'a';
    while (n > 1){
        letra++;
        n--;
    }
    return letra;
}

void print_coordenada (COORDENADA c,FILE *filename){
    int linha = c.linha;
    char letra = int_to_char (c.coluna);
    fprintf(filename,"%c%d",letra,9-linha);
}

void print_movs (ESTADO *e,FILE *filename){
    int i = 1, n = 0, k = 1;
    while (k){
        COORDENADA c = obter_jogada (e,n++);
        if ( c.linha == 0 && c.coluna == 0) k = 0;
        else{
        if (n%2 != 0)fprintf (filename,"%02d: ",i++);
        print_coordenada (c,filename);
        if (n%2 != 0) fputc (' ',filename);
        else fputc ('\n',filename);
        }
    }
    if (!k && n%2 == 0) fputc ('\n',filename);
}

void print_linha (){
    printf (" -------------------------------\n");
}

//Função que recebe o nr do jogador que ganhou  e o estado para imprimir a mensagem de vencedor
void display_gameover (int n,ESTADO *e){
char * jogador = obter_nome_jogador (e,n);
printf ("|-------------------------------|\n");
printf ("  PARABÉNS, %s!GANHASTE!\n",jogador);
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
        switch (n){
        case 1: printf ("Tabuleiro gravado em %s\n",filename);
        break;
        case 2: printf("Tabuleiro lido do ficheiro %s\n",filename);
        break;
        case 3: printf ("Ficheiro %s não existe\n",filename);
        break;
        case 4: printf ("\tJOGO TERMINADO\n");
        break;
        }
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
    printf (" #%d-> JOGADA %d - ",nr,nr/2);
    char * player = obter_nome_jogador (e,jog);
    printf ("(J%d)%s",jog,player);
    putchar (':');
}
// COMANDOS DAS FUNÇÕES

void do_movs (ESTADO *e,FILE *fp){
    int nr = obter_num_jogadas(e);
    print_linha ();
    printf (" Lista de Movimentos (%d):\n",nr);
    print_linha ();
    printf ("    J1 J2\n");
    print_linha ();
    print_movs (e,fp);
}

void do_quit (){
    print_linha ();
    print_mensagem (4,"");
    print_linha();
}

void do_ler (char *filename,ESTADO *e){
    print_linha ();
    print_mensagem (2,filename);
    print_linha ();
    print_tabuleiro (e,stdout);

}

void do_gravar (FILE *fp,char*filename, ESTADO *e){
    fp = fopen (filename, "w+");
    print_tabuleiro (e,fp);
    print_movs (e,fp);
    fclose (fp);
    print_linha ();
    print_mensagem (1,filename);
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
            if (sscanf (linha, "gr %s",filename) ==1) do_gravar (fp,filename, e); //comando para gravar o tabuleiro num ficheiro 
        else { 
            if (sscanf (linha, "ler %s",filename) ==1) { //comando para ler o tabuleiro de um ficheiro
            if (ler_tabuleiro (e,filename)) do_ler (filename,e);
            else {
                print_linha ();
                print_mensagem (3,filename);
            }
            }
            else {
                if (strlen(linha) == 2 && sscanf (linha, "%[Q]",linha) ==1) {// comando para dar QUIT do jogo
                    i = 0; 
                    do_quit ();
                }
            else {
                 if (strlen(linha) == 5 && sscanf (linha, "movs%s",filename) != 0) do_movs (e,fp); //comando para mostar os movimentos
            else {
            print_linha ();
            print_erro (1);
            }
            }
            }
            }
        }
        }
    return 1;
}
