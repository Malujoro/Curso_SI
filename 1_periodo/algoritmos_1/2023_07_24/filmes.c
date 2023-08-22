#include <stdio.h>

//  Aplicativo para armazenar filmes
//      Código
//      Nome
//      Categoria [vetor]
//      Quantidade

int main(void)
{
    int quant_filmes = 5;
    char nome_filme[quant_filmes][40], categoria[5][40];
    int filmes[quant_filmes][3];
    int l, c, op_categoria;

    printf("\n");
    for (l = 0; l < 5; l++)
    {
        printf("Nome da %dº categoria: ", l+1);
        gets(categoria[l]);
        setbuf(stdin, NULL);
    }

    for (l = 0; l < quant_filmes; l++)
    {
        printf("\nCódigo do %dº filme: ", l+1);
        scanf("%d", &filmes[l][0]);
        setbuf(stdin, NULL);

        printf("Nome do filme: ");
        gets(nome_filme[l]);
        setbuf(stdin, NULL);

        printf("Quantidade: ");
        scanf("%d", &filmes[l][1]);
        setbuf(stdin, NULL);

        printf("\nCategorias:");
        for (c = 0; c < 5; c++)
        {
            printf("\n[%d] - %s", c+1, categoria[c]);
        }
        printf("\nOpção: ");
        scanf("%d", &op_categoria);
        setbuf(stdin, NULL);

        filmes[l][2] = op_categoria-1;

        printf("\nFilme %d cadastrado\n", l+1);
    }

    printf("\nListar filmes da categoria:");
        for (c = 0; c < 5; c++)
        {
            printf("\n[%d] - %s", c+1, categoria[c]);
        }
        printf("\nOpção: ");
        scanf("%d", &op_categoria);
        setbuf(stdin, NULL);

    printf("\nCódigo \t Nome \t Quantidade");
    for (l = 0; l < quant_filmes; l++)
    {
        
        if (op_categoria-1 == filmes[l][2])
        {
            printf("\n %d \t %s \t %d", filmes[l][0], nome_filme[l], filmes[l][1]);
        }
    }

    return 0;
}