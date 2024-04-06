lista = []
while True:
    num = int(input("Digite um número: "))
    if(num < 0):
        break
    elif(num == 0):
        lista.insert(len(lista)//2, num)
    elif(num % 2 == 0):
        lista.insert(0, num)
    elif(num % 2 == 1):
        lista.append(num)

for i in lista:
    print(i, end='')
print()