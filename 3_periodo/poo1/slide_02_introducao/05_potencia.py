base = int(input('Digite a base: '))
exp = int(input('Digite o expoente: '))

i = 0
result = 1

while(i < exp):
    result *= base
    i += 1

print(f'\n{base}^{exp} = {result}')
