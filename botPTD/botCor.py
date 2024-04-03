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

def verificaShiny():
    # if(clicaImagem('x1.png') or clicaImagem('shiny.png')):
    if(clicaImagem('x1.png')):
        press('p')
        a = input('Pausado! Enter para continuar')
        # press('2')

p6 = [1500, 740]
p5 = [1300, 740]
p4 = [1070, 740]
p3 = [855, 740]
p2 = [660, 740]
p1 = [460, 740]

while True:
    # Entrar na fase
    sleep(2)
    click(1260, 480)

    # Iniciar partida (Start)
    sleep(0.2)
    click(1633, 115)

    # Skipar cena
    sleep(0.2)
    click(233, 104)

    # Diminuir tela para 75% (tecla 9)
    sleep(0.2)
    press('7')

    # Posicionar os 6 pokemons (do último pro primeiro)
    sleep(0.5)
    posiciona(p6[0], p6[1], 460, 420)
    posiciona(p5[0], p5[1], 260, 480)
    posiciona(p4[0], p4[1], 260, 360)
    posiciona(p3[0], p3[1], 260, 300)
    posiciona(p2[0], p2[1], 260, 260)
    posiciona(p1[0], p1[1], 230, 160)

    # Aumentar speed para x4 (tecla 4)
    sleep(0.2)
    press('4')
    press('0')

    # Looping para verificar o level up
    while True:
        upou = False

        verificaShiny()

        # Encontra o o pokémon que precisa upar
        if(pixel(p6[0], p6[1])[0] == 255 or pixel(p6[0], p6[1])[1] == pixel(p6[0], p6[1])[2] == 0):
            click(p6[0], p6[1])
            sleep(0.1)
            click(1559, 587)
            upou = True
        
        if(pixel(p5[0], p5[1])[0] == 255 or pixel(p5[0], p5[1])[1] == pixel(p5[0], p5[1])[2] == 0):
            click(p5[0], p5[1])
            sleep(0.1)
            click(1559, 587)
            upou = True

        if(pixel(p4[0], p4[1])[0] == 255 or pixel(p4[0], p4[1])[1] == pixel(p4[0], p4[1])[2] == 0):
            click(p4[0], p4[1])
            sleep(0.1)
            click(1559, 587)
            upou = True
        
        if(pixel(p3[0], p3[1])[0] == 255 or pixel(p3[0], p3[1])[1] == pixel(p3[0], p3[1])[2] == 0):
            click(p3[0], p3[1])
            sleep(0.1)
            click(1559, 587)
            upou = True

        if(pixel(p2[0], p2[1])[0] == 255 or pixel(p2[0], p2[1])[1] == pixel(p2[0], p2[1])[2] == 0):
            click(p2[0], p2[1])
            sleep(0.1)
            click(1559, 587)
            upou = True
        
        if(pixel(p1[0], p1[1])[0] == 255 or pixel(p1[0], p1[1])[1] == pixel(p1[0], p1[1])[2] == 0):
            click(p1[0], p1[1])
            sleep(0.1)
            click(1559, 587)
            upou = True
        
        verificaShiny()

        if(upou):
            clicaImagem('continue.png')
            clicaImagem('dontlearn.png')
            clicaImagem('done.png')

        verificaShiny()

        if(clicaImagem('end.png')):
            break