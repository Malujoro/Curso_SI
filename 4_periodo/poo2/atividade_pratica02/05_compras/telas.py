from item import *
import sys

from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout, QHBoxLayout, QTableWidget, QTableWidgetItem, QHeaderView, QAbstractItemView, QDialog, QFormLayout, QLineEdit, QLabel, QMessageBox
from PyQt5.QtGui import QFont
from PyQt5.QtCore import pyqtSignal, QObject

descontos = [10, 50, 0]
limite_compra = 100

class MonitorTotal(QObject):

    preco_alterado = pyqtSignal(float)

    def __init__(self, preco_limite):
        super().__init__()
        self._preco = 0
        self._avisar = True
        self._preco_limite = preco_limite
        self._log_descontos = []

    @property
    def preco(self) -> float:
        return self._preco

    @preco.setter
    def preco(self, preco: float) -> None:
        if(preco >= 0):
            if(preco >= self._preco):
                self._log_descontos = []
            else:
                desconto = self._preco - preco
                self._log_descontos.append(f"Desconto de R${desconto:.2f} aplicado")

            self._preco = preco
            if(self._avisar):
                self.preco_alterado.emit(preco)

    @property
    def preco_limite(self) -> float:
        return self._preco_limite

    @preco_limite.setter
    def preco_limite(self, preco_limite: float) -> None:
        if(preco_limite >= 0):
            self._preco_limite = preco_limite

    @property
    def log_descontos(self) -> list[str]:
        return self._log_descontos

    @log_descontos.setter
    def log_descontos(self, log_descontos: list[str]) -> None:
        self._log_descontos = log_descontos

    @property
    def avisar(self) -> bool:
        return self._avisar

    @avisar.setter
    def avisar(self, avisar: bool) -> None:
        self._avisar = avisar

class TelaItens(QWidget):

    def __init__(self, carrinho: CarrinhoCompras):
        super().__init__()
        self._carrinho = carrinho
        self._labels = []
        self._monitor = MonitorTotal(limite_compra)
        self._monitor.preco_alterado.connect(self.aviso_valor)
        self.iniciar_ui()

    def iniciar_ui(self):
        self.setWindowTitle("Carrinho de compras")
        self.setGeometry(650, 250, 1000, 700)

        layout = QVBoxLayout()
        
        colunas = ["Nome", "Preço", "Quantidade"]

        self._tabela = QTableWidget()
        self._tabela.setRowCount(0)
        self._tabela.setColumnCount(len(colunas))

        self._tabela.setHorizontalHeaderLabels(colunas)

        self.atualizar_tabela(self._carrinho.itens)

        header = self._tabela.horizontalHeader()
        fonte_header = QFont("Arial", 25, QFont.Bold)
        header.setFont(fonte_header)
        
        header.setSectionResizeMode(QHeaderView.Stretch)

        self._tabela.setEditTriggers(QAbstractItemView.NoEditTriggers)
        layout.addWidget(self._tabela)

        linha_valores = QHBoxLayout()

        coluna_preco = QVBoxLayout()
        label_desconto = QLabel(f"Desconto de R${descontos[0]:.2f} em compras acima de R${descontos[1]:.2f}")
        label_desconto.setFont(QFont("Arial", 16))
        coluna_preco.addWidget(label_desconto)

        self._monitor.preco = self._carrinho.aplicar_desconto(descontos[0], descontos[1])
        
        textos = {"Total da compra": f"{self._carrinho.calcular_total():.2f}",
                  "Total após desconto": f"{self._monitor.preco:.2f}",}

        for indice, (key, value) in enumerate(textos.items()):
            self._labels.append(QLabel(f"{key}: R$ {value}", self))
            self._labels[indice].setStyleSheet("font-size: 24px;")
            coluna_preco.addWidget(self._labels[indice])


        linha_valores.addLayout(coluna_preco)

        self._desconto_edit = QLineEdit(self)
        self._desconto_edit.setFont(QFont("Arial", 16))
        self._desconto_edit.setFixedSize(250, 50)
        self._desconto_edit.setPlaceholderText("Cupom de Desconto")

        linha_valores.addWidget(self._desconto_edit)

        layout.addLayout(linha_valores)


        linha_botoes = QHBoxLayout()

        botoes = {"Adicionar Item": self.abrir_tela_adicionar_item,
                  "Descontos aplicados": self.abrir_tela_resumo,
                  "Aplicar desconto": self.validar_campo}
        
        largura_botao = 200
        altura_botao = 100
        fonte_botao = QFont("Arial", 16)

        for nome, funcao in botoes.items():
            botao = QPushButton(nome)
            botao.clicked.connect(funcao)  
            botao.setMinimumSize(largura_botao, altura_botao)
            botao.setFont(fonte_botao)
            linha_botoes.addWidget(botao)
        
        layout.addLayout(linha_botoes)

        self.setLayout(layout)

    def atualizar_tabela(self, itens):
        self._tabela.setRowCount(0)
        for item in itens:
            self.adicionar_item(item, False, False)

    def abrir_tela_adicionar_item(self):
        dialogo = TelaCadastroItens(self)
        dialogo.exec_()

    def adicionar_item(self, item: Item, new = True, updateText = True):
        if(new):
            self._carrinho.add(item)
        num_linhas = self._tabela.rowCount()
        self._tabela.insertRow(num_linhas)

        atributos = [item.nome, f"{item.preco:.2f}", str(item.quantidade)]
        fonte = QFont("Arial", 22)

        for indice, atributo in enumerate(atributos):
            item = QTableWidgetItem(atributo)
            item.setFont(fonte)
            self._tabela.setItem(num_linhas, indice, item)
        
        if(updateText):
            self.atualizar_texto()
    
    def atualizar_texto(self, calcular = True):
        if(calcular):
            self._monitor.avisar = False
            self._monitor.preco = self._carrinho.calcular_total()
            self._monitor.avisar = True
            self._monitor.preco = self._carrinho.aplicar_desconto(descontos[0], descontos[1])

        textos = {"Total da compra": f"{self._carrinho.calcular_total():.2f}",
                  "Total após desconto": f"{self._monitor.preco:.2f}",}

        for indice, (key, value) in enumerate(textos.items()):
            self._labels[indice].setText(f"{key}: R$ {value}")

    def abrir_tela_resumo(self):
        mensagem = ""
        
        for desconto in self._monitor.log_descontos:
            mensagem += (f"<font size='10'>{desconto}</font><br>")
        
        if(mensagem == ""):
            mensagem += "<font size='10'>Nenhum</font><br>"

        QMessageBox.information(self, "Resumo", mensagem, QMessageBox.Ok)

    def validar_campo(self):
        desconto = self._desconto_edit.text()
        erro = ""

        if(desconto == ""):
            erro = "Preencha o campo de desconto."

        if(erro == ""):
            try:
                valor = float(desconto)
                if(valor <= 0 or valor > self._monitor.preco):
                    raise
            except:
                erro = "Digite um valor válido."

        if(erro != ""):
            mensagem = (f"<font size='10'>{erro}</font><br>")
            QMessageBox.warning(self, "Erro", mensagem, QMessageBox.Ok)
            return
        
        self._monitor.preco -= valor
        self.atualizar_texto(False)

    def aviso_valor(self):
        if(self._monitor.preco >= limite_compra):
            mensagem = (f"<font size='10'>A compra excedeu o valor de R${limite_compra:.2f}</font><br>")
            QMessageBox.warning(self, "Erro", mensagem, QMessageBox.Ok)


class TelaCadastroItens(QDialog):
    
    def __init__(self, tela_principal: TelaItens):
        super().__init__()
        self._tela_principal = tela_principal
        self.iniciar_ui()

    def iniciar_ui(self):
        self.setWindowTitle('Cadastrar Item')
        self.setGeometry(500, 150, 500, 200)
        
        layout = QFormLayout()

        fonte_padrao = QFont("Arial", 25)
        fonte_label = fonte_padrao
        fonte_input = fonte_padrao

        atributos = ["Nome: ", "Preço: ", "Quantidade: "]
        
        self.inputs = []

        for indice, nome in enumerate(atributos):
            self.inputs.append(QLineEdit(self))
            self.inputs[indice].setFont(fonte_input)
            self.inputs[indice].setFixedSize(250, 50)

            label = QLabel(nome, self)
            label.setFont(fonte_label)
            layout.addRow(label, self.inputs[indice])

        botao_salvar = QPushButton('Salvar')
        botao_salvar.clicked.connect(self.validar_campos)
        layout.addWidget(botao_salvar)

        self.setLayout(layout)

    def validar_campos(self):
        erro = ""

        for input in self.inputs:
            if(input.text() == ""):
                erro = "Preencha todos os campos."
                break

        if(erro == ""):
            try:
                preco = float(self.inputs[1].text())
                quantidade = int(self.inputs[2].text())
                if(preco < 0 or quantidade < 0):
                    raise

            except:
                erro = "Digite valores válidos"

        if(erro != ""):
            mensagem = (f"<font size='10'>{erro}</font><br>")
            QMessageBox.warning(self, "Erro", mensagem, QMessageBox.Ok)
            return
        
        self.salvar_item()

    def salvar_item(self):
        atributos = []

        for input in self.inputs:
            atributos.append(input.text().capitalize())

        item = Item(atributos[0], float(atributos[1]), int(atributos[2]))
        self._tela_principal.adicionar_item(item)
        self.close()

def iniciar_programa(carrinho: CarrinhoCompras = CarrinhoCompras()):
    app = QApplication(sys.argv)
    tela = TelaItens(carrinho)
    tela.show()
    sys.exit(app.exec_())

if(__name__ == "__main__"):
    carrinho = CarrinhoCompras()
    carrinho.add(Item("Maçã", 7, 1))
    carrinho.add(Item("Banana", 5, 2))
    carrinho.add(Item("Goiaba", 6, 1))
    iniciar_programa(carrinho)