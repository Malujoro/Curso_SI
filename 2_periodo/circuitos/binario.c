#include <stdio.h>

int main(void)
{
    float n, r;
    
    printf("\nDigite um número decimal: ");
    scanf(" %f", &n);
    r = n;

    printf("Número digitado: %f\n\n", n);
    while (r != 0)
    {
        if (r >= 1)
            r -= 1;

        if (r != 0)
        {
            printf("%f * ", r);   
            r *= 2;
            printf("2 = %f\n", r);
        }
    }
    
    return 0;
}