#include <stdio.h>
#include <stdlib.h>

#define MAXCHAR 100

struct Pessoa 
{
    char nome[MAXCHAR];
    int idade;
    float altura;
};

// void cadastro(FILE *arquivo, )
// {

// }

int main()
{
    FILE *arquivo = fopen("2023_12_14.bin", "ab");
    
    if(arquivo == NULL)
        printf("Erro! Arquivo não aberto");
    else
    {
        struct Pessoa pessoa;

        printf("Digite um nome: ");
        scanf("%[^\n]s", pessoa.nome);

        printf("Digite uma idade: ");
        scanf(" %d", &pessoa.idade);

        printf("Digite uma altura: ");
        scanf(" %f", &pessoa.altura);

        fwrite(&pessoa, sizeof(struct Pessoa), 1, arquivo);
        // fputs("\n", arquivo);

        fclose(arquivo);

        struct Pessoa pessoa2;
        arquivo = fopen("2023_12_14.bin", "rb");
        printf("\n");
        while(fread(&pessoa2, sizeof(struct Pessoa), 1, arquivo) == 1)
        {
            printf("\nNome: %s", pessoa2.nome);
            printf("\nIdade: %d", pessoa2.idade);
            printf("\nAltura: %.2f\n", pessoa2.altura);
        }
        fclose(arquivo);
    }

    return 0;
}