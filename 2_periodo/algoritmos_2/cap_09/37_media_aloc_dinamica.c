#include <stdio.h>
#include <stdlib.h>

void media_vetor(float *matriz, int tam, float *media)
{
	int i;
	*media = 0;

	for(i = 0; i < tam; i++)
	{
		*media += *(matriz + i);
	}
    
	*media /= tam;
}

int main()
{
	int tam, i;
	float media;

	printf("Quantas notas serão digitadas? ");
	scanf(" %d", &tam);

	float *matriz = (float *) malloc(tam * sizeof(float));

	for(i = 0; i < tam; i++)
	{
		printf("%dª nota: ", i+1);
		scanf(" %f", &matriz[i]);
	}

	media_vetor(matriz, tam, &media);

	printf("A média das %d notas foi %.2f\n", tam, media);

	free(matriz);
}