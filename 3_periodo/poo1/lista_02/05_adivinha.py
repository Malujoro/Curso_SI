from random import randint

def continuar():
    while True:
        letra = (input(("\nDeseja continuar? [S / N] "))).lower()
        print()
        if(letra == 's'):
            return True
        if(letra == 'n'):
            return False
        print("Erro! Digite S ou N")

while True:
    pc = randint(0, 100)
    tentativa = 1

    print("[Adivinhe o número gerado pelo computador]")
    print("Você tem no máximo 10 tentativas!!")
    while tentativa <= 10:
        jogador = int(input(f"{tentativa}ª tentativa: "))
        
        if(jogador == pc):
            print(f"Você ganhou! o número era {pc}")
            break
        
        tentativa += 1

    if(tentativa > 10):
        print(f"\nVocê perdeu! o número era {pc}")
    
    if(not continuar()):
        break