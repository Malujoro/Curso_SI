#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tam = -1;
    char *palavra = (char *) malloc(1 * sizeof(char));

    printf("Digite uma palavra: ");
    do
    {
        tam++;
        palavra[tam] = getchar();
        palavra = realloc(palavra, (tam+2)*sizeof(char));
    }while(palavra[tam] != '\n');
    palavra[tam] = '\0';
    
    printf("\nPalavra: %s | %d letras\n", palavra, tam);

    return 0;
}