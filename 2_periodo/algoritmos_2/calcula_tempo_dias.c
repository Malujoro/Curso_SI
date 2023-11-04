#include <stdio.h>

int gregoriana_juliana(int dia, int mes, int ano)
{
	int juliana;

	juliana = (1461 * (ano + 4800 + (mes - 14) / 12)) / 4 + (367 * (mes - 2 - 12 * ((mes - 14) / 12))) / 12 - (3 * ((ano + 4900 + (mes - 14) / 12) / 100)) / 4 + dia - 32075;
	
	return juliana;
}

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

int pascoa(int ano)
{
	int a, b, c, d, e, f, g, h, i, k, l, m;
	int mes, dia;

	a = ano % 19;
	b = ano / 100;
	c = ano % 100;
	d = b / 4;
	e = b % 4;
	f = (b + 8) / 25;
	g = (b - f + 1) / 3;
	h = (19 * a + b - d - g + 15) % 30;
	i = c / 4;
	k = c % 4;
	l = (32 + 2 * e + 2 * i - h - k) % 7;
	m = (a + 11 * h + 22 * l) / 451;
	mes = (h + l - 7 * m + 114) / 31;
	dia = ((h  + l - 7 * m + 114) % 31) + 1;
	
	return ((mes * 100) + dia);
}

int sexta_santa(int ano)
{
	int data_pasc;
	long int data;

	data_pasc = (ano * 10000) + pascoa(ano);
	data = passa_tempo(data_pasc, -2);
	data = data % 10000;

	return data;	
}

int terca_carnaval(int ano)
{
	int data_pasc;
	long int data;

	data_pasc = (ano * 10000) + pascoa(ano);
	data = passa_tempo(data_pasc, -47);
	data = data % 10000;

	return data;
}

int corpus_christ(int ano)
{
	int data_pasc;
	long int data;

	data_pasc = (ano * 10000) + pascoa(ano);
	data = passa_tempo(data_pasc, 60);
	data = data % 10000;

	return data;
}

int main()
{
	int ano1 = 2023, ano2 = 2024;

	printf("%d\n", sexta_santa(ano1));
	printf("%d\n", terca_carnaval(ano1));
	printf("%d\n", corpus_christ(ano1));

	printf("\n%d\n", sexta_santa(ano2));
	printf("%d\n", terca_carnaval(ano2));
	printf("%d\n", corpus_christ(ano2));

	return 0;
}