#include <stdio.h>

/*
    Dados 20 números, exibir a média aritmética dos números pares e a
    média aritmética dos números ímpares.
*/

int main(void)
{
    int i, num, quant_impar = 0, quant_par = 0;
    float media_impar = 0, media_par = 0;

    for (i = 0; i < 20; i++)
    {
        printf("%dº número: ", i+1);
        scanf(" %d", &num);

        if (num % 2 == 0)
        {
            quant_par++;
            media_par += num;
        }
        else
        {
            quant_impar++;
            media_impar += num;
        }
    }
    
    if (quant_impar > 0)
        media_impar /= quant_impar;
    if (quant_par > 0)
        media_par /= quant_par;

    printf("\nMédia dos pares: %.1f", media_par);
    printf("\nMédia dos ímpares: %.1f\n", media_impar);

    return 0;
}