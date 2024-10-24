import csv
from datetime import datetime


def arquivo_existe(nome_arquivo):
    try:
        with open(nome_arquivo, "r") as _:
            return True
    except:
        return False


def salvar_arquivo(nome_arquivo, lista_dados, cabecalho = ["Descrição", "Data de Vencimento", "Status"], criar_novo = False):
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


def exibir_tarefas(nome_arquivo, exibir_linha = False):
    lista_dados = ler_arquivo(nome_arquivo)

    if(lista_dados == []):
        print("Não há tarefas cadastrados")
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


def concluir_tarefa(nome_arquivo):
    if(not exibir_tarefas(nome_arquivo, True)):
        return

    lista_dados = ler_arquivo(nome_arquivo)

    tam = len(lista_dados[1:])
    op = leia_int("\nTarefa a ser concluída: ")
    if(op >= 1 and op <= tam):
        if(lista_dados[op][2] == "Concluída"):
            print("\nTarefa já foi marcada como concluída anteriormente")
        else:
            lista_dados[op][2] = "Concluída"
            salvar_arquivo(nome_arquivo, lista_dados, criar_novo = True)
            print("\nTarefa concluída com sucesso")
    else:
        print("\nTarefa inválida")


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


# nome_arquivo = "4_periodo/poo2/atividade_pratica02_arquivos/tarefas.csv"
nome_arquivo = "tarefas.csv"

while True:
    print("[Menu de Tarefas]")
    print("[1] - Adicionar Tarefa")
    print("[2] - Visualizar Tarefas")
    print("[3] - Marcar Tarefa como concluída")
    print("[0] - Sair do programa")
    op = input("Opção: ")
    print()
    if(op == "1"):
        descricao = input("Descrição da tarefa: ")
        data = leia_data("Data de vencimento: ")
        salvar_arquivo(nome_arquivo, [[descricao, data, "Pendente"]])
    elif(op == "2"):
        exibir_tarefas(nome_arquivo)
    elif op == "3":
        concluir_tarefa(nome_arquivo)
    elif(op == "0"):
        print("Saindo do programa...")
        break
    else:
        print("Opção inválida")
    print()