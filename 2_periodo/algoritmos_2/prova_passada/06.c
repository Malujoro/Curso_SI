#include <stdio.h>

void divide(float num)
{
    int inteiro = num;
    float decimal = num - inteiro;

    printf("%f é igual a %d + %f\n", num, inteiro, decimal);
}

int main()
{
    float n;

    printf("\nDigite um número: ");
    scanf(" %f", &n);

    divide(n);

    return 0;
}