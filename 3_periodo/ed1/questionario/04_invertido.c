#include <stdio.h>

// 1234
// 4 + (123)
// 4 + (3 + (12))
// 4 + (3 + (2 + (1)))

// 4 + (3 + (20 + 1))
// 4 + (3 + 21)
// 4 + (300 + 21)
// 4 + 321
// 4000 + 321
// 4321

int inverter(int num)
{
    if(num < 10)
        return num;
    
    int unidade = num % 10, resto = inverter(num / 10), tamanho = 10;
    
    while(tamanho <= resto)
        tamanho *= 10;

    return (unidade * tamanho) + resto;
}

int main()
{
    int num, inv;
    
    printf("Digite um número: ");
    scanf(" %d", &num);

    inv = inverter(num);

    printf("Número invertido: %d\n", inv);

    return 0;    
}