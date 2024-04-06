#include <stdio.h>

int main()
{
    int tecla, num;

    printf("Número quebrado e o Digitado: ");
    scanf(" %d %d", &tecla, &num);

    int aux = num, casas = 1, result = 0;

    while(aux > 0)
    {
        // Pega o "Último dígito" do número e verifica se é igual a tecla quebrada
        if(aux % 10 != tecla)
        {
            // Se não for, então o resultado vai receber o dígito em sua "posição" (variável casas)
            result += (aux % 10) * casas;
            // Incrementa a variável de casas
            casas *= 10;
        }
        // Auxiliar recebe a divisão inteira dela mesma (excluindo o "Último dígito", para poder verificar os outros)
        aux /= 10;
    }
    printf("Número digitado: %d\n", result);

    return 0;
}