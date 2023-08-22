#include <stdio.h>
#include <string.h>

int main(void)
{
    char nome[100];
    float nota, media;
    int cont_nota, cont_aluno=1;

    while (cont_aluno <= 20)
    {
        printf("\nNome do %dº aluno: ", cont_aluno);
        fgets(nome, 100, stdin);
        setbuf(stdin, NULL);
        
        cont_nota = 0;
        media = 0;
        printf("\n");
        while (cont_nota < 3)
        {
            printf("%dª Nota: ", cont_nota+1);
            scanf("%f", &nota);
            setbuf(stdin, NULL);
            if (nota >= 0 && nota <= 10)
            {
                media += nota;
                cont_nota++;
            }
            else
                printf("Nota inválida!!\n");
        }

        media /= 3;
        printf("\nMédia do %s : %.2f", nome, media);

        printf("\nSituação: ");
        if (media >= 7)
        {
            printf("Aprovado\n");
        }
        else if (media >= 4)
        {
            printf("Prova Final\n");
        }
        else
        {
            printf("Reprovado\n");
        }
        cont_aluno++;
    }
    return 0;
}