#include <stdio.h>

void trocar(float *a, float *b)
{
	float aux = *a;
	*a = *b;
	*b = aux;
}

int main()
{
	float a, b;

	printf("Valor de A: ");
	scanf(" %f", &a);

	printf("Valor de B: ");
	scanf(" %f", &b);

	trocar(&a, &b);

	printf("\nValor de A: %.1f", a);
	printf("\nValor de B: %.1f\n", b);

	return 0;
}