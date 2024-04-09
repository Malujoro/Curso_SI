#include <stdio.h>
#include <stdlib.h>

double **alocarMatriz(int m, int n)
{
    double **matriz = (double **) malloc(m * sizeof(double *));
    for(int i = 0; i < m; i++)
        matriz[i] = (double *) malloc(n * sizeof(double));
}

void desalocarMatriz(double **matriz, int m)
{
    for(int i = 0; i < m; i++)
        free(matriz[i]);
    free(matriz);
}

void preencherMatriz(double **matriz, int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("Matri");
            scanf("%f", &matriz[i][j]);
        }
    }
}

int main()
{
    int m, n;

    printf("Tamanho das matrizes: ");
    scanf(" %d %d", &m, &n);

    double **matriz1 = alocarMatriz(m, n);
    preencherMatriz(matriz1, m, n);

    double **matriz2 = alocarMatriz(m, n);
    preencherMatriz(matriz2, m, n);

    double **matriz3 = alocarMatriz(m, n);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
    }

    desalocarMatriz(matriz1, m);
    desalocarMatriz(matriz2, m);
    return 0;
}