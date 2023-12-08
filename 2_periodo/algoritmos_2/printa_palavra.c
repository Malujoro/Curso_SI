#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TAM 100

int main()
{
	// char palavra[TAM] = {"hello world"};
	char palavra[TAM];
	char palavra2[TAM];
	char letra;
	int i;

	printf("Digite uma palavra: ");
	scanf(" %[^\n]s", palavra);
	for(i = 0; palavra[i] != '\0'; i++)
	{
		letra = ' ';
		if(palavra[i] >= 'a' && palavra[i] <= 'z')
			letra = 'a';
		else if(palavra[i] >= 'A' && palavra[i] <= 'Z')
			letra = 'A';

		if(letra == 'A' || letra == 'a')
		{
			for(palavra2[i] = letra; palavra2[i] < letra+25; palavra2[i] += 1)
			{
				usleep(35000);
				system("clear");
				printf("\n%s", palavra2);
				if(palavra2[i] == palavra[i])
					break;
			}
		}
		else
		{
			usleep(35000);
			system("clear");
			printf("\n%s", palavra2);
			palavra2[i] = palavra[i];
		}
	}
	usleep(35000);
	system("clear");
	printf("\n");

	return 0;
}