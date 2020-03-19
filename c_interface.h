/**
@file c_interface.h
Definição das funções que imrimem no ecrã
*/

#ifndef ___INTERFACE_H___
#define ___INTERFACE_H___
#include <stdio.h>
/**
\brief Interpretador dos inputs do utilizador 
@param e Apontador para o ESTADO
@returns Um int caso seja executado devidamente ou não 
*/
int interpretador(ESTADO *e);
/**
\brief Imprime o tabuleiro no ecrã ou num ficheiro
@param e Apontador para o ESTADO
@param filename Apontador para p ficheiro
*/
void print_tabuleiro(ESTADO *e,FILE *filename) ;
/**
\brief Display da mensagem para o Vencedor
@param e Apontador para o ESTADO
*/
void display_gameover (int n,ESTADO *e);
/**
\brief Display de mensagens de erro
@param m Int para selecionar qual mensagem mostrar
*/
void print_erro (int n);
/**
\brief Função que faz corresponder os nomes introduzidos pelo Utilizador ao respetivo Jogador
@param n Int para selecionar qual jogador se trata
@param nome Array com o nome introduzido pelo Utilizador
*/
char* nomes (int n,char nome []);
#endif