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
#endif