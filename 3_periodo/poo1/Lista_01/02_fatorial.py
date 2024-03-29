def fatorialIterativo(num):
    result = 1
    for i in range(num, 1, -1):
        result *= i
    return result
        

def fatorialRecursivo(num):
    if(num == 0):
        return 1
    return num * fatorialRecursivo(num-1)

num = int(input('Digite um número para ser calculado o fatorial: '))

print(f'Fatorial Iterativo: {fatorialIterativo(num)}')
print(f'Fatorial Recursivo: {fatorialRecursivo(num)}')