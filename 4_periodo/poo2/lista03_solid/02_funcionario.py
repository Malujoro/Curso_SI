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
        return self._salarioBase + (self._salarioBase * self._bonus / 100)
    
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
    
    
func = Funcionario(1000)
print(f"Salário do Funcionario: R${func.calcularSalario():.2f}")
ger = Gerente(1000, 10)
print(f"Salário do Gerente: R${ger.calcularSalario():.2f}")
dev = Desenvolvedor(1000, 200)
print(f"Salário do Desenvolvedor: R${dev.calcularSalario():.2f}")