#include <stdio.h>

/*
    Dadas as idades de várias pessoas, exibir a menor idade, a maior idade
    e a média aritmética das idades.
    O programa termina quando for digitada uma idade -1.
*/

int main(void)
{
    float media = 0;
    int maior, menor, idade, quant = 0;

    do
    {
        printf("%dª idade [-1 sai]: ", quant+1);
        scanf(" %d", &idade);

        if (idade >= 0)
        {
            if (quant == 0 || idade > maior)
                maior = idade;
            if (quant == 0 || idade < menor)
                menor = idade;
            
            media += idade;

            quant ++;
        }
    } while (idade != -1);
    
    media /= quant;

    printf("\nMenor idade: %d", menor);
    printf("\nMaior idade: %d", maior);
    printf("\nMédia: %.1f\n", media);
    return 0;
}