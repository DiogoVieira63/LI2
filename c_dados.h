/**
@file c_dados.h
Definição do estado e das funções que o manipulam
*/

#ifndef ___DADOS_H___
#define ___DADOS_H___

/**
Tipo de dados para uma CASA
*/
typedef enum {VAZIO ='.',
             BRANCA ='*', 
              PRETA = '#',
              POS1 = '1',
              POS2 = '2'} CASA;

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


typedef struct {
    char jogador1 [11];
    char jogador2 [11];
    } NOMES;

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
    NOMES nomes;
    } ESTADO;

/**
\brief Inicializa o ESTADO
@returns o ESTADO devidamente iniciado
*/
ESTADO* inicializar_estado();
/**
\brief Muda o jogador atual
@param e Apontador para o ESTADO
*/
void alterar_jogador_atual (ESTADO *e);
/**
\brief Muda o nr de jogadas
@param e Apontador para o ESTADO
*/
void alterar_num_jogadas (ESTADO *e);
/**
\brief Muda o estado de uma CASA
@param e Apontador para o ESTADO
@param c A COORDENADA
*/
void alterar_estado_casa (ESTADO *e,COORDENADA c);
/**
\brief Guarda a coordenada na jogada
@param e Apontador para o ESTADO
@param c A COORDENADA
*/
void guardar_jogada (ESTADO *e,COORDENADA c);
/**
\brief Obtém o estado da casa
@param e Apontador para o ESTADO
@param c A COORDENADA
@returns A CASA respetiva
*/
CASA obter_estado_casa (ESTADO *e, COORDENADA c);
void modificar_casa (ESTADO *e,COORDENADA c,CASA casa);
#endif