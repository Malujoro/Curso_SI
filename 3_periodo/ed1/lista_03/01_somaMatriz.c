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

int **somarMatriz(int **matriz1, int **matriz2, int tam)
{
    int **matriz3 = alocarMatriz(tam, tam);

    for(int i = 0; i < tam; i++)
    {
        for(int j = 0; j < tam; j++)
            matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
    }
    
    return matriz3;
}

int main()
{
    int tam = 5;
    int **a = alocarMatriz(tam, tam);
    int **b = alocarMatriz(tam, tam);

    preencherMatriz(a, tam, tam);
    preencherMatriz(b, tam, tam);

    int **matriz3 = somarMatriz(a, b, tam);

    exibirMatriz(a, tam, tam);
    exibirMatriz(b, tam, tam);
    exibirMatriz(matriz3, tam, tam);

    liberarMatriz(a, tam);
    liberarMatriz(b, tam);
    liberarMatriz(matriz3, tam);
    return 0;
}