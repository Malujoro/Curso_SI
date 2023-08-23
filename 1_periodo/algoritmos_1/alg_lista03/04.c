#include <stdio.h>

/*
    Exibir o somatório dos números entre 20 e 60.
*/

int main(void)
{
    int i, soma = 0;

    for (i = 20; i <= 60; i++)
    {
        soma += i;
    }
    printf("\nSomatório dos números entre 20 e 60: %d\n", soma);

    return 0;
}