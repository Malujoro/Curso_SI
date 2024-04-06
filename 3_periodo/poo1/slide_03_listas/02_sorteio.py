import random

inicio, fim = (input("Digite o intervalo (separado por espaço): ")).split(" ")

inicio = int(inicio)
fim = int(fim)

if(inicio > fim):
    inicio, fim = fim, inicio

while True:
    quant = int(input("Quantos números serão sorteados? "))

    if((quant > fim - inicio + 1) or quant <= 0):
        print(f"\nErro! Digite uma quantidade válida para o intervalo fechado [{inicio}, {fim}] (um positivo menor ou igual a {fim-inicio+1})\n")
        continue
    break

lista = []
for i in range(quant):
    while True:
        num = random.randint(inicio, fim)
        if(lista.count(num) == 0):
            lista.append(num)
            break

print(lista)