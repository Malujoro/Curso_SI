def tamString(s):
    cont = 0
    for i in s:
        cont += 1
    return cont

str = input("Digite uma string: ")
print(f"Tamanho de {str}: {tamString(str)}")