#include <stdio.h>

int main()
{
	int num, i, j, k, tot = 0, igual = 0;
	float prob;

	printf("Digite um número entre 3 e 18: ");
	scanf(" %d", &num);

	for(i = 1; i <= 6; i++)
	{
		for(j = 1; j <= 6; j++)
		{
			for(k = 1; k <= 6; k++)
			{
                tot++;
                igual += (i + j + k == num) ? 1 : 0;
			}
		}
	}
	prob = (tot != 0) ? ((float)igual/tot) * 100 : 0;
	printf("A probabilidade de sair %d é %.2f%%\n", num, prob);

	return 0;
}