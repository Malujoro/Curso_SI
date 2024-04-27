import functools as ft

def maior(x, y):
    if(x > y):
        return x
    return y

def menor(x, y):
    if(x < y):
        return x
    return y

def par(x):
    return x % 2 == 0

def soma(x, y):
    return x + y

def negativo(x):
    return x < 0

lista = [12, -2, 4, 8, 29, 45, 78, 36, -17, 2, 12, 8, 3, 3, -52]

print(lista)
print(f"Maior elemento: {ft.reduce(maior, lista)}")
print(f"Menor elemento: {ft.reduce(menor, lista)}")
print(f"Pares: {list(filter(par, lista))}")
print(f"O primeiro elemento aparece {lista.count(lista[0])} vezes")
print(f"Média: {ft.reduce(soma, lista) / len(lista)}")
print(f"Soma dos negativos: {ft.reduce(soma, filter(negativo, lista))}")