lista = [x for x in range(10)]

i = 0
j = len(lista)-1

print(f"Lista: {lista}")

while i < j:
    lista[i], lista[j] = lista[j], lista[i]
    i += 1
    j -= 1

print(f"Lista trocada: {lista}")