#include <stdio.h>

float calcula(float n1, float n2, char sinal)
{
    float result;

    switch (sinal)
    {
        case '+':
            result = n1 + n2;
            break;
        case '-':
            result = n1 - n2;
            break;
        case '*':
        case 'x':
        case 'X':
            result = n1 * n2;
            break;
        case '/':
            result = n1 / n2;
            break;
    }
    return result;

}

int fatorial(int num)
{
    int i, result = 1;

    for(i = num; i > 1; i--)
    {
        result *= i;
    }
    return result;
}

int main()
{
    int n = 5;
    
    printf("\nFatorial de %d: %d\n", n, fatorial(n));
}