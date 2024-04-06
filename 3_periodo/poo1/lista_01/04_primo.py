def primo(num):
    if(num <= 1):
        return False
    
    for i in range(2, num):
        if(num % i == 0):
            return False
    return True

inicio = int(input('Digite o início: '))
fim = int(input('Digite o fim: '))

vazio = True

for i in range(inicio, fim+1):
    if(primo(i)):
        vazio = False
        print(i, end = ' -> ')

if(vazio):
    print('Não existe nenhum número primo dentro desse intervalo')
else:
    print('FIM')