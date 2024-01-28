#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM4 11 // Tamanho das datas 00/00/0000
#define TAM5 6 // Tamanho das horas 00:00

void limpaBuffer()
{
    while(getchar() != '\n');
}

int comparaHora(char *entrada, char *saida)
{
    char aux[TAM5], aux2[TAM5];

    int i, j;
    for(i = 0, j = 0; i < TAM5 && j < TAM5-1; i++, j++)
    {
        if(entrada[j] == ':')
            j++;
        aux[i] = entrada[j];
        aux2[i] = saida[j];
    }
    aux[i] = '\0';
    aux2[i] = '\0';
    return atoi(aux2) - atoi(aux);
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

int verificaHora(char *string)
{
    int x, i, tam = strlen(string);
    char aux[3], pos;

    for(int i = 0; i < tam; i++)
    {
        if(string[i] == ':')
        {
            pos = i;
            break;
        }
    }
    // Formatando horas nos formatos 1:23 e 12:3 para 01:23 e 12:03
    if(tam == 4 && (pos == 1 || pos == 2))
    {
        if(pos == 1)
        {
            for(i = tam-1; i >= 0; i--)
                string[i+1] = string[i];
            string[0] = '0';
        }
        else if(pos == 2)
        {
            string[4] = string[3];
            string[3] = '0';
        }

        string[5] = '\0';
        tam++;
    }
    // Formatando horas nos formatos 1:2 01:02
    else if(tam == 3 && pos == 1)
    {
        for(i = tam-1; i >= 0; i--)
            string[i+1] = string[i];
        string[4] = string[3];
        string[0] = '0';
        string[3] = '0';
        string[5] = '\0';
        tam = 5;
    }

    // Verifica se o horário é válido
    if(tam == TAM5-1 && string[2] == ':')
    {
        strncpy(aux, string, 2);
        aux[2] = '\0';
        x = atoi(aux);
        if(verificaInt(aux, 2) && x >= 0 && x <= 23)
        {
            for(i = 3; i < TAM5-1; i++)
                aux[i-3] = string[i];
            
            aux[2] = '\0';
            x = atoi(aux);
            if(verificaInt(aux, 2) && x >= 0 && x <= 59)
                return 1;
        }
    }
    return 0;
}

void leiaHora(char *texto, char *hora)
{
    char aux[TAM5];
    int tam, invalido = 1;

    do
    {
        printf("%s", texto);
        scanf(" %[^\n]s", aux);
        limpaBuffer();

        tam = strlen(aux);

        if(tam == TAM5-2 && verificaInt(aux, tam))
        {
            for(int i = 3; i > 1; i--)
                hora[i+1] = aux[i];

            hora[2] = ':';

            strncpy(hora, aux, 2);
            if(verificaHora(hora))
                invalido = 0;
        }
        else if(verificaHora(aux))
        {
            strcpy(hora, aux);
            invalido = 0;
        }
        if(invalido)
            printf("\nHora inválida!!\n");
    }while(invalido);
    hora[TAM5-1] = '\0';
}
#include <string.h>

#define TAM4 11 // Tamanho das datas 00/00/0000
#define TAM5 6 // Tamanho das horas 00:00

void limpaBuffer()
{
    while(getchar() != '\n');
}

int comparaHora(char *entrada, char *saida)
{
    char aux[TAM5], aux2[TAM5];

    int i, j;
    for(i = 0, j = 0; i < TAM5 && j < TAM5-1; i++, j++)
    {
        if(entrada[j] == ':')
            j++;
        aux[i] = entrada[j];
        aux2[i] = saida[j];
    }
    aux[i] = '\0';
    aux2[i] = '\0';
    return atoi(aux2) - atoi(aux);
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

int verificaHora(char *string)
{
    int x, tam = strlen(string);
    char aux[3];

    if(tam == TAM5-1 && string[2] == ':')
    {
        strncpy(aux, string, 2);
        aux[2] = '\0';
        x = atoi(aux);
        if(verificaInt(aux, 2) && x >= 0 && x <= 23)
        {
            for(int i = 3; i < TAM5-1; i++)
                aux[i-3] = string[i];
            
            aux[2] = '\0';
            x = atoi(aux);
            if(verificaInt(aux, 2) && x >= 0 && x <= 59)
                return 1;
        }
    }
    return 0;
}

void leiaHora(char *texto, char *hora)
{
    char aux[TAM5];
    int tam, invalido = 1;

    do
    {
        printf("%s", texto);
        scanf(" %[^\n]s", aux);
        limpaBuffer();

        tam = strlen(aux);

        if(tam == TAM5-2 && verificaInt(aux, tam))
        {
            for(int i = 3; i > 1; i--)
                hora[i+1] = aux[i];

            hora[2] = ':';

            strncpy(hora, aux, 2);
            if(verificaHora(hora))
                invalido = 0;
        }
        else if(verificaHora(aux))
        {
            strcpy(hora, aux);
            invalido = 0;
        }
        if(invalido)
            printf("\nHora inválida!!\n");
    }while(invalido);
    hora[TAM5-1] = '\0';
}

int main()
{
	char entrada[TAM4], saida[TAM4];

    leiaHora("\nEntrada: ", entrada);
    verificaHora(entrada);

    leiaHora("\nSaida: ", saida);
    verificaHora(saida);

    int dif = comparaHora(entrada, saida);

    if(dif > 0)
    {
        printf("\nHoras válidas");
    }
    else
        printf("\nHora inválida");

    printf("\nDiferença de %d minutos\n", dif);

	return 0;
}