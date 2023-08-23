#include <stdio.h>

/*
    Dados N números digitados pelo usuário, exibir o maior e o menor deles.
*/

int main(void)
{
    int n, num, maior, menor, i;

    printf("\nQuantidade de números digitados: ");
    scanf(" %d", &n);
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%dº número: ", i+1);
        scanf(" %d", &num);
        if (i == 0)
        {
            maior = num;
            menor = num;
        }
        else
        {
            if (num > maior)
                maior = num;

            if (num < menor)
                menor = num;
        }
    }
    printf("\nMaior: %d", maior);
    printf("\nMenor: %d\n", menor);
    return 0;
}