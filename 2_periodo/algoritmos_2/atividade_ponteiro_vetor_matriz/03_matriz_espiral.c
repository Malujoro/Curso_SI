#include <stdio.h>
#include <stdlib.h>

// Função para exibir toda a matriz
void exibir(int **matriz, int tam)
{
    int i, j;

    printf("\n");
    for(i = 0; i < tam; i++)
    {
        for(j = 0; j < tam; j++)
        {
            printf("%d \t", *(*(matriz + i) + j));
        }
        printf("\n");
    }
}

// Função para preencher a matriz começando do centro e formando uma espiral
// Com valores de 1 até N²
void espiral(int **matriz, int tam)
{
    // Inicialmente, o valor da linha e da coluna recebem exatamente a posição do meio da matriz
    int lin = tam/2, col = tam/2;
    int i, j, num = 1;
    // O valor central recebe o número 1
    *(*(matriz + lin) + col) = num;

    // Laço de repetição de 1 até a dimensão da matriz (quantidade de "interações")
    // Cada "interação" vai ocorrer duas vezes (uma para linha e outra para coluna)
    // Exemplo: Matriz 5x5
    // Começa na posição central (2,2).
    // Um passo para a direita (coluna+1), depois um passo para baixo (linha+1).
    // Dois passos para a esquerda (coluna-2), depois dois passos para cima (linha-2).
    // Três passos para a direita (coluna+3), depois três passos para baixo (linha+3).
    // Quatro passos para a esquerda (coluna-4), depois quatro passos para cima (linha-4).
    // "Cinco" passos para a direita (coluna+5). Porém, só poderão ocorrer 4 passos, pois o quinto sairá dos limites da matriz
    for(i = 1; i <= tam; i++)
    {
        for(j = 0; j < i*2; j++)
        {
            // Caso seja um "Passo ímpar", será incrementado posições
            if(i % 2 == 1)
            {
                // A primeira metade dos passos serão das colunas, e o restante será das linhas
                if(j < i)
                    col++; // Passo para direita
                else
                    lin++; // Passo para baixo
            }
            // Caso seja um "Passo par", será decrementado posições
            else
            {
                if(j < i)
                    col--; // Passo para esquerda
                else
                    lin--; // Passo para cima
            }
            // Verificação para sair do laço de repetição caso a linha ou coluna saia do limite da matriz
            if(lin >= tam || col >= tam)
                break;
            // Caso esteja dentro, poderá inserir o número dentro da matriz
            else
            {
                num++;
                *(*(matriz + lin) + col) = num;
            }
        }
    }
}

int main()
{
    int tam, i;

    printf("Dimensão da matriz: ");
    scanf(" %d", &tam);

    if(tam % 2 == 0)
        printf("Erro! Matriz não é de ordem ímpar");
    else
    {
        int **matriz = (int **) malloc(tam * sizeof(int *));
        for(i = 0; i < tam; i++)
        {
            *(matriz + i) = (int *) malloc(tam * sizeof(int));
        }

        espiral(matriz, tam);
        exibir(matriz, tam);

        for(i = 0; i < tam; i++)
        {
            free(*(matriz + i));
        }
        free(matriz);
    }
    
    return 0;
}