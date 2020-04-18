#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_dados.h"
#include "logica_prog.h"
#include "c_interface.h"
#include "lista.h"

#define BUF_SIZE 1024


DADOS criar_dados (COORDENADA c, int n,ESTADO *e){
	DADOS d;
	d.coord = c;
	d.dist = distancia (c,n);
	d.casas_livres = conta_casas_livres (e,c);
	return d;
}

LISTA criar_lista(){
  LISTA l;
  COORDENADA c = {0,0};
  l = malloc (sizeof(NODO));
  l->valor.coord = c;
  l->proximo = NULL;
  return l; 
}

void print_lista (LISTA l){
	LISTA l1 = criar_lista ();
	for (l1 = l; l1; l1= l1->proximo){
		printf ("COORDENADA %d%d = dist: %d e casas livres = %d\n",l1->valor.coord.coluna, l1->valor.coord.linha,l1->valor.dist,l1->valor.casas_livres);
	}
}


LISTA insere_cabeca (LISTA l, DADOS dados){
  LISTA l1 = criar_lista ();
  COORDENADA c= l->valor.coord;
  if (c.linha == 0 && c.coluna == 0){
    l->valor = dados;
    return l;
  }
  else {
    l1->valor = dados;
    l1->proximo = l;
  }
  return l1;
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
				l = insere_cabeca (l,d);
			}
		}

}
return l;
}

//mudar para o módulo certo
int can_I_win (DADOS dados,ESTADO *e){// n corresponde ao jogador atual
	int i = 0;
	int n = obter_jogador_atual (e);
	if (dados.casas_livres == 0) i= 1;
	COORDENADA c = dados.coord;
	if (n == 1 && obter_estado_casa (e,c) == POS1) i = 1;
	if (n == 2 && obter_estado_casa (e,c) == POS2) i = 1;
	return i;
}



/*
void * devolve_cabeca(LISTA l){
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
*/

COORDENADA melhor_jogada (LISTA l, ESTADO *e){
	COORDENADA melhor = l->valor.coord;
	int menor_dist = l->valor.dist;
	LISTA l1 = criar_lista();
	for (l1 = l;l1;l1 = l1->proximo){
		COORDENADA c = l1->valor.coord;
		if (can_I_win(l1->valor,e)) return c;
		if (l1->valor.casas_livres > 1 && l1->valor.dist < menor_dist) {
			melhor = c;
			menor_dist = l1->valor.dist;
		}
	}
	return melhor;
}
/*
int main() {
	LISTA l = criar_lista(); // Criar uma lista vazia
	ESTADO *e = inicializar_estado ();
	/*
	COORDENADA c = {4,5};
	jogar (e,c);
	COORDENADA c1 = {3,6};
	jogar (e,c1);
	COORDENADA c2= {2,7};
	jogar (e,c2);
	modificar_jogador_atual (e,1);
	
	l = posicoes_possiveis (e);
	//l = insere_cabeca (l,d1);
	//l = insere_cabeca (l,d2);
	print_lista (l);
	COORDENADA c4 = {1,8};
	DADOS d = criar_dados (c4,1,e);
	modificar_jogador_atual (e,1);
	putchar (obter_estado_casa(e,c4));
	printf ("DADOS DA COORDENADA = %d %d\n",d.casas_livres,d.dist);
	printf ("É POSSIVÉL GANHAR? %d\n",can_I_win (d,e));
	
	COORDENADA melhor = melhor_jogada (l,e);
	printf ("MELHOR = {%d,%d}",melhor.coluna,melhor.linha);

  /*  
  printf("Insira várias linhas, acabando com CTRL-D:\n");

  // control-D é a tecla CTRL e a tecla D ao mesmo tempo
  // Em windows é capaz de ser CTRL-Z
    while(fgets(linha, BUF_SIZE, stdin) != 0) {
        // A função strdup cria uma cópia da string que foi lida
        // Insere uma cópia da linha lida na cabeça da lista
        L = insere_cabeca(L, strdup(linha));
    }

  printf("\n==============================\n");
  printf(  "=          PERCURSO          =\n");
  printf(  "==============================\n\n");
    // percorre sem remover os elementos da lista
    for(LISTA T = L; !lista_esta_vazia(T); T = proximo(T)) {
        // Vai buscar a cabeça da lista
        // Passa do tipo genérico void * para char *
        char *str = (char *) devolve_cabeca(T);
        printf("%s", str);
    }
    
  printf("\n==============================\n");
  printf(  "=           REMOCAO          =\n");
  printf(  "==============================\n\n");
    // percorre e vai removendo a cabeça
    while(!lista_esta_vazia(L)) {
        char *str = (char *) devolve_cabeca(L);
        L = remove_cabeca(L);
        printf("%s", str);
        free(str);
    }
	
  return 0;
}
*/
