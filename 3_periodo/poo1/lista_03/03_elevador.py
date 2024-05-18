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
        

    def entra(self):
        if(self._quantPessoas < self._capacidade):
            self._quantPessoas += 1
            return True, "Pessoa entrou"
        return False, "Capacidade máxima atingida"

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
