while True:
    litros = float(input("Quantidade de litros: "))

    print("\nTipo de combustível")
    print("[A] - Álcool")
    print("[G] - Gasolina")
    print("[0] - Sair")
    opcao = input("Opção: ").upper()

    if(opcao == "A"):
        preco = 3.45
        if(litros <= 20):
            desconto = 3
        else:
            desconto = 5
    elif(opcao == "G"):
        preco = 4.53
        if(litros <= 20):
            desconto = 4
        else:
            desconto = 6
    elif(opcao == "0"):
        break
    else:
        print("Opção inválida")
        continue

    result = (preco - (preco * desconto / 100)) * litros
    print(f"\nPreço por litro: R${preco}")
    print(f"Valor a ser pago: R${result:.2f}\n")