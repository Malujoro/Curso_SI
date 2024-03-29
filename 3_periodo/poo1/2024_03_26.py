# Teste de Assert
'''a = 10.5

try:
    assert isinstance(a, int)
except AssertionError:
    while True:
        print('Erro!!')
        try:
            a = int(input('Digite um número inteiro: '))
            break
        except:
            pass

print(f'O número inteiro digitado foi {a}')'''

def soma(a, b = 0):
    return a + b

def subtracao(a, b = 0):
    return a - b

def multiplicacao(a, b = 1):
    return a * b

def divisao(a, b = 1):
    return a / b

def menu():
    print('\nMenu: ')
    print('[+] - Soma')
    print('[-] - Subtração')
    print('[*] - Multiplicação')
    print('[/] - Divisão')
    print('[a] - Trocar o valor de A')
    print('[b] - Trocar o valor de B')
    print('[sair] - Sair')
    op = (input('Digite a operação: ')).lower()
    return op

# # Verifica se o arquivo "executado" é o "original" do código
# if __name__ == '__main__': 
    # c = soma(5, 2)
    # print(c)

a = float(input('A: '))
b = float(input('B: '))
while True:
    op = menu()

    if(op == '+'):
        result = soma(a, b)
    elif(op == '-'):
        result = subtracao(a, b)
    elif(op in '*x'):
        result = multiplicacao(a, b)
    elif(op in '/:'):
        result = divisao(a, b)
    elif(op in 'a'):
        a = float(input('A: '))
    elif(op in 'b'):
        b = float(input('B: '))
    elif(op == 'sair'):
        break

    if(op in '+-/*:x'):
        print(f'{a} {op} {b} = {result}')