#include <stdio.h>

#define TOTAL 3
int n;
float media = 0;

int main(){
    for (int i = 0; i < TOTAL; i++){
        printf("Digite o %dº número: ", i+1);
        scanf(" %d", &n);
        media += n;
    }
    media /= 3;
    printf("\nA média é: %.2f", media);

    if (media >= 7)
    {
        printf("\nAluno aprovado\n");
    }
    else if (media >= 4)
    {
        printf("\nAluno em Exame Final! Força guerreiro\n");
    }
    else
    {
        printf("\nReprovado! Te vejo período que vem\n");
    }
    return 0;
}