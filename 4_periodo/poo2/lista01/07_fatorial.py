num = int(input("Digite um número: "))

result = 1

if(num > 0):
    for i in range(num, 0, -1):
        result *= i

print(f"{num}! = {result}")