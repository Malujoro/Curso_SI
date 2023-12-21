#include <stdio.h>
#include <stdlib.h>

FILE *abrir_arquivo(char *nome, char *modo)
{
    FILE *arquivo = fopen(nome, modo);

    if(arquivo == NULL)
    {
        printf("ERRO!! Arquivo pôde ser aberto");
        exit(EXIT_FAILURE);
    }
    return arquivo;
}

int leitura_dinamica(char *palavra)
{
    int tam = 0;

    do
    {
        palavra[tam] = getchar();
        tam++;
        palavra = realloc(palavra, (tam+1) * sizeof(char));
    } while (palavra[tam-1] != '\n');
    tam--;
    palavra[tam] = '\0';

    return tam;
}

int main()
{
    FILE *arquivo = abrir_arquivo("05.txt", "a");
    int tam, i, j;
    char *palavra = (char *) malloc(sizeof(char));

    printf("Digite apenas caracteres: ");
    tam = leitura_dinamica(palavra);

    for(i = 0; i < tam; i++)
    {
        if(!((palavra[i] >= 'a' && palavra[i] <= 'z') || (palavra[i] >= 'A' && palavra[i] <= 'Z')))
            break;
    }

    if(i == tam)
    {
        char *vetor = (char *) malloc(sizeof(char));
        int tam2 = 0, ocorr = 0, repet;
        vetor[0] = palavra[0];
        tam2++;
        vetor = realloc(vetor, (tam2+1) * sizeof(char));
        // Laço para criar um vetor com apenas "letras únicas" (uma letra de cada)
        for(i = 1; i < tam; i++)
        {
            for(j = 0; j < tam2; j++)
            {
                if(palavra[i] == vetor[j])
                    break;
            }

            if(j == tam2)
            {
                vetor[tam2] = palavra[i];
                tam2++;
                vetor = realloc(vetor, (tam2+1) * sizeof(char));
            }
        }
        vetor[tam2] = '\0';
        // Laço para comparar se existem letras repetidas e contar quantas "letras únicas" se repetem
        for(i = 0; i < tam2; i++)
        {
            for(repet = 0, j = 0; j < tam; j++)
            {
                if(vetor[i] == palavra[j])
                    repet++;
            }

            if(repet > 1)
                ocorr++;
        }
        printf("\nPalavra: %s | Letras únicas: %s | Ocorrências: %d\n", palavra, vetor, ocorr);

        fputs(palavra, arquivo);
        fputc('\n', arquivo);
        free(vetor);
    }
    else
        printf("\nERRO! Digite apenas caracteres\n");

    free(palavra);
    fclose(arquivo);
    return 0;
}