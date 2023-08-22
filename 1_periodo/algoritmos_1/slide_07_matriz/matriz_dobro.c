#include <stdio.h>

int main(void)
{
    int matriz[3][3], dobro[3][3];
    int c, l;

    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("Número na posição [%d, %d]: ", l+1, c+1);
            scanf("%d", &matriz[l][c]);
            setbuf(stdin, NULL);
            dobro[l][c] = matriz[l][c] * 2;
        }
    }

    printf("\nMatriz dobrada:");

    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("\nNúmero na posição [%d, %d]: %d", l+1, c+1, dobro[l][c]);
        }
    }

    return 0;
}