zero = []
par = []
impar = []
while True:
    num = int(input("Digite um número: "))
    if(num < 0):
        break
    elif(num == 0):
        zero.append(num)
    elif(num % 2 == 0):
        par.append(num)
    elif(num % 2 == 1):
        impar.append(num)

par.sort()
impar.sort()

completa = par + zero + impar
print(completa)
print()