class Equipamento:

    __slots__ = ["_nome", "_fabricante", "_anoFabricacao"]

    def __init__(self, nome, fabricante, anoFabricacao):
        self._nome = nome
        self._fabricante = fabricante
        self._anoFabricacao = anoFabricacao

    @property
    def nome(self):
        return self._nome
    
    @property
    def fabricante(self):
        return self._fabricante
    
    @property
    def anoFabricacao(self):
        return self._anoFabricacao

    @nome.setter
    def nome(self, nome):
        self._nome = nome

    @fabricante.setter
    def fabricante(self, fabricante):
        self._fabricante = fabricante

    @anoFabricacao.setter
    def anoFabricacao(self, anoFabricacao):
        if(anoFabricacao > 0):
            self._anoFabricacao = anoFabricacao
    
    def exibir(self):
        print(f"Nome: {self._nome}")
        print(f"Fabricante: {self._fabricante}")
        print(f"Ano de Fabricação: {self._anoFabricacao}")
        return True, "Equipamento exibido com sucesso"

class Computador(Equipamento):

    __slots__ = ["_nome", "_fabricante", "_anoFabricacao", "_processador", "_memoriaRam"]

    def __init__(self, nome, fabricante, anoFabricacao, processador, memoriaRam):
        super().__init__(nome, fabricante, anoFabricacao)
        self._processador = processador
        self._memoriaRam = memoriaRam

    @property
    def processador(self):
        return self._processador
    
    @property
    def memoriaRam(self):
        return self._memoriaRam
    
    @processador.setter
    def processador(self, processador):
        self._processador = processador

    @memoriaRam.setter
    def memoriaRam(self, memoriaRam):
        self._memoriaRam = memoriaRam
    
    def exibir(self):
        super().exibir()
        print(f"Processador: {self._processador}")
        print(f"Memória Ram: {self._memoriaRam}")
        return True, "Computador exibido com sucesso"

equipamento = Equipamento("Controle", "Inova", 2022)
equipamento.exibir()
print()

computador = Computador("Aspire 5", "Acer", 2024, "Ryzen 7", "Ddr 4")
computador.exibir()