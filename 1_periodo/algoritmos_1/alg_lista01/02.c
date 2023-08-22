#include <stdio.h>

int main(void)
{
    int numero;

    printf("Número: ");
    scanf("%d", &numero);


    printf("\nAntecessor: %d", numero-1);
    printf("\nSucessor: %d\n", numero+1);

    return 0;
}