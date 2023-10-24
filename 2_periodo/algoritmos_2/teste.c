#include <stdio.h>

#define MAX 10

typedef struct
{
	char nome[100];
	float peso;
	float calorias;
} Dieta;

int add(Dieta matriz[], int quant);
void listar(Dieta matriz[], int quant);

int main()
{
	Dieta matriz[MAX];
	int op, tot = 0;

	do
	{
		printf("\n---------------Menu---------------");
		printf("\n[1] - Adicionar comida");
		printf("\n[2] - Listar todas as comidas");
		printf("\n[0] - Sair do programa");
		printf("\n----------------------------------");
		printf("\nOpção: ");
		scanf(" %d", &op);

		switch(op)
		{
			case 1:
				if (tot < MAX)
				{
					tot = add(matriz, tot);
				}
				else
				{
					printf("\nLista Cheia! Não é possível adicionar mais comidas\n");
				}
				break;
		
			case 2:
				if (tot == 0)
				{
					printf("\nLista vazia! Adicione alguma comida\n");
				}
				else
				{
					listar(matriz, tot);
				}
				break;
			
			case 0:
				printf("\nSaindo...\n");
				break;
				
			default:
				printf("\nOpção inválida!\n");
		}
	}while(op != 0);
	
	return 0;
}

int add(Dieta matriz[], int quant)
{
	printf("\n----------%dº Comida----------", quant+1);
	
	printf("\nNome: ");
	scanf(" %[^\n]s", matriz[quant].nome);

	do
	{
		printf("Peso [g]: ");
		scanf(" %f", &matriz[quant].peso);
	}while(matriz[quant].peso <= 0);
	
	do
	{	
		printf("Calorias: ");
		scanf(" %f", &matriz[quant].calorias);
	}while(matriz[quant].calorias <= 0);
	
	quant++;
	return quant;
}

void listar(Dieta matriz[], int quant)
{
	int i;

	for(i = 0; i < quant; i++)
	{
		printf("\n----------%dº Comida----------", i+1);
		printf("\nNome: %s", matriz[i].nome);
		printf("\nPeso: %.1f g", matriz[i].peso);
		printf("\nCalorias: %.1f cal", matriz[i].calorias);
		printf("\n-----------------------------\n");	
	}
}