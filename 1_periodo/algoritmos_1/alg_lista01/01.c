#include <stdio.h>

int main(void)
{
    char nome[20], sobrenome[20];

    printf("\nNome: ");
    setbuf(stdin, NULL);
    scanf("%s", nome);
    
    printf("\nSobrenome: ");
    setbuf(stdin, NULL);
    scanf("%s", sobrenome);

    printf("\nNome completo: %s %s\n", nome, sobrenome);

    return 0;
}