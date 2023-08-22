#include <stdio.h>

int main(void)
{
    int num, quant_i=0, quant_p=0, i=0;

    while (i < 20)
    {
        printf("%dº número: ", i+1);
        scanf("%d", &num);

        if (num % 2 == 0)
        {
            quant_p++;
        }
        else
        {
            quant_i++;
        }
        i++;
    }
    printf("Foram digitados %d pares e %d ímpares", quant_p, quant_i);
    return 0;
}