#include <stdio.h>
#include <stdlib.h>

FILE *abrir_arquivo(char *nome, char *modo)
{
    FILE *arquivo = fopen(nome, modo);

    if(arquivo == NULL)
    {
        printf("\nERRO! Arquivo não pôde ser aberto\n");
        exit(EXIT_FAILURE);
    }
    return arquivo;
}

// Função que recebe o endereço de um arquivo e grava uma frase nele
void escreve(FILE *arquivo)
{
    char ch;

    printf("Digite uma palavra: ");
    do
    {
        ch = getchar();
        fputc(ch, arquivo);
    }while(ch != '\n');
}

// Função que recebe o endereço de um arquivo e um vetor dinâmico, lê e insere uma frase nele
int leitura_frase(FILE *arquivo, char *palavra)
{
    int tam = 0;
    // "String dinâmica" baseada na leitura de um arquivo
    do 
    {
        palavra[tam] = fgetc(arquivo);
        tam++;
        palavra = realloc(palavra, (tam+1)*sizeof(char));
    }while(palavra[tam-1] != '\n');
    tam--;
    palavra[tam] = '\0';
    
    return tam;
}

int main()
{
    FILE *arquivo;
    char *palavra;
    int tam;

    arquivo = abrir_arquivo("01.txt", "w");
    escreve(arquivo);
    fclose(arquivo);


    arquivo = abrir_arquivo("01.txt", "r");
    
    palavra = (char *) malloc(sizeof(char));
    tam = leitura_frase(arquivo, palavra);
    printf("\nA palavra %s tem %d letras\n", palavra, tam);
    
    fclose(arquivo);

    free(palavra);
    return 0;
}