#include <stdio.h>
#include <stdlib.h>

int main()
{
    int lin, col;

    printf("Tamanho da matriz (Linhas Colunas): ");
    scanf(" %d %d", &lin, &col);

    float **matriz = (float **) malloc(lin * sizeof(float *));
    for(int i = 0; i < lin; i++)
        matriz[i] = (float *) malloc(col * sizeof(float));


    for(int i = 0; i < lin; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("Matriz[%d][%d]: ", i, j);
            scanf(" %f", &matriz[i][j]);
        }
    }

    for(int i = 0; i < lin; i++)
    {
        for(int j = 0; j < col; j++)
            printf("\nMatriz[%d][%d]: %.2f", i, j, matriz[i][j]);
    }
    printf("\n");

    for(int i = 0; i < lin; i++)
        free(matriz[i]);
    free(matriz);
    return 0;
}