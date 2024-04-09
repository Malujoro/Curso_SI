#include <stdio.h>
#include <stdlib.h>

char *repete(char *s, int n)
{
    int tam;

    for(tam = 0; s[tam] != '\0'; tam++);

    int novoTam = ((tam+1) * n)-1;

    char *novaFrase = (char *) malloc((novoTam+1) * sizeof(char));

    for(int i = 0; i < novoTam; i++)
    {
        for(int j = 0; j < tam; j++, i++)
            novaFrase[i] = s[j];
        novaFrase[i] = ' ';
    }
    novaFrase[novoTam] = '\0';
    return novaFrase;
}

int main()
{
    char *nome = repete("[Mateus]", 5);
    printf("\n%s\n", nome);

    return 0;
}