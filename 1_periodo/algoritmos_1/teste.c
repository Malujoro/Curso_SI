#include <stdio.h>
#include <ctype.h>

float leia_float(char texto[])
{
    float num;
    int retorno;
    char letra;

    do
    {
        printf("%s", texto); // Exibe o texto recebido
        retorno = scanf(" %f", &num); // Recebe 1 se o digitado for float

        do // Limpa o buffer do teclado
        {
            letra = getchar(); 
        } while(letra != '\n');

        if (retorno == 0)
        {
            printf("Entrada inválida! Digite um número real");
        }
    } while (retorno == 0);

    return num;
}

int main()
{
    float num;
    
    num = leia_float("\nDigite dinheiro: R$");
    printf("\n%.2f\n", num);
}

// Scanf retorna 1 e 0
/*
int main(void)
{
    int retorno;
    float numero;
    char letra;

    do
    {
        printf("\nNúmero: ");
        //setbuf(stdin, NULL);
        retorno = scanf(" %f", &numero);
        do
        {
            letra = getchar();
            //printf("[%c]\n", letra);
        } while (letra != '\n');
        
        printf("Retorno: %d", retorno);
        printf("\nNúmero: %f", numero);
    } while (retorno >= 0);
}
*/

// Verifica se o digitado é inteiro
/*
int main()
{
    char c;

    do
    {
        printf("\nDigite um número: ");
        scanf(" %s", &c);

        printf("Valor: %d ", isdigit(c));

        if (isdigit(c) == 0)
            printf("[Caractere]\n");
        else
            printf("[Número]\n");
    } while (isdigit(c) != -1);
   return 0;
}
*/

// Lê apenas um caractere
/*
int main(void)
{
    char c;

    printf("Digite algo: ");
    c = getchar();
    printf("Digitou: %c | %d", c, c);
    
    return 0;
}
*/