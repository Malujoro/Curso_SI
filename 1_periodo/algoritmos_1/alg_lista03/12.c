#include <stdio.h>

/*
    Dados N números digitados pelo usuário, exibir o somatório, o maior e o
    menor deles.
*/

int main(void)
{
    int i, n, num, soma, maior, menor;

    printf("\nQuantidade de números digitados: ");
    scanf(" %d", &n);
    printf("\n");
    soma = 0;
    for (i = 0; i < n; i++)
    {
        printf("%dº número: ", i+1);
        scanf(" %d", &num);
        soma += num;
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
    printf("\nSomatório: %d", soma);
    printf("\nMaior: %d", maior);
    printf("\nMenor: %d\n", menor);
    return 0;
}