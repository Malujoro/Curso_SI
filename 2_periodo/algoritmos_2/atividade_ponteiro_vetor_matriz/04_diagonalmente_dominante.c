#include <stdio.h>
#include <stdlib.h>

void preencher(int **matriz, int tam)
{
    int i, j;

    printf("\n");
    for(i = 0; i < tam; i++)
    {
        for(j = 0; j < tam; j++)
        {
            printf("Matriz[%d][%d]: ", i, j);
            scanf(" %d", (*(matriz + i) + j));
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
            printf("%d \t", *(*(matriz + i) + j));
        }
        printf("\n");
    }
}

int diagonal_dominante(int **matriz, int tam)
{
    int i, j, soma;

    for(i = 0; i < tam; i++)
    {
        soma = 0;
        for(j = 0; j < tam; j++)
        {
            if(i != j)
                soma += abs(*(*(matriz + i) + j));
        }
        if(abs(*(*(matriz + i) + i)) <= soma)
            return 0;
    }
    return 1;
}

int main()
{
    int tam, i;

    printf("Dimensão da matriz: ");
    scanf(" %d", &tam);

    int **matriz = (int **) malloc(tam * sizeof(int *));
    for(i = 0; i < tam; i++)
    {
        *(matriz + i) = (int *) malloc(tam * sizeof(int));
    }
    
    preencher(matriz, tam);
    exibir(matriz, tam);
    if(diagonal_dominante(matriz, tam))
        printf("\nÉ diagonalmente dominante\n");
    else
        printf("\nNÃO é diagonalmente dominante\n");


    for(i = 0; i < tam; i++)
    {
        free(*(matriz + i));
    }
    free(matriz);
    return 0;
}