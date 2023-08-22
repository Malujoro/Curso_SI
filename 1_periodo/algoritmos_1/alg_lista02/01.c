#include <stdio.h>

/*
    Dado um número, informar se ele é ou não é múltiplo de 3.
*/

int main(void)
{
    int num;

    printf("\nNúmero inteiro: ");
    scanf(" %d", &num);

    if (num % 3 == 0)
    {
        printf("\nÉ múltiplo de 3\n");
    }
    else
    {
        printf("\nNão é múltiplo de 3\n");
    }
    return 0;
}