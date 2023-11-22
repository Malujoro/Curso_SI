#include <stdio.h>

void frac(float num, int *inteiro, float *dec)
{
    *inteiro = num;
    *dec = num - *inteiro;
}

int main()
{
    float num, dec;
    int inteiro;

    printf("Digite um número decimal: ");
    scanf(" %f", &num);

    frac(num, &inteiro, &dec);

    printf("%.2f = %d + %.2f\n", num, inteiro, dec);

    return 0;
}