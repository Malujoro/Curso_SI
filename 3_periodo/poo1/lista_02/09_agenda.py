def cadastraPessoa():
    pessoa = {}
    pessoa["nome"] = input("Nome: ")
    pessoa["endereço"] = input("Endereço: ")
    pessoa["CEP"] = input("CEP: ")
    pessoa["bairro"] = input("Bairro: ")
    pessoa["telefone"] = input("Telefone: ")
    return pessoa

lista = []
for i in range(10):
    print(f"{i+1}ª pessoa: ")
    lista.append(cadastraPessoa())
    print()

print(f"\n[Agenda de contatos]")
for i in range(9, -1, -1):
    print(f"\n{i+1}ª pessoa: ")
    print(f"Nome: {lista[i]['nome']}")
    print(f"Endereço: {lista[i]['endereço']}")
    print(f"CEP: {lista[i]['CEP']}")
    print(f"Bairro: {lista[i]['bairro']}")
    print(f"Telefone: {lista[i]['telefone']}")