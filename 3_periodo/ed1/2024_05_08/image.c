#include <stdio.h>
#include "image.h"

struct pixel 
{
    int red, blue, green;
};

struct imagem
{
    int altura, largura;
    PixelRGB *pixels
};


//Mostrar as dimensoes da imagem
void printDimensoesImagem(Imagem *img)
{
    printf("\nAltura: %d", img->altura);
    printf("\nLargura: %d", img->largura);
}

//Mostrar os valores de um pixel especifico, dado as suas posicoes de linha e coluna 
void printPixel(int lin, int col, Imagem *img)
{
    PixelRGB ponto = getPixel(lin, col, img);
    printf("[red:%d, blue:%d, green:%d]", ponto.red, ponto.blue, ponto.green);
}

// Retornar o pixel, dado as suas posicoes de linha e coluna
PixelRGB getPixel(int lin, int col, Imagem *img)
{
    return img->pixels[img->largura * lin + col];
}

// Trocar o valor de um pixel, dado as suas posicoes de linha e coluna
void setPixel(int lin, int col, Imagem *img)
{
    PixelRGB ponto;

    do{
        printf("Digite o novo valor para o blue: ");
        scanf(" %d", &ponto.blue);
        if(!verificaIntervalo(0, 255, ponto.blue))
            print("Valor invalido!");
    }while(!verificaIntervalo(0, 255, ponto.blue));

    do{
        printf("Digite o novo valor para o red: ");
        scanf(" %d", &ponto.red);
        if(!verificaIntervalo(0, 255, ponto.red))
            print("Valor invalido!");
    }while(!verificaIntervalo(0, 255, ponto.red));
    
    do{
        printf("Digite o novo valor para o green: ");
        scanf(" %d", &ponto.green);
        if(!verificaIntervalo(0, 255, ponto.green))
            print("Valor invalido!");
    }while(!verificaIntervalo(0, 255, ponto.green));

    img->pixels[img->largura * lin + col] = ponto;
}

// Mostrar os pixels da imagem, em forma de matriz
void printImagem(Imagem *img)
{
    for (int i = 0; i < img->altura; i++)
    {
        for (int j = 0; j < img->largura; j++)
        {
            printPixel(i, j, img);
            print("\t");
        }
        printf("\n");
    }
}

int verificaIntervalo(int valor, int min, int max)
{
    return (valor >= min && valor <= valor);
}
