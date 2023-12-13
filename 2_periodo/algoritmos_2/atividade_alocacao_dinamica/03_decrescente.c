#include <stdio.h>
#include <stdlib.h>

void decrescente(int *vetor, int tam)
{
	int i, j, aux;
	int *maior;

	for(i = 0; i < tam-1; i++)
	{
		maior = &vetor[i];
		for(j = i+1; j < tam; j++)
		{
			if(vetor[j] > *maior)
				maior = &vetor[j];
		}
		aux = vetor[i];
		vetor[i] = *maior;
		*maior = aux;
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
		printf("vetor[%d]: ", i);
		scanf(" %d", &vetor[i]);
	}

	decrescente(vetor, tam);

	for(i = 0; i < tam; i++)
		printf("%d ", vetor[i]);

	vetor = realloc(vetor, tam/2 * sizeof(int));
	printf("\n\nMetade do vetor:\n");
	for(i = 0; i < tam/2; i++)
		printf("%d ", vetor[i]);

	free(vetor);

	return 0;
}