#include <stdio.h>

/*
    Dada a idade de uma pessoa, informar sua classe eleitoral.
    • não eleitor (abaixo de 16 anos);
    • eleitor obrigatório (entre 18 e 65 anos);
    • eleitor facultativo (entre 16 e 18 anos ou maior que 65 ano)
*/

int main(void)
{
    int idade;

    printf("Idade: ");
    scanf(" %d", &idade);

    if (idade < 16)
        printf("Não eleitor\n");
    else if (idade >= 18 && idade < 65)
        printf("Eleitor obrigatório\n");
    else
        printf("Eleitor Facultativo\n");
    
    return 0;
}