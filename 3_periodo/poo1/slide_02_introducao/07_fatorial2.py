while True:
    num = int(input('Número para calcular fatorial (negativo para sair): '))

    if(0 < num < 16):
        result = 1
        for i in range(num, 1, -1):
            result *= i

        print(result, '\n')
    elif(num < 0):
        break
    else:
        print('\nDigite números positivos menores que 16!\n')