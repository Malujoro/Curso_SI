import os
import csv

def arquivo_existe(nome_arquivo):
    return os.path.exists(nome_arquivo) 

def salvar_arquivo(nome_arquivo, lista_dados, cabecalho = ["Nome", "Telefone", "Email"]):
    modo = "a"
    if not arquivo_existe(nome_arquivo):
        modo = "w"

    with open(nome_arquivo, modo, newline = "") as arquivo:
        escritor = csv.writer(arquivo)
        if(modo == "w"):
            escritor.writerow(cabecalho)
        escritor.writerows(lista_dados)

def ler_arquivo(nome_arquivo):
    if arquivo_existe(nome_arquivo):
        lista_dados = []
        with open(nome_arquivo, "r", newline = "") as arquivo:
            leitor = csv.reader(arquivo)
            for linha in leitor:
                lista_dados.append(linha)
            return lista_dados

def exibir_contatos(dados):
    for linha in dados:
        print(linha)

cabecalho = ["Nome", "Telefone", "Email"]
nome_arquivo = "4_periodo/poo2/contatos.csv"

while True:
    print("[Menu de contatos]")
    print("[1] - Adicionar contato")
    print("[2] - Visualizar contatos")
    print("[0] - Sair do programa")
    op = input("Opção: ")
    print()
    if(op == "1"):
        nome = input("Nome: ")
        telefone = input("Telefone: ")
        email = input("Email: ")
        salvar_arquivo(nome_arquivo, [[nome, telefone, email]])
    elif(op == "2"):
        lista_dados = ler_arquivo(nome_arquivo)
        exibir_contatos(lista_dados)
    elif(op == "0"):
        print("Saindo do programa...")
        break
    else:
        print("Opção inválida")
    print()