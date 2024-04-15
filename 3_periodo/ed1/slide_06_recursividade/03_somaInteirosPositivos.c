#include <stdio.h>

int somaInteiros(int k)
{
    if(k <= 0)
        return 0;
    return k + somaInteiros(k-1);
}

int main()
{
    int k = 5;

    printf("Soma dos inteiros de %d até 0: %d\n", k, somaInteiros(k));

    return 0;
}