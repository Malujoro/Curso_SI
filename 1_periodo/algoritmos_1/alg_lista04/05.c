#include <stdio.h>

// Modifique o exercício anterior para que sejam inseridos N números ao invés de 100

int main(void)
{
    int quant;
    int i, maior, menor;
    float soma, media, quant_par, quant_impar, par=0, impar=0;

    printf("Quantos números serão digitados? ");
    scanf("%d", &quant);
    setbuf(stdin, NULL);

    int vetor[quant];

    for (i = 0; i < quant; i++)
    {
        printf("%dº número: ", i+1);
        scanf("%d", &vetor[i]);
        setbuf(stdin, NULL);
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