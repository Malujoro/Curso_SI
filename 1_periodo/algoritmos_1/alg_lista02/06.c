#include <stdio.h>

/*
    Dado um número de três algarismos, dizer se cada algarismo é par ou impar
*/

int main(void)
{
    int num, cent, dez, uni;

    printf("Número de 3 algarismos: ");
    scanf(" %d", &num);

    cent = num / 100;
    dez = (num % 100) / 10;
    uni = num % 100 % 10;
    
    
    printf("\nCentena: %d - ", cent);
    if (cent % 2 == 0)
        printf("Par");
    else
        printf("Ímpar");
    
    printf("\nDezena: %d - ", dez);
    if (dez % 2 == 0)
        printf("Par");
    else
        printf("Ímpar");

    printf("\nUnidade: %d - ", uni);
    if (uni % 2 == 0)
        printf("Par\n");
    else
        printf("Ímpar\n");

    return 0;
}