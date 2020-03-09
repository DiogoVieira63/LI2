#include "c_dados.h"
#include "logica_prog.h"
#include "c_interface.h"


int main(){
ESTADO *e = inicializar_estado();
interpretador(e);
return 0;
}