#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    char nome[50];
    char data[11];
} Pessoa;

typedef struct
{
    char nome[50];
    int idade;
} Pessoa2;

FILE *abrir_arquivo(char *nome, char *modo)
{
    FILE *arquivo = fopen(nome, modo);

    if(arquivo == NULL)
    {
        printf("\nERRO!! Arquivo não pode ser aberto\n");
        exit(EXIT_FAILURE);
    }

    return arquivo;
}

int leitura_dinamica_palavra(char *palavra)
{
    int tam = 0;
    
    do
    {
        palavra[tam] = getchar();
        tam++;
        palavra = realloc(palavra, (tam+1) * sizeof(char));
    }while(palavra[tam-1] != '\n');
    tam--;
    palavra[tam] = '\0';

    return tam;
}

int ano_atual()
{
    time_t atual;
    struct tm *infoTempo;

    // Obtém a hora atual em segundos desde 1 de janeiro de 1970 (Epoch)
    time(&atual);

    // Converte a hora atual para uma estrutura de tempo local
    infoTempo = localtime(&atual);

    // Retorna o ano atual (adiciona 1900, pois tm_year contém o ano desde 1900)
    return infoTempo->tm_year + 1900;
}

void menu(int *op)
{
    printf("\n-------Menu-------");
    printf("\n[1] - Cadastrar");
    printf("\n[2] - Exibir");
    printf("\n[3] - Montar arquivo de idades");
    printf("\n[4] - Exibir idade");
    printf("\nOpção: ");
    scanf(" %d", op);
    while(getchar() != '\n');
}

int main()
{
    FILE *arquivo;
    char *palavra;
    Pessoa pessoa;
    Pessoa2 pessoa2;

    int op;

    menu(&op);

    palavra = (char *) malloc(sizeof(char));
    switch(op)
    {
        case 1:
            arquivo = abrir_arquivo("04_ano.bin", "ab");

            leitura_dinamica_palavra(palavra);
            strcpy(pessoa.nome, palavra);

            leitura_dinamica_palavra(palavra);
            strcpy(pessoa.data, palavra);

            fwrite(&pessoa, sizeof(Pessoa), 1, arquivo);
        
            fclose(arquivo);
            break;

        case 2:
            arquivo = abrir_arquivo("04_ano.bin", "rb");

            while(fread(&pessoa, sizeof(Pessoa), 1, arquivo) == 1)
                printf("%s | %s\n", pessoa.nome, pessoa.data);
            
            fclose(arquivo);
            break;

        case 3:
            int i;
            char ano[5];

            arquivo = abrir_arquivo("04_ano.bin", "rb");
            FILE *arquivo2 = abrir_arquivo("04_idade.bin", "wb");

            while(fread(&pessoa, sizeof(Pessoa), 1, arquivo) == 1)
            {
                strcpy(pessoa2.nome, pessoa.nome);
                for(i = 0; i < 5; i++)
                    ano[i] = pessoa.data[i+6];
                pessoa2.idade = ano_atual() - atoi(ano);
                fwrite(&pessoa2, sizeof(Pessoa2), 1, arquivo2);
            }

            fclose(arquivo2);
            break;

        case 4:
            arquivo = abrir_arquivo("04_idade.bin", "rb");

            while(fread(&pessoa2, sizeof(Pessoa2), 1, arquivo) == 1)
                printf("%s | %d\n", pessoa2.nome, pessoa2.idade);
            
            fclose(arquivo);
            break;
    }

    free(palavra);
    return 0;
}