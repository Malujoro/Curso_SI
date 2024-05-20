class Elevador():

    __slots__ = ["_andarAtual", "_quantAndares", "_capacidade", "_quantPessoas"]

    def __init__(self, capacidade, quantAndares):
        self._andarAtual = 0
        self._quantAndares = quantAndares
        self._capacidade = capacidade
        self._quantPessoas = 0

    @property
    def andarAtual(self):
        return self._andarAtual
    
    @property
    def quantAndares(self):
        return self._quantAndares

    @property
    def capacidade(self):
        return self._capacidade

    @property
    def quantPessoas(self):
        return self._quantPessoas
    
    @andarAtual.setter
    def andarAtual(self, andarAtual):
        if(andarAtual >= 0 and andarAtual <= self._quantAndares):
            self._andarAtual = andarAtual
            return True, "Andar atual alterado com sucesso"
        return False, "Andar atual inválido"

    @quantAndares.setter
    def quantAndares(self, quantAndares):
        if(quantAndares > 0):
            self._quantAndares = quantAndares
            return True, "Total de andares alterado com sucesso"
        return False, "Total de andares deve ser positiva"
    
    @capacidade.setter
    def capacidade(self, capacidade):
        if(capacidade > 0):
            self._capacidade = capacidade
            return True, "Capacidade máxima alterada com sucesso"
        return False, "Capacidade máxima deve ser positiva"
        
    @quantPessoas.setter
    def quantPessoas(self, quantPessoas):
        if(quantPessoas >= 0 and quantPessoas <= self._capacidade):
            self._quantPessoas = quantPessoas
            return True, "Quantidade de pessoas alterado com sucesso"
        return False, "Quantidade de pessoas inválida"

    def entra(self):
        if(self._quantPessoas < self._capacidade):
            self._quantPessoas += 1
            return True, "Pessoa entrou"
        return False, "Elevador está cheio"

    def sai(self):
        if(self._quantPessoas > 0):
            self._quantPessoas -= 1
            return True, "Pessoa saiu"
        return False, "Elevador está vazio"

    def sobe(self):
        if(self._andarAtual < self._quantAndares):
            self._andarAtual += 1
            return True, "Elevador subiu"
        return False, "Elevador já está no último andar"

    def desce(self):
        if(self._andarAtual > 0):
            self._andarAtual -= 1
            return True, "Elevador desceu"
        return False, "Elevador já está no térreo"


def menu():
    print("\nMenu do elevador")
    print("[1] - Entrar pessoa")
    print("[2] - Sai pessoa")
    print("[3] - Sobe andar")
    print("[4] - Desce andar")
    print("[Enter] - Encerrar programa")
    return input("Opção: ")

elevador = Elevador(int(input("Capacidade do elevador: ")), int(input("Quantidade de andares (sem contar o térreo): ")))
while True:
    print(f"\nQuantidade de pessoas no elevador: {elevador.quantPessoas}/{elevador.capacidade}")
    print(f"Andar atual: {elevador.andarAtual}/{elevador.quantAndares}")
    
    op = menu()

    if(op == "1"):
        _, msg = elevador.entra()
    elif(op == "2"):
        _, msg = elevador.sai()
    elif(op == "3"):
        _, msg = elevador.sobe()
    elif(op == "4"):
        _, msg = elevador.desce()
    elif(op == ""):
        print("\nEncerrando programa...")
        break
    else:
        msg = "Erro! Opção inválida"
    
    print(f"\n[{msg}]")