num = int(input('Fatorial de: '))

result = 1
for i in range(num, 1, -1):
    result *= i

print(result)