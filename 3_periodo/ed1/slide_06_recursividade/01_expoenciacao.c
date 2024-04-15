#include <stdio.h>

float potencia(int b, int p)
{
    if(b == 0)
        return 0;
    else if(p == 0)
        return 1;
    else if(p > 0)
        return b * potencia(b, p-1);
    return 1.0 / b * potencia(b, p+1);
}

int main()
{
    int base = 2;

    for(int i = -5; i < 6; i++)
        printf("\n%d^%d = %f\n", base, i, potencia(base, i));

    return 0;
}