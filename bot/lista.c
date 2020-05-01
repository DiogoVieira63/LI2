#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_dados.h"
#include "logica_prog.h"
#include "c_interface.h"
#include "lista.h"

#define BUF_SIZE 1024

LISTA criar_lista(){
	LISTA l;
	l = (NODO *)malloc (sizeof(NODO));
	l->valor = NULL;
	l->proximo = NULL;
	return l; 
}

LISTA insere_cabeca (LISTA l, void *valor){
	LISTA l1 = criar_lista ();
	if (l->valor == NULL){
    	l->valor = valor;
		l->proximo = NULL;
    	return l;
  	}
	else {
    	l1->valor = valor;
		l1->proximo = l;
		}
	return l1;
}

void* devolve_cabeca(LISTA l){
	return l->valor;
}


LISTA proximo(LISTA l){
	return l->proximo;
}

LISTA remove_cabeca(LISTA l){
	LISTA l1 = criar_lista ();
	l1 = proximo (l);
	free (l);
	return l1;
}

void remover_lista (LISTA l){
	while (l) l = remove_cabeca (l);	
}

// CRIAR UMA LISTA COM TODAS AS POSSIVEÍS CASAS PARA SE JOGAR
LISTA posicoes_possiveis (ESTADO *e){
	LISTA l;
	int jog = obter_jogador_atual (e);
	l = criar_lista ();
	COORDENADA atual = obter_ultima_jogada (e);
    for (int linha = atual.linha-1;linha <= atual.linha+1;linha++)
    {
        for (int coluna = atual.coluna-1;coluna <= atual.coluna+1;coluna++){
			COORDENADA c = {coluna,linha};
			if (isValid (e,c)) {
				DADOS d = criar_dados (c,jog,e);
				l = insere_cabeca (l,(void*) d);
			}
		}

}
return l;
}

LISTA remove_coordenada (LISTA l,COORDENADA c){
    DADOS d1 = l->valor;
    if (d1->coord.linha == c.linha && d1->coord.coluna == c.coluna){
      l = remove_cabeca (l);
    }
    else {
    for (LISTA l1 = l; l1->proximo;l1=l1->proximo){
        DADOS d = l1->proximo->valor;
        if (d->coord.linha == c.linha && d->coord.coluna == c.coluna){
            l1->proximo =remove_cabeca (l1->proximo);
            break;
        }
    }
    }
    return l;
}

DADOS criar_dados (COORDENADA c, int n,ESTADO *e){
	DADOS d = malloc (sizeof (info));
	double dist = distancia (c,n);
	d->coord = c;
	d->dist = dist;
	d->casas_livres = conta_casas_livres (e,c);
	return d;
}

// VERIFICAR SE O ADVERSÁRIO GANHA NA JOGADA A SEGUIR
int can_he_win  (ESTADO *e){ //estado correspondente à coordenada que decidimos jogar
	int res = 0;
	LISTA l = criar_lista ();
	l = posicoes_possiveis (e);
	LISTA l1;
	for (l1 = l;l1;l1 = proximo (l1)){
		DADOS atual = (DADOS) devolve_cabeca (l1);
		if (atual->casas_livres == 0) res = 1;
	}
	remover_lista (l);
	remover_lista (l1);
	return res;
}

int can_I_win (DADOS dados,ESTADO *e){// n corresponde ao jogador atual
	int i = 0;
	int n = obter_jogador_atual (e);
	if (dados->casas_livres == 0) i= 1;
	COORDENADA c = dados->coord;
	if (n == 1 && obter_estado_casa (e,c) == POS1) i = 1;
	if (n == 2 && obter_estado_casa (e,c) == POS2) i = 1;
	return i;
}

COORDENADA random_c (ESTADO *e){
	LISTA l = criar_lista ();
	l = posicoes_possiveis (e);
	DADOS d = l->valor;
	COORDENADA c = d->coord;
	remover_lista (l);
	return c;
}

int one_way (ESTADO *e){
	COORDENADA c;
	int i = 1;
	int contagem = 0;
	ESTADO *teste = (ESTADO *) malloc (sizeof (ESTADO));
	memcpy (teste,e,sizeof (ESTADO));
	while (i){
	LISTA l = posicoes_possiveis (teste);
	LISTA l1;
	for (l1 = l; l1;proximo (l1)){
		DADOS d = l1->valor;
		if (d->casas_livres == 1) {
			c = d->coord;
			jogar (teste,c);
			contagem++;
			i = 1;
			break;
			
		}
		else if (d->casas_livres == 0) {
			return contagem;
		}
		else {
			i = 0;
			break;
		}

	}
	remover_lista (l);
	}
	free (teste);
	return contagem;
}

COORDENADA melhor_jogada(LISTA l, ESTADO *e,int n){
	if (l== NULL) return random_c (e);
	ESTADO *teste = (ESTADO *) malloc (sizeof (ESTADO));
	DADOS atual = (DADOS)devolve_cabeca (l);
	COORDENADA melhor = atual->coord;
	double menor_dist = atual->dist;
	LISTA l1 = criar_lista();
	for (l1 = l;l1;l1 = proximo (l1)){
		memcpy (teste,e,sizeof (ESTADO));
		atual = devolve_cabeca (l1);
		COORDENADA c = atual->coord;
		if (can_I_win(atual,teste)) return c;
		jogar (teste,c);
		if (can_he_win(teste) != 1){
			if (atual->dist <= menor_dist) {
				melhor = c;
				menor_dist = atual->dist;
			}
		if (n == 2 && one_way (teste)%2!=0 && one_way (teste)) return c;
		}
	}
	memcpy (teste,e,sizeof (ESTADO));
	jogar (teste,melhor);
	if (can_he_win(teste) && n == 1){
		melhor = melhor_jogada (remove_cabeca(l),e,1);
	}
	if (n == 2 && (can_he_win(teste) || (one_way (teste)%2==0 && one_way (teste)))){
		melhor = melhor_jogada (remove_coordenada (l,melhor),e,2);
	}
	remover_lista (l);
	free (teste);
	return melhor;
}