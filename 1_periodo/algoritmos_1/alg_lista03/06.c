#include <stdio.h>
#include <math.h>

/*
    Entrar com N números, exibir a metade e a raiz cúbica de cada número.
    Onde o valor N é dado também pelo usuário.
*/

int main(void)
{
    int num, i, quant;

    printf("\nQuantidade de números digitados: ");
    scanf(" %d", &quant);

    for (i = 0; i < quant; i++)
    {
        printf("\n%dº Número: ", i+1);
        scanf(" %d", &num);

        printf("Metade de %d: %.1f", num, num/2.0);
        printf("\nRaíz cúbica de %d: %.1f\n", num, pow(num, 1.0/3.0));
    }
    printf("\n");
    return 0;
}