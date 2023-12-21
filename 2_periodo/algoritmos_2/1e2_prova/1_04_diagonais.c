#include <stdio.h>

int main()
{
    int i, j, linhas, colunas;
    float diag1 = 1, diag2 = 1, soma;

    printf("Linhas da matriz: ");
    scanf(" %d", &linhas);

    printf("Colunas da matriz: ");
    scanf(" %d", &colunas);

    float matriz[linhas][colunas];

    if(linhas == colunas)
    {
        for(i = 0; i < linhas; i++)
        {
            for(j = 0; j < linhas; j++)
            {
                printf("Elemento [%d][%d]: ", i, j);
                scanf(" %f", &matriz[i][j]);

                if(i == j)
                {
                    diag1 *= matriz[i][j];
                }
                if((i+j) == (linhas-1))
                {
                    diag2 *= matriz[i][j];
                }
            }
        }
    }
    soma = diag1 + diag2;
    printf("\nMultiplicação da diagonal principal: %f", diag1);
    printf("\nMultiplicação da diagonal secundária: %f", diag2);
    printf("\nSoma das multiplicações: %f\n", soma);
    return 0;
}