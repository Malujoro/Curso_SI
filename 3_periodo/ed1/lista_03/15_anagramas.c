#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 3

char *alocarStr(int tam)
{
    char *vetor = (char *) malloc(tam * sizeof(char));
    
    if(!vetor)
    {
        printf("Erro! Não foi possível alocar o vetor");
        exit(EXIT_FAILURE);
    }
    
    return vetor;
}

int tamanho(char *str)
{
    int tam;

    for(tam = 0; str[tam] != '\0'; tam++);

    return tam;
}

int main()
{
    char *vetor = alocarStr(MAX_STR);

    printf("Digite no máximo 3 caracteres: ");
    scanf(" %s", vetor);

    int tam = tamanho(vetor);
    int tot = 0;

    for(int i = 0; i < tam; i++)
    {
        if(tam > 1)
        {
            for(int j = 0; j < tam; j++)
            {
                if(tam > 2)
                {
                    for(int k = 0; k < tam; k++)
                    {
                        if(i != j && i != k && j != k)
                        {
                            printf("%c%c%c\n", vetor[i], vetor[j], vetor[k]);
                            tot++;
                        }
                    }
                }
                else if(i != j)
                {
                    printf("%c%c\n", vetor[i], vetor[j]);
                    tot++;
                }
            }
        }
        else
        {
            printf("%c\n", vetor[i]);
            tot++;
        }
    }
    printf("\nSão %d anagramas possíveis\n", tot);
    return 0;
}