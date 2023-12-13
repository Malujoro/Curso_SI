#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arquivo = fopen("media.txt", "w");
    float nota, media;
    int i;

    if(arquivo == NULL)
        printf("Erro ao abrir o arquivo!");
    else
    {
        for(i = 0; i < 3; i++)
        {
            printf("%dª nota: ", i+1);
            scanf(" %f", &nota);
            media += nota;
            fprintf(arquivo, "%.2f ", nota);
        }
        media /= 3;
        fprintf(arquivo, "%.2f ", media);

        if(media < 0 || media > 10)
            fprintf(arquivo, "Média inválida");
        else if(media >= 7)
            // fprintf(arquivo, "Aprovado");
            // Aparentemente fputs funciona do mesmo jeito que fprintf
            fputs("Aprovado", arquivo);
        else if(media >= 4)
            fprintf(arquivo, "Prova Final");
        else
            fprintf(arquivo, "Reprovado");

        fclose(arquivo);
        
        float vetor[4];
        char situacao[50];

        arquivo = fopen("media.txt", "r");
        for(i = 0; i < 4; i++)
            fscanf(arquivo, "%f", &vetor[i]);

        fscanf(arquivo, "%f", &vetor[3]);
        fscanf(arquivo, "%[^\n]s", situacao);

        printf("\nMédia: %.2f\n", vetor[3]);
        printf("\nSituação: %s\n", situacao);
        fclose(arquivo);
    }
    return 0;
}