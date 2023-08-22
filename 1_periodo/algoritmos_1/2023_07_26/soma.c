#include <stdio.h>

void saudacao()
{
    printf("\n Seja Bem-vindo");
}

float soma(int n1, int n2)
{
    float result;
    result = n1 + n2;
    return result;
}

int main(void)
{
    float n1, n2, total;

    saudacao();

    printf("N1: ");
    scanf("%f", &n1);

    printf("N2: ");
    scanf("%f", &n2);

    total = soma(n1, n2);
    printf("O total é: %.2f", total);
}