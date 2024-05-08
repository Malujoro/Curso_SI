#include <stdio.h>
#include <stdlib.h>
#include "str.h"

int str_len(char *str1)
{
    int aux = 0;
    while (str1[aux] != '\0')
        aux++;

    return aux;
}

int str_cmp(char *str, char *str2)
{
    if (str_len(str) != str_len(str2))
        return 1;

    for (int i = 0; i < str_len(str)-1; i++)
    {
        if (str[i]!=str2[i])
            return 1;
    }
    return 0;    
}

char *str_copy(char *str, char *string)
{
    int len_string1 = str_len(str);

    for(int i = 0; i < len_string1; i++)
        string[i] = str[i];
    
    string[len_string1] = '\0';
    
    return string;
}

char *str_join(char *str, char *str2, char *str3)
{
    int tam1 = str_len(str);
    int tam2 = str_len(str2);
    
    for(int i = 0; i < tam1; i++)
        str3[i] = str[i];

    for(int i = tam1, j = 0; j < tam2; i++, j++)
        str3[i] = str2[j];
    
    str3[tam1 + tam2] = '\0';
    
    return str3;
}