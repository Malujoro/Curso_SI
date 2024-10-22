import csv
from datetime import datetime


def arquivo_existe(nome_arquivo):
    try:
        with open(nome_arquivo, "r") as _:
            return True
    except:
        return False


def salvar_arquivo(nome_arquivo, lista_dados, cabecalho = ["Nome do Usuário", "Título do Livro", "Data de Empréstimo", "Data de Devolução"], criar_novo = False):
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


def exibir_emprestimos(nome_arquivo, exibir_linha = False):
    lista_dados = ler_arquivo(nome_arquivo)

    if(lista_dados == []):
        print("Não há empréstimos cadastrados")
        return False

    i = 0

    if(exibir_linha):
        print("    ", end="")

    for linha in lista_dados:
        if(i > 0 and exibir_linha):
            print(f"[{i}º] ", end="")

        print(f"{linha[0]} | {linha[1]} | {linha[2]} | {linha[3]}")
        i += 1
    return True


def atualizar_devolucao(nome_arquivo):
    if(not exibir_emprestimos(nome_arquivo, True)):
        return

    lista_dados = ler_arquivo(nome_arquivo)

    tam = len(lista_dados[1:])
    op = leia_int("\nEmpréstimo com devolução a ser atualizada: ")
    if(op >= 1 and op <= tam):
        while True:
            data_devolucao = leia_data("\nData de Devolução: ")
            diferenca = diferenca_dias(lista_dados[op][2], data_devolucao)
            if(diferenca > 0):
                break
            print("\nDevolução inválida\n")
            
        lista_dados[op][3] = data_devolucao
        salvar_arquivo(nome_arquivo, lista_dados, criar_novo = True)
        print("\nDevolução atualizada com sucesso")
    else:
        print("\nEmpréstimo inválida")


def leia_int(texto):
    while True:
        try:
            valor = int(input(texto))
            if(valor < 0):
                raise
            return valor
        except:
            print("\nDigite um número válido\n")


def leia_data(texto):
    while True:
        try:
            data_str = input(texto)
            data = datetime.strptime(data_str, "%d/%m/%Y")
            return data.strftime('%d/%m/%Y')
        except:
            print("\nData inválida! Formato correto: dd/mm/yyyy\n")


def diferenca_dias(inicio, fim):
    formato = "%d/%m/%Y"
    try:
        inicio = datetime.strptime(inicio, formato)
        fim = datetime.strptime(fim, formato)

        diferenca = fim - inicio
        return diferenca.days
    except:
        print(f"Datas inválidas")


# nome_arquivo = "4_periodo/poo2/atividade_pratica02_arquivos/emprestimos.csv"
nome_arquivo = "emprestimos.csv"

while True:
    print("[Menu de Empréstimos]")
    print("[1] - Registrar Empréstimo")
    print("[2] - Visualizar Empréstimos")
    print("[3] - Atualizar Data de Devolução")
    print("[0] - Sair do programa")
    op = input("Opção: ")
    print()
    if(op == "1"):
        nome = input("Nome do usuário: ")
        titulo = input("Título do livro: ")

        while True:
            data_emprestimo = leia_data("Data de empréstimo: ")
            data_devolucao = leia_data("Data de devolução: ")
            diferenca = diferenca_dias(data_emprestimo, data_devolucao)
            if(diferenca > 0):
                break
            print("\nIntervalo inválido\n")

        salvar_arquivo(nome_arquivo, [[nome, titulo, data_emprestimo, data_devolucao]])
    elif(op == "2"):
        exibir_emprestimos(nome_arquivo)
    elif op == "3":
        atualizar_devolucao(nome_arquivo)
    elif(op == "0"):
        print("Saindo do programa...")
        break
    else:
        print("Opção inválida")
    print()