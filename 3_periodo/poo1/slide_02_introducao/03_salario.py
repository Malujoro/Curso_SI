salHora = float(input('Salário por hora R$'))
horasMes = int(input('Quantidade de horas trabalhadas por mês: '))

salBruto = salHora * horasMes
ir = salBruto * 0.11
inss = salBruto * 0.08
sindicato = salBruto * 0.05
salLiq = salBruto - ir - inss - sindicato

print(f'Salário bruto: R${salBruto}')
print(f'IR: R${ir}')
print(f'INSS: R${inss}')
print(f'Sindicato: R${sindicato}')
print(f'Salário líquido: R${salLiq}')