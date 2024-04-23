def media(lista):
    soma = 0
    for i in lista:
        soma += i
    return soma/len(lista)

def mediaAluno(dicionario, nome):
    for chave, elemento in dicionario.items():
        if(chave == nome):
            return media(elemento)
    return False

dicio = {}
while True:
    nome = (input("Nome [0 para sair]: ")).lower()
    if(nome == "0"):
        break
    dicio[nome] = [float(input("1ª nota: ")), float(input("2ª nota: "))]
    print()

nome = (input("\nDigite o nome do aluno que quer buscar a nota: ")).lower()
if(mediaAluno(dicio, nome)):
    print(f"Média de {nome}: {mediaAluno(dicio, nome)}")
else:
    print(f"Aluno {nome} não encontrado")

print("\n\nMédia de todos os alunos: ")
for chave, valor in dicio.items():
    print(f"\nNome do aluno: {chave}")
    print(f"Média: {media(valor)}")