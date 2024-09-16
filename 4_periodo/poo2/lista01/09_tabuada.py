num = int(input("Montar a tabuada de: "))
inicio = int(input("Começar por: "))
fim = int(input("Terminar em: "))

if(inicio > fim):
    inicio, fim = fim, inicio

print(f"\nVou montar a tabuada de {num} começando em {inicio} e terminando em {fim}:")
for i in range(inicio, fim+1):
    print(f"{num} X {i} = {num * i}")