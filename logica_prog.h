/**
@file logica_prog.h
Funções que dizem respeito à lógica do programa
*/

#ifndef ___LOGICA_H___
#define ___LOGICA_H___


/**
\brief Função que faz a jogada dada pela coordenada
Esta função verifica se a a jogada da coordenada dada será válida. Caso não seja, chama a devida função para mostrar uma mensagem de erro. Caso seja, chama funções para alterarem o estado devidamente.
@param e Apontador para o ESTADO
@param c A COORDENADA
*/
int jogar(ESTADO *e, COORDENADA c);
/**
\Função que verifica se naquele estado o jogo chegou ao fim.
@param e Apontador para o ESTADO
@returns Devolve 1, caso o jogo tenha chegado ao fim, caso contrário, devolve 0.
*/
int fim_do_jogo (ESTADO* e);
//COORDENADA melhor_casa (ESTADO *e, COORDENADA c);
#endif