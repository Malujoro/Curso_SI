#include <stdio.h>

int main(void)
{
    int horas, min, seg, mili;

    printf("Horas: ");
    scanf("%d", &horas);

    min = horas * 60;
    seg = min * 60;
    mili = seg * 1000;

    printf("Minutos: %d", min);
    printf("\nSegundos: %d", seg);
    printf("\nMilissegundos: %d\n", mili);

    return 0;
}