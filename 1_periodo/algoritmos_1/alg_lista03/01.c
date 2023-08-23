#include <stdio.h>

/*
    Exibir os múltiplos de 5 no intervalo de 1 a 100.
*/

int main(void)
{
    int i;

    printf("\nMúltiplos de 5 de 1 a 100");
    for (i = 1; i < 101; i++)
    {
        if (i % 5 == 0)
            printf("\n%d", i);
    }
    printf("\n");
    return 0;
}