#include "c_dados.h"
#include "logica_prog.h"
#include "c_interface.h"

//FUNÇÃO MAIN
int main(){
ESTADO *e = inicializar_estado();
interpretador(e);
return 0;
}


