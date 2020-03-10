//Não sei se está certa, falta testar.
void mostrar_tabuleiro(ESTADO *e) {
int linha = 1;
while (linha <= 8){
int coluna = 1;
while (coluna <= 8)
{
CASA atual = e -> tab [coluna][linha];
if (atual == VAZIO) putchar ('.');
else if (atual == PRETA) putchar ('#');
else putchar ('*');
coluna++;
putchar (' ');
}
putchar ('\n');
linha++;
}
}


int interpretador(ESTADO *e) {
char linha[BUF_SIZE];
char col[2], lin[2];
if(fgets(linha, BUF_SIZE, stdin) == NULL)return 0;
if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {COORDENADA coord = {*col -'a', *lin -'1'};
jogar(e, coord);
mostrar_tabuleiro(e);
}
return 1;
}
