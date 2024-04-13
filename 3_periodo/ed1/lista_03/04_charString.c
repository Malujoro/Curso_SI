#include <stdio.h>
#include <stdlib.h>

char *charString(char letra)
{
    char *string = (char *) malloc(sizeof(char));
    if(!string)
    {
        printf("Erro! Não foi possível alocar");
        exit(EXIT_FAILURE);
    }

    string[0] = letra;
    string[1] = '\0';
    return string;
}

int main()
{
    char letra = 'C';
    char *string = charString(letra);
    printf("%s\n", string);

    free(string);
    string = NULL;
    return 0;
}