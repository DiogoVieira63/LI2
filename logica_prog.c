#include "c_dados.h"
#include <stdio.h>
#include <stdlib.h>

//Função auxiliar da (fim_do_jogo) que observa se todas as peças à volta estão ocupadas por PRETAS
int contar_vizinhos (ESTADO *e){
    COORDENADA atual = e->ultima_jogada;
    int contagem = 0;
    int linha = atual.linha-1;
    while (linha <= atual.linha+1)
    {
    int coluna = atual.coluna-1;
        while (coluna <= atual.coluna+1)
        {
        if (e->tab [coluna][linha] == PRETA || linha < 1 || linha > 8 || coluna < 1 || coluna > 8 || (linha == atual.linha && coluna == atual.coluna));
        else return 0;
        coluna++;
        }
    linha++;
    }
return 1;
}

//Função que recebe o nr do jogador que ganhou para imprimir a mensagem de vencedor
void display_gameover (int n){
printf ("PARABÉNS, JOGADOR %d! GANHASTE!\n",n);
}

int fim_do_jogo (ESTADO* e){
COORDENADA c = e->ultima_jogada;
//QUANDO O JOGADOR GANHA POR CHEGAR À SUA CASA
if (c.coluna == 1 && c.linha == 8) {
    display_gameover (1);
    return 1;
}
if (c.coluna == 8 && c.linha == 1) {
    display_gameover (2);
    return 1;
}
//QUANDO O JOGADOR GANHA POR DEIXAR O OUTRO ENCURRALADO
int jog;
if (e->jogador_atual == 1)jog = 2;
else jog = 1;
if (contar_vizinhos (e)) {
    display_gameover (jog);
    return 1;
}
return 0;
}

int jogar(ESTADO *e, COORDENADA c) {
    int m,n;
    m = e->ultima_jogada.coluna;
    n = e->ultima_jogada.linha; 
    CASA peca_atual = e->tab [m][n]; 
    if ((abs (c.linha-n) <= 1) && (abs (c.coluna -m) <= 1) && !(c.linha == n && c.coluna == m)){
            CASA peca_destino = e->tab [c.coluna][c.linha];
            if (peca_destino == VAZIO) {
            alterar_jogada (e,c);
            alterar_estado_casa (e,c);
            alterar_estado_casa (e,e->ultima_jogada);
            alterar_num_jogadas (e);
            alterar_jogador_atual (e);
            e->ultima_jogada =c;
            }
            else {
            printf ("Jogada Impoossível. \n");
            return 0;
            }
            return 1;
        }
    else (printf ("Jogada Impossível \n"));
    return 0;
}