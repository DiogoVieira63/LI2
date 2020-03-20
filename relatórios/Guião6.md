# Relatório GUIÃO 6

Neste Guião, foi nos pedido para fazer várias tarefas, relatando, em seguida, detalhadamente, cada uma delas:

- ### Documentação do código

Inicialmente começamos por documentar os vários protótipos das diferentes camadas do nosso projeto, respeitando devidamente a sua nomenclatura. Posteriormente, passámos á instalação do comando dyoxigen para gerar um ficheiro que realiza a leitura dessa mesma documentação, guardando o ficheiro gerado numa pasta html.

- ### Criação de um prompt

Para este processo, nós começamos por definir uma auxilar (que se apresenta na camada interface) que lê (através do scanf) o nome dos dois jogadores. De seguida, após cada jogada o prompt fica encarregue de ler o ESTADO de cada jogador após cada jogada, nomeadamente o número da jogada correspondente a cada jogador e o número total de jogadas efetuadas no jogo. 

- ## Comandos adicionados ao interpretador

1. ### Comando gr

Este comando tem como objetivo, imprimir o tabuleiro num ficheiro associado ao nome que o utilizador escrever após o gr.
Para tal fim, fizemos uma função idêntica à que anteriormente tinhamos feito que imprimia o Tabuleiro no ecrã, que dado um ESTADO e um FILENAME, imprime o tabuleiro num ficheiro com o respetivo FILENAME. Como estas duas funções são muito semelhantes, decidimos fundir as duas numa só função, que imprime quer o tabuleiro no ecrã quer no ficheiro. 
Quando o jogador pretender utilizar este comando definimos devidamente um scanf para detetar tal uso.

2. ### Comando ler

Este comando tem como objetivo, ler o tabuleiro num ficheiro associado ao nome que o utilizador escrever após o ler.
Caso o ficheiro não exista, aparecerá uma mensagem no ecrã a dizer o mesmo.
Caso contrário, analisa a informação do ficheiro e chama funções para alterar o ESTADO, conforme o tabuleiro lido.
Quando o jogador pretender utilizar este comando definimos devidamente um scanf para detetar tal uso.

3. ### Comando Q

Este comando tem apenas a finalidade de sair do jogo.
Para a concretização do mesmo, apenas é feita a quebra do ciclo que possibilita o jogo desenrolar.
Quando o jogador pretender utilizar este comando definimos devidamente um scanf para detetar tal uso.

- ## Jogada

1. ### Implementação e Validação
A implementação e a validação da jogada são feitas na função Jogar:
Verifica se a coordenada para a qual se pretende ir é uma das casas à volta da peça atual:
- Caso não seja, devolve uma mensagem de erro.
- Caso seja, passa para a fase seguinte.

A fase seguinte é verificar se a casa que pretendemos ir se encontra vazia, ou se é uma das casas vencedoras:
- Caso não seja, devolve uma mensagem de erro.
- Caso seja, chama devidamente as funções que alteram o estado conforme a jogada.

2. ### Deteção do fim do jogo
Existe duas maneiras para a deteção do fim do jogo:
1. #### Quando se chega a uma das casas vencedoras:
Caso a casa POS1, ou a casa POS2, sejam alcançadas, o jogo acaba e aparece uma mensagem de parabéns para o jogador vencedor.

2. #### Quando o jogador não tem mais movimentos possíveis:
Para esta maneira, usamos uma função auxiliar (ha_nao_casas_livres), que verifica se à volta da peça atual, se encontra alguma casa livre:
- Caso se encontre, então o jogo continua normalmente.
- Caso contrário, o jogo termina, e aparece uma mensagem de parabéns para o jogador que efetuou a última jogada.
