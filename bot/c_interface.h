/**
@file c_interface.h
Definição das funções que imprimem no ecrã
*/

#ifndef ___INTERFACE_H___
#define ___INTERFACE_H___
#include <stdio.h>
/**
\brief Imprime o tabuleiro no ecrã ou num ficheiro
@param e Apontador para o ESTADO
@param filename Apontador para o ficheiro
*/
void print_tabuleiro(ESTADO *e,FILE *filename);
/**
\brief Função que faz a conversão de char para CASA
@param n O char para ser convertido
@returns A casa devidamente convertida
*/
CASA char_to_peca (char n);
/**
\brief Faz a conversão de string para um inteiro
@param str A string para ser convertido
@returns O inteiro devidamente convertido
*/
int str_to_int (char* str );
/**
\brief Lê as jogadas de um ficheiro e guarda no ESTADO
@param fp O apontador para o ficheiro
@param e O apontador para o ESTADO
@param n O nr de jogadas que terá de ler
*/
void ler_jogadas (FILE *fp, ESTADO *e,int n);
/**
\brief Lê um tabuleiro de um ficheiro e muda o estdo consoante
@param e O apontador para o ESTADO
@param filename O apontador para o ficheiro
@returns 1, se a leitura for bem sucedida, 0 caso contrário
*/
int ler_tabuleiro (ESTADO *e,char *filename);
/**
\brief Imprime uma coordenada num ficheiro
@param c A COORNDENADA a ser imprimida
@param e Apontador para o ESTADO
*/
void print_coordenada (COORDENADA c,FILE *filename);
/**
\brief Imprime os movimentos do jogo num ficheiro
@param e Apontador para o ESTADO
@param filename Apontador para o Ficheiro
*/
void print_movs (ESTADO *e,FILE *filename);
/**
\brief Imprime uma linha de '-' no ecrã, diz respeito à apresentação do jogo
*/
void print_linha ();
/**
\brief Display da mensagem para o Vencedor no ecrã
@param e Apontador para o ESTADO
*/
void display_gameover (int n,ESTADO *e);
/**
\brief Imprime as mensagens de erro no ecrã
@param n Int para selecionar qual mensagem mostrar
*/
void print_erro (int n);
/**
\brief Imprime uma mensagem num ficheiro
@param n Int para selecionar qual mensagem mostrar
@param filename Apontador para o ficheiro
*/
void print_mensagem (int n,char *filename);
/**
\brief Imprime o resultado no ecrã
@param e Apontador para o ESTADO
@param n Para saber se é o resultado final ou não
*/
void print_resultado (ESTADO *e, int n);
/**
\brief Função que faz corresponder os nomes introduzidos pelo Utilizador ao respetivo Jogador
@param n Int para selecionar qual jogador se trata
@param nome Array com o nome introduzido pelo Utilizador
*/
char* nomes (int n,char nome []);
/**
\brief Imprime o prompt que contém a informação do nr total de jogadas, do nr de jogadas feitas por cada jogador e a informação relativamente ao jogador que irá jogar
@param e Apontador para o ESTADO
*/
void prompt (ESTADO *e);
/**
\brief Corresponde ao comando movs
@param e Apontador para o ESTADO
*/
void do_movs (ESTADO *e);
/**
\brief Corresponde ao comando Q
@param e Apontador para o ESTADO
*/
void do_quit (ESTADO *e);
/**
\brief Corresponde ao comando ler
@param filename Apontador para o ficheiro
@param e Apontador para o ESTADO
*/
void do_ler (char *filename,ESTADO *e);
/**
\brief Corresponde ao comando gr
@param fp Apontador para o ficheiro
@param fulename String com o nome do ficheiro onde se vai gravar
@param e Apontador para o ESTADO
*/
void do_gravar (FILE *fp,char*filename, ESTADO *e);
/**
\brief Função que efetua as jogadas
@param e Apontador para o ESTADO
@param c A COORDENADA onde se vai jogar 
@retunrns 0 se o jogo tiver chegado ao fim, 1 caso contrário
*/
int do_jogada (ESTADO *e, COORDENADA c);
/**
\brief Função que imprime as informações no final de cada jogo
@param e Apontador para o ESTADO
*/
int do_final (ESTADO *e);
/**
\brief Função que imprime as informações no inicio de cada jogo
@param e Apontador para o ESTADO
@param n O nr de jogos
*/
void do_inicio (ESTADO *e, int n);
/**
\brief Corresponde ao comando pos
@param e Apontador para o ESTADO
@param s A string que contém o nr para a posição que queremos
@returns 0, se o nr da posição for maior do que o nr max de jogadas, 1 caso contrário
*/
int do_pos (ESTADO *e,char *s);
/**
\brief Corresponde ao comando jog e jog2
@param e Apontador para o ESTADO
@param n Pode ser 1 ou 2, que corresponde ao jog e ao jog 2, respetivamente
@retunrns 0 se o jogo tiver chegado ao fim, 1 caso contrário
*/
int do_jog (ESTADO *e,int n);
/**
\brief Interpretador dos inputs do utilizador 
@param e Apontador para o ESTADO
@returns Um int caso seja executado devidamente ou não 
*/
int interpretador(ESTADO *e,int n);
#endif
