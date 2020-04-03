# GUIÃO 8

Neste guião foi-nos proposto implemntar uma tarefa:

## 1. Implementação do comando pos

O comando **pos** deve permitir ao utilizador aceder a uma jogada anterior.

Para tal, implementamos a função:
```c
int do_pos (ESTADO *e,char *s)
```
Que, devolve um inteiro, que corresponde a :

- 0 (quando é impossível vizualizar a jogada pretendida);
- 1 (quando é possível);

Para facilitar a implementação deste comando, adicionamos:
```c
int max_jogadas;
```
À [estrutura do ESTADO](https://github.com/JoseDiogoMartinsVieira/LI2PL3G2/blob/master/relat%C3%B3rios/Estrutura.md). 

E alteramos o propósito do
```c
int num_jogadas;
```
Assim, o **num_jogadas** informa-nos até qual jogada estamos a considerar neste momento.

Enquanto que o **max_jogadas** informa-nos do nr máximo de jogadas que é preciso considerar.

### Os objetivos desta distinção são os seguintes:

**1.** Aceder a jogadas anteriores, sem perder informações das jogadas;

**2.** Conseguir aceder a jogadas anteriores e regressar para jogadas à frente;

**3.** Quando acede a uma jogada anterior e efetua uma jogada, ajustar o **max_jogadas**.
