num = int(input("Digite um número: "))

divisores = [x for x in range(2, num) if num % x == 0]

if(len(divisores) > 0):
    print("Não é primo")
else:
    print("É primo")