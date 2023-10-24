#include <stdio.h>

int main()
{
    int i, tam;

    printf("\nDigite o comprimento do vetor: ");
    scanf(" %d", &tam);

    int vetor[tam];
    printf("\n");
    for(i = 0; i < tam; i++)
    {
        printf("%dº valor: ", i+1);
        scanf(" %d", &vetor[i]);
    }
    for(i = tam-1; i >= 0; i--)
    {
        printf("\n%dº valor: %d", i+1, vetor[i]);
    }
    printf("\n");
    return 0;
}