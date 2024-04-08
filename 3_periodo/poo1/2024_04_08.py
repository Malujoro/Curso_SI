# Utilização Map
# def dobro(n):
#     return n*2

# lista = [0, 1, [2, 3, 4], 5, 6]
# # lista = [0, 1, 5, 6]
# lista2 = map(dobro, lista)

# print(list(lista2))

# def quadrado(n):
#     return n*n

# def par(n):
#     return n % 2 == 0

# lista = [1, 2, 3, 4, 5, 6, 7]

# lista2 = map(quadrado, lista)
# lista3 = filter(par, lista)

# print(list(lista2))
# print(list(lista3))

## Map, Reduce e Filter
# def dobro(n):
#     return n*2

# def isZero(n):
#     return n == 0

# def par(n):
#     return n != 0 and n % 2 == 0

# def impar(n):
#     return n % 2 == 1

# lista = []
# while True:
#     num = int(input("Número: "))
#     if(num < 0):
#         break
#     lista.append(num)

# lista.sort()
# completo = list(filter(par, lista)) + list(filter(isZero, lista)) + list(filter(impar, lista))
# completoMap = list(map(dobro, completo))
# print(list(completo))
# print(completoMap)

import functools as ft

def maior(x, y):
    if(x >= y):
        return x
    return y

def soma(x, y):
    return x + y

def par(x):
    return x % 2 == 0

lista = [0, 1, 2, 3, 4, 5, 6]
pares = list(filter(par, lista))
result = ft.reduce(soma, pares)
maiorNum = ft.reduce(maior, lista)

print(result, maiorNum)