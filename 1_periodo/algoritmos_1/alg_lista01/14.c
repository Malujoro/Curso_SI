#include <stdio.h>

int main(void)
{
    float a, b, c;

    printf("A: ");
    scanf("%f", &a);

    printf("B: ");
    scanf("%f", &b);

    c = a;
    a = b;
    b = c;

    printf("A: %.1f | B: %.1f", a, b);
    
    return 0;
}