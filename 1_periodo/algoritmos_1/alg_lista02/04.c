#include <stdio.h>

/*
    Dado um número, informar se ele é divisível por 3, por 7 ou por 11 ou se
    não é divisível por nenhum dos três números.
*/

int main(void)
{
    int num;

    printf("\nNúmero inteiro: ");
    scanf(" %d", &num);
    printf("\n");
    if (num % 3 == 0 || num % 7 == 0 || num % 11 == 0)
    {
        if (num % 3 == 0)
        {
            printf("É divisível por 3\n");
        }
        if (num % 7 == 0)
        {
            printf("É divisível por 7\n");
        }
        if (num % 11 == 0)
        {
            printf("É divisível por 11\n");
        }
    }
    else
    {
        printf("Não é divisível por nenhum dos três números\n");
    }
    
    return 0;
}