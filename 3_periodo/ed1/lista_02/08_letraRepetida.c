#include <stdio.h>
#include <stdlib.h>

char *alocarVetor(char tam)
{
    char *vetor = (char *) malloc(tam * sizeof(char));

    if(!vetor)
    {
        printf("Erro! Não foi possível alocar o vetor!");
        exit(EXIT_FAILURE);
    }

    return vetor;
}

void exibirVetor(int *vetor, int tam)
{
    for(int i = 0; i < tam; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

int *repete(char *frase, char letra, int *quant)
{
    int tam = 0;
    *quant = 0;
    
    while(frase[tam] != '\0')
    {
        if(frase[tam] == letra)
            (*quant)++;
        tam++;
    }

    int *repetidos = (int *) malloc((*quant) * sizeof(int));

    for(int i = 0, j = 0; i < tam; i++)
    {
        if(frase[i] == letra)
        {
            repetidos[j] = i;
            j++;
        }
    }

    return repetidos;
}

int main()
{
    char *vetor = alocarVetor(100);
    char letra;

    printf("Digite uma frase: ");
    scanf(" %[^\n]s", vetor);

    printf("Digite uma letra: ");
    scanf(" %c", &letra);

    while(getchar() != '\n');

    int tam;
    int *repetidos = repete(vetor, letra, &tam);

    printf("\nA letra %c aparece %d vezes.", letra, tam);
    printf("\nNas posições: ");
    exibirVetor(repetidos, tam);

    return 0;
}