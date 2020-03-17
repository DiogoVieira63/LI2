/**
@file dados.h
Definição do estado e das funções que o manipulam
*/

#ifndef ___DADOS_H___
#define ___DADOS_H___

/**
Tipo de dados para uma CASA
*/
typedef enum {VAZIO, BRANCA, PRETA} CASA;

/**
Tipo de dados para uma COORDENADA
*/
typedef struct {
    int coluna;
    int linha;
    } COORDENADA;

/**
Tipo de dados para uma JOGADA
*/
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
    } JOGADA;

/**
Tipo de dados para JOGADAS
*/
typedef JOGADA JOGADAS[32];

/**
Tipo de dados para o ESTADO
*/
typedef struct {
    /**Tabuleiro*/
    CASA tab[8][8];
    /**as jogadas*/
    JOGADAS jogadas;
    /**a coordenada da ultima jogada*/
    COORDENADA ultima_jogada;
    /**o nr de jogadas*/
    int num_jogadas;
    /**Um inteiro (1 ou 2) correspodente ao jogador atual*/
    int jogador_atual;
    } ESTADO;

ESTADO* inicializar_estado();
void alterar_jogador_atual (ESTADO *e);
void alterar_num_jogadas (ESTADO *e);
/**
\brief Muda o estado de uma casa
@param e Apontador para o estado
@param c A coordenada
@returns o apontador para o estado devidamente alterado
*/
void alterar_estado_casa (ESTADO *e,COORDENADA c);
void guardar_jogada (ESTADO *e,COORDENADA c);
CASA obter_estado_casa (ESTADO *e, COORDENADA c);
#endif