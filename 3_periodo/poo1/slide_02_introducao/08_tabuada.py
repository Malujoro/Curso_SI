num = int(input('Montar a tabuada de: '))
inicio = int(input('Começar por: '))
fim = int(input('Terminar em: '))

print(f'Montando a tabuada de {num} começando em {inicio} e terminando em {fim}:')
for i in range(inicio, fim+1):
    print(f'{num} x {i} = {num * i}')