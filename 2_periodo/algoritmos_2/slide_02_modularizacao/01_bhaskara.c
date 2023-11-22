#include <stdio.h>
#include <math.h>

void bhaskara(float a, float b, float c)
{
    float delta, x1, x2;

    if(a == 0)
        printf("\nErro! o valor de A não pode ser 0\n");
    else
    {
        delta = pow(b, 2) - 4 * a * c;
        printf("\nValor de delta: [%.0f]", delta);
        if(delta < 0)
            printf("\nNão existem raízes reais\n");
        else
        {
            x1 = (-b + sqrt(delta)) / 2 * a;
            x2 = (-b - sqrt(delta)) / 2 * a;

            if(delta == 0)
            {
                printf("\nApenas uma raíz real:");
                printf("\nx = [%.2f]\n", x1);
            }
            else if(delta > 0)
            {
                printf("\nExistem duas raízes reais:");
                printf("\nx1 = [%.2f] e x2 = [%.2f]\n", x1, x2);
            }
        }
    }
}

int main()
{
    float a, b, c;

    printf("Valor de A: ");
    scanf(" %f", &a);

    printf("Valor de B: ");
    scanf(" %f", &b);
    
    printf("Valor de C: ");
    scanf(" %f", &c);

    bhaskara(a, b, c);

    return 0;
}