#include <stdio.h>
#include <stdlib.h>

int main()
{
	char nome[100];
	int idade;
	float preco;

	FILE *arquivo = fopen("teste.txt", "w");
	fprintf(arquivo, "%d %.2f %s", 19, 18.58, "Mateus da Rocha Sousa");
	fclose(arquivo);

	FILE *arquivo2 = fopen("teste.txt", "r");
	fscanf(arquivo2, "%d %f %[^\n]s",&idade, &preco, nome);

	printf("%s\n%d\n%f\n", nome, idade, preco);
	fclose(arquivo2);
}