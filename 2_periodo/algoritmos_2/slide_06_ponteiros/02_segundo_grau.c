#include <stdio.h>
#include <math.h>

int raizes(float a, float b, float c, float *x1, float *x2)
{
    float delta;

    if(a == 0)
    {
        printf("\nErro! O valor A deve ser diferente de 0\n");
    }
    else
    {
        delta = pow(b, 2) - (4 * a * c);

        if(delta >= 0)
        {
            *x1 = (-b + sqrt(delta)) / 2 * a;
            *x2 = (-b - sqrt(delta)) / 2 * a;
            if(delta == 0)
                return 1;
            else if(delta > 0)
                return 2;
        }
    }
    return 0;
}

int main()
{
    float a, b, c, x1, x2;
    int quant;

    printf("Digite os valores de A, B e C: ");
    scanf(" %f %f %f", &a, &b, &c);

    quant = raizes(a, b, c, &x1, &x2);
    printf("\nA equação (%.1fx²) + (%.1fx) + (%.1f) tem %d raíz(es)", a, b, c, quant);
    printf("\n[X1: %.1f] [X2: %.1f]\n", x1, x2);
    return 0;
}