def media(lista):
    total = 0
    for i in lista:
        total += i
    return total / len(lista)

def mediana(lista):
    lista.sort()
    tam = len(lista)
    if(tam % 2 == 1):
        return lista[tam//2]

    return (lista[tam//2] + lista[tam//2 -1]) / 2

def variancia(lista):
    soma = 0
    for i in lista:
        soma += (i - media(lista)) ** 2
    return soma/len(lista)

def desvioPadrao(lista):
    return variancia(lista) ** (1/2)

lista = [x for x in range(1, 101)]
dicio = {}
dicio["media"] = media(lista)
dicio["mediana"] = mediana(lista)
dicio["variancia"] = variancia(lista)
dicio["desvioPadrao"] = desvioPadrao(lista)

for chave, valor in dicio.items():
    print(f"{chave}: {valor}")