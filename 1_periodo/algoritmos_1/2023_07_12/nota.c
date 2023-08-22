#include <stdio.h>

int main(void)
{
    float notas[5][5], maior, soma, maior_media;
    int l, c, quant_ap;

    for (l=0; l < 5; l++)
    {
        soma = 0;
        printf("\nDigite as notas do %d aluno:\n", l+1);
        for (c=0; c < 4; c++)
        {
            printf("Digite a %d nota: ", c+1);
            scanf("%f", &notas[l][c]);

            soma += notas[l][c];
        }
        notas[l][c] = soma/4;
    }

    quant_ap = 0;
    for (l=0; l < 5; l++)
    {
        for (c=0; c < 4; c++)
        {
            if (notas[l][c] >= 7)
            {
                quant_ap++;
            }
        }
    }
    printf("A quantidade de notas aprovativas é: %d\n", quant_ap);

    for (l=0; l < 5; l++)
    {
        maior = notas[l][0];
        for (c=0; c < 4; c++)
        {
            if (notas[l][c] > maior)
            {
                maior = notas[l][c];
            }
        }
        printf("\nA maior nota do %d aluno é: %.2f", l+1, maior);
    }

    maior_media = notas[0][4];
    for (l=1; l < 5; l++)
    {
        if (notas[l][4] > maior_media)
        {
            maior_media = notas[l][4];
        }
    }
    printf("\nA maior média é: %.2f", maior_media);
    return 0;
}

