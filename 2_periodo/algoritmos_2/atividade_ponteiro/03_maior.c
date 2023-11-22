#include <stdio.h>

void vetor_maior(float *vetor, int tam, float *maior)
{
	int i;

	*maior = *vetor;
	for(i = 1; i < tam; i++)
	{
		if(*(vetor + i) > *maior)
			*maior = *(vetor + i);
	}
}

int main()
{
	int quant, i;
	float maior;

	printf("Qual o tamanho do vetor? ");
	scanf(" %d", &quant);

	float vetor[quant];

	for(i = 0; i < quant; i++)
	{
		printf("Vetor[%d]: ", i);
		scanf(" %f", &vetor[i]);
	}

	vetor_maior(vetor, quant, &maior);

	printf("Maior valor do vetor: %.1f\n", maior);

	return 0;
}