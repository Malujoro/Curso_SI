#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int len(char *string)
{
    int i;

    for(i = 0; *(string + i) != '\0'; i++);

    return i;
}

void menu(int *op)
{
    printf("\n-----Conversões disponíveis-----");
    printf("\n[01] - Decimal para Binário");
    printf("\n[02] - Decimal para Octal");
    printf("\n[03] - Decimal para Hexadecimal");
    printf("\n[04] - Binário para Decimal");
    printf("\n[05] - Binário para Octal");
    printf("\n[06] - Binário para Hexadecimal");
    printf("\n[07] - Octal para Decimal");
    printf("\n[08] - Octal para Binário");
    printf("\n[09] - Octal para Hexadecimal");
    printf("\n[10] - Hexadecimal para Decimal");
    printf("\n[11] - Hexadecimal para Binário");
    printf("\n[12] - Hexadecimal para Octal");
    printf("\n[00] - Sair");
    printf("\n--------------------------------");
    printf("\nOpção escolhida: ");
    scanf(" %d", op);
}

void leiastr(char texto[], char *var)
{
    printf("%s", texto);
    scanf(" %s", var);
    while(getchar() != '\n');
}

void bin_para_dec(char binario[], unsigned long int *num)
{
    int i, j, tam;
    *num = 0;

    tam = len(binario);
    
    for(i = tam-1, j = 0; i >= 0; i--, j++)
        *num += (binario[i]-'0') * pow(2, j);
}

void oct_para_dec(char octal[], unsigned long int *num)
{
    int i, j, tam;
    *num = 0;

    tam = len(octal);
    
    for(i = tam-1, j = 0; i >= 0; i--, j++)
        *num += (octal[i]-'0') * pow(8, j);
}

void dec_para_bin(unsigned long int num, unsigned long int *bin)
{
    int i;
    unsigned long int soma = 0;
    *bin = 0;
    
    for(i = 0; pow(2, i) < num; i++);
    for(; i >= 0; i--)
    {
        *bin *= 10;
        if(soma + pow(2, i) <= num)
        {
            soma += pow(2, i);
            *bin += 1;
        }
    }
}

void dec_para_oct(unsigned long int num, unsigned long int *oct)
{
    int i, j;
    unsigned long int soma = 0, resto, tam;

    for(resto = num; resto > 0; resto /= 8)
    {
        soma *= 10;
        soma += resto % 8;
    }
    soma += resto;

    for(tam = 10; tam <= num; tam*=10);

    tam /= 10;

    *oct = 0;
    for(i = 1, j = tam; i <= tam; i*=10, j/=10)
    {
        *oct += (soma / j) * i;
        soma -= (soma / j) * j;
    }
}

void bin_para_oct(char binario[], unsigned long int *oct)
{
    unsigned long int dec;
    *oct = 0;
    bin_para_dec(binario, &dec);
    dec_para_oct(dec, oct);
}

void oct_para_bin(char octal[], unsigned long int *bin)
{
    unsigned long int dec;
    *bin = 0;
    oct_para_dec(octal, &dec);
    dec_para_bin(dec, bin);
}

void hex_para_dec(char hexa[], unsigned long int *num)
{
    int i, j, tam;
    *num = 0;

    tam = len(hexa);

    for(i = 0, j = tam-1; i < tam; i++, j--)
    {
        if(hexa[j] >= '0' && hexa[j] <= '9')
            *num += (hexa[j] - '0') * pow(16, i);
        else if(hexa[j] >= 'a' && hexa[j] <= 'z')
            *num += (hexa[j] - 'a' + 10) * pow(16, i);
        else if(hexa[j] >= 'A' && hexa[j] <= 'Z')
            *num += (hexa[j] - 'A' + 10) * pow(16, i);
    }
}

void dec_para_hex(unsigned long int num, char hexa[])
{
    int i, j, resto;
    char ch, aux;
    
    hexa[0] = '0';
    for(i = 0, resto = num; resto > 0; resto /= 16, i++)
    {
        if(resto % 16 < 10)
            ch = (resto % 16) + '0';
        else
            ch = (resto % 16) - 10 + 'A';
        hexa[i] = ch;
    }
    if(i != 0)
        hexa[i] = '\0';
    for(j = 0, i--; j < i; j++, i--)
    {
        aux = hexa[j];
        hexa[j] = hexa[i];
        hexa[i] = aux;
    }
}

void bin_para_hex(char binario[], char hexa[])
{
    unsigned long int dec;
    bin_para_dec(binario, &dec);
    dec_para_hex(dec, hexa);
}

void oct_para_hex(char octal[], char hexa[])
{
    unsigned long int dec;
    oct_para_dec(octal, &dec);
    dec_para_hex(dec, hexa);
}

void hex_para_bin(char hexa[], unsigned long int *bin)
{
    unsigned long int dec;
    hex_para_dec(hexa, &dec);
    dec_para_bin(dec, bin);
}

void hex_para_oct(char hexa[], unsigned long int *oct)
{
    unsigned long int dec;
    hex_para_dec(hexa, &dec);
    dec_para_oct(dec, oct);
}

int main()
{
    int op;
    unsigned long int num, num2;
    // char *numero;
    char numero[100], numero2[100];

    do
    {
        // numero = malloc(100 * sizeof(char));
        menu(&op);

        if(op >= 1 && op <= 3)
        {
            printf("Digite um número decimal: ");
            scanf(" %ld", &num2);
        }
        else if(op >= 4 && op <= 6)
        {
            leiastr("Digite um número binário: ", numero);
        }
        else if(op >= 7 && op <= 9)
        {
            leiastr("Digite um número octal: ", numero);
        }
        else if(op >= 10 && op <= 12)
        {
            leiastr("Digite um número hexadecimal: ", numero2);
        }

        switch(op)
        {
            case 1: // [1] - Decimal para Binário
                dec_para_bin(num2, &num);
                break;

            case 2: // [2] - Decimal para Octal
                dec_para_oct(num2, &num);
                break;

            case 3: // [3] - Decimal para Hexadecimal
                dec_para_hex(num2, numero2);
                break;

            case 4: // [4] - Binário para Decimal
                bin_para_dec(numero, &num);
                break;

            case 5: // [5] - Binário para Octal
                bin_para_oct(numero, &num);
                break;

            case 6: // [6] - Binário para Hexadecimal
                bin_para_hex(numero, numero2);
                break;
            
            case 7: // [7] - Octal para Decimal
                oct_para_dec(numero, &num);
                break;

            case 8: // [8] - Octal para Binário
                oct_para_bin(numero, &num);
                break;
            
            case 9: // [9] - Octal para Hexadecimal
                oct_para_hex(numero, numero2);
                break;

            case 10: // [10] - Hexadecimal para decimal
                hex_para_dec(numero2, &num);
                break;
            
            case 11: // [11] - Hexadecimal para Binário
                hex_para_bin(numero2, &num);
                break;
            
            case 12: // [12] - Hexadecimal para Octal
                hex_para_oct(numero2, &num);
                break;

            case 0: // [0] - Sair
                printf("\nSaindo do programa...\n\n");
                break;

            default:
                printf("\nOpção inválida! Digite novamente\n");
        }
        if(op != 0)
        {
            if(op % 3 == 0 && op > 0 && op <= 9)
                printf("\nConvertido: %s\n", numero2);
            else
                printf("\nConvertido: %ld\n", num);
        }
        // free(numero);
    }while(op != 0);
}