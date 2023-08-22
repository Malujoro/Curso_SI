#include <stdio.h>

// Preencher um vetor com os números 10 a 20,
// e depois mostrar os elementos ímpares do vetor.

int main(void)
{
    int pos, cont = 10, vetor[11];

    for (pos = 0; pos < 11; pos++)
    {
        vetor[pos] = cont;
        cont++;
    }

    for (pos = 0; pos < 11; pos++)
    {
        if (vetor[pos] % 2 == 1)
        {
            printf("%d\n", vetor[pos]);
        }
    }
    
    return 0;
}