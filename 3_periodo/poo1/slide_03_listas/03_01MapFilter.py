def par(x):
    return x != 0 and x % 2 == 0

def impar(x):
    return x % 2 == 1

def zero(x):
    return x == 0

def quadrado(x):
    return x ** 2

lista = []
while True:
    num = int(input("Digite um número [negativo sai] : "))
    if(num < 0):
        break
    lista.append(num)

lista.sort()

listaFinal = list(filter(par, lista))
listaFinal += list(filter(zero, lista))
listaFinal += list(filter(impar, lista))
listaFinal = list(map(quadrado, listaFinal))
print(listaFinal)