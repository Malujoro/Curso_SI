#include <stdio.h>

/*
    Entrar com as idades de 20 pessoas. Exibir a média aritmética das idades,
    a maior idade e menor idade.
*/

int main(void)
{
    int quant = 20, idade, maior, menor, i;
    float media = 0;

    for (i = 0; i < quant; i++)
    {
        printf("%dª idade: ", i+1);
        scanf(" %d", &idade);
        
        if (i == 0 || idade > maior)
            maior = idade;
        if (i == 0 || idade < menor)
            menor = idade;

        media += idade;
    }
    media /= quant;

    printf("\nMaior idade: %d", maior);
    printf("\nMenor idade: %d", menor);
    printf("\nMédia: %.1f\n", media);
    return 0;
}