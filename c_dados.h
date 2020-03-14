#ifndef ___DADOS_H___
#define ___DADOS_H___


typedef enum {VAZIO, BRANCA, PRETA} CASA;

typedef struct {
    int coluna;
    int linha;
    } COORDENADA;
    
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
    } JOGADA;
    
typedef JOGADA JOGADAS[32];

typedef struct {
    CASA tab[8][8];
    JOGADAS jogadas;
    COORDENADA ultima_jogada;
    int num_jogadas;
    int jogador_atual;
    } ESTADO;
ESTADO *inicializar_estado();
ESTADO* alterar_jogador_atual (ESTADO *e);
ESTADO* alterar_num_jogadas (ESTADO *e);
ESTADO* alterar_estado_casa (ESTADO *e,COORDENADA c);
#endif