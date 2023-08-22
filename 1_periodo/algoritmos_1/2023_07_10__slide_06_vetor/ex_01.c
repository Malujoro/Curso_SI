#include <stdio.h>

int main(void)
{
    int tamanho=1, i, maior, menor;
    float media;

    while (tamanho != 0)
    {    
        printf("\nQuantidade de números: ");
        setbuf(stdin, NULL);
        scanf("%d", &tamanho);

        int vetor[tamanho];

        for (i=0; i < tamanho; i++)
        {
            printf("%dº Número: ", i+1);
            setbuf(stdin, NULL);
            scanf("%d", &vetor[i]);
        }

        for (i=tamanho-1; i >= 0; i--)
        {
            printf("\nNúmero: %d", vetor[i]);
        }
        printf("\n");

        media = vetor[0];
        maior = vetor[0];
        menor = vetor[0];
        
        for (i=1; i < tamanho; i++)
        {
            media += vetor[i];
            if (vetor[i] > maior)
            {
                maior = vetor[i];
            }
            if (vetor[i] < menor)
            {
                menor = vetor[i];
            }
        }
        media /= tamanho;
        printf("\nMaior: %d", maior);
        printf("\nMenor: %d", menor);
        printf("\nMedia: %f", media);
    }   
        return 0;
}