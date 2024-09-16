peso = float(input("Peso de peixes: "))
excesso = 0
if(peso > 50):
    excesso = peso - 50
multa = excesso * 4

if(multa > 0):
    print(f"João trouxe {excesso} Kg acima do permitido")
    print(f"A multa paga deverá ser de R${multa:.2f}")
else:
    print("João não precisa pagar multa")