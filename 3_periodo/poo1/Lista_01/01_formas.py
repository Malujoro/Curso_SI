while True:
    print('Escolha uma figura: ')
    print('[1] - Triângulo')
    print('[2] - Quadrado')
    print('[3] - Círculo')
    print('[0] - Sair')
    op = int(input('Opção: '))

    if(op == 1):
        base = float(input('\nBase do triângulo: '))
        altura = float(input('\nAltura do triângulo: '))
        print(f'\nA área do triângulo é {base*altura/2}\n')
    elif(op == 2):
        lado = float(input('\nLado do quadrado: '))
        print(f'\nA área do quadrado é {lado*lado}\n')
    elif(op == 3):
        raio = float(input('\nRaio do círculo: '))
        print(f'\nA área do círculo é {(raio*raio) * 3.14}\n')
    elif(op == 0):
        print('\nSaindo...')
        break
    else:
        print('\nOpção inválida!\n')