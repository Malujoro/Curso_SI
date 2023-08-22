#include <stdio.h>

/*
    Dado um número, informar se ele está na casa das unidades, dezenas, centenas,
    milhares ou acima dos milhares
*/

int main(void)
{
    int num;

    printf("Número: ");
    scanf(" %d", &num);

    if (num < 10)
        printf("Casa das unidades");
    else if (num < 100)
        printf("Casa das dezenas");
    else if (num < 1000)
        printf("Casa das centenas");
    else if (num < 10000)
        printf("Casa dos milhares");
    else
        printf("Casa acima dos milhares");
    
    printf("\n");
    return 0;
}