#include "c_dados.h"
#include "logica_prog.h"
#include "c_interface.h"
#include "lista.h"
#include <string.h>

int main(int argc, char **argv){
    FILE *fp;
    ESTADO *e = inicializar_estado();
    if (argc == 3){
        char* lido = argv[1];
        char* guardar = argv [2];
        int i = ler_tabuleiro (e,lido);
        if (i){
            LISTA l = criar_lista ();
            l = posicoes_possiveis (e);
            COORDENADA c;
            c = melhor_jogada (l,e,2);
            jogar(e, c);   
        }
        fp = fopen (guardar, "w+");
        print_tabuleiro (e,fp); 
        fputc ('\n',fp);
        print_movs (e,fp);
        fclose (fp);
        if (fim_do_jogo (e)) return 0;
    }
    return 0;
}