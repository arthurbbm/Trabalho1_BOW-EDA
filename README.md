# Trabalho 1

O trabalho consiste em um software do tipo Bag of Words (BOW) em C. Ele contém um menu principal com opções de leitura do dicionário, de leitura de um texto de referência A e de um texto de referência B, de exibição da bag of words referentes aos dois textos em uma tabela e de cálculo da distância euclidiana entre os vetores com as ocorrências das palavras nos dois textos.

## Grupo
- Arthur Borges Bringel  Machado 160113032
- Flavio Vieira Leão 150125682
- Lucas Rocha Figueiredo Santana e Barros 150137478

## Notação Big-O
A notação Big-O é membro da família das notações assintóticas e descreve o comportamento limitante de uma função quando a variável tende a infinito. Ela é usada em Ciência da Computação para classificar o desempenho de algoritmos e o faz de acordo com o aumento de elementos que afeta o crescimento do número de operações. Ela pode ser definida formalmente da seguinte forma:

f(x) = O(g(x)), sendo x -> \infinito

Para analisar o nosso algoritmo, iremos adotar as seguintes simplificações:
- Se f(x) é a soma de vários termos, o que possuir maior taxa de crescimento é mantido, e todos os outros são omitidos.
- Se f(x) é um produto de diversos fatores, quaisquer constantes (termos do produto que não depente de x) são omitidos.

Pela análise de linha por linha dos arquivos, cada função do programa recebeu a função matemática O de maior ordem em seu escopo de linhas. Dessa forma, a função main() recebeu a representação O da maior da linha que possui a maior ordem em seu escopo. Logo, a complexidade do programa é limitada pela função a seguir:

f(n) = O(n^4)

Isto indica que os dados que estão sendo operados passam pelo mesmo procedimento 4 vezes, o que é muito ruim, mas um tanto comum em operações como bubble sort, que foi exatamente o caso do programa em questão. Esta situação pode ser reduzida para uma função do tipo O(log n), otimizando os processos.
