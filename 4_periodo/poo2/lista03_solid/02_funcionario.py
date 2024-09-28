class Funcionario:
    """
    Classe que representa um funcionário

    Atributos
    ---------
    salarioBase: float

    Métodos
    ---------
    calcularSalario():
        Calcula o salário do funcionário
    """

    __slots__ = ["_salarioBase"]

    def __init__(self, salarioBase: float) -> None:
        self._salarioBase = salarioBase

    @property
    def salarioBase(self) -> float:
        return self._salarioBase
    
    @salarioBase.setter
    def salarioBase(self, salarioBase: float) -> None:
        if(salarioBase >= 0):
            self._salarioBase = salarioBase

    def calcularSalario(self) -> float:
        """
        Calcula o salário do funcionário

        Retorno
        -------
        O salário do funcionário
        """
        return self._salarioBase


class Gerente(Funcionario):
    """
    Classe que representa um gerente (herda de Funcionario)

    Atributos
    ---------
    salarioBase: float

    bonus: float

    Métodos
    ---------
    calcularSalario():
        Calcula o salário do gerente
    """

    __slots__ = ["_bonus"]

    def __init__(self, salarioBase: float, bonus: float) -> None:
        super().__init__(salarioBase)
        self._bonus = bonus

    @property
    def bonus(self) -> float:
        return self._bonus
    
    @bonus.setter
    def bonus(self, bonus: float) -> None:
        if(bonus >= 0):
            self._bonus = bonus
    
    def calcularSalario(self) -> float:
        """
        Calcula o salário do gerente

        Retorno
        -------
        O salário do gerente com o aumento do bônus (em porcentagem)
        """
        return self._salarioBase + (self._salarioBase * self._bonus / 100)
    
class Desenvolvedor(Funcionario):
    """
    Classe que representa um desenvolvedor (herda de Funcionario)

    Atributos
    ---------
    salarioBase: float

    bonus: float

    Métodos
    ---------
    calcularSalario():
        Calcula o salário do desenvolvedor
    """

    __slots__ = ["_bonus"]

    def __init__(self, salarioBase: float, bonus: float) -> None:
        super().__init__(salarioBase)
        self._bonus = bonus
    
    @property
    def bonus(self) -> float:
        return self._bonus
    
    @bonus.setter
    def bonus(self, bonus: float) -> None:
        if(bonus >= 0):
            self._bonus = bonus

    def calcularSalario(self) -> float:
        """
        Calcula o salário do desenvolvedor

        Retorno
        -------
        O salário do desenvolvedor com o aumento do bônus (em reais)
        """
        return self._salarioBase + self._bonus
    
    
func = Funcionario(1000)
print(f"Salário do Funcionario: R${func.calcularSalario():.2f}")
ger = Gerente(1000, 10)
print(f"Salário do Gerente: R${ger.calcularSalario():.2f}")
dev = Desenvolvedor(1000, 200)
print(f"Salário do Desenvolvedor: R${dev.calcularSalario():.2f}")