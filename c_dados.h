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

typedef struct {
    int j1;
    int j2;
    } VITORIAS;

/**
Tipo de dados para JOGADAS
*/
typedef COORDENADA JOGADAS[64];

/**
Tipo de dados para NOMES
*/
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
    JOGADAS ignore;
    JOGADAS jogadas;
    /**a coordenada da ultima jogada*/
    COORDENADA ultima_jogada;
    /**o nr de jogadas*/
    int num_jogadas;
    int max_jogadas;
    /**Um inteiro (1 ou 2) correspodente ao jogador atual*/
    int jogador_atual;
    /** Guarda os nomes introduzidos pelo utiilizador*/
    NOMES nomes;
    VITORIAS vitorias;
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
\brief Muda o estado de uma CASA conforme a lógica do Jogo
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
/**
\brief Modifica uma casa para um determinado estado de CASA
@param e Apontador para o ESTADO
@param c A COORDENADA
@param casa O estado da casa que quero na coordenada
*/
void modificar_casa (ESTADO *e,COORDENADA c,CASA casa);
/**
\brief Obtém o estado da casa
@param e Apontador para o ESTADO
@returns O nr de jogadas
*/
int obter_num_jogadas (ESTADO *e);
/**
\brief Obtém o nome do jogador
@param e Apontador para o ESTADO
@param n Nr do jogador pretendido
@returns Apontador para a string pretendida
*/
char* obter_nome_jogador (ESTADO *e,int n);
/**
\brief Obtém o nr do jogador atual 
@param e Apontador para o ESTADO
@returns Um int com nr do jogador atual
*/
int obter_jogador_atual (ESTADO *e);
/**
\brief Modifica uma casa para um determinado estado de CASA
@param e Apontador para o ESTADO
@param n Int para o qual mudar
*/
void modificar_jogador_atual (ESTADO *e,int n);
/**
\brief Modifica o nr de jogadas para um determinado nr de jogadas
@param e Apontador para o ESTADO
@param n Int para o qual mudar
*/
void modificar_num_jogadas (ESTADO *e, int n);
/**
\brief Obtém a COORDENADA da última jogada
@param e Apontador para o ESTADO
@returns A COORDENADA 
*/
COORDENADA obter_ultima_jogada (ESTADO *e);
/**
\brief Modifica a última jogada para uma determinada COORDENADA
@param e Apontador para o ESTADO
@param c A COOORDENADA para a qual modificar
*/
void modificar_ultima_jogada (ESTADO *e,COORDENADA c);
/**
\brief Obtém a COORDENADA da jogada guardada num certo número
@param e Apontador para o ESTADO
@returns A COORDENADA 
*/
COORDENADA obter_jogada (ESTADO *e,int n);
/**
\brief Dá reset nas jogadas
@param e Apontador para o ESTADO
*/
void init_jogadas (ESTADO *e);
/**
\brief Muda o nº de vitórias
@param e Apontador para o ESTADO
@param n Int para indicar o jogador que ganhou
*/
void muda_vitorias (ESTADO *e, int n);
/**
\brief Dá reset no ESTADO
@param e Apontador para o ESTADO
*/
void init_estado (ESTADO *e);
/**
\brief Obtém o nr de vitõrias de um jogador
@param e Apontador para o ESTADO
@param n Int para indicar o jogador que se pretende: 1 / 2
@returns o nr de vitorias
*/
int obter_vitoria (ESTADO *e, int n);
/**
\brief Apaga uma determinada jogada
@param e Apontador para o ESTADO
@param n Int para indicar o nr da jogada que se pretende
*/
void delete_jogada (ESTADO *e, int n);
/**
\brief Obter o nr max de jogadas
@param e Apontador para o ESTADO
@returns o nr max de jogadas
*/
int obter_max_jogadas (ESTADO *e);
/**
\brief Modificar o nr maximo de jogadas para um certo número
@param e Apontador para o ESTADO
@param n Int para indicar o nr para o qual se vai mudar
*/
void modificar_max_jogadas (ESTADO *e, int n);
/**
\brief Tabuleiro para o inicio do jogo
@param e Apontador para o ESTADO

*/
void tab_inicial (ESTADO *e);
#endif
