def posicao(lista, elemento):
    pos = 0
    for i in lista:
        if(i == elemento):
            return pos
        pos += 1
    return -1

lista = [6, 1, 2, 3, 4, 5]
lista2 = [2, 3, "a", 6, 0]

for i in lista2:
    if(posicao(lista, i) != -1):
        print(f"{i} existe na posição {posicao(lista, i)}")
    else:
        print(f"{i} não existe")