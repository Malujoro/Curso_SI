#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *abrir_arquivo(char *nome, char *modo)
{
    FILE *arquivo = fopen(nome, modo);

    if(arquivo == NULL)
    {
        printf("\nERRO! Arquivo não pode ser aberto\n");
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
        palavra = realloc(palavra, (tam+1)*sizeof(char));
    }while(palavra[tam-1] != '\n');
    tam--;
    palavra[tam] = '\0';
    
    return tam;
}

int leitura_dinamica_arquivo(FILE *arquivo, char *palavra)
{
    int tam = 0;
    // "String dinâmica" baseada na leitura de um arquivo
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
    char *nome;
    FILE *arquivo1, *arquivo2;
    int tam_nome, tam, i;

    nome = (char *) malloc(sizeof(char));
    printf("Digite o nome de arquivo: ");
    tam_nome = leitura_dinamica(nome);

    char *nome2 = (char *) malloc((tam_nome+4) * sizeof(char));

    strncat(nome2, nome, tam_nome-4);
    strcat(nome2, "_inv.txt");

    arquivo1 = abrir_arquivo(nome, "r");
    arquivo2 = abrir_arquivo(nome2, "w");
    
    do
    {
        tam = leitura_dinamica_arquivo(arquivo1, nome);

        for(i = tam-1; i >= 0; i--)
            fputc(nome[i], arquivo2);
        if(tam > 0)
            fputc('\n', arquivo2);
    }while(tam > 0);
    free(nome2);
    free(nome);

    fclose(arquivo1);
    fclose(arquivo2);

    printf("\nNomes gravados com sucesso!!\n");

    return 0;
}