#include <stdio.h>

int main(void)
{
    char nomes[100][100];
    int cod_quant[100][2];
    float compra_venda[100][2], preco_maior;
    int op, quant=0;
    int c, pos_maior, pos_menor, quant_menor;

    // Mateus
    do
    {
    printf("\n----------Menu----------");
    printf("\n1 - Cadastrar Produto");
    printf("\n2 - Listar o nome de todos os produtos");
    printf("\n3 - Informar o nome do produto mais caro");
    printf("\n4 - Informar o nome do produto que possui menor quantidade");
    printf("\n0 - Sair");
    printf("\n\n Opção:");
    scanf("%d", &op);
    setbuf(stdin, NULL);

    switch (op)
    {
        case 1:
            printf("Código do %dº produto", quant+1);
            scanf("%d", &cod_quant[quant][0]);
            setbuf(stdin, NULL);
        
            //Gabriel
            printf("Nome do %d produto: ", quant+1);
            gets(nomes[quant]);
            setbuf(stdin, NULL);

            printf("Quantidade do %dº produto: ", quant+1);
            scanf("%d", &cod_quant[quant][1]);
            setbuf(stdin, NULL);

            printf("Informe o preço de compra do %d produto: ", quant+1);
            scanf("%f", &compra_venda[quant][0]);
            setbuf(stdin, NULL);

            compra_venda[quant][1] = compra_venda[quant][0] * 1.30;

            // Mateus
            if ((quant == 0) || (compra_venda[quant][1] > preco_maior))
            {
                preco_maior = compra_venda[quant][1];
                pos_maior = quant;
            }

            if ((quant == 0) || (cod_quant[quant][1] < quant_menor))
            {
                quant_menor = cod_quant[quant][1];
                pos_menor = quant;
            }

            quant ++;
            break;
        
        // Gabriel
        case 2:
            printf("A seguir, os nomes dos produtos: ");
            for(c = 0; c < quant; c++) {
                printf("\n%s", nomes[c]);
            }
            break;

        case 3:
            printf("%s", nomes[pos_maior]);
            break;
        case 4:
            printf("%s", nomes[pos_menor]);
            break;
        case 0:
            printf("Saindo...");
            break;
        default:
        {
            printf("Opção Inválida!!");
        }
    }
    } while (op != 0);
    return 0;
}