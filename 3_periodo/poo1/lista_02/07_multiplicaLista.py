def preencheLista(tam):
    lista = []

    for i in range(tam):
        lista.append(int(input(f"{i+1}º Elemento: ")))
    
    return lista

print("Lista 1")
lista1 = preencheLista(10)
print("\nLista 2")
lista2 = preencheLista(10)

lista3 = []
for i in range(10):
    lista3.append(lista1[i] * lista2[i])

print("\nLista 3")
print(lista3)