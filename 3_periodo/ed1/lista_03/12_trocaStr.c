#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 100

char *alocarVetor(char tam)
{
    char *vetor = (char *) malloc(tam * sizeof(char));
    
    if(!vetor)
    {
        printf("Erro! Não foi possível alocar o vetor");
        exit(EXIT_FAILURE);
    }

    return vetor;
}

void liberarVetor(char *vetor)
{
    free(vetor);
    vetor = NULL;
}

void trocarEndereco(char **s1, char **s2)
{
    char *s3 = *s1;
    *s1 = *s2;
    *s2 = s3;
}

int main()
{
    char *s1 = alocarVetor(MAX_STR);
    char *s2 = alocarVetor(MAX_STR);

    printf("Digite a String 1: ");
    scanf(" %[^\n]s", s1);

    printf("Digite a String 2: ");
    scanf(" %[^\n]s", s2);

    trocarEndereco(&s1, &s2);

    printf("\ns1: %s", s1);
    printf("\ns2: %s", s2);

    return 0;
}