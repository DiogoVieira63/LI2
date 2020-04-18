#ifndef ___LISTAS_H___
#define ___LISTAS_H___

typedef struct {
   COORDENADA coord;
   int dist;
   int casas_livres;
}DADOS;


typedef struct nodo {
   DADOS valor;
   struct nodo *proximo;
} NODO, *LISTA; 

// Cria uma lista vazia
LISTA criar_lista();
// Insere um valor na cabeça da lista
LISTA insere_cabeca(LISTA L, DADOS dados);
// Devolve a cabeça da lista
DADOS devolve_cabeca(LISTA L);
// Devolve a cauda da lista
LISTA proximo(LISTA L);
// Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
LISTA remove_cabeca(LISTA L);
// Devolve verdareiro se a lista é vazia
int lista_esta_vazia(LISTA L);
COORDENADA melhor_jogada (LISTA l, ESTADO *e);
LISTA posicoes_possiveis (ESTADO *e);
#endif