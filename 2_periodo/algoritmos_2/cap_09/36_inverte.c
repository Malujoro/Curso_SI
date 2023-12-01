#include <stdio.h>

void inverte(char *str)
{
    int tam, i, j;
    char aux;

    for(tam = 0; *(str + tam) != '\0'; tam++);

    for(i = 0, j = tam-1; i < j; i++, j-- )
    {
        aux = *(str + i);
        *(str + i) = *(str + j);
        *(str + j) = aux;
    }
}

int main()
{
    char nome[50];
    
    printf("Digite uma palavra: ");
    scanf(" %[^\n]s", nome);

    inverte(nome);

    printf("\nInvertendo essa palavra fica: %s\n", nome);
}