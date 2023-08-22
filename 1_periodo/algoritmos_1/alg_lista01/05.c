#include <stdio.h>

int main(void)
{
    float nota1, nota2, nota3, nota4;
    
    printf("Nota 1: ");
    scanf("%f", &nota1);

    printf("Nota 2: ");
    scanf("%f", &nota2);

    printf("Nota 3: ");
    scanf("%f", &nota3);

    printf("Nota 4: ");
    scanf("%f", &nota4);

    printf("A média das notas é: %.2f", (nota1 + nota2 + nota3 + nota4)/4);

    return 0;
}