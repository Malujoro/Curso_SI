#include <stdio.h>
#define TAM 100

// Função para ler os valores de um vetor
void LerVetor(float vetor[])
{
    int i;

    for(i = 0; i < TAM; i++)
    {
        printf("Posição[%d]: ", i);
        scanf(" %f", &vetor[i]);
    }
}

// Função para encontrar o maior valor de um vetor
float maior_valor(float vetor[])
{
    int i;
    float maior = vetor[0];

    for(i = 1; i < TAM; i++)
    {
        if(vetor[i] > maior)
            maior = vetor[i];
    }

    return maior;
}

// Função para encontrar o menor valor de um vetor
float menor_valor(float vetor[])
{
    int i;
    float menor = vetor[0];

    for(i = 1; i < TAM; i++)
    {
        if(vetor[i] < menor)
            menor = vetor[i];
    }

    return menor;
}

// Função para somar os valores de um vetor
float soma_valor(float vetor[])
{
    int i;
    float soma = 0;

    for(i = 0; i < TAM; i++)
        soma += vetor[i];

    return soma;
}

// Função para calcular a média dos valores de um vetor
float media_valor(float vetor[])
{
    float media = soma_valor(vetor);
    return media /= TAM;
}

// Função para somar 2 vetores e "montar" outro vetor
void soma_vetores(float vetor1[], float vetor2[], float vetor3[])
{
    int i;

    for(i = 0; i < TAM; i++)
    {
        vetor3[i] = vetor1[i] + vetor2[i];
    }
}

// Função para somar exibir os valores de um vetor
void exibir_vetor(float vetor[])
{
    int i;

    for(i = 0; i < TAM; i++)
    {
        printf("\nPosição[%d]: %.2f", i, vetor[i]);
    }
    printf("\n");
}

int main()
{
	char op;
    float vetorA[TAM], vetorB[TAM], vetorC[TAM];

    printf("\nVetor A:\n");
    LerVetor(vetorA);

    printf("\nVetor B:\n");
    LerVetor(vetorB);

	do
	{
		printf("\n----------MENU----------");
		printf("\na) Calcular o MAIOR elemento do Vetor A");
		printf("\nb) Calcular o MENOR elemento do Vetor B");
		printf("\nc) Calcular a SOMA e a MÉDIA dos elementos do Vetor A");
		printf("\nd) Calcular a SOMA e a MÉDIA dos elementos do Vetor B");
		printf("\ne) Montar o Vetor C, que é a soma dos vetores A e B e escrever os elementos do Vetor C");
		printf("\nf) Escrever os elementos do Vetor A");
		printf("\ng) Escrever os elementos do Vetor B");
		printf("\nh) SAIR do Programa");
		printf("\n------------------------");
		printf("\nOpção: ");
		scanf(" %c", &op);

		if(op >= 'A' && op <= 'Z')
				op += 32;

        switch(op)
        {
            case 'a':
                printf("\nO maior valor do Vetor A é: %.2f\n", maior_valor(vetorA));
                break;
            
            case 'b':
                printf("\nO menor valor do Vetor B é: %.2f\n", menor_valor(vetorB));
                break;
            
            case 'c':
                printf("\nA soma dos valores do Vetor A é: %.2f", soma_valor(vetorA));
                printf("\nA média dos valores do Vetor A é: %.2f\n", media_valor(vetorA));
                break;
            
            case 'd':
                printf("\nA soma dos valores do Vetor B é: %.2f", soma_valor(vetorB));
                printf("\nA média dos valores do Vetor B é: %.2f\n", media_valor(vetorB));
                break;
            
            case 'e':
                soma_vetores(vetorA, vetorB, vetorC);
                printf("\nVetor C:\n");
                exibir_vetor(vetorC);
                break;
            
            case 'f':
                exibir_vetor(vetorA);
                break;
            
            case 'g':
                exibir_vetor(vetorB);
                break;
            
            case 'h':
                printf("\nFinalizando programa...\n");
                break;
            
            default:
                printf("\nErro! Opção inválida\n");
        }
	}while(op != 'h');

	return 0;
}