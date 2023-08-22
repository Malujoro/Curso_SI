#include <stdio.h>

/*
    Em um campeonato nacional de arco-e-flecha tem-se equipes de três
    jogadores para cada estado. Sabendo-se que cada jogador não recebe,
    necessariamente, a mesma quantidade de pontos, fazer um algoritmo que
    dados os pontos obtidos por cada jogador, exibir:
    • os pontos em ordem crescente;
    • se a soma dos pontos for maior ou igual a 100 exibir a média, caso
    contrário exibir “equipe desclassificada”.
*/

int main(void)
{
    int n1, n2, n3;
    float media;

    printf("Jogador 1: ");
    scanf(" %d", &n1);

    printf("Jogador 2: ");
    scanf(" %d", &n2);

    printf("Jogador 3: ");
    scanf(" %d", &n3);

    if (n1 <= n2 && n1 <= n3)
    {
        printf("\n%d - ", n1);

        if (n2 <= n3)
        {
            printf("%d - %d", n2, n3);
        }
        else
        {
            printf("%d - %d", n3, n2);
        }
    }
    else if (n2 <= n1 && n2 <= n3)
    {
        printf("\n%d - ", n2);

        if (n1 <= n3)
        {
            printf("%d - %d", n1, n3);
        }
        else
        {
            printf("%d - %d", n3, n1);
        }
    }
    else
    {
        printf("\n%d - ", n3);

        if (n1 <= n2)
        {
            printf("%d - %d", n1, n2);
        }
        else
        {
            printf("%d - %d", n2, n1);
        }
    }
    
    media = n1 + n2 + n3;

    if (media >= 100)
    {
        media /= 3;
        printf("\n\nA média é: %.1f\n", media);
    }
    else
    {
        printf("\n\nEquipe desclassificada!\n");
    }
    return 0;
}
