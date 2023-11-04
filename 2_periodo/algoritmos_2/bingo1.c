#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i, j, num;
	int vetor[25], quant = 0;

	srand(time(NULL));

	for(i = 0; i < 25; i++)
	{
		num = rand() % 51;
		for(j = 0; j < quant; j++)
		{
			if(vetor[j] == num)
				break;
		}
		if(i == j)
		{
			vetor[i] = num;
			quant++;
		}
		else
		{
			i--;
		}
	}

	printf("\nB   I   N   G   O\n");
	for(i = 0; i < 25; i++)
	{
		if(i >= 5 && i % 5 == 0)
		{
			printf("\n");
		}
		printf("%-3d ", vetor[i]);
	}

	return 0;
}