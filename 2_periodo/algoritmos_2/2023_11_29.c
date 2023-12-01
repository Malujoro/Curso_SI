#include <stdio.h>
#include <stdlib.h>

void preencher(int **matriz, int tam)
{
    int i, j;
    for(i = 0; i < tam; i++)
    {
        for(j = 0; j < tam; j++)
        {
            printf("Matriz[%d][%d]: ", i, j);
            // scanf(" %d", (*(matriz + i) + j));
            scanf(" %d", &matriz[i][j]);
        }
    }
}

void exibir(int **matriz, int tam)
{
    int i, j;

    printf("\n");
    for(i = 0; i < tam; i++)
    {
        for(j = 0; j < tam; j++)
        {
            // printf("%d\t", *(*(matriz + i) + j));
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void diagPrin(int **matriz, int tam)
{
    int i, soma = 0;

    for(i = 0; i < tam; i++)
    {
        // soma += *(*(matriz + i) + i);
        soma += matriz[i][i];
    }

    printf("\nSoma da diagonal: %d\n", soma);
}

int main()
{
    int tam, i;

    printf("Digite a dimensão da matriz: ");
    scanf(" %d", &tam);

    // Declara um "Vetor de ponteiros" do tipo inteiro
    int **matriz = (int **) malloc(tam * sizeof(int *));
    // Cada posição do "Vetor de ponteiro" vai receber um Ponteiro para outro Vetor, criando uma matriz
    for(i = 0; i < tam; i++)
    {
        // *(matriz + i) = (int *) malloc(tam * sizeof(int));
        matriz[i] = (int *) malloc(tam * sizeof(int));
    }

    preencher(matriz, tam);
    exibir(matriz, tam);
    diagPrin(matriz, tam);

    // Libera o espaço ocupado por cada ponteiro do "Vetor de Ponteiro"
    for(i = 0; i < tam; i++)
    {
        // free(*(matriz + i));
        free(matriz[i]);
    }
    // Libera espaço pelo "Vetor de Ponteiro"
    free(matriz);
    return 0;
}