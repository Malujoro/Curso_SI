#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM4 11 // Tamanho das datas 00/00/0000
#define TAM5 6 // Tamanho das horas 00:00

void limpaBuffer()
{
    while(getchar() != '\n');
}

int verificaInt(char *string, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        if(string[i] - '0' < 0 || string[i] - '0' > 9)
            return 0;
    }
    return 1;
}



// Converte uma data do calendário Gregoriano para o calendário Juliano
// Recebe os valores em string gregoriana 12/34/5678. Retorna o valor em juliana
int gregorianaJuliana(char *grego)
{
    char aux[TAM4-2];

    for(int i = 0, j = 0; i < TAM4-3 && j < TAM4-1; i++, j++)
    {
        if(grego[j] == '/')
            j++;
        aux[i] = grego[j];
    }

    aux[TAM4-3] = '\0';
    int data = atoi(aux);

    int dia = data / 1000000;
    int mes = (data / 10000) - (dia * 100);
    int ano = data % 10000;
	int juliana;

	juliana = (1461 * (ano + 4800 + (mes - 14) / 12)) / 4 + (367 * (mes - 2 - 12 * ((mes - 14) / 12))) / 12 - (3 * ((ano + 4900 + (mes - 14) / 12) / 100)) / 4 + dia - 32075;
	
	return juliana;
}

// Converte uma data do calendário Juliano para o calendário Gregoriano
// Recebe o valor em juliana. Retorna os valores em data gregoriana 12345678 (12/34/5678)
long int julianaGregoriana(int juliana)
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
	
	return ((dia * 1000000) + (mes * 10000) + ano);
}

// Compara se a diferença entre a data de entrada e de saída é válida
// Recebe as strings de entrada e saída
int comparaData(char *entrada, char *saida)
{
    int data1, data2;

    data1 = gregorianaJuliana(entrada);
    data2 = gregorianaJuliana(saida);

    return data2 - data1;
}


// Função para verificar se uma data é válida
// Recebe a String a ser verificada
int verificaData(char *string)
{
    char aux[4];
    int tam = strlen(string);

    if(tam == TAM4-1 && string[2] == '/' && string[5] == '/')
    {
        strncpy(aux, string, 2);
        if(verificaInt(aux, 2))
        {
            int dia, mes, ano, data;
            dia = atoi(aux);
            int i;
            for(i = 3; i < 5; i++)
                aux[i-3] = string[i];

            if(verificaInt(aux, 2))
            {
                mes = atoi(aux);
                for(i = 6; i < TAM4-1; i++)
                    aux[i-6] = string[i];
                
                if(verificaInt(aux, 4))
                {
                    ano = atoi(aux);
                    // Monta a data em uma variável, para poder verificar
                    data = (dia * 1000000) + (mes * 10000) + ano;
                    // Irá converter a data em juliana, e desconverter para gregoriana
                    long int gregoriana = julianaGregoriana(gregorianaJuliana(string));
                    // Caso a data digitada e a convertida sejam iguais, então são válidas
                    if(data == gregoriana)
                        return 1;
                }
            }
        }
    }
    return 0;
}

// Função para ler apenas números inteiros
// Recebe o Texto a ser exibido. Retorna o Inteiro lido
int leiaInt(char *texto)
{
    int num, retorno;

    do
    {
        // Exibe a mensagem recebida
        printf("%s", texto);
        // Scanf retorna 1 caso a leitura tenha sido um sucesso
        retorno = scanf(" %d", &num);
        limpaBuffer();

        if(retorno == 0)
            printf("\nEntrada inválida!! Digite um número inteiro!\n");
    }while(retorno == 0);
    
    return num;
}

// Função para ler a Data digitada e conferir se está em um formato válido 12/34/5678 ou 12345678
// Após a leitura, irá formatá-la e deixar no formato 12/34/5678
// Recebe o texto a ser exibido e a variável que vai receber a data
void leiaData(char *texto, char *data)
{
    int tam, invalido = 1;
    char aux[TAM4];

    do
    {
        printf("%s", texto);
        scanf(" %[^\n]s", aux);
        limpaBuffer();

        if(aux[2] == '-' || aux[2] == ' ')
            aux[2] = '/';

        if(aux[5] == '-' || aux[5] == ' ')
            aux[5] = '/';


        tam = strlen(aux);
        if(tam == TAM4-3 && verificaInt(aux, tam))
        {
            int i;
            for(i = 7; i > 3; i--)
                data[i+2] = aux[i];

            data[5] = '/';

            for(i = 3; i > 1; i--)
                data[i+1] = aux[i];

            data[2] = '/';

            strncpy(data, aux, 2);
            data[TAM4-1] = '\0';
            if(verificaData(data))
                invalido = 0;
        }

        else if(verificaData(aux))
        {
            strcpy(data, aux);
            data[TAM4-1] = '\0';
            invalido = 0;
        }

        if(invalido)
            printf("\nData inválida!!\n");
    }while(invalido);
}

int main()
{
	char entrada[TAM4], saida[TAM4];

    leiaData("\nEntrada: ", entrada);
    verificaData(entrada);

    leiaData("\nSaida: ", saida);
    verificaData(saida);

    int dif = comparaData(entrada, saida);

    if(dif > 0)
        printf("\nDatas válidas");
    else
        printf("\nDatas inválidas");

    printf("\nDiferença de %d dias\n", dif);

	return 0;
}