#include <stdio.h>
#include <stdlib.h>
#include "str.h"

char *alocaStr(int tam)
{
    char *str = (char *) malloc(tam * sizeof(char));

    if(!str)
    {
        printf("ERRO na alocação\n");
        exit(EXIT_FAILURE);
    }
    return str;
}

int main()
{
    char *string1 = alocaStr(40);
    char string2[] = {"Alef Cauan"};
    char *string3 = alocaStr(40);

    printf("Digite uma string: ");
    scanf(" %[^\n]s", string1);

    printf("len = %d\n", strlen(string1));
    printf("As strings são iguais? %d\n", strcmp(string1, string2));
    string3 = strcopy(string1, string3);
    printf("A strings 3 é %s\n", string3);
    string3 = strjoin(string1, string2, string3);
    printf("A strings 3 é %s\n", string3);
    
    return 0;
}