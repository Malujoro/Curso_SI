#include <stdio.h>
#include <stdlib.h>

int main()
{
    char vetor[100], letras[100];
    int quant = 0, naoExiste, repeticao;

    printf("Digite uma palavra: ");
    scanf(" %[^\n]s", vetor);

    for(int i = 0; vetor[i] != '\0'; i++)
    {
        naoExiste = 1;

        for(int j = 0; j < quant; j++)
        {
            if(vetor[i] == letras[j])
            {
                naoExiste = 0;
                break;
            }
        }

        if(quant == 0 || naoExiste)
        {
            letras[quant] = vetor[i];
            quant++;
        }
    }

    for(int i = 0; i < quant; i++)
    {
        repeticao = 0;
        for(int j = i; vetor[j] != '\0'; j++)
        {
            if(letras[i] == vetor[j])
                repeticao++;
        }
        printf("'%c' = %d\n", letras[i], repeticao);
    }

    return 0;
}