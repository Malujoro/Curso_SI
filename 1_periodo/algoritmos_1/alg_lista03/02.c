#include <stdio.h>

/*
    Exibir o quadrado dos números de 10 a 30.
*/

int main(void)
{
    int i;

    for (i = 10; i < 31; i++)
    {
        printf("\n%d ao quadrado é %d", i, i*i);
    }
    printf("\n");
    return 0;
}