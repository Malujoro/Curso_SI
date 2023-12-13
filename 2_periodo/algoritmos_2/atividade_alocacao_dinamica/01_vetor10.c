#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int quant, i;

	srand(time(NULL));

	do
	{
		printf("Quantidade de valores: ");
		scanf(" %d", &quant);
	}while(quant < 10);

	float *vetor = (float *) malloc(quant * sizeof(float));

	for(i = 0; i < 10; i++)
		vetor[i] = rand() % 10100 * 0.01;


	for(i = 0; i < 10; i++)
		printf("%.2f\n", vetor[i]);

	free(vetor);

	return 0;
}