def imprimeLista(lista):
    for i in lista:
        if(isinstance(i, list)):
            imprimeLista(i)
        else:
            print(i)

imprimeLista([1, "a", 2.5])
print()
imprimeLista([0, 1, [2, [3, 4]], 5])