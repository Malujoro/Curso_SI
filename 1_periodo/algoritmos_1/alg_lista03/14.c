#include <stdio.h>

/*
    Entrar com números positivos e exibir se cada número é par ou impar.
    O algoritmo termina quando é digitado -1.
*/

int main(void)
{
    int num;

    do
    {
        printf("\nNúmero [-1 sai]: ");
        scanf(" %d", &num);
        if (num > 0)
        {
            if (num % 2 == 0)
                printf("Par\n");
            else
                printf("Ímpar\n");
        }
    } while (num >= 0);

    return 0;
}