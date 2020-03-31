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
int str_to_int (char* str ){
    int length = strlen (str), nr;
    if (length == 1) nr = str[0]- '1' + 1;
    else nr = (str[0] - '1' + 1) * 10 + str[1] - '1' +1;
    return nr;
}

// ler as jogadas do ficheiro
void ler_jogadas (FILE *fp, ESTADO *e,int n){
    int nr = (n+1)/2; //nr de linhas 
    int i = 0; //para percorrer o nr de jogadas
    char str [11];
    init_jogadas (e);//para dar reset nas jogadas
    modificar_num_jogadas (e,0);
    if (fgets(str,11, fp)== NULL);//para ignorar a primeira linha 
    while (fgets(str,11, fp)!= NULL){ // para percorrer o ficheiro linha por linha até chegar a uma linha vazia
        int k =4; //posição da coordenada na string
        int f; // para saber quantas coordenadas tem na linha, 1 ou 2
        if (n - i> 1) f = 2;
        else f = 1;
        while (f){
        COORDENADA c = {str[k]- 'a'+1,9-(str[k+1]-'1'+1)};
        guardar_jogada (e,c); // para guardar a jogada no ESTADO
        k+=3;
        i++;
        modificar_num_jogadas (e,i); // para modificar o nr de jogadas
        f--;
        }
        nr--;
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
                modificar_ultima_jogada (e,c);
            }
            if (atual == PRETA) contagem++;
            modificar_casa (e,c,atual);
            coluna++;
            }
            }
        }
    }
    ler_jogadas (fp,e,contagem); // para ler as jogadas do ficheiro, que se encontram após o tabuleiro
    if (contagem%2 == 0) modificar_jogador_atual (e,1); 
    else modificar_jogador_atual (e,2);
    modificar_num_jogadas (e,contagem);
    modificar_max_jogadas (e,contagem);
    fclose(fp);
    }
    return 1;
}

// FUNÇÕES DE IMPRIMIR

void print_coordenada (COORDENADA c,FILE *filename){
    int linha = c.linha;
    char letra = c.coluna+96; //ascii code
    fprintf(filename,"%c%d",letra,9-linha);
}

void print_movs (ESTADO *e,FILE *filename){
    int i = 1, n = 0, k = 1, jogadas = obter_num_jogadas (e);
    while (k){
        COORDENADA c = obter_jogada (e,n);
        if (jogadas == n++) k = 0;
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
    if (n == 2) printf ("Jogada Inválida \n");
    if (n == 3) printf ("Comando inválido\n"); 
    if (n == 4) printf ("Posição desconhecida\n");
}

//Imprime uma mensagem no ecrã, conforme o int que recebe
void print_mensagem (int n,char *filename){
    if (n == 1) printf ("Tabuleiro gravado em %s\n",filename);
    if (n == 2) printf("Tabuleiro lido do ficheiro %s\n",filename);
    if (n == 3) printf ("Ficheiro %s não existe\n",filename);
}

void print_resultado (ESTADO *e, int n){
    char * nome1 = obter_nome_jogador (e,1);
    char * nome2 = obter_nome_jogador (e,2);
    int nr1= strlen(nome1), nr2 = strlen (nome2), total = 31- nr1- nr2;
    if (n) printf ("\n\t ");
    else printf ("\t   ");
    printf ("RESULTADO ");
    if (n) printf("FINAL\n");
    putchar ('\n');
    print_linha();
    printf(" %s",nome1);
    printf("%*c", total, ' '); //nr de espaços entre cada nome
    printf("%s\n",nome2);
    printf(" J1----->   %d   X   %d   <-----J2\n",obter_vitoria (e,1),obter_vitoria (e,2));
    print_linha ();
}

//Função que dado o nr do jogador, e uma string. Faz scanf do nome que o utilzador responder e coloca na string.
char* nomes (int n,char nome []){
    if (n==1) printf(" Escolha o nome \n(max10 e sem espaços)\n");
    printf(" Jogador %d:",n);
    scanf("%10s",nome);
    print_linha ();
    return nome;
}

void prompt (ESTADO *e){
    int nr = obter_num_jogadas (e), jog = obter_jogador_atual(e);
    print_linha ();
    printf (" #%d-> JOGADA %d - ",nr,nr/2);
    char * player = obter_nome_jogador (e,jog);
    printf ("(J%d)%s",jog,player);
    putchar (':');
}
// COMANDOS DAS FUNÇÕES

void do_movs (ESTADO *e){
    int nr = obter_num_jogadas(e);
    print_linha ();
    printf (" Lista de Movimentos (%d):\n",nr);
    print_linha ();
    printf ("    J1 J2\n");
    print_linha ();
    print_movs (e,stdout); // imprime os movimentos no ecrã
}

void do_quit (ESTADO *e){
    print_linha ();
    print_resultado (e,1);
    putchar ('\n');
    printf ("\t JOGO TERMINADO\n");
    putchar ('\n');
    print_linha();
}

void do_ler (char *filename,ESTADO *e){
    print_linha ();
    print_mensagem (2,filename);
    print_linha ();
    print_tabuleiro (e,stdout); //imprime o tabuleiro lido no ecrã

}

void do_gravar (FILE *fp,char*filename, ESTADO *e){
    fp = fopen (filename, "w+");
    print_tabuleiro (e,fp); // imprimir o tabuleiro no ficheiro
    fputc ('\n',fp);
    print_movs (e,fp); // imprimir os movimentos no tabuleiro
    fclose (fp);
    print_linha ();
    print_mensagem (1,filename);
}

int do_jogada (ESTADO *e, COORDENADA c){
    print_linha ();
    if (jogar(e, c)) print_tabuleiro(e,stdout);// imprime o tabuleiro no ecrã, se a jogada for válida
    if (fim_do_jogo (e)) return 0;   
    else return 1;
}

int do_final (ESTADO *e){
    char linha1 [BUF_SIZE];
    print_resultado (e,0);
     while (1){
        printf(" DESFORRA \t  SAIR DO JOGO\n     |\t\t\t|\n DIGITE N\t    DIGITE Q\n");
        printf("->");
        if(fgets(linha1, BUF_SIZE, stdin) == NULL)return 0;
        if(strlen(linha1) == 2 && sscanf(linha1, "%[Q]", linha1) == 1) {
            do_quit (e);
            return 0;
        }
        else if(strlen(linha1) == 2 && sscanf(linha1, "%[N]", linha1) == 1){
            print_linha ();
            return 1;
        }
        else {
            print_linha ();
            print_erro (3);
            print_linha ();
        }
        }
}

void do_inicio (ESTADO *e, int n){
    char * nome1 = obter_nome_jogador (e,1);
    char * nome2 = obter_nome_jogador (e,2);
    int nr1= strlen(nome1), nr2 = strlen (nome2), total = 31- nr1- nr2;
    printf ("|-------RASTROS: JOGO Nº%d-------|\n",n);
    print_linha();
    printf(" %s",nome1);
    printf("%*c", total, ' '); //nr de espaços entre cada nome
    printf("%s\n",nome2);
    printf(" J1----->   %d   X   %d   <-----J2\n",obter_vitoria (e,1),obter_vitoria (e,2));
    print_linha ();
}


int do_pos (ESTADO *e,char *s){
    int nr = str_to_int (s) * 2;
    int i = 0;
    int max = obter_max_jogadas (e);
    if (nr > max || nr < 0) {
        print_linha ();
        print_erro (4);
        return 0;
    }
    else {
    tab_inicial (e);
    COORDENADA inicial = {5,4}; 
    modificar_casa (e,inicial,PRETA);
    while (i < nr) {
        COORDENADA c = obter_jogada (e,i);
        modificar_casa (e,c,PRETA);
        i++;
    }
    if (nr == 0) {
    COORDENADA c = {5,4};
    tab_inicial(e);
    modificar_num_jogadas (e,0);
    modificar_ultima_jogada (e,c);
    modificar_jogador_atual (e,1);
    }
    else {
        modificar_num_jogadas (e,nr);
        COORDENADA c = obter_jogada (e,nr-1);
        modificar_casa (e,c,BRANCA);
        modificar_ultima_jogada (e,c);
        modificar_jogador_atual (e,1);
    }
    }
    return 1;
}
/*
int do_jog (ESTADO *e){
    COORDENADA c = obter_ultima_jogada (e);
    COORDENADA j = melhor_casa (e,c);
    int i = do_jogada (e,j);
    return i;
}
*/

int interpretador(ESTADO *e, int n) {
    int i = 1;
    FILE *fp;
    fp = stdout;
    do_inicio (e,n);
    print_tabuleiro (e,fp);
    char linha1[BUF_SIZE]; 
    char filename [BUF_SIZE];   
    if (n==1)if(fgets(linha1, BUF_SIZE, stdin) == NULL)return 0; // necessário para que o input seja nulo ao entrar no while no 1º Jogo
    while (i){
        fp = stdout; // ecrã
        char linha[BUF_SIZE];
        char col[2], lin[2];
        prompt (e);
        if(fgets(linha, BUF_SIZE, stdin) == NULL)return 0; // Dar scan do input do utilizador
        if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) { //comando para efetuar uma jogada
        COORDENADA coord = {*col -'a'+1, 9-(*lin -'1'+1)}; 
        i = do_jogada (e,coord);
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
                    do_quit (e);
                    return 0;
                }
            else {
                 if (strlen(linha) == 5 && sscanf (linha, "movs%s",filename) != 0) do_movs (e); //comando para mostar os movimentos
            else {
                if (sscanf (linha, "pos %s",filename) ==1){
                    if (do_pos (e,filename)) print_tabuleiro (e,stdout);
                }
            /*else {
                if (strlen(linha) == 4 && sscanf (linha, "jog%s",filename) != 0) i = do_jog (e);*/
            else  {
            print_linha ();
            print_erro (1);
            }
            }
            }
//            }
            }
            }
        }
        }
        return (do_final (e));
    return 1;
}
