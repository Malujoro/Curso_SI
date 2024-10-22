import csv
from datetime import datetime


def arquivo_existe(nome_arquivo):
    try:
        with open(nome_arquivo, "r") as _:
            return True
    except:
        return False


def salvar_arquivo(nome_arquivo, lista_dados, cabecalho = ["Descrição", "Valor", "Data"]):
    modo = "a"

    if(not arquivo_existe(nome_arquivo)):
        modo = "w"

    with open(nome_arquivo, modo, newline = "") as arquivo:
        escritor = csv.writer(arquivo)
        if(modo == "w"):
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


def exibir_despesa(nome_arquivo):
    lista_dados = ler_arquivo(nome_arquivo)

    if(lista_dados == []):
        print("Não há despesas cadastradas")
        return False

    print(f"{lista_dados[0][0]} | {lista_dados[0][1]} | {lista_dados[0][2]}")
    for linha in lista_dados[1:]:
        print(f"{linha[0]} | R${float(linha[1]):.2f} | {linha[2]}")

    return True


def calcular_despesa(nome_arquivo):
    lista_dados = ler_arquivo(nome_arquivo)

    if(lista_dados == []):
        print("Não há despesas cadastradas")
        return

    total = 0
    for lista in lista_dados[1:]:
        total += float(lista[1])

    print(f"Total das despesas registradas: R${total:.2f}")


def leia_float(texto):
    while True:
        try:
            valor = float(input(texto))
            if(valor < 0):
                raise
            return valor
        except:
            print("\nDigite um valor válido\n")


def leia_data(texto):
    while True:
        try:
            data_str = input(texto)
            data = datetime.strptime(data_str, "%d/%m/%Y")
            return data.strftime('%d/%m/%Y')
        except:
            print("\nData inválida! Formato correto: dd/mm/yyyy\n")


# nome_arquivo = "4_periodo/poo2/atividade_pratica02_arquivos/despesas.csv"
nome_arquivo = "despesas.csv"

while True:
    print("[Menu de Estoque]")
    print("[1] - Registrar Despesa")
    print("[2] - Visualizar Despesas")
    print("[3] - Exibir Total de Despesas")
    print("[0] - Sair do programa")
    op = input("Opção: ")
    print()
    if(op == "1"):
        descricao = input("Descrição da Despesa: ")
        valor = leia_float("Valor: R$")
        data = leia_data("Data: ")
        salvar_arquivo(nome_arquivo, [[descricao, valor, data]])
    elif(op == "2"):
        exibir_despesa(nome_arquivo)
    elif op == "3":
        calcular_despesa(nome_arquivo)
    elif(op == "0"):
        print("Saindo do programa...")
        break
    else:
        print("Opção inválida")
    print()