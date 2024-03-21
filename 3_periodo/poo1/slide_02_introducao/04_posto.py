litros = int(input('Quantidade de litros: '))
tipo = input('Tipo de combustível (A para álcool e G para gasolina): ')

if(tipo in 'Aa'):
    preco = 3.45
    if(litros <= 20):
        desconto = 3
    else:
        desconto = 5
elif(tipo in 'Gg'):
    preco = 4.53
    if(litros <= 20):
        desconto = 4
    else:
        desconto = 6

if(tipo in 'AaGg'):
    valPago = (preco - (preco * desconto/100)) * litros
    print(f'Valor a ser pago R${valPago:.2f}')
else:
    print('Tipo inválido')