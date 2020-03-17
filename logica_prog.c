#include "c_dados.h"
#include "c_interface.h"
#include <stdio.h>
#include <stdlib.h>

//Função auxiliar da (fim_do_jogo) que observa se todas as peças à volta estão ocupadas por PRETAS
int ha_nao_casas_livres (ESTADO *e){
    COORDENADA atual = e->ultima_jogada;
    int contagem = 0;
    int linha = atual.linha-1;
    while (linha <= atual.linha+1)
    {
    int coluna = atual.coluna-1;
        while (coluna <= atual.coluna+1)
        {
        COORDENADA c = {coluna,linha};
        if (obter_estado_casa (e,c) == PRETA || linha < 1 || linha > 8 || coluna < 1 || coluna > 8 || (linha == atual.linha && coluna == atual.coluna));
        else return 0;
        coluna++;
        }
    linha++;
    }
return 1;
}

int fim_do_jogo (ESTADO* e){
COORDENADA c = e->ultima_jogada;
//QUANDO O JOGADOR GANHA POR CHEGAR À SUA CASA
if (c.coluna == 1 && c.linha == 8) {
    display_gameover (1,e);
    return 1;
}
if (c.coluna == 8 && c.linha == 1) {
    display_gameover (2,e);
    return 1;
}
//QUANDO O JOGADOR GANHA POR DEIXAR O OUTRO ENCURRALADO
int jog;
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
    m = e->ultima_jogada.coluna;
    n = e->ultima_jogada.linha; 
    CASA peca_atual = obter_estado_casa (e,e->ultima_jogada); 
    if ((abs (c.linha-n) <= 1) && (abs (c.coluna -m) <= 1) && !(c.linha == n && c.coluna == m)){
            CASA peca_destino = obter_estado_casa (e,c);
            if (peca_destino == VAZIO) {
                alterar_estado_casa (e,c);
                alterar_estado_casa (e,e->ultima_jogada);
                guardar_jogada (e,c);
                alterar_num_jogadas (e);
                alterar_jogador_atual (e);
                e->ultima_jogada =c;
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