#include <stdio.h>

// Armazenar código, nome, quantidade e valor de 100 produtos.
// Exibir o nome, quantidade e valor de um produto dados seu código.

int main(void)
{
    int quant = 100, i, op;
    int cod_quant[quant][2];
    // 0 - Código
    // 1 - Quantidade
    char nomes[quant][100];
    float preco[quant];

    for (i = 0; i < quant; i++)
    {
        printf("\n%dº Produto:", i+1);
        
        do
        {
            printf("\nCódigo: ");
            scanf("%d", &op);
            setbuf(stdin, NULL);
            if (op <= 0)
            {
                printf("Opção inválida!");
            }
        } while (op <= 0);

        cod_quant[i][0] = op;

        printf("Nome: ");
        gets(nomes[i]);
        setbuf(stdin, NULL);

        printf("Quantidade: ");
        scanf("%d", &cod_quant[i][1]);
        setbuf(stdin, NULL);

        printf("Valor: R$");
        scanf("%f", &preco[i]);
        setbuf(stdin, NULL);
    }
    
    do
    {
        printf("\nCódigo do produto buscado [0 sai]:");
        scanf("%d", &op);

        if (op != 0)
        {
            printf("\nProdutos encontrados:\n");
            for (i = 0; i < quant; i++)
            {
                if (cod_quant[i][0] == op)
                {
                    printf("%s \t \t %d \t \t R$%.2f\n", nomes[i], cod_quant[i][1], preco[i]);
                }
            }
        }
    } while (op != 0);
    return 0;
}