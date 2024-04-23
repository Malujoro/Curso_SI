def media(lista):
    soma = 0
    for i in lista:
        soma += i
    return soma/len(lista)

dicio = {}
for i in range(5):
    nome = input(f"Nome do {i+1}º corredor: ")
    dicio[nome] = []
    for j in range(3):
        dicio[nome].append(float(input(f"Tempo da {j+1}º volta [em segundos]: ")))
    print()

cont = 0
for nome, vetor in dicio.items():
    for i in range(0, len(vetor)):
        if((cont == 0 and i == 0) or (vetor[i] < melhorTempo)):
            melhorTempo = vetor[i]
            melhorVolta = i
            melhorNome = nome
    if(cont == 0 or media(vetor) < menorMedia):
        menorMedia = media(vetor)
        campeao = nome
        
    cont += 1

print(f"\n{melhorNome} teve a melhor volta [{melhorVolta+1}], com {melhorTempo} segundos")
print(f"\nO campeão foi: {campeao}, com uma media de tempo de {menorMedia} segundos")