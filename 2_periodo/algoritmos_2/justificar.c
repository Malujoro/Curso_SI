#include <stdio.h>

void justify(char str[], int modo, int n)
{
    int tam = 0, i, pos, esq;

    while(str[tam] != '\0')
    {
        tam++;
    }
    
    switch(modo)
    {
        case 0: // Esquerda
            for(i = tam; i < n; i++)
            {
                str[i] = ' ';
            }
            str[n] = '\0';
            break;
        case 1: // Centralizado
            esq = (n - tam) / 2;
            // Joga a string pra direita
            str[tam] = ' ';
            for(i = tam-1, pos = tam + esq - 1; i >= 0; i--, pos--)
            {
                str[pos] = str[i];
            }
            // Limpa a string, deixando com espaços na esquerda
            for(; pos >= 0; pos--)
            {
                str[pos] = ' ';
            }
            // Adiciona os espaços da direita
            for(i = tam+esq; i < n; i++)
            {
                str[i] = ' ';
            }
            str[n] = '\0';
            break;
        case 2: // Direita
            for(i = tam, pos = n; i >= 0; i--, pos--)
            {
                str[pos] = str[i];
            }
            for(; pos >= 0; pos--)
            {
                str[pos] = ' ';
            }
        break;
    }
}

int main(void)
{
    char nome[20] = "Casa";
    char nome2[20] = "Pedra";
    char nome3[20] = "Sol";

    justify(nome, 0, 10);
    printf("\n[%s]\n", nome);

    justify(nome2, 1, 10);
    printf("\n[%s]\n", nome2);

    justify(nome3, 2, 10);
    printf("\n[%s]\n", nome3);
    return 0;
}