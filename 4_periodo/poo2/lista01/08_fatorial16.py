while True:
    num = int(input("Digite um número (negativo para sair): "))

    if(num < 0):
        print("Saindo...")
        break
    if(num > 0 and num < 16):
        result = 1
        for i in range(num, 0, -1):
            result *= i
        print(f"\n{num}! = {result}\n")
    elif(num >= 16):
        print("\nEntrada inválida! Digite um número menor que 16\n")
