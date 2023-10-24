#include <stdio.h>
#include <stdlib.h>

#define TOTAL_MES 12

struct Data
{
	int dia;
	char mes[10];
	int ano;
};

struct tipo_mes
{
	char nome[10];
	char abrev[3];
	int dias;
	int num_mes;
};

struct tipo_mes matriz[TOTAL_MES] = {
	{"Janeiro", "Jan", 31, 1},
	{"Fevereiro", "Fev", 28, 2},
	{"Março", "Mar", 31, 3},
	{"Abril", "Abr", 30, 4},
	{"Maio", "Mai", 31, 5},
	{"Junho", "Jun", 30, 6},
	{"Julho", "Jul", 31, 7},
	{"Agosto", "Ago", 31, 8},
	{"Setembro", "Set", 30, 9},
	{"Outubro", "Out", 31, 10},
	{"Novembro", "Nov", 30, 11},
	{"Dezembro", "Dez", 31, 12}
};

// Função para somar os dias dos meses que se passaram (recebe o número do mês)
int dias_corridos_int(int mes);
// Função para somar os dias dos meses que se passaram (recebe o nome/abreviação do mês)
int dias_corridos_nome(char nome[]);
// Função para comparar duas strings sem diferenciar maiúsculas e minúsculas (retorna 0 caso sejam iguais)
int stricmp(char str1[], char str2[]);


int main()
{

	struct Data data;
	int total;

	do // Looping para ler um dia válido
	{
		printf("Digite o dia [Ex: 15]: ");
		scanf(" %d", &data.dia);
	}while(data.dia < 1 || data.dia > 31);

	do // Looping para ler um mês válido
	{
		printf("Digite o mês [Ex: 04, abr ou abril]: ");
		scanf(" %s", data.mes);
	}while(atoi(data.mes) < 0 || atoi(data.mes) > TOTAL_MES);

	do // Looping para ler um ano válido
	{
		printf("Digite o ano [Ex: 2023]: ");
		scanf(" %d", &data.ano);
	}while(data.ano < 0);

	// Verifica se o ano digitado é bissexto, para modificar a quantidade de dias de fevereiro
	if((data.ano % 4 == 0 && data.ano % 100 != 0) || data.ano % 400 == 0)
	{
		printf("[Ano Bissexto!]");
		matriz[1].dias = 29;
	}
	else
	{
		matriz[1].dias = 28;
	}

	printf("\nDo início do ano até o dia ");
	total = data.dia;
	// Verifica se o mês digitado foi em número ou caractere
	if(atoi(data.mes) > 0)
	{
		total += dias_corridos_int(atoi(data.mes));
		printf("%02d/%02d/%04d ", data.dia, atoi(data.mes), data.ano);
	}
	else
	{
		total += dias_corridos_nome(data.mes);
		printf("%02d de %s de %d ", data.dia, data.mes, data.ano);
	}
	printf("se passaram %d dias\n", total);
}


int dias_corridos_int(int mes)
{
	int i, tot = 0;

	for(i = 0; i < mes-1; i++)
	{
		tot += matriz[i].dias;
	}
	return tot;
}

int dias_corridos_nome(char nome[])
{
	int i, tot = 0;

	for(i = 0; i < 12; i++)
	{
		if (stricmp(matriz[i].nome, nome) == 0 || stricmp(matriz[i].abrev, nome) == 0)
			break;
			
		tot += matriz[i].dias;
	}
	return tot;
}

int stricmp(char str1[], char str2[])
{
	int i = 0;

	while(str1[i] != '\0' && str2[i] != '\0')
	{
		if((str1[i] == str2[i]) ||
			((str1[i] >= 'a' && str1[i] <= 'z') && (str1[i]-32 == str2[i])) ||
			((str1[i] >= 'A' && str1[i] <= 'Z') && (str1[i]+32 == str2[i])))
			i++;
		else
	    	return str1[i] - str2[i];
	}

    if (str1[i] == '\0' &&  str2[i] == '\0')
      return 0;
    else if (str1[i] == '\0')
      return -str2[i];
    else if (str2[i] == '\0')
      return str1[i];
}