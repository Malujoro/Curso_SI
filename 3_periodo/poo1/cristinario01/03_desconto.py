precoInicial = float(input("Preço original da roupa: R$"))
porcentagem = float(input("Porcentagem %: "))
desconto = porcentagem/100 * precoInicial
precoFinal = precoInicial - desconto
print(f"Desconto de R${desconto:0.2f}")
print(f"Preço final: R${precoFinal:0.2f}")