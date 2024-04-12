#include <stdio.h>
#include <stdlib.h>

int **alocarMatriz(int lin, int col)
{
    int **matriz = (int **) malloc(lin * sizeof(int *));
    
    if(!matriz)
    {
        printf("Erro! Não foi possível alocar a matriz");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < lin; i++)
    {
        matriz[i] = (int *) malloc(col * sizeof(int));
        if(!matriz[i])
        {
            printf("Erro! Não foi possível alocar a matriz");
            exit(EXIT_FAILURE);
        }
    }
    
    return matriz;
}

void preencherMatriz(int **matriz, int lin, int col)
{
    for(int i = 0; i < lin; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("Matriz[%d][%d]: ", i, j);
            scanf(" %d", &matriz[i][j]);
        }
    }
}

void exibirMatriz(int **matriz, int lin, int col)
{
    for(int i = 0; i < lin; i++)
    {
        for(int j = 0; j < col; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

void liberarMatriz(int **matriz, int lin)
{
    for(int i = 0; i < lin; i++)
    {
        free(matriz[i]);
        matriz[i] = NULL;
    }
    
    free(matriz);
    matriz = NULL;
}

int main()
{
    int m, n;

    printf("Tamanhos a matriz M e N: ");
    scanf(" %d %d", &m, &n);

    int **matriz = alocarMatriz(m, n);
    preencherMatriz(matriz, m, n);
    exibirMatriz(matriz, m, n);
    liberarMatriz(matriz, m);

    return 0;
}