import csv


def arquivo_existe(nome_arquivo):
    try:
        with open(nome_arquivo, "r") as _:
            return True
    except:
        return False


def salvar_arquivo(nome_arquivo, lista_dados, cabecalho = ["Nome", "Matrícula", "Curso"], criar_novo = False):
    modo = "a"

    if(not arquivo_existe(nome_arquivo) or criar_novo):
        modo = "w"

    with open(nome_arquivo, modo, newline = "") as arquivo:
        escritor = csv.writer(arquivo)
        if(modo == "w" and not criar_novo):
            escritor.writerow(cabecalho)
        escritor.writerows(lista_dados)


def ler_arquivo(nome_arquivo):
    lista_dados = []

    if(arquivo_existe(nome_arquivo)):
        with open(nome_arquivo, "r", newline = "") as arquivo:
            leitor = csv.reader(arquivo)

            for linha in leitor:
                lista_dados.append(linha)

    return lista_dados


def exibir_alunos(nome_arquivo, exibir_linha = False):
    lista_dados = ler_arquivo(nome_arquivo)

    if(lista_dados == []):
        print("Não há alunos cadastrados")
        return False

    i = 0

    if(exibir_linha):
        print("    ", end="")

    for linha in lista_dados:
        if(i > 0 and exibir_linha):
            print(f"[{i}º] ", end="")

        print(f"{linha[0]} | {linha[1]} | {linha[2]}")
        i += 1
    return True


def atualizar_curso(nome_arquivo):
    if(not exibir_alunos(nome_arquivo, True)):
        return

    lista_dados = ler_arquivo(nome_arquivo)

    tam = len(lista_dados[1:])
    op = leia_int("\nAluno a ter o curso atualizado: ")
    if(op >= 1 and op <= tam):
        lista_dados[op][2] = input("\nNovo curso: ")
        salvar_arquivo(nome_arquivo, lista_dados, criar_novo = True)
        print("\nAluno atualizado com sucesso")
    else:
        print("\nAluno inválido")


def leia_int(texto):
    while True:
        try:
            valor = int(input(texto))
            if(valor < 0):
                raise
            return valor
        except:
            print("\nDigite um número válido\n")


def matricula_existe(lista_dados, matricula):
    try:
        for dados in lista_dados:
            if(dados[1] == matricula):
                raise
        return False
    except:
        return True

# nome_arquivo = "4_periodo/poo2/atividade_pratica02_arquivos/alunos.csv"
nome_arquivo = "alunos.csv"

while True:
    print("[Menu de Alunos]")
    print("[1] - Adicionar Aluno")
    print("[2] - Visualizar Alunos")
    print("[3] - Atualizar Curso")
    print("[0] - Sair do programa")
    op = input("Opção: ")
    print()
    if(op == "1"):
        lista_dados = ler_arquivo(nome_arquivo)

        matricula = input("Matrícula: ")
        if(matricula_existe(lista_dados, matricula)):
            print("\nMatrícula já existente\n")
            continue

        nome = input("Nome do Aluno: ")
        curso = input("Curso: ")
        salvar_arquivo(nome_arquivo, [[nome, matricula, curso]])
    elif(op == "2"):
        exibir_alunos(nome_arquivo)
    elif op == "3":
        atualizar_curso(nome_arquivo)
    elif(op == "0"):
        print("Saindo do programa...")
        break
    else:
        print("Opção inválida")
    print()