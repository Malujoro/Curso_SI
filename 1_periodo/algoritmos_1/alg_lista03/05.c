#include <stdio.h>
#include <math.h>

/*
    Entrar com dez números, exibir a metade e a raiz cúbica de cada número.
*/

int main(void)
{
    int num, i;

    for (i = 0; i < 10; i++)
    {
        printf("\n%dº Número: ", i+1);
        scanf(" %d", &num);

        printf("Metade de %d: %.1f", num, num/2.0);
        printf("\nRaíz cúbica de %d: %.1f\n", num, pow(num, 1.0/3.0));
    }

    return 0;
}