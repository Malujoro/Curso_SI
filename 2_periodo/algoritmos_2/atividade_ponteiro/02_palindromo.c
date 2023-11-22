#include <stdio.h>

int palindromo(char *palavra)
{
	int tam, i, j;

	for(tam = 0; *(palavra+tam) != '\0'; tam++);

	for(i = 0, j = tam-1; i < j; i++, j--)
	{
		if(*(palavra + i) != *(palavra + j))
			return 0;
	}
	return 1;
}

int main()
{
	char nome[50];

	printf("Digite um nome: ");
	scanf("%[^\n]s", nome);

	if(palindromo(nome))
		printf("\nÉ Palíndromo\n");
	else
		printf("\nNão é Palíndromo\n");

	return 0;
}