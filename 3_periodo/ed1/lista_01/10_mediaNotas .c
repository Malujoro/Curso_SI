#include <stdio.h>
#include <stdlib.h>

int main()
{
    int quant;

    printf("Quantidade de alunos: ");
    scanf(" %d", &quant);

    float *vetor = (float *) malloc(quant * sizeof(float));

    float media = 0;
    for(int i = 0; i < quant; i++)
    {
        printf("Nota do %dº aluno: ", i+1);
        scanf(" %f", &vetor[i]);
        media += vetor[i];
    }
    media /= quant;
    
    printf("\nMédia da turma: %.2f\n", media);

    free(vetor);
    return 0;
}