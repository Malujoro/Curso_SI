#include <stdio.h>
#include <stdlib.h>

int **alocaMatriz(int m, int n)
{
    int **matriz = (int **) malloc(m * sizeof(int *));
    for(int i = 0; i < m; i++)
        matriz[i] = (int *) malloc(n * sizeof(int ));
    
    return matriz;
}

void liberaMatriz(int **matriz, int m)
{
    for(int i = 0; i < m; i++)
        free(matriz[i]);
    free(matriz);
}

void preencheMatriz(int **matriz, int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            matriz[i][j] = i+j;
    }
}

void exibeMatriz(int **matriz, int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

int main()
{
    int m, n;

    printf("Digite o tamanho M N de uma matriz: ");
    scanf(" %d %d", &m, &n);

    int **matriz = alocaMatriz(m, n);

    preencheMatriz(matriz, m, n);
    exibeMatriz(matriz, m, n);

    liberaMatriz(matriz, m);
    return 0;
}