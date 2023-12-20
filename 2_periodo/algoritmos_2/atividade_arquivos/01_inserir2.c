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

// Função que recebe o endereço de um arquivo e conta a primeira frase do arquivo
int conta_frase(FILE *arquivo)
{
    int tam = 0;
    while(fgetc(arquivo) != '\n') 
        tam++;
    
    return tam;
}

int main()
{
    FILE *arquivo;
    int tam;

    arquivo = abrir_arquivo("01.txt", "w");
    escreve(arquivo);
    fclose(arquivo);


    arquivo = abrir_arquivo("01.txt", "r");
    
    tam = conta_frase(arquivo);

    char palavra[tam];
    rewind(arquivo); // Função para voltar o arquivo pro início
    fgets(palavra, tam+1, arquivo);

    printf("\nA palavra %s tem %d letras\n", palavra, tam);
    
    fclose(arquivo);

    return 0;
}