#include <stdio.h>

void troca_vetor(float vetor1[], float vetor2[])
{
    float aux;
    int i;

    for(i = 0; i < 5; i++)
    {
        aux = vetor1[i];
        vetor1[i] = vetor2[i];
        vetor2[i] = aux;
    }
}

int main()
{
    float x[5], y[5];
    int i;

    for(i = 0; i < 5; i++)
    {
        printf("x[%d]: ", i);
        scanf(" %f", &x[i]);
    }
    printf("\n");
    for(i = 0; i < 5; i++)
    {
        printf("y[%d]: ", i);
        scanf(" %f", &y[i]);
    }

    troca_vetor(x, y);

    for(i = 0; i < 5; i++)
    {
        printf("\nx[%d]: %.1f", i, x[i]);
    }
    printf("\n");
    for(i = 0; i < 5; i++)
    {
        printf("\ny[%d]: %.1f", i, y[i]);
    }
    return 0;
}