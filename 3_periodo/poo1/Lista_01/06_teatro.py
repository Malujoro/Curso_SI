'''
Custo total 200
5 reais o ingresso, vendem 120
a cada -0.5 diminuido no ingresso, vendas aumentam em 26
'''
preco = 5
quantidade = 120
lucro = (preco * quantidade) - 200
lucroMaximo = lucro

while(preco > 1):
    print(f'preço ingresso = {preco:.2f}, quantidade = {quantidade}, lucro = {lucro:.2f}')
    preco -= 0.5
    quantidade += 26
    lucro = (preco * quantidade) - 200
    if(lucro > lucroMaximo):
        lucroMaximo = lucro
        precoMaximo = preco
        quantidadeMaxima = quantidade

print(f'\nLucro máximo = {lucroMaximo:.2f}')
print(f'Preço do ingresso = {precoMaximo:.2f}')
print(f'Quantidade vendida = {quantidadeMaxima}')