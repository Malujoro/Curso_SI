class Funcionario:

    __slots__ = ["_salarioBase"]

    def __init__(self, salarioBase: float):
        self._salarioBase = salarioBase

    @property
    def salarioBase(self):
        return self._salarioBase
    
    @salarioBase.setter
    def salarioBase(self, salarioBase: float):
        if(salarioBase >= 0):
            self._salarioBase = salarioBase

    def calcularSalario(self):
        return self._salarioBase


class Gerente(Funcionario):

    __slots__ = ["_bonus"]

    def __init__(self, salarioBase: float, bonus: float):
        super().__init__(salarioBase)
        self._bonus = bonus

    @property
    def bonus(self):
        return self._bonus
    
    @bonus.setter
    def bonus(self, bonus: float):
        if(bonus >= 0):
            self._bonus = bonus
    
    def calcularSalario(self):
        return self._salarioBase + self._bonus
    
class Desenvolvedor(Funcionario):

    __slots__ = ["_bonus"]

    def __init__(self, salarioBase: float, bonus: float):
        super().__init__(salarioBase)
        self._bonus = bonus
    
    @property
    def bonus(self):
        return self._bonus
    
    @bonus.setter
    def bonus(self, bonus: float):
        if(bonus >= 0):
            self._bonus = bonus

    def calcularSalario(self):
        return self._salarioBase + self._bonus
    
func = Funcionario()