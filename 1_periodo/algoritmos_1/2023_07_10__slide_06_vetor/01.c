#include <stdio.h>

int main(void)
{
    int vetor[8], i;
    int quant30=0, soma30=0, soma_total=0;

    for (i=0; i < 8; i++)
    {
        printf("%dº Número: ", i+1);
        scanf("%d", &vetor[i]);
    }

    printf("\nNúmeros digitados:\n");
    for (i=0; i < 8; i++)
    {
        printf("\nNúmero: %d", vetor[i]);
        
        if (vetor[i] > 30)
        {
            quant30 ++;
            soma30 += vetor[i];
        }
        soma_total += vetor[i];
    }
    
    printf("\nNúmeros maiores que 30: %d", quant30);
    printf("\nSoma dos maiores que 30: %d", soma30);
    printf("\nSoma Total: %d\n", soma_total);
    return 0;
}