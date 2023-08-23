#include <stdio.h>

/*
    Exibir os números múltiplos de 3 no intervalo de 10 a 30.
*/

int main(void)
{
    int i;
    printf("\nMúltiplos de 3 de 10 a 30\n");
    for (i = 10; i <= 30; i++)
    {
        if (i % 3 == 0)
        {
            printf("\n%d", i);
        }
    }
    printf("\n");
    return 0;
}