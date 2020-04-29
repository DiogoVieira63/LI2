/**
@file lista.h
Funções que dizem respeito às funções relativamente a LISTAS
*/


#ifndef ___LISTAS_H___
#define ___LISTAS_H___

typedef struct info{
   COORDENADA coord;
   double dist;
   int casas_livres;
}info, *DADOS;


typedef struct nodo {
   void* valor;
   struct nodo *proximo;
} NODO, *LISTA; 

/**
\brief Criar uma lista
@returns A lista criada
*/
LISTA criar_lista();
/**
\brief Insere um valor na cabeca da LISTA
@param L A lista
@param valor Apontador para o valor a ser inserido
@returns A Lista devidamente modificada
*/
LISTA insere_cabeca(LISTA L, void *valor);
/**
\brief Devolver o valor que se encontra na cabeça da lista
@param L A lista
@returns O apontador para o valor pretendido
*/
void *devolve_cabeca(LISTA L);
/**
\brief Passo o apontador da Lista para o proximo
@param L A lista
@returns A Lista devidamente modificada
*/
LISTA proximo(LISTA L);
/**
\brief Remove a cabeca da LISTA
@param L A lista
@returns A Lista devidamente modificada
*/
LISTA remove_cabeca(LISTA L);
/**
\brief verifica se a LISTA está vazia
@param L A lista
@returns 1 se a LISTA estiver vazia, 0 caso contrário
*/
int lista_esta_vazia(LISTA L);
/**
\brief Remove uma LISTA, libertando a memória ocupada pela mesma
@param L A lista
*/
void remover_lista (LISTA l);
/**
\brief Escolhe a melhor jogada para o jogador atual fazer
@param l A lista
@param e Apontador para o ESTADO
@returns A coordendada correspondente à melhor jogada
*/
COORDENADA melhor_jogada (LISTA l, ESTADO *e);
COORDENADA melhor_jogada2 (LISTA l, ESTADO *e);
/**
\brief Dado um ESTADO, cria uma lista com todas as coordenadas possíveis de jogar
@param e Apontador para o ESTADO
@returns A Lista devidamente criada
*/
LISTA posicoes_possiveis (ESTADO *e);
#endif

