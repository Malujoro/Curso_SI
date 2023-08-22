#include <stdio.h>

int main(void)
{
    int n, c, d, u, n2;
    
    printf("Número inteiro de 3 algarismos: ");
    scanf("%d", &n);

    c = n / 100;
    d = (n % 100) / 10;
    u = ((n % 100) % 10);
    n2 = (u * 100) + (d * 10) + c;

    printf("\nNúmero invertido: %d", n2);
}