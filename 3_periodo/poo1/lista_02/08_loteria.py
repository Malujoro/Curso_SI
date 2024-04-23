from random import randint

def geraLista(tam):
    lista = []

    for i in range(tam):
        lista.append(randint(1, 3))
    
    return lista

def geraCartao(num, tam):
    return {"numero": num, "vetor": geraLista(tam)}

def quantIgual(lista1, lista2):
    soma = 0
    for i in range(len(lista1)):
        if(lista1[i] == lista2[i]):
            soma += 1
    return soma

gabarito = geraLista(13)
cartoes = [geraCartao(1, 13), geraCartao(2, 13), geraCartao(3, 13)]

for i in cartoes:
    acertos = quantIgual(gabarito, i['vetor'])
    print(f"Cartão número {i['numero']} - {acertos} acertos")
    if(acertos == 13):
        print("Ganhador!!\n")