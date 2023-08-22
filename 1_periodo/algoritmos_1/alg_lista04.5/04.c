#include <stdio.h>

// Elaborar um algoritmo que lê uma matriz M(6,6) e um valor A.
// Multiplicar a matriz M pelo valor A e inserir em outra matriz
// mostrar para o usuário as duas matrizes

int main(void)
{
    int l, c, matriz[6][6], cont=1, a, matriz_A[6][6];
    
    printf("Valor A: ");
    scanf("%d", &a);

    for (l = 0; l < 6; l++)
    {
        for (c = 0; c < 6; c++)
        {
            matriz[l][c] = cont;
            matriz_A[l][c] = matriz[l][c] * a;
            cont++;
        }
    }

    printf("\nMatriz 1:\n");
    for (l = 0; l < 6; l++)
    {
        for (c = 0; c < 6; c++)
        {
            printf("%d \t", matriz[l][c]);
        }
        printf("\n");
    }

    printf("\nMatriz A:\n");
    for (l = 0; l < 6; l++)
    {
        for (c = 0; c < 6; c++)
        {
            printf("%d \t", matriz_A[l][c]);
        }
        printf("\n");
    }
    return 0;
}