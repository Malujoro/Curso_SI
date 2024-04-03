// Programa para gerar uma string aleatória dependendo
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x;

    printf("Tamanho da string: ");
    scanf(" %d", &x);

    char nome[x];
    // 32 a 126
    // 94 - Diferença de 32
    for(int i = 0; i < x; i++)
        nome[i] = (rand() % 95) + 32;

    printf("String: %s\n", nome);
    return 0;
}