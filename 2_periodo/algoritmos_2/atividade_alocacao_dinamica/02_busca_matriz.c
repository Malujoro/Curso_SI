#include <stdio.h>
#include <stdlib.h>

void preenche(int **matriz, int lin, int col)
{
	int i, j;

	for(i = 0; i < lin; i++)
	{
		for(j = 0; j < col; j++)
		{
			printf("Matriz[%d][%d]: ", i, j);
			scanf(" %d", &matriz[i][j]);
		}
	}
}

int busca(int num, int **matriz, int lin, int col)
{
	int i, j;

	for(i = 0; i < lin; i++)
	{
		for(j = 0; j < col; j++)
		{
			if(num == matriz[i][j])
				return 1;
		}
	}
	return 0;
}

int main()
{
	int lin, col, i, num;

	printf("Linhas e Colunas da matriz: ");
	scanf(" %d %d", &lin, &col);

	int **matriz = (int **) malloc(lin * sizeof(int *));
	for(i = 0; i < lin; i++)
		matriz[i] = (int*) malloc(col * sizeof(int));

	preenche(matriz, lin, col);

	printf("\nValor buscado: ");
	scanf(" %d", &num);
	if(busca(num, matriz, lin, col))
		printf("Valor encontrado\n");
	else
		printf("Valor não encontrado\n");

	for(i = 0; i < lin; i++)
		free(matriz[i]);
	free(matriz);

	return 0;
}