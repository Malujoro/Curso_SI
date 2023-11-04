#include <stdio.h>

float media(float n1, float n2, float n3, char op)
{
    float result;
    switch(op)
    {
        case 'A':
            result = (n1 + n2 + n3) / 3;
            return result;
            break;
        
        case 'P':
            result = ((n1 * 3) + (n2 * 4) + (n3 * 3)) / 10;
            return result;
            break;
        
        default:
            return 0;
    }
}

int main()
{
    printf("Média: %.2f", media(2, 2, 2, 'P'));
    return 0;
}