/**
@file c_interface.h
Definição das funções que imrimem no ecrã
*/

#ifndef ___INTERFACE_H___
#define ___INTERFACE_H___

/**
\brief Interpretador dos inputs do utilizador 
@param e Apontador para o ESTADO
@returns Um int caso seja executado devidamente ou não 
*/
int interpretador(ESTADO *e);
/**
\brief Imprime o tabuleiro
@param e Apontador para o ESTADO
*/
void mostrar_tabuleiro(ESTADO *e);
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
char* nomes (int n,char nome []);
#endif