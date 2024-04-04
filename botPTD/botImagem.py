from pyautogui import *
from time import sleep

def posiciona(x1, y1, x2, y2):
    sleep(0.2)
    mouseDown(x1, y1, 'left')
    sleep(0.2)
    moveTo(x2, y2)
    mouseUp(x2, y2, 'left')

def clicaImagem(nome):
    coord = locateCenterOnScreen(nome, confidence=0.9)
    if(coord != None):
        click(coord.x, coord.y)
        return 1
    return 0

## Coordenadas Pokémon - PC
p6 = [1500, 740]
p5 = [1300, 740]
p4 = [1070, 740]
p3 = [855, 740]
p2 = [660, 740]
p1 = [460, 740]

while True:
    # Entrar na fase
    sleep(2)
    click(348, 477)

    # Iniciar partida (Start)
    sleep(0.2)
    click(1633, 115)

    # Skipar cena
    sleep(0.2)
    click(233, 104)

    # Diminuir tela para 75% (tecla 9)
    sleep(0.2)
    press('9')

    # Posicionar os 6 pokemons (do último pro primeiro)
    sleep(0.2)
    posiciona(p6[0], p6[1], 1050, 411)
    posiciona(p5[0], p5[1], 1031, 128)
    posiciona(p4[0], p4[1], 737, 146)
    posiciona(p3[0], p3[1], 755, 550)
    posiciona(p2[0], p2[1], 408, 695)
    posiciona(p1[0], p1[1], 1230, 546)

    # Aumentar speed para x4 (tecla 4)
    sleep(0.2)
    press('4')

    # Looping para verificar o level up
    while True:
        # Encontra o o pokémon que precisa upar
        if(clicaImagem('seta1.png')):
            sleep(0.2)
            click(1559, 587)

            clicaImagem('continue.png')
            clicaImagem('dontlearn.png')
        
        if(clicaImagem('x1.png') or clicaImagem('shiny.png')):
            press('p')
            press('2')

        if(clicaImagem('end.png')):
            break