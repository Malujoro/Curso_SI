base = float(input("Base: "))
expoente = int(input("Expoente: "))

result = 1

if(expoente > 0):
    for i in range(expoente):
        result *= base
elif(expoente < 0):
    for i in range(expoente, 0):
        result /= base

print(f"{base}^{expoente} = {result}")