from item import *
import sys

from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout, QHBoxLayout, QTableWidget, QTableWidgetItem, QHeaderView, QAbstractItemView, QDialog, QFormLayout, QLineEdit, QLabel, QMessageBox
from PyQt5.QtGui import QFont

class TelaItens(QWidget):

    def __init__(self, carrinho: CarrinhoCompras):
        super().__init__()
        self._carrinho = carrinho
        self._labels = []
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

        self.atualizar_tabela(self._carrinho.itens, updateText=False)

        header = self._tabela.horizontalHeader()
        fonte_header = QFont("Arial", 25, QFont.Bold)
        header.setFont(fonte_header)
        
        header.setSectionResizeMode(QHeaderView.Stretch)

        self._tabela.setEditTriggers(QAbstractItemView.NoEditTriggers)
        layout.addWidget(self._tabela)

        label_desconto = QLabel("Desconto de R$10.00 em compras acima de R$50.00")
        label_desconto.setFont(QFont("Arial", 16))
        layout.addWidget(label_desconto)

        textos = {"Total da compra": f"{self._carrinho.calcular_total():.2f}",
                  "Total após desconto": f"{self._carrinho.aplicar_desconto(10, 50)}",}

        for indice, (key, value) in enumerate(textos.items()):
            self._labels.append(QLabel(f"{key}: R$ {value}", self))
            self._labels[indice].setStyleSheet("font-size: 24px;")
            layout.addWidget(self._labels[indice])

        linha_botoes = QHBoxLayout()

        botoes = {"Adicionar Item": self.teste,
                  "Remover Item": self.teste,
                  "Aplicar desconto": self.teste}
        
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

    def teste(self):
        print("Clicado")

    def atualizar_tabela(self, itens, updateText = True):
        self._tabela.setRowCount(0)
        for item in itens:
            self.adicionar_item(item, new = False)

        if(updateText):
            self.atualizar_texto()

    def abrir_tela_adicionar_item(self):
        dialogo = TelaCadastroItens(self)
        dialogo.exec_()

    def adicionar_item(self, item: Item, new = True):
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
    
    def atualizar_texto(self):
        textos = {"Total da compra": f"{self._carrinho.calcular_total():.2f}",
                  "Total após desconto": f"{self._carrinho.aplicar_desconto(10, 50)}",}

        for indice, (key, value) in enumerate(textos.items()):
            self._labels[indice].setText(f"{key}: R$ {value}")


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

        atributos = ["Título: ", "Gênero: ", "Avaliação: "]
        
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
                valor = float(self.inputs[2].text())
                if(valor < 0 or valor > 10):
                    erro = "Digite uma avaliação entre 0 e 10."
            except:
                erro = "Digite um valor numérico para Avaliação."

        if(erro != ""):
            mensagem = (f"<font size='10'>{erro}</font><br>")
            QMessageBox.warning(self, "Erro", mensagem, QMessageBox.Ok)
            return
        
        self.salvar_item()

    def salvar_item(self):
        atributos = []

        for input in self.inputs:
            atributos.append(input.text().capitalize())

        item = Item(atributos[0], atributos[1], float(atributos[2]))
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