#include <stdio.h>

int main(void)
{
    float n;

    printf("\nNúmero real: ");
    scanf("%f", &n);

    printf("Terça metade: %.2f\n", n/3/2);

    return 0;
}