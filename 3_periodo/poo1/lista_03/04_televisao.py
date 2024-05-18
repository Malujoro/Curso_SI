class Televisao():

    __slots__ = ["_volumeAtual", "_canalAtual", "_quantCanais"]

    def __init__(self, volumeAtual, canalAtual, quantCanais):
        self._volumeAtual = volumeAtual
        self._canalAtual = canalAtual
        self._quantCanais = quantCanais

    @property
    def volumeAtual(self):
        return self._volumeAtual
    
    @property
    def canalAtual(self):
        return self._canalAtual
    
    @property
    def quantCanais(self):
        return self._quantCanais
    
    @volumeAtual.setter
    def volumeAtual(self, volumeAtual):
        if(volumeAtual >= 0 and volumeAtual <= 100):
            self._volumeAtual = volumeAtual
            return True, "Volume atual alterado com sucesso"
        return False, "Volume inválido"
    
    @canalAtual.setter
    def canalAtual(self, canalAtual):
        if(canalAtual > 0 and canalAtual <= self._quantCanais):
            self._canalAtual = canalAtual
            return True, "Canal atual alterado com sucesso"
        return False, "Canal inválido"

    @quantCanais.setter
    def quantCanais(self, quantCanais):
        if(quantCanais > 0):
            self._quantCanais = quantCanais
            return True, "Quantidade de canais alterada com sucesso"
        return False, "Quantidade de canais deve ser positiva"

    

class ControleRemoto():

    __slots__ = ["_televisao"]

    def __init__(self, televisao):
        self._televisao = televisao
    
    def aumentarVolume(self):
        if(self._televisao.volumeAtual < 100):
            self._televisao.volumeAtual += 1
            return True, "Volume aumentado"
        return False, "Volume já está no máximo"
    
    def diminuirVolume(self):
        if(self._televisao.volumeAtual > 0):
            self._televisao.volumeAtual -= 1
            return True, "Volume diminuído"
        return False, "Volume já está no mínimo"

    def aumentarCanal(self):
        if(self._televisao.canalAtual == self._televisao.quantCanais):
            self._televisao.canalAtual = 1
            msg = "Canal voltou para 1"
        else:
            self._televisao.canalAtual += 1
            msg = "Canal aumentado"
        return True, msg

    def diminuirCanal(self):
        if(self._televisao.canalAtual == 1):
            self._televisao.canalAtual = self._televisao.quantCanais
            msg = f"Canal voltou para {self._televisao.quantCanais}"
        else:
            self._televisao.canalAtual -= 1
            msg = "Canal diminuído"
        return True, msg

    def trocarCanal(self, canal):
        if(canal >= 1 and canal <= self._televisao.quantCanais):
            self._televisao.canalAtual = canal
            return True, "Canal alterado"
        return False, "Canal inválido"

    def volumeAtual(self):
        return self._televisao.volumeAtual

    def canalAtual(self):
        return self._televisao.canalAtual

    def menu(self):
        while True:
            print(f"Canal atual: {self._televisao.canalAtual}/{self._televisao.quantCanais}")
            print(f"Volume atual: {self._televisao.volumeAtual}/100")

            print("\nMenu do Controle Remoto")
            print("[1] - Aumentar volume")
            print("[2] - Diminuir volume")
            print("[3] - Aumentar canal")
            print("[4] - Diminuir canal")
            print("[5] - Trocar canal")
            print("[Enter] - Desligar TV")
            op = input("Opção: ")

            if(op == "1"):
                _, msg = self.aumentarVolume()
            elif(op == "2"):
                _, msg = self.diminuirVolume()
            elif(op == "3"):
                _, msg = self.aumentarCanal()
            elif(op == "4"):
                _, msg = self.diminuirCanal()
            elif(op == "5"):
                _, msg = self.trocarCanal(int(input("Canal: ")))
            elif(op == ""):
                print("\nDesligando TV..")
                break
            else:
                msg = "Erro! Opção inválida"
            
            print(f"\n[{msg}]\n")


controle = ControleRemoto(Televisao(10, 2, 5))
controle.menu()