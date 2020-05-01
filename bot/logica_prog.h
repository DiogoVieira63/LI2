/**
@file logica_prog.h
Funções que dizem respeito à lógica do programa
*/

#ifndef ___LOGICA_H___
#define ___LOGICA_H___


/**
\Função que verifica há casas livres para a jogada atual
@param e Apontador para o ESTADO
@returns Devolve 1, caso haja casas livres, caso contrário, devolve 0.
*/
int ha_nao_casas_livres (ESTADO *e);
/**
\Função que verifica se naquele estado o jogo chegou ao fim.
@param e Apontador para o ESTADO
@returns Devolve 1, caso o jogo tenha chegado ao fim, caso contrário, devolve 0.
*/
int fim_do_jogo (ESTADO* e);
/**
\brief Verifica se uma coordenada é válida para se jogar
@param e Apontador para o ESTADO
@param c COORDDENADA a verificar
@returns 1 se a COORDENADA for válida, 0 caso contrário
*/
int isValid (ESTADO *e,COORDENADA c);

/**
\brief Calcula a distância de uma COORDENADA até à casa vencedora
@param c A COORDENADA ponto inicial
@param n Um int correspondente à casa que se pretende saber, 1 ou 2
@returns A distancia devidamente calculada
*/
double distancia (COORDENADA c, int n);
/**
\brief Conta as casas livrs de uma determindada COORDENADA
@param e Apontador para o ESTADO
@param atual A COORDENDADA escolhida
@returns O nr de casas livres para aquela COORDENADA
*/
int conta_casas_livres (ESTADO *e, COORDENADA atual);
/**
\brief Função que faz a jogada dada pela coordenada
Esta função verifica se a a jogada da coordenada dada será válida. Caso não seja, chama a devida função para mostrar uma mensagem de erro. Caso seja, chama funções para alterarem o estado devidamente.
@param e Apontador para o ESTADO
@param c A COORDENADA
*/
int jogar(ESTADO *e, COORDENADA c);
#endif