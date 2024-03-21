peso = float(input('Peso de peixes (em Kg): '))

if(peso > 50):
    excesso = peso - 50
    multa = excesso * 4
    print(f'Houveram {excesso}Kg excedente(s)')
    print(f'O valor da multa será R${multa:.2f}')
else:
    print('Não houve peso excedente e nem multa')