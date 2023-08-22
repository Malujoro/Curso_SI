#include <stdio.h>

int main(void)
{
    int op=1, i;
    float vetor[4], maior, menor, media=0;

    printf("\n");

    for (i=0; i < 4; i++)
    {
        printf("%dª Nota: ", i+1); // Recebe as 4 notas
        scanf("%f", &vetor[i]);

        media += vetor[i]; // Soma as notas

        if (i == 0)
        {
            maior = vetor[i];
            menor = vetor[i];
        }
        else
        {    

            if (vetor[i] > maior) // Pega o maior número
            {
                maior = vetor[i];
            }
            if (vetor[i] < menor) // Pega o menor número
            {
                menor = vetor[i];
            }
        }
    }

    media /= 4; // Termina a média

    while (op != 5)
    {    
        printf("\n------------Menu------------");
        printf("\n1 - Média das notas\n2 - Maior nota\n3 - Menor nota\n4 - Situação do aluno (Aprovado, Reprovado)\n5 - Sair do menu\n\nOpção: ");
        scanf("%d", &op);

        switch (op)
        {
            case 1:
            {
                printf("\nMédia do aluno: %.2f", media);
                break;
            }
            case 2:
            {
                printf("\nMaior nota: %.2f", maior);
                break;
            }
            case 3:
            {
                printf("\nMenor nota: %.2f", menor);
                break;
            }
            case 4:
            {
                printf("\nSituação do aluno:");
                if (media >= 7 || media <= 10)
                {
                    printf("\nAprovado");
                }
                else if (media >=0 || media < 7)
                {
                    printf("\nReprovado");
                }
                else
                {
                    printf("Média inválida");
                }
                break;
            }
            case 5:
            {
                printf("\nSaindo...\n");
                break;
            }
            default:
            {
                printf("\nOpção inválida!!");
            }
        }
        printf("\n");
    }
    return 0;
}