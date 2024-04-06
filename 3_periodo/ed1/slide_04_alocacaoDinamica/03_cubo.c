#include <stdio.h>
#include <stdlib.h>

void preencheCubo(int ***cubo, int tam)
{
    int quant = 0;
    
    for(int i = 0; i < tam; i++)
    {
        for(int j = 0; j < tam; j++)
        {
            for(int k = 0; k < tam; k++)
            {
                cubo[i][j][k] = quant;
                quant++;
            }
        }
    }
}

void exibeCubo(int ***cubo, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        for(int j = 0; j < tam; j++)
        {
            for(int k = 0; k < tam; k++)
                printf("%d \t", cubo[i][j][k]);
            printf("\n");
        }
        printf("\n");
    }
}

int main()
{
    int tam;
    
    printf("Tamanho do cubo: ");
    scanf(" %d", &tam);

    int ***cubo = (int ***) malloc(tam * sizeof(int **));
    
    for(int i = 0; i < tam; i++)
    {
        cubo[i] = (int **) malloc(tam * sizeof(int *));
        for(int j = 0; j < tam; j++)
            cubo[i][j] = (int *) malloc(tam * sizeof(int));
    }
    
    printf("\n");
    preencheCubo(cubo, tam);
    exibeCubo(cubo, tam);

    for(int i = 0; i < tam; i++)
    {
        for(int j = 0; j < tam; j++)
            free(cubo[i][j]);
        free(cubo[i]);
    }
    free(cubo);

    return 0;
}