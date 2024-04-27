dicio = {}
while True:
    cpf = input("Digite o seu cpf [enter para sair]: ")
    if(cpf == ''):
        break

    dicio[cpf] = [input("Nome: "), int(input("Idade: "))]

maior18 = [x for x in dicio.values() if x[1] >= 18]

print(maior18)