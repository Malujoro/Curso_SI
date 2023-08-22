#include <stdio.h>

int main(void)
{
    float vel_media, tempo, dist, gas;

    printf("Velocidade média [Km/h]: ");
    scanf("%f", &vel_media);

    printf("Tempo gasto [h]: ");
    scanf("%f", &tempo);
    
    dist = vel_media * tempo;
    gas = dist / 12;

    printf("\nDistância percorrida: %f Km", dist);
    printf("\nGasolina necessária: %f L", gas);

    return 0;
}