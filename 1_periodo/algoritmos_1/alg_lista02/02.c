#include <stdio.h>

/*
    Dado um número, informar se ele é ou não é divisível por 5.
*/

int main(void)
{
    int num;

    printf("\nNúmero inteiro: ");
    scanf(" %d", &num);

    if (num % 5 == 0)
    {
        printf("\nÉ divisível por 5\n");
    }
    else
    {
        printf("\nNão é divisível por 5\n");
    }
    return 0;
}