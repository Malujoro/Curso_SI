#include <stdio.h>

float raizQuadrada(int num)
{
    float raiz = 0;
    float casa = 1;

    while(1)
    {
        for(int i = 0; raiz * raiz <= num; i++)
        {
            if(raiz * raiz == num || raiz + casa == raiz)
                return raiz;

            raiz += casa;
        }
        raiz -= casa;
        casa /= 10;
    };
}

int main()
{
    int num = 2;
    printf("Raiz quadrade de %d: %f\n", num, raizQuadrada(num));

    return 0;
}