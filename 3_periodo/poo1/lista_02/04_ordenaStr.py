def ordenaStr(str):
    lista = list(str)

    for i in range(len(lista)):
        for j in range(i+1, len(lista)):
            if(lista[j] < lista[i]):
                lista[i], lista[j] = lista[j], lista[i]
    
    return ''.join(lista)

str = (input("Digite uma string: ")).lower()
print(f"{str} ordenada: {ordenaStr(str)}")