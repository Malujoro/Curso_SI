#include <stdio.h>
#include <stdlib.h>

int **alocarMatriz(int m, int n)
{
    int **matriz = (int **) malloc(m * sizeof(int *));

    if(!matriz)
        exit(1);

    for(int i = 0; i < m; i++)
    {
        matriz[i] = (int *) malloc(n * sizeof(int));
        
        if(!matriz)
            exit(1);
    }

    int cont = 1;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            matriz[i][j] = cont;
            cont++;
        }
    }

    return matriz;
}

void imprimirMatriz(int **matriz, int m, int n)
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
    int m = 5, n = 4;
    int **matriz = alocarMatriz(m, n);
    imprimirMatriz(matriz, m, n);
    return 0;
}