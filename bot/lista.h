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
\brief Remove uma LISTA, libertando a memória ocupada pela mesma
@param L A lista
*/
void remover_lista (LISTA l);
/**
\brief Dado um ESTADO, cria uma lista com todas as coordenadas possíveis de jogar
@param e Apontador para o ESTADO
@returns A Lista devidamente criada
*/
LISTA posicoes_possiveis (ESTADO *e);
/**
\brief Remove o nodo que contenha a COORDENADA dada como argumento
@param l A LISTA
@param c A COORDENADA que vai ser removida
@returns A Lista devidamente alterada
*/
LISTA remove_coordenada (LISTA l,COORDENADA c);
/**
\brief Cria os dados relativamente à COOORDENADA dada
@param c A COORDENADA
@param n Referente ao jogador atual
@param e Apontador para o ESTADO
@returns Os DADOS devidamente criados
*/
DADOS criar_dados (COORDENADA c, int n,ESTADO *e);
/**
\brief Função que deteta se o jogador adversário pode vencer dado um ESTADO com a simulação da jogada
@param e Apontador para o ESTADO
@returns 1, se o jogador adversário tiver oportunidade de vencer na próxima jogada, 0 caso contrário
*/
int can_he_win  (ESTADO *e);
/**
\brief Função que deteta se sou capaz de vencer relativamnete aos DADOS referidos
@param dados Os dados a examinar
@param e Apontador para o ESTADO
@returns 1, se der para vencer, 0 caso contrário
*/
int can_I_win (DADOS dados,ESTADO *e);
/**
\brief Função que escolhe uma COORDENADA válida, só é usada quando a unica opção é a derrota
@param e Apontador para o ESTADO
@returns Uma COORDENADA válida para se jogar
*/
COORDENADA random_c (ESTADO *e);
/**
\brief Deteta se irei ficar encurralado ou se posso encurralar o adversário
@param e Apontador para o ESTADO
@returns 0, se não encontrar um caminho sem saída, caso contrário devolve o nr de coordenadas do caminho sem saída
*/
int one_way (ESTADO *e);
/**
\brief Escolhe a melhor jogada para o jogador atual fazer
@param l A lista
@param e Apontador para o ESTADO
@returns A coordendada correspondente à melhor jogada
*/
COORDENADA melhor_jogada (LISTA l, ESTADO *e,int n);
#endif

