#include <stdio.h>

/*
    Dados N números digitados pelo usuário, exibir o somatório deles.
    Onde o valor N é dado também pelo usuário.
*/

int main(void)
{
    int n, num, soma, i;

    printf("\nQuantidade de números digitados: ");
    scanf(" %d", &n);
    printf("\n");
    soma = 0;
    for (i = 0; i < n; i++)
    {
        printf("%dº número: ", i+1);
        scanf(" %d", &num);
        soma += num;
    }
    printf("\nSomatório: %d\n", soma);
    return 0;
}