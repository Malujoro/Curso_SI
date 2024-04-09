## Usando Lambda
# import functools as ft

# lista = [1, 2, 3, 4]

# dobro = list(map(lambda x: x*2, lista))
# somaTodos = ft.reduce(lambda x, y: x+y, dobro)

# print(list(dobro))
# print(somaTodos)


## Refazendo as questões - Lista Par, Zero, Impar
# lista = []
# while True:
#     num = int(input("Digite um número: "))
        
#     if(num < 0):
#         break

#     lista.append(num)

# lista.sort()
# completo = list(filter(lambda x: x != 0 and x % 2 == 0, lista)) + list(filter(lambda x: x == 0, lista)) + list(filter(lambda x: x % 2 == 1, lista))
# print(completo)

# Refazendo as questões - Soma todos de uma lista
# import functools as ft
# lista = [0, 1, 2, 3, 4, 5, 6]

# total = ft.reduce(lambda x, y: x+y, filter(lambda x: x % 2 == 0, lista))
# print(total)

n = int(input("Digite um número: "))

lista = [x for x in range(1, n+1) if n % x == 0]

print(lista)
if(len(lista) >= 2):
    print("Não é primo")
else:
    print("É primo")
