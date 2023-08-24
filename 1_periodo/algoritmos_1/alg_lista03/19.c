#include <stdio.h>

/*
    Dados 20 números, exibir quantos são impares e quantos são pares.
*/

int main(void)
{
    int num, impar = 0, par = 0, i;
    
    printf("\n");
    for (i = 0; i < 20; i++)
    {
        printf("%dº Número: ", i+1);
        scanf(" %d", &num);

        if (num % 2 == 0)
            par++;
        else
            impar++;
    }

    printf("\n%d ímpares", impar);
    printf("\n%d pares\n", par);

    return 0;
}