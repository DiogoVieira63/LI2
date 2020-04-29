#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_dados.h"
#include "logica_prog.h"
#include "c_interface.h"
#include "lista.h"

#define BUF_SIZE 1024


//FAZER FUNÇÃO PARA REMOVER LISTA



LISTA remove_coordenada (LISTA l,COORDENADA c){
    LISTA l2;
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

int length (LISTA l) {
	LISTA l1;
	int contagem;
	for (l1=l;l1;proximo (l1)) contagem++;
	return contagem;
}

DADOS criar_dados (COORDENADA c, int n,ESTADO *e){
	DADOS d = malloc (sizeof (info));
	double dist = distancia (c,n);
	d->coord = c;
	d->dist = dist;
	d->casas_livres = conta_casas_livres (e,c);
	return d;
}

LISTA criar_lista(){
  LISTA l;
  l = (NODO *)malloc (sizeof(NODO));
  l->valor = NULL;
  l->proximo = NULL;
  return l; 
}


void print_lista (LISTA l){
	LISTA l1 = criar_lista ();
	for (l1 = l; l1; l1= l1->proximo){
		DADOS d = (DADOS) devolve_cabeca (l1);
		printf ("COORDENADA %d%d = dist: %f e casas livres = %d\n",d->coord.coluna, d->coord.linha,d->dist,d->casas_livres);
	}
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

//VER_PARIDADE


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

//mudar para o módulo certo
int can_I_win (DADOS dados,ESTADO *e){// n corresponde ao jogador atual
	int i = 0;
	int n = obter_jogador_atual (e);
	if (dados->casas_livres == 0) i= 1;
	COORDENADA c = dados->coord;
	if (n == 1 && obter_estado_casa (e,c) == POS1) i = 1;
	if (n == 2 && obter_estado_casa (e,c) == POS2) i = 1;
	return i;
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
	LISTA l1;
	while (l) l = remove_cabeca (l);	
}

//char *str = (char *) devolve_cabeca(T);

COORDENADA random_c (ESTADO *e){
	LISTA l = criar_lista ();
	l = posicoes_possiveis (e);
	DADOS d = l->valor;
	COORDENADA c = d->coord;
	free (l);
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


COORDENADA melhor_jogada (LISTA l, ESTADO *e){
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
		}
	}
	memcpy (teste,e,sizeof (ESTADO));
	jogar (teste,melhor);
	if (can_he_win(teste)){
		melhor = melhor_jogada (remove_cabeca(l),e);//
	}
	remover_lista (l);
	free (teste);
	return melhor;
}


COORDENADA melhor_jogada2 (LISTA l, ESTADO *e){
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
		if (one_way (teste)%2!=0 && one_way (teste)) return c;
		}
	}
	memcpy (teste,e,sizeof (ESTADO));
	jogar (teste,melhor);
	if (can_he_win(teste) || (one_way (teste)%2==0 && one_way (teste))){
		melhor = melhor_jogada (remove_coordenada (l,melhor),e);//
	}
	remover_lista (l);
	free (teste);
	return melhor;
}


/*
int verificar_paridade (ESTADO *e,COORDENADA){
	int n = obter_jogador_atual (e);

}
*/

int* count_lines (ESTADO *e,int *v, int n){ //n corresponde a linhas(1) ou colunas(0)
	int i = 1;
	while (i <= 8)
	{
		int contagem = 0;
		for (int j = 0;j < 8;j++){
			COORDENADA c;
			if (n == 0) c = (COORDENADA){j,i};
			else c =(COORDENADA) {i,j};
			if (isValid (e,c)) contagem++;
		}
		v[i-1] = contagem; 
		i++;
	}
	return v;
}




/* 
IDEIAS

---------------------------------

ADICIONAR OUTRO APONTADOR À ESTRUTURA PARA CONSEGUIR SIMULAR AS JOGADAS

OU SEJA,

UM APONTADOR APONTA PARA OS DADOS SEGUINTES, OUTRA APONTA PARA AS PRÓXIMAS POSSIVÉIS JOGADAS.

ARRANJAR ALGUM TIPO DE ALGORITMO PARA PERCORRER DESTE MODO A ARVÓRE E DECIDIR QUE COORDENADA JOGAR.

DETERMINAR PROFUNDIDADE DA ÁRVORE, PARA JÁ FAZER COM 4 JOGADAS

DDEPOIS SE CONSEGUIDO, FAZER MAIS

-----------------------------------

VER TAMBÉM: CAMINHOS E AREÁS LIVRES 

E ZONAS PROIBIDAS

------------------------------------

VERIFICAR PARIDADE, QUANDO EM DISPITA PELA LINHA, OU SEJA, NUNCA QUEBRAR A PARIDADE, ESPERAR QUE SEJA O ADVERSÁRIO A FAZÊ-LO,

-----------------------------------

IDENTIFICAR A EXISTÊNCIA DE CAMINHOS ISOLADOS, OU SEJA, DE CAMINHOS EM QUE SÓ HAJA UMA CASA POSSÍVEL PARA JOGAR

E TENTAR LEVAR O ADVERSÁRIO PARA ESSES CAMINHOS E DE PREFERÊNCIA PARA GANHAR

*/



/*
int main() {
	
	LISTA l = criar_lista(); // Criar uma lista vazia
	ESTADO *e = inicializar_estado ();



IMPORTANTE 


	ESTADO *guardado = (ESTADO *) malloc(sizeof(ESTADO));
	memcpy (guardado,e,sizeof(ESTADO));



	COORDENADA c = {5,5};
	jogar (e,c);
	print_tabuleiro (guardado,stdout);
	print_tabuleiro (e,stdout);
	
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

