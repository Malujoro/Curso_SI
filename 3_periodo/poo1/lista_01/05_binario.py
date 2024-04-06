num = int(input('Digite um número inteiro em base decimal: '))

aux = num
casas = 1
binario = 0

while(aux > 0):
    binario += (aux % 2) * casas
    casas *= 10
    aux //= 2

print(f'{num} em binário é: {binario}')