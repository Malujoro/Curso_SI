#include <stdio.h>

int main()
{
    int num, x = -1, soma = 0, maior, menor, quant = 0;
    float media;

    do
    {
        printf("Digite um número (-1 para sair): ");
        scanf(" %d", &num);

        if(num != x)
        {
            if(quant == 0 || num > maior)
                maior = num;
            
            if(quant == 0 || num < menor)
                menor = num;

            soma += num;
            quant++;
        }
    }while(num != x);

    if(quant > 0)
    {
        media = (float) soma/quant;

        printf("\nSoma: %d", soma);
        printf("\nMédia: %.2f", media);
        printf("\nMaior: %d, menor: %d", maior, menor);
    }

    return 0;
}