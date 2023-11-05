#include <stdio.h>

#define ESPACO 26

// Função para converter data gregoriana em juliana
int gregoriana_juliana(int dia, int mes, int ano)
{
	int juliana;

	juliana = (1461 * (ano + 4800 + (mes - 14) / 12)) / 4 + (367 * (mes - 2 - 12 * ((mes - 14) / 12))) / 12 - (3 * ((ano + 4900 + (mes - 14) / 12) / 100)) / 4 + dia - 32075;
	
	return juliana;
}

// Função para converter data juliana em gregoriana 
long int juliana_gregoriana(int juliana)
{
	int b, n, k, j;
	int dia, mes, ano;

	b = juliana + 68569;
	n = (4 * b) / 146097;
	b = b - ((146097 * n + 3) / 4);
	k = 4000 * (b + 1) / 1461001;
	b = b - (1461 * k) / 4 + 31;
	j = (80 * b) / 2447;
	dia = b - (2447 * j) / 80;
	b = (j / 11);
	mes = j + 2 - (12 * b);
	ano = 100 * (n - 49) + k + b;
	
	return ((ano * 10000) + (mes * 100) + dia);
}

// Função para saber dia da semana
int dia_juliana(int dia, int mes, int ano)
{
	return ((gregoriana_juliana(dia, mes, ano) + 1) % 7);
}

// Função para calcular a passagem de tempo.
// Deve ser enviado a data, e a passagem de dias (negativa ou positiva)
// Retorna a data no formato yyyymmdd
long int passa_tempo(long int data, int passagem)
{
	int juliana;
	int dia, mes, ano;

	ano = data / 10000;
	mes = (data % 10000) / 100;
	dia = data % 100;

	juliana = gregoriana_juliana(dia, mes, ano);
	juliana += passagem;
	return juliana_gregoriana(juliana);
}

// Função para desenhar uma linha de 26 espaços
void linha()
{
	int i;

	for(i = 0; i < ESPACO; i++)
		printf("-");
}

// Função para centralizar um texto em 26 espaços
void centralizar(char str[])
{
	int i, quant;
	
	for(i = 0; str[i] != '\0'; i++);

	quant = (ESPACO - i) / 2;

	for(i = 0; i < quant; i++)
	{
		printf(" ");
	}
	printf("%s", str);
}

int main()
{
	char matriz[12][15] = {"JANEIRO", "FEVEREIRO", "MARÇO", "ABRIL", "MAIO", "JUNHO", "JULHO", "AGOSTO", "SETEMBRO", "OUTUBRO", "NOVEMBRO", "DEZEMBRO"};
	int dia, mes, ano, semana, i;
	long int data; // Formato yyyymmdd - ano mês dia

	// Usuário insere o ano
	printf("Digite um ano: ");
	scanf("%d", &ano);
	// É criado a data ANO/01/01
	data = (ano * 10000) + 101;
	linha();

	printf("\nCalendário de %d", ano);
	do
	{
		// É calculado o mês e dia
		mes = (data % 10000) / 100;
		dia = data % 100;
		// Imprime o cabeçalho de início
		if(dia == 1)
		{
			printf("\n");
			linha();
			printf("\n");
			centralizar(matriz[mes-1]);
			printf("\n");
			linha();
			printf("\n D   S   T   Q   Q   S   S\n");
			semana = dia_juliana(dia, mes, ano);
			for(i = 0; i < semana; i++)
			{
				printf("    ");
			}
		}

		printf("%02d  ", dia);
		
		// Dá uma quebra de linha após uma sexta feira (que não seja o ultimo dia do mês)
		if (((dia + semana) % 7 == 0) && (passa_tempo(data, 1) - data == 1))
			printf("\n");
		data = passa_tempo(data, 1);
	}while(data < (ano+1) * 10000);
	printf("\n");
	linha();
	printf("\n");
	return 0;
}