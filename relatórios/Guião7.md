# GUIÃO 7

Neste guião foi-nos pedido para que implementássemos duas tarefas:

## 1. Implementação do comando movs

O comando movs, tem como função imprimir os movimentos efetuados pelos dois jogadores até ao momento em que o comando é utilizado.

Para isso, tivemos de implementar uma função:
```c 
void guardar_jogada (ESTADO *e,COORDENADA c)
```

Para guardar as jogadas efetuadas de modo cronológico.

De seguida, defimos devidamente um sscanf, para quando o utlizador digitar **movs**, imprima no ecrã a lista de movimentos,como se vê na imagem em baixo:

![terminal](https://github.com/JoseDiogoMartinsVieira/LI2PL3G2/blob/master/relat%C3%B3rios/imagens/movs.png?raw=true)

## 2. Alteração dos comandos ler e gr, de acordo com o movs

- ### Comando gr

Agora o comando **gr**, não só grava o tabuleiro, mas também a lista de movimentos. 

Para isso, utilizámos a seguinte função:
```c
void print_movs (ESTADO *e,FILE *filename)
```
que imprime os movimentos num ficheiro, onde o nome deste é o que o utilizador escrever no terminal após o **gr**.

- ### Comando ler

Para o comando **ler**, implementámos a função:
```c
void ler_jogadas (FILE *fp, ESTADO *e,int n)
```

Que é chamada após o tabuleiro ser lido, e tem a função de:

- Ler as jogadas de cada linha e chamar funções que alterem o ESTADO, de forma correta.



