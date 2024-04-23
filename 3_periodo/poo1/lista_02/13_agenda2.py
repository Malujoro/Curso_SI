dicio = {}


def leiaNome():
    return input("Nome: ")


def leiaTelefone():
    return input("Telefone: ")
    

def chaveExiste(chave):
    if(chave in dicio):
        return True
    print("\nNome não existente")
    return False


def incluirNovoNome(nome, telefone):
    dicio[nome] = []
    
    if(isinstance(telefone, list)):
        for i in telefone:
            dicio[nome].append(i)
    else:
        dicio[nome].append(telefone)


def incluirTelefone(nome, telefone):
    if(chaveExiste(nome)):
        dicio[nome].append(telefone)
    else:
        while True:
            resp = (input("Deseja incluir esse nome na agenda? [S / N] ")).lower()
            if(resp == 's'):
                incluirNovoNome(nome, telefone)
                break
            elif resp == 'n':
                break
            else:
                print("\nErro! Digite uma resposta válida") 


def excluirTelefone(nome, telefone):
    if(chaveExiste(nome)):
        if (len(dicio[nome]) == 1):
            excluirNome(nome)
        else:
            dicio[nome].remove(telefone)
            print("Telefone removido com sucesso")


def excluirNome(nome):
    if(chaveExiste(nome)):
        dicio.pop(nome, None)
        print("Nome removido com sucesso")


def consultarTelefone(nome):
    if(chaveExiste(nome)):
        cont = 0
        print()
        if(isinstance(dicio[nome], list)):
            for tel in dicio[nome]:
                print(f"{cont+1}º telefone: {tel}")
                cont += 1
        else:
            print(f"{cont+1}º telefone: {dicio[nome]}")
        print()


def menu():
    print("\nMenu")
    print("[1] - Adicionar nome")
    print("[2] - Adicionar telefone")
    print("[3] - Excluir telefone")
    print("[4] - Excluir nome")
    print("[5] - Consultar telefone")
    return int(input("Opção [negativo sai]: "))

while True:
    op = menu()
    print()
    if(op < 0):
        print("Saindo do programa...")
        break
    elif(op == 1):
        lista = []
        nome = leiaNome()

        while True:
            print()
            tel = leiaTelefone()
            if(tel == ''):
                break
            lista.append(tel)

        incluirNovoNome(nome, lista)
    elif(op == 2):
        incluirTelefone(leiaNome(), leiaTelefone())
    elif(op == 3):
        excluirTelefone(leiaNome(), leiaTelefone())
    elif(op == 4):
        excluirNome(leiaNome())
    elif(op == 5):
        consultarTelefone(leiaNome())
    else:
        print("Erro! Digite uma opção válida")