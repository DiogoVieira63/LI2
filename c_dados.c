void tab_inicial (CASA tab [8][8]){
int linha = 1;
while (linha <= 8){
int coluna = 1;
while (coluna <= 8) tab [linha] [coluna++] = VAZIO;
linha++;
}
tab [5][4]= BRANCA; 
}


//Esta função deverá criar um estado vazio (com o tabuleiro inicializado)
ESTADO *inicializar_estado() {
ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
e->jogador_atual = 1;
e->num_jogadas = 0; 
/*
e->jogadas->jogador1.linha = 0;
e->jogadas->jogador1.coluna = 0;
e->jogadas->jogador2.linha = 0;
e->jogadas->jogador2.coluna = 0;
*/
tab_inicial (e->tab);
e->ultima_jogada.linha = 0; // por ser a peça onde começa mas não sei se posso declarar assim
e->ultima_jogada.coluna = 0;
return e;
}


// Esta função permite obter o número do jogador atual
int obter_jogador_atual(ESTADO *estado);


//Esta função permite obter quantas jogadas foram efetuadas (cada jogada tem o movimento de dois jogadores)
int obter_numero_de_jogadas(ESTADO *estado);


//Esta função permite obter o estado atual da casa
int obter_estado_casa(ESTADO *e, COORDENADA c);


// Estruturas de dados (devem ser colocadas no módulo correto da camada dos dados
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
    int num_jogadas;
    int jogador_atual;
    } ESTADO;
    