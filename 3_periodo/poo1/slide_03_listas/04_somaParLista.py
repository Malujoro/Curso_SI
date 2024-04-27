import functools as ft

def par(x):
    return x % 2 == 0

def soma(a, b):
    return a + b

lista = [x for x in range(10)]
somaPar = ft.reduce(soma, filter(par, lista))
print(somaPar)