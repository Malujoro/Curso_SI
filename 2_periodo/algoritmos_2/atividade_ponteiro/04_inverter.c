#include <stdio.h>

void inverte(float *vetor, int tam)
{
	int i, j;
	float aux;

	for(i = 0, j = tam-1; i < j; i++, j--)
	{
		aux = *(vetor + i);
		*(vetor + i) = *(vetor + j);
		*(vetor + j) = aux;
	}
}

int main()
{
	int i, tam;

	printf("Tamanho do vetor: ");
	scanf(" %d", &tam);

	float vetor[tam];

	for(i = 0; i < tam; i++)
	{
		printf("Valor[%d]: ", i);
		scanf(" %f", &vetor[i]);
	}

	inverte(vetor, tam);

	for(i = 0; i < tam; i++)
		printf("\nValor[%d]: %.1f", i, vetor[i]);
    printf("\n");
	return 0;
}