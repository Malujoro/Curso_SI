#include <stdio.h>

int main(void)
{
    int cod, quant;
    float preco, soma=0, total=0;
    char cont=' ';
 
    while (cont != 'N' && cont != 'n')
    {
        printf("\n------------------------------------");
        printf("\n|  Especificação  | Código | Preço |");
        printf("\n|-----------------|--------|-------|");
        printf("\n| Cachorro quente |  100   | 1.20  |");
        printf("\n| Bauru simples   |  101   | 1.30  |");
        printf("\n| Bauru com ovo   |  102   | 1.50  |");
        printf("\n| Hambúrguer      |  103   | 1.20  |");
        printf("\n| Cheeseburguer   |  104   | 1.30  |");
        printf("\n| Refrigerante    |  105   | 1.00  |");
        printf("\n-----------------------------------");
        
        cod = 0;
        while (cod < 100 || cod > 105)
        {
            printf("\nCódigo [0 para sair]: ");
            scanf("%d", &cod);
            setbuf(stdin, NULL);

            switch (cod)
            {
                case 100:
                    printf("\n[Cachorro quente]");
                    preco = 1.20;
                    break;
                case 101:
                    printf("\n[Bauru simples]");
                    preco = 1.30;
                    break;
                case 102:
                    printf("\n[Bauru com ovo]");
                    preco = 1.50;
                    break;
                case 103:
                    printf("\n[Hambúrguer]");
                    preco = 1.20;
                    break;
                case 104:
                    printf("\n[Cheeseburguer]");
                    preco = 1.30;
                    break;
                case 105:
                    printf("\n[Refrigerante]");
                    preco = 1.00;
                    break;
                default:
                    printf("\nCódigo inválido!!\n");
            }
        }
        
        printf("\n\nQuantidade: ");
        scanf("%d", &quant);
        setbuf(stdin, NULL);

        soma = preco * quant;
        total += soma;

        printf("\nAcréscimo de R$%.2f reais na conta", soma);
        printf("\nTotal: R$%.2f", total);

        printf("\n\nContinuar compra? [S/N]: ");
        scanf("%c", &cont);
        setbuf(stdin, NULL);
    }
    return 0;
}