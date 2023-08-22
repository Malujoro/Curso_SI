#include <stdio.h>

/*
    Dado um número, informar se ele é divisível por 3 e por 7.
*/

int main(void)
{
    int num;

    printf("\nNúmero inteiro: ");
    scanf(" %d", &num);

    if (num % 3 == 0 && num % 7 == 0)
    {
        printf("\nÉ divisível por 3 e por 7\n");
    }
    else
    {
        printf("\nNão é divisível por 3 e por 7\n");
    }
    return 0;
}