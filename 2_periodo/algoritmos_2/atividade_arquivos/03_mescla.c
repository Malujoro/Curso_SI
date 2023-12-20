#include <stdio.h>
#include <stdlib.h>

FILE *abrir_arquivo(char *nome, char *modo)
{
    FILE *arquivo = fopen(nome, modo);

    if(arquivo == NULL)
    {
        printf("ERRO! Não foi possível abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    return arquivo;
}

int leitura_dinamica_arquivo(char *palavra, FILE *arquivo)
{
    int tam = 0;

    do
    {
        palavra[tam] = fgetc(arquivo);
        tam++;
        palavra = realloc(palavra, (tam+1)*sizeof(char));
    }while(palavra[tam-1] != '\n' && palavra[tam-1] != EOF);
    tam--;
    palavra[tam] = '\0';

    return tam;
}

int main()
{
    FILE *arquivo1, *arquivo2, *arquivo3;
    char *linha1, *linha2;
    int tam1, tam2;

    arquivo1 = abrir_arquivo("01.txt", "r");
    arquivo2 = abrir_arquivo("01_inv.txt", "r");
    arquivo3 = abrir_arquivo("03.txt", "w");

    linha1 = (char *) malloc(sizeof(char));
    linha2 = (char *) malloc(sizeof(char));
    do
    {
        tam1 = leitura_dinamica_arquivo(linha1, arquivo1);
        if(tam1 > 0)
        {
            fputs(linha1, arquivo3);
            fputc('\n', arquivo3);
        }

        tam2 = leitura_dinamica_arquivo(linha2, arquivo2);
        if(tam2 > 0)
        {
            fputs(linha2, arquivo3);
            fputc('\n', arquivo3);
        }
    }while(tam1 > 0 || tam2 > 0);

    printf("\nArquivo 1 e 2 Mesclados com sucesso!\n");

    free(linha1);
    free(linha2);

    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivo3);

    return 0;
}