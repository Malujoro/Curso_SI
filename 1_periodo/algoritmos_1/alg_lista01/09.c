#include <stdio.h>

int main(void)
{
    int n, c, d, u;
    
    printf("Número inteiro de 3 algarismos: ");
    scanf("%d", &n);

    c = n / 100;
    d = (n % 100) / 10;
    u = ((n % 100) % 10);

    printf("\nCentena: %d", c);
    printf("\nDezena : %d", d);
    printf("\nUnidade: %d", u);
}