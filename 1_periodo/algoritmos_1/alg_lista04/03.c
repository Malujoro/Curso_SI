#include <stdio.h>

// Entrar com um vetor A com 50 números inteiros
// Gerar um vetor B onde cada elemento é o quadrado do elemento, na respectiva
// posição do vetor A

int main(void)
{
    int quant = 50, i;
    int vetor_a[quant], vetor_b[quant];

    for (i = 0; i < quant; i++)
    {
        printf("%dº Número: ", i+1);
        scanf("%d", &vetor_a[i]);

        vetor_b[i] = vetor_a[i] * vetor_a[i];
    }

    for (i = 0; i < quant; i++)
    {
        printf("\nA: %d | B: %d", vetor_a[i], vetor_b[i]);
    }

    return 0;
}