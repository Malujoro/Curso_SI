#include <stdio.h>

void conta_ch(char *frase, char ch, int *quant)
{
	int i, tam;
	*quant = 0;

	for(tam = 0; *(frase + tam) != '\0'; tam++);

	for(i = 0; i < tam; i++)
	{
		if(*(frase + i) == ch)
			(*quant)++;
	}
}

int main()
{
	char vetor[50], letra;
	int quant;

	printf("Digite uma frase: ");
	scanf("%[^\n]s", vetor);

	printf("Qual letra deverá ser contada? ");
	scanf(" %c", &letra);

	conta_ch(vetor, letra, &quant);

	printf("\nA letra %c aparece %d vezes na frase: %s\n", letra, quant, vetor);

	return 0;
}