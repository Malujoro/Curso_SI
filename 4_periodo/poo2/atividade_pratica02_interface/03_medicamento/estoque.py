from datetime import datetime

class EstoqueMedicamentos:

    __slots__ = ["_nome", "_quantidade", "_data_validade"]

    def __init__(self, nome: str, quantidade: int, data_validade: datetime) -> None:
        self._nome = nome
        self._quantidade = quantidade
        self._data_validade = data_validade

    @property
    def nome(self) -> str:
        return self._nome
    
    @nome.setter
    def nome(self, nome: str):
        self._nome = nome

    @property
    def quantidade(self) -> int:
        return self._quantidade
    
    @quantidade.setter
    def quantidade(self, quantidade: int):
        if(quantidade >= 0):
            self._quantidade = quantidade

    @property
    def data_validade(self) -> datetime:
        return self._data_validade
    
    @data_validade.setter
    def data_validade(self, data_validade: datetime):
        self._data_validade = data_validade

    def add(self, quant: int) -> tuple[bool, str]:
        if(quant < 0):
            return False, "Quantidade inválida"
        
        self._quantidade += quant
        return True, "Quantidade adicionada com sucesso"
    
    def sub(self, quant: int) -> tuple[bool, str]:
        if(quant < 0 or quant > self._quantidade):
            return False, "Quantidade inválida"
        
        self._quantidade -= quant
        return True, "Quantidade subtraída com sucesso"
    
if(__name__ == "__main__"):
    medicamentos = []
    medicamentos.append(EstoqueMedicamentos("Medic 1", 10, datetime(2024, 11, 1).date()))
    medicamentos.append(EstoqueMedicamentos("Medic 2", 0, datetime(2025, 2, 12).date()))
    medicamentos.append(EstoqueMedicamentos("Medic 3", 5, datetime(2025, 3, 12).date()))
    medicamentos.append(EstoqueMedicamentos("Medic 4", 0, datetime(2024, 10, 30).date()))