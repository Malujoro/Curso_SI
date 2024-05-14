class Conta:

    __slots__ = ['_saldo', '_titular']

    _total_contas = 0

    def __init__(self, titular, saldo):
        self._titular = titular
        self._saldo = saldo
        Conta._total_contas += 1

    @property ## Get
    def saldo(self):
        return self._saldo
    
    @saldo.setter ## Set
    def saldo(self, saldo):
        if(saldo < 0):
            raise 'Saldo não pode ser negativo'
        else:
            self._saldo = saldo

    @staticmethod ## Cria métodos que não precisam do self, logo, é possível chamá-lo pelo nome da classe
    def get_total_contas():
        return Conta._total_contas


c1 = Conta('Flavio', 100)
c2 = Conta('Henrique', 0)
c3 = Conta('Iago', 1000)
# c1.saldo = 1000
# print(c1.saldo)
print(Conta.get_total_contas())