#include <stdio.h>

int somaIntervalo(int a, int b)
{
    if(b < a)
        return somaIntervalo(b, a);
    else if(a == b)
        return a;
    return a + somaIntervalo(a+1, b);
}

int main()
{
    int a = 3, b = 5;

    printf("Soma do intervalo [%d a %d]: %d\n", a, b, somaIntervalo(a,b));

    return 0;
}