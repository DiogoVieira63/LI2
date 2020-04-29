#include "c_dados.h"
#include "logica_prog.h"
#include "c_interface.h"
#include "lista.h"
#include <string.h>
#include <math.h>
//FUNÇÃO MAIN
int main(){
char nome1 [11],nome2 [11];
int i = 1;
ESTADO *e = inicializar_estado();
while (i){
init_estado (e);
if (i == 1){
nomes (1,nome1);
strcpy(e->nomes.jogador1 , nome1);
nomes (2,nome2);
strcpy(e->nomes.jogador2 , nome2);
e->vitorias.j1= 0;
e->vitorias.j2= 0;
}
if (interpretador(e,i))i++;
else i = 0;
}

return 0;
}


