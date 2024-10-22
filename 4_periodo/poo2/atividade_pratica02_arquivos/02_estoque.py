import csv


def arquivo_existe(nome_arquivo):
    try:
        with open(nome_arquivo, "r") as _:
            return True
    except:
        return False


def salvar_arquivo(nome_arquivo, lista_dados, cabecalho = ["Nome", "Quantidade", "Preço Unitário"], criar_novo = False):
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


def exibir_estoque(nome_arquivo, exibir_linha = False):
    lista_dados = ler_arquivo(nome_arquivo)

    if(lista_dados == []):
        print("Não há produtos cadastrados")
        return False

    i = 1

    if(exibir_linha):
        print("    ", end="")

    print(f"{lista_dados[0][0]} | {lista_dados[0][1]} | {lista_dados[0][2]}")
    for linha in lista_dados[1:]:
        if(i > 0 and exibir_linha):
            print(f"[{i}º] ", end="")

        print(f"{linha[0]} | {linha[1]} | R${float(linha[2]):.2f}")
        i += 1
    return True


def atualizar_estoque(nome_arquivo):
    if(not exibir_estoque(nome_arquivo, True)):
        return

    lista_dados = ler_arquivo(nome_arquivo)

    tam = len(lista_dados[1:])
    op = leia_int("\nProduto a ser atualizado: ")
    if(op >= 1 and op <= tam):
        quant = leia_int("\nNova quantidade: ")
        lista_dados[op][1] = quant
        salvar_arquivo(nome_arquivo, lista_dados, criar_novo = True)
        print("\nProduto atualizado com sucesso")
    else:
        print("\nProduto inválido")


def leia_int(texto):
    while True:
        try:
            valor = int(input(texto))
            if(valor < 0):
                raise
            return valor
        except:
            print("\nDigite um número válido\n")


def leia_float(texto):
    while True:
        try:
            valor = float(input(texto))
            if(valor < 0):
                raise
            return valor
        except:
            print("\nDigite um valor válido\n")


# nome_arquivo = "4_periodo/poo2/atividade_pratica02_arquivos/estoque.csv"
nome_arquivo = "estoque.csv"

while True:
    print("[Menu de Estoque]")
    print("[1] - Adicionar Produto")
    print("[2] - Visualizar Estoque")
    print("[3] - Atualizar Estoque")
    print("[0] - Sair do programa")
    op = input("Opção: ")
    print()
    if(op == "1"):
        nome = input("Nome do Produto: ")
        quant = leia_int("Quantidade em Estoque: ")
        preco = leia_float("Preço unitário: R$")
        salvar_arquivo(nome_arquivo, [[nome, quant, preco]])
    elif(op == "2"):
        exibir_estoque(nome_arquivo)
    elif op == "3":
        atualizar_estoque(nome_arquivo)
    elif(op == "0"):
        print("Saindo do programa...")
        break
    else:
        print("Opção inválida")
    print()