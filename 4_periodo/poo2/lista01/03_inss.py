ganho = float(input("Quanto você ganha por hora? R$"))
horas = float(input("Quantidade de horas trabalhadas por mês: "))
salario_bruto = ganho * horas

imposto_renda = salario_bruto * 0.11
inss = salario_bruto * 0.08
sindicato = salario_bruto * 0.05
salario_liquido = salario_bruto - imposto_renda - inss - sindicato

print(f"Salário bruto: R${salario_bruto:.2f}")
print(f"Valor pago de Imposto de Renda R${imposto_renda:.2f}")
print(f"Valor pago ao INSS R${inss:.2f}")
print(f"Valor pago ao sindicato R${sindicato:.2f}")
print(f"Salário liquido: R${salario_liquido:.2f}")