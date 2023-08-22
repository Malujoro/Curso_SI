#include <stdio.h>

// Dados 100 números armazenados em um vetor, exibir:
// a. o maior número
// b. o menor número
// c. o somatório de todos os números
// d. a média aritmética de todos os números
// e. o percentual de números pares
// f. o percentual de números ímpares

int main(void)
{
    int quant = 100, i;
    int vetor[quant];
    int maior, menor;
    float soma, media, quant_par, quant_impar, par=0, impar=0;

    for (i = 0; i < quant; i++)
    {
        printf("%dº número: ", i+1);
        scanf("%d", &vetor[i]);
    }

    maior = vetor[0];
    menor = vetor[0];
    soma = 0;
    for (i = 0; i < quant; i++)
    {
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }

        if (vetor[i] < menor)
        {
            menor = vetor[i];
        }

        soma += vetor[i];

        if (vetor[i] % 2 == 0)
        {
            quant_par ++;
        }
        else
        {
            quant_impar ++;
        }

    }

    media = soma / quant;
    par = (quant_par / quant) * 100;
    impar = (quant_impar / quant) * 100;

    printf("\nMaior: %d", maior);
    printf("\nMenor: %d", menor);
    printf("\nSomatório: %.0f", soma);
    printf("\nMédia: %.2f", media);
    printf("\nPorcentagem pares: %.2f%%", par);
    printf("\nPorcentagem ímpares: %.2f%%\n", impar);

    return 0;
}