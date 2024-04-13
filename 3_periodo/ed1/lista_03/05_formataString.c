#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 100

char *alocarVetor(int tam)
{
    char *vetor = (char *) malloc(tam * sizeof(char));

    if(!vetor)
    {
        printf("Erro! Não foi possível alocar");
        exit(EXIT_FAILURE);
    }

    return vetor;
}

void desalocarVetor(char *vetor)
{
    free(vetor);
    vetor = NULL;
}

int tamanho(char *string)
{
    int tam;

    for(tam = 0; string[tam] != '\0'; tam++);

    return tam;
}

char *minuscula(char *string)
{
    int tam = tamanho(string);
    char *stringMinuscula = alocarVetor(tam);

    for(int i = 0; i < tam; i++)
    {
        if(string[i] >= 'A' && string[i] <= 'Z')
            stringMinuscula[i] = string[i] + ('a' - 'A');
        else
            stringMinuscula[i] = string[i];
    }

    return stringMinuscula;
}

char *maiuscula(char *string)
{
    int tam = tamanho(string);
    char *stringMaiuscula = alocarVetor(tam);

    for(int i = 0; i < tam; i++)
    {
        if(string[i] >= 'a' && string[i] <= 'z')
            stringMaiuscula[i] = string[i] - ('a' - 'A');
        else
            stringMaiuscula[i] = string[i];
    }

    return stringMaiuscula;
}

int main()
{
    char *string = alocarVetor(MAX_STR);

    printf("Digite uma frase (com apenas letras): ");
    scanf(" %s", string);

    int tam = tamanho(string);

    string = (char *) realloc(string, tam * sizeof(char));

    char *stringMinuscula = minuscula(string);
    char *stringMaiuscula = maiuscula(string);
    char *stringAlternado = alocarVetor(tam);

    for(int i = 0; i < tam; i++)
    {
        if(i % 2 == 0)
            stringAlternado[i] = stringMaiuscula[i];
        else
            stringAlternado[i] = stringMinuscula[i];
    }

    printf("\nMinúscula: %s", stringMinuscula);
    printf("\nMaiuscula: %s", stringMaiuscula);
    printf("\nAlternado: %s\n", stringAlternado);

    desalocarVetor(string);
    desalocarVetor(stringMaiuscula);
    desalocarVetor(stringMinuscula);
    desalocarVetor(stringAlternado);
    return 0;
}