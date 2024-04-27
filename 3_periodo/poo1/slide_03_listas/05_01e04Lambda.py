import functools as ft

lista = []
while True:
    num = int(input("Digite um número [negativo sai]: "))
    if(num < 0):
        break
    lista.append(num)

lista.sort()

listaPar = list(filter(lambda x: x % 2 == 0 and x != 0, lista))

listaFinal = listaPar + list(filter(lambda x: x == 0, lista)) + list(filter(lambda x: x % 2 == 1, lista))

somaPar = ft.reduce(lambda x, y: x + y, listaPar)

print(listaFinal)
print(somaPar)