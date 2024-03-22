#include <stdio.h>
#include <stdlib.h>

char *subtrai(char *s1, char *s2)
{
    char *s3 = (char *) malloc(sizeof(char));
    int tam3 = 0;

    for(int i = 0; s1[i] != '\0'; i++)
    {
        int igual = 0;
        for(int j = 0; s2[j] != '\0'; j++)
        {
            if(s1[i] == s2[j])
            {
                igual = 1;
                break;
            }
        }

        if(igual == 0)
        {
            s3[tam3] = s1[i];
            tam3++;
            s3 = (char *) realloc(s3, (tam3+1)*sizeof(char));
        }
    }
    s3[tam3] = '\0';
    return s3;
}

int main()
{
    char *s1 = (char *) malloc(100 * sizeof(char));
    char *s2 = (char *) malloc(100 * sizeof(char));

    printf("Escreva uma frase: ");
    scanf(" %[^\n]s", s1);
    
    printf("\nDigite as letras que deseja retirar (Ex: abc): ");
    scanf(" %[^\n]s", s2);

    char *s3 = subtrai(s1, s2);

    printf("\nFrase modificada: %s\n", s3);

    free(s1);
    free(s2);
    free(s3);
    
    return 0;
}