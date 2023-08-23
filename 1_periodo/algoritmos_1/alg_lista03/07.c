#include <stdio.h>

/*
    Dados os números inteiros A e B, fazer um algoritmo que calcule A^B.
*/

int main(void)
{
    int  i, a, b, result;

    printf("Base: ");
    scanf(" %d", &a);

    printf("Expoente: ");
    scanf(" %d", &b);

    result = a;
    for (i = 1; i < b; i++)
    {
        result *= a;
    }


    printf("%d elevado a %d = %d\n", a, b, result);
    return 0;
}