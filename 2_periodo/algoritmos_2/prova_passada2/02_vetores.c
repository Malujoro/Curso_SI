#include <stdio.h>
#include <stdlib.h>

void preencherVetor(float *vetor, int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        printf("%dº valor: ", i+1);
        scanf(" %f", &vetor[i]);
    }
}

void verificaTamanho(int tam1, int tam2)
{
    if(tam1 == tam2)
        printf("\nTamanhos iguais\n");
    else
        printf("\nTamanhos diferentes\n");
}

void verificaValoresComum(float *vetor1, int tam1, float *vetor2, int tam2)
{
    int i, j;

    for(i = 0; i < tam1; i++)
    {
        for(j = 0; j < tam2; j++)
        {
            if(vetor1[i] == vetor2[j])
            {
                printf("\nExistem valores comuns\n");
                return;
            }
        }
    }
    printf("\nNão existem valores comuns\n");
}

float calcula_Soma(float *vetor, int tam)
{
    int i;
    float soma = 0;

    for(i = 0; i < tam; i++)
        soma += vetor[i];
    
    return soma;
}

int main()
{
    int tam1, tam2;
    float soma1, soma2;

    printf("Tamanho do 1º vetor: ");
    scanf(" %d", &tam1);

    float *vetor1 = (float *) malloc(tam1 * sizeof(float));
    preencherVetor(vetor1, tam1);

    printf("Tamanho do 2º vetor: ");
    scanf(" %d", &tam2);

    float *vetor2 = (float *) malloc(tam2 * sizeof(float));

    preencherVetor(vetor2, tam2);

    verificaTamanho(tam1, tam2);
    verificaValoresComum(vetor1, tam1, vetor2, tam2);

    soma1 = calcula_Soma(vetor1, tam1);
    soma2 = calcula_Soma(vetor2, tam2);

    if(soma1 == soma2)
        printf("\nA soma dos valores dos vetores são iguais\n");
    else
        printf("\nA soma dos valores dos vetores não são iguais\n");

    free(vetor1);
    free(vetor2);

    return 0;
}