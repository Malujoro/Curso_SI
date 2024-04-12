#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n;

    printf("Digite o tamanho da matriz (M N): ");
    scanf(" %d %d", &m, &n);

    int **matriz = (int **) malloc(m * sizeof(int *));
    matriz[0] = (int *) malloc(n * sizeof(int));
    for(int i = 1; i < m; i++)
        matriz[i] = matriz[0];

    for(int i = 0; i < m; i++)
        matriz[0][i] = i;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }

    free(matriz[0]);
    free(matriz);
    return 0;
}