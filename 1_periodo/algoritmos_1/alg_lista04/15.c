#include <stdio.h>

// Criar um algoritmo que possa armazenar as alturas de dez atletas de cinco delegações
// que participarão dos jogos de verão
// Imprimir a maior altura de cada delegação e a maior altura de todas

int main(void)
{
    int atletas = 2, equipes = 2;
    float matriz[equipes][atletas], maior_altura[equipes+1];
    // Equipe = Linha             // Último: maior altura geral
    // Atleta = Coluna
    int l, c;

    for (l = 0; l < equipes; l++)
    {
        printf("\n%dº delegação:\n", l+1);
        for (c = 0; c < atletas; c++)
        {
            printf("%dº altura [m]: ", c+1);
            scanf("%f", &matriz[l][c]);
            setbuf(stdin, NULL);
        }
    }

    for (l = 0; l < equipes; l++) // Coleta as maiores alturas por equipe/delegação
    {
        maior_altura[l] = matriz[l][0];
        for(c = 1; c < atletas; c++)
        {
            if (matriz[l][c] > maior_altura[l])
            {
                maior_altura[l] = matriz[l][c];
            }
        }
    }

    maior_altura[equipes] = maior_altura[0];
    for (l = 1; l < equipes; l++)
    {
        if (maior_altura[l] > maior_altura[equipes])
        {
            maior_altura[equipes] = maior_altura[l];
        }
    }
    
    printf("Maiores alturas de cada delegação:");
    for (l = 0; l < equipes; l++)
    {
        printf("\n[%dª] - %.2f m",l+1 , maior_altura[l]);
    }

    printf("\n\nMaior altura de todas:");
    printf("\n%.2f m\n", maior_altura[equipes]);

    return 0;
}