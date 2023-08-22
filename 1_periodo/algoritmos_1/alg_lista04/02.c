#include <stdio.h>

// Armazenar código, nome, quantidade e valor de 100 produtos
// Listar os nomes de todos os produtos juntamente com seu código, quantidade e valor.

int main(void)
{
    int quant = 3, i;
    // 0 código | 1 quantidade
    int produtos[quant][2]; 
    char nomes[quant][100];
    float preco[quant];

    for (i = 0; i < quant; i++)
    {
        printf("\nCódigo do %dº produto: ", i+1);
        scanf("%d", &produtos[i][0]);
        setbuf(stdin, NULL);

        printf("Nome do %dº produto: ", i+1);
        gets(nomes[i]);
        setbuf(stdin, NULL);
        
        printf("Quantidade do %dº produto: ", i+1);
        scanf("%d", &produtos[i][1]);
        setbuf(stdin, NULL);

        printf("Preço do %dº produto: R$", i+1);
        scanf("%f", &preco[i]);
        setbuf(stdin, NULL);
    }

    for (i = 0; i < quant; i++)
    {
        printf("\n[%s] \t [%d] \t [%d] \t [%.2f]", nomes[i], produtos[i][0], produtos[i][1], preco[i]);
    }

    return 0;
}