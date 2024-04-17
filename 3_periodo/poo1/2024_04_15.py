## Conjuntos
# a = set("Mateus")
# b = set("Ghabriel")

# print(a)
# print(b)

# print(a - b)
# print(a | b)
# print(a & b)
# print(a ^ b)

## Dicionários
personagem = {}
personagem["nome"] = "Alef cauan"
personagem["hp"] = 150
personagem["força"] = -1
personagem["mentalidade"] = -50000000
personagem["agilidade"] = -500
personagem["skin"] = "Lula"
personagem["classe"] = "Corrupto"
personagem["habilidades"] = ["Furto", "Faz o L", "Imposto"]
personagem["título"] = "O imprendível"

print("Ficha de personagem:")
for chave, valor in personagem.items():
    print(f"{chave}: {valor}")