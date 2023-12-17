#include <stdio.h>
#include <stdlib.h>

#define TAM_STR 50

typedef struct
{
	char titulo[TAM_STR];
	char autor[TAM_STR];
	int registro;
	float preco;
} Livro;

void menu(int *op)
{
	char ch;

	printf("\n----------Menu----------");
	// Leitura e Gravação - Caractere por Caractere
	printf("\n[1] - Leitura de frases por caractere por caractere");
	printf("\n[2] - Exibir frases por caractere por caractere");
	// Leitura e Gravação - Linha por Linha
	printf("\n[3] - Leitura de frases linha a linha");
	printf("\n[4] - Exibir frases linha a linha");
	// Leitura e Gravação - Dados formatados
	printf("\n[5] - Leitura de frases dados formatados");
	printf("\n[6] - Exibir frases dados formatados");
	// Leitura e Gravação - Blocos de Bytes (Matrizes ou Structs)
	printf("\n[7] - Leitura de frases struct");
	printf("\n[8] - Exibir frases struct");
	printf("\n[0] - Sair do programa");
	printf("\nOpção: ");
	scanf(" %d", op);

	while((ch = getchar()) != '\n');
	printf("\n");
}

FILE *abrir_arquivo(char *nome, char *modo)
{
	FILE *arquivo = fopen(nome, modo);

	if(arquivo == NULL)
	{
		printf("Erro de abertura!!");
		exit(EXIT_FAILURE);
	}
	return arquivo;
}

int main()
{
	FILE *arquivo;
	int op, codigo;
	char ch, string[TAM_STR];
	float preco;
	Livro item;

	do
	{
		menu(&op);

		switch(op)
		{
			case 1:
				arquivo = abrir_arquivo("teste1.txt", "a");
				
				printf("Digite uma frase: ");
				while((ch = getchar()) != '\n')
					fputc(ch, arquivo);
				fputc('\n', arquivo);
				
				fclose(arquivo);
				break;

			case 2:
				arquivo = abrir_arquivo("teste1.txt", "r");
				
				// feof - Retorna verdadeiro caso tenha chegado no final do arquivo
				while(!feof(arquivo))
				{
					// fgetc - Retorna o caractere lido ou EOF no fim do arquivo
					ch = fgetc(arquivo);
					printf("%c", ch);
				}
				
				fclose(arquivo);
				break;

			case 3:
				arquivo = abrir_arquivo("teste2.txt", "a");

				printf("Digite uma frase: ");
				scanf(" %[^\n]s", string);
				fputs(string, arquivo);
				fputs("\n", arquivo);

				fclose(arquivo);
				break;

			case 4:
				arquivo = abrir_arquivo("teste2.txt", "r");

				while(fgets(string, TAM_STR, arquivo) != NULL)
					printf("%s", string);

				fclose(arquivo);
				break;
			
			case 5:
				arquivo = abrir_arquivo("teste3.txt", "a");
			
				printf("Título: ");
				scanf(" %[^\n]s", string);
			
				printf("Código: ");
				scanf(" %d", &codigo);
			
				printf("Preço: ");
				scanf(" %f", &preco);

				fprintf(arquivo, "%s %d %.2f\n", string, codigo, preco);
			
				fclose(arquivo);
				break;
			
			case 6:
				arquivo = abrir_arquivo("teste3.txt", "r");
			
				printf("%-16s %-12s %-8s\n", "Título", "Código", "Preço");
				while(fscanf(arquivo, "%s %d %f", string, &codigo, &preco) != EOF)
					printf("%-16s %-10d R$%-4.2f\n", string, codigo, preco);
			
				fclose(arquivo);
				break;
			
			case 7:
				arquivo = abrir_arquivo("teste4.bin", "ab");
			
				printf("Título: ");
				scanf(" %[^\n]s", item.titulo);
				
				printf("Autor: ");
				scanf(" %[^\n]s", item.autor);
			
				printf("Código: ");
				scanf(" %d", &item.registro);
			
				printf("Preço: ");
				scanf(" %f", &item.preco);
			
				fwrite(&item, sizeof(Livro), 1, arquivo);

				fclose(arquivo);
				break;
			
			case 8:
				arquivo = abrir_arquivo("teste4.bin", "rb");
			
				while(fread(&item, sizeof(Livro), 1, arquivo) == 1)
				{
					printf("\nTítulo: %s", item.titulo);
					printf("\nAutor: %s", item.autor);
					printf("\nCódigo: %d", item.registro);
					printf("\nPreço: R$%.2f\n", item.preco);
				}
			
				fclose(arquivo);
				break;
			
			case 0:
				break;
		}


	}while(op != 0);

    return 0;
}