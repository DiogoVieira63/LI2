#include "c_dados.h"
#include "c_interface.h"
#include <stdio.h>
#include <stdlib.h>

//Função auxiliar da (fim_do_jogo) que observa se todas as peças à volta estão ocupadas por PRETAS
int ha_nao_casas_livres (ESTADO *e){
    COORDENADA atual = obter_ultima_jogada (e);
    int contagem = 0;
    for (int linha = atual.linha-1;linha <= atual.linha+1;linha++)
    {
        for (int coluna = atual.coluna-1;coluna <= atual.coluna+1;coluna++)
        {
        COORDENADA c = {coluna,linha};
        if (obter_estado_casa (e,c) == PRETA || linha < 1 || linha > 8 || coluna < 1 || coluna > 8 || (linha == atual.linha && coluna == atual.coluna));
        else return 0;
        }
    }
return 1;
}

int fim_do_jogo (ESTADO* e){
COORDENADA c = obter_ultima_jogada (e);
CASA atual = obter_estado_casa (e,c);
//QUANDO O JOGADOR GANHA POR CHEGAR À SUA CASA
if (atual == POS1) {
    display_gameover (1,e);
    return 1;
}
if (atual == POS2) {
    display_gameover (2,e);
    return 1;
}
//QUANDO O JOGADOR GANHA POR DEIXAR O OUTRO ENCURRALADO
int jog,j_atual = obter_jogador_atual (e);
if (e->jogador_atual == 1)jog = 2;
else jog = 1;
if (ha_nao_casas_livres (e)) {
    display_gameover (jog,e);
    return 1;
}
return 0;
}

int jogar(ESTADO *e, COORDENADA c) {
    int m,n;
    COORDENADA ult = obter_ultima_jogada (e);
    m = ult.coluna;
    n = ult.linha; 
    CASA peca_atual = obter_estado_casa (e,ult); 
    if ((abs (c.linha-n) <= 1) && (abs (c.coluna -m) <= 1) && !(c.linha == n && c.coluna == m)){
            CASA peca_destino = obter_estado_casa (e,c);
            if (peca_destino == VAZIO || peca_destino == POS1 || peca_destino == POS2) {
                alterar_estado_casa (e,c);
                alterar_estado_casa (e,ult);
                guardar_jogada (e,c);
                alterar_num_jogadas (e);
                alterar_jogador_atual (e);
                alterar_ultima_jogada (e,c);
            }
            else {
                print_erro (2);
                return 0;
            }
            return 1;
        }
    else print_erro (2);
    return 0;
}
