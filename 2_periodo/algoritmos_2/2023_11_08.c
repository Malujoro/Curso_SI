#include <stdio.h>

void preencher(int vetor[], int tam)
{
    int i;

    printf("\n");
    for(i = 0; i < tam; i ++)
    {
        printf("Vetor[%d]: ", i);
        scanf(" %d", &vetor[i]);
    }
}

int verifica_valores(int vetor1[], int tam1, int vetor2[], int tam2)
{
    int i, j, k, total = 0;

    for(i = 0; i < tam1; i++)
    {
        for(j = 0; j < tam2; j++)
        {
            for(k = 0; k < tam2; k++)
            {
                if(vetor1[j] == vetor1[k])
                    break;
            }
            if((j == k) && (vetor1[i] == vetor2[j]))
                total++;
        }
    }
    return total;
}

int main()
{
    int tam1, tam2, total;

    printf("Tamanho do Vetor 1: ");
    scanf(" %d", &tam1);

    printf("Tamanho do Vetor 2: ");
    scanf(" %d", &tam2);

    int vetor1[tam1], vetor2[tam2];

    preencher(vetor1, tam1);
    preencher(vetor2, tam2);
    total = verifica_valores(vetor1, tam1, vetor2, tam2);

    printf("\nExistem %d valores repetidos\n", total);
    return 0;
}