#include <stdio.h>
#include <stdlib.h>

char *inverte(char *s)
{
    int tam;

    for(tam = 0; s[tam] != '\0'; tam++);
    
    char *nova = (char *) malloc(tam * sizeof(char));

    nova[tam] = '\0';
    tam--;

    for(int i = 0; i <= tam; i++, tam--)
    {
        nova[i] = s[tam];
        nova[tam] = s[i];
    }
    return nova;
}

int main()
{
    char vetor[] = "MateusLucas";
    char *invertido = inverte(vetor);

    printf("[%s] - [%s]\n", vetor, invertido);

    free(invertido);
    return 0;
}