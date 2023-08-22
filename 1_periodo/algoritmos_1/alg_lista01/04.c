#include <stdio.h>

int main(void)
{
    float n1, n2;

    printf("1º Número: ");
    scanf("%f", &n1);

    printf("2º Número: ");
    scanf("%f", &n2);

    printf("Média: %.2f\n", ((n1+n2)/2));
    return 0;
}