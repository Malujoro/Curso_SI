#include <stdio.h>

float soma(int n1, float n2)
{
    return n1 + n2;
}

int main()
{
    int n1;
    float n2, result;

    printf("Digite o número inteiro: ");
    scanf(" %d", &n1);

    printf("Digite o número float: ");
    scanf(" %f", &n2);

    result = soma(n1, n2);
    printf("Soma de %d com %.1f: %.1f\n", n1, n2, result);

    return 0;
}