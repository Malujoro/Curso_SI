#include <stdio.h>
#include <stdlib.h>

int main()
{
    int quant;
    printf("Tamanho da string a ser digitada: ");
    scanf("%d", &quant);

    char *string = (char *) malloc(quant * sizeof(char));

    printf("String: ");
    scanf("%s", string);

    printf("Você digitou [%s]\n", string);

    free(string);
    return 0;
}