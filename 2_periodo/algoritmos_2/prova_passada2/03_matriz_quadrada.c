#include <stdio.h>
#include <stdlib.h>

int verificaPreencheMatriz(int **matriz, int lin, int col)
{
    int i, j;

    if(lin == col)
    {
        for(i = 0; i < lin; i++)
        {
            for(j = 0; j < col; j++)
            {
                printf("Matriz[%d][%d]: ", i, j);
                scanf(" %d", &matriz[i][j]);
            }
        }
        return 1;
    }
    else
        return 0;
}

int somaDiagonalPrimaria(int **matriz, int tam)
{
    int i, soma = 0;

    for(i = 0; i < tam; i++)
        soma += matriz[i][i];

    return soma;
}

int somaDiagonalSecundaria(int **matriz, int tam)
{
    int i, j, soma = 0;

    for(i = 0; i < tam; i++)
    {
        for(j = 0; j < tam; j++)
        {
            if(i+j == tam-1)
                soma += matriz[i][j];
        }
    }
    return soma;
}

int main()
{
    int lin, col, i;
    int soma1, soma2;

    printf("Linhas: ");
    scanf(" %d", &lin);

    printf("Colunas: ");
    scanf(" %d", &col);

    int **matriz;

    matriz = (int **) malloc(lin * sizeof(int *));
    for(i = 0; i < lin; i++)
        matriz[i] = (int *) malloc(col * sizeof(int));

    if(verificaPreencheMatriz(matriz, lin, col))
    {
        soma1 = somaDiagonalPrimaria(matriz, lin);
        soma2 = somaDiagonalSecundaria(matriz, lin);
    }
    else
        printf("\nMatriz não é quadrada!!");

    printf("\nSoma principal: %d", soma1);
    printf("\nSoma secundária: %d", soma2);

    for(i = 0; i < lin; i++)
        free(matriz[i]);
    free(matriz);

    return 0;
}