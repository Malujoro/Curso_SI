#include <stdio.h>

/*
    Entrar com dois números que indiquem o limite inferior e superior de um
    intervalo.
    Exibir os números impares entre o intervalo.
*/

int main(void)
{
    int i, inf, sup;

    printf("Limite inferior: ");
    scanf(" %d", &inf);
    
    printf("Limite superior: ");
    scanf(" %d", &sup);

    printf("\n Números ímpares entre %d e %d:\n", inf, sup);
    for (i = inf; i < sup; i++)
    {
        if (i % 2 == 1)
            printf("%d\n", i);
    }

    return 0;
}