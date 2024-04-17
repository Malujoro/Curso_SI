## Dicionários
# pessoa = {}

# while True:
#     cpf = int(input("Digite seu CPF: "))
#     if(cpf <= 0):
#         break
#     pessoa[cpf] = [input("Digite seu nome: "), int(input("Digite sua idade: "))]
#     print()

# maior18 = [x for x in pessoa.values() if x[1] >= 18]
# print(pessoa)
# print(maior18)

## Lista de Listas
lista1 = [x for x in range(1, 5)]
lista2 = [x for x in range(5, 8)]
lista3 = [x for x in range(8, 10)]
lista4 = [lista1, lista2, lista3]

for i in lista4:
    for j in i:
        print(j, end=" ")
    print()