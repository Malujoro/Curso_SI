#include <stdio.h>
#include <stdlib.h>

void preenche(int **matriz, int tam, int *vetor)
{
	int i, j;

	for(i = 0; i < tam; i++)
	{
		for(j = 0; j < tam; j++)
			matriz[i][j] = vetor[j];
	}
}

void exibir(int **matriz, int tam)
{
	int i, j;

	for(i = 0; i < tam; i++)
	{
		for(j = 0; j < tam; j++)
			printf("%d \t", matriz[i][j]);
		
		printf("\n");
	}
}

int main()
{
	int tam, i;

	printf("Tamanho do vetor: ");
	scanf(" %d", &tam);

	int *vetor = (int *) malloc(tam * sizeof(int));

	for(i = 0; i < tam; i++)
	{
		printf("Vetor[%d]: ", i);
		scanf(" %d", &vetor[i]);
	}

	int **matriz = (int **) calloc(tam, sizeof(int *));
	for(i = 0; i < tam; i++)
		matriz[i] = (int *) calloc(tam, sizeof(int));

	preenche(matriz, tam, vetor);
	exibir(matriz, tam);

	for(i = 0; i < tam; i++)
		free(matriz[i]);
	free(matriz);
	free(vetor);
	return 0;
}