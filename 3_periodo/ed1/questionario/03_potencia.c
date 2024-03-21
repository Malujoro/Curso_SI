#include <stdio.h>

int potencia(int x, int y)
{
    if(y == 0)
        return 1;
    else if(y == 1)
        return x;

    return x * potencia(x, y-1);
}

int main()
{
    int x, y, result;

    printf("Base: ");
    scanf(" %d", &x);

    printf("Potência: ");
    scanf(" %d", &y);

    result = potencia(x, y);

    printf("%d^%d = %d\n", x, y, result);

    return 0;
}