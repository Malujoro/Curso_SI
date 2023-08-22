#include <stdio.h>

int main(void)
{
    float kg, g;
    
    printf("Peso [Kg]: ");
    scanf("%f", &kg);

    g = kg * 1000;

    printf("Peso (em gramas): %.2f", g);

    return 0;
}