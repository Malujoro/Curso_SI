#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
            matriz[i][j] = (rand() % 9) + 1;
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
    printf("\n");
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

int **transposta(int **matriz, int lin, int col)
{
    int **matrizT = alocarMatriz(col, lin);

    for(int i = 0; i < lin; i++)
    {
        for(int j = 0; j < col; j++)
            matrizT[j][i] = matriz[i][j];
    }

    return matrizT;
}

int main()
{
    int m, n;

    srand(time(NULL));

    printf("Tamanho M N da matriz: ");
    scanf(" %d %d", &m, &n);

    int **matriz = alocarMatriz(m, n);
    preencherMatriz(matriz, m, n);

    int **matrizT = transposta(matriz, m, n);

    exibirMatriz(matriz, m, n);
    exibirMatriz(matrizT, n, m);

    liberarMatriz(matriz, m);
    liberarMatriz(matrizT, n);
    return 0;
}