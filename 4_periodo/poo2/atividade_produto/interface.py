from produto import *

from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout, QMainWindow, QTableWidget, QTableWidgetItem, QHeaderView, QAbstractItemView, QDialog, QFormLayout, QLineEdit, QLabel, QMessageBox
from PyQt5.QtGui import QFont


class Menu(QMainWindow):

    def __init__(self, cadastro: CadastroProdutos):
        super().__init__()
        self._cadastro = cadastro
        self._produtos = cadastro.listar_produtos()
        self.iniciar_ui()

    def iniciar_ui(self):
        self.setWindowTitle("Gerenciador de produtos")
        self.setGeometry(650, 250, 500, 300)

        central_widget = QWidget(self)

        botoes = {"Adicionar Produto": self.abrir_tela_adicionar_produto, "Buscar Produto": self.abrir_tela_buscar_produto, "Remover Produto": self.abrir_tela_buscar_produto, "Mostrar todos": self.mostrar_todos}
        largura_botao = 200
        altura_botao = 100
        fonte_botao = QFont("Arial", 25)

        layout = QVBoxLayout()

        for nome, funcao in botoes.items():
            botao = QPushButton(nome)
            botao.clicked.connect(funcao)   
            botao.setMinimumSize(largura_botao, altura_botao)
            botao.setFont(fonte_botao)
            layout.addWidget(botao)

        central_widget.setLayout(layout)

        self.setCentralWidget(central_widget)

    def abrir_tela_adicionar_produto(self):
        dialogo = TelaCadastroProdutos(self)
        dialogo.exec_()

    def adicionar_produto(self, produto: Produto):
        self._cadastro.adicionar_produto(produto)

    def abrir_tela_buscar_produto(self):
        dialogo = TelaBusca(self)
        dialogo.exec_()

    def buscar_produto(self, nome: str):
        ret, msg, produto = self._cadastro.buscar_produto(nome)
    
        if(ret):
            mensagem = (
            f"<font size='10'>Nome: {produto.nome}</font><br>"
            f"<font size='10'>Código: {produto.codigo}</font><br>"
            f"<font size='10'>Preço: R${produto.preco}</font><br>"
            f"<font size='10'>Quantidade em Estoque: {produto.quant_estoque}</font><br>"
            f"<font size='10'>Descrição: {produto.descricao}</font>"
        )
            
            QMessageBox.information(self, msg, mensagem, QMessageBox.Ok)
        else:
            mensagem = (f"<font size='10'>Nenhum produto encontrado com esse nome.</font><br>")
            QMessageBox.warning(self, msg, mensagem, QMessageBox.Ok)

    def abrir_tela_remover_cliente(self):
        dialogo = TelaBusca(self, True)
        dialogo.exec_()

    def remover_produto(self, cpf: str):
        ret, msg, produto = self._cadastro.buscar_produto(cpf)
    
        if(ret):
            dialogo = TelaCadastroProdutos(self, produto)
            dialogo.exec_()
        else:
            mensagem = (f"<font size='10'>Nenhum produto encontrado com esse Nome.</font><br>")
            QMessageBox.warning(self, msg, mensagem, QMessageBox.Ok)

    def mostrar_todos(self):
        self.janela_lista = QWidget()
        self.janela_lista.setWindowTitle("Lista de Produtos")
        self.janela_lista.setGeometry(500, 150, 1000, 800)

        layout = QVBoxLayout()

        colunas = ["Nome", "Código", "Preço", "Estoque", "Descrição"]

        tabela = QTableWidget()
        tabela.setColumnCount(len(colunas))
        tabela.setHorizontalHeaderLabels(colunas)

        tabela.setRowCount(len(self._cadastro.listar_produtos()))

        fonte_header = QFont()
        fonte_header.setBold(True)
        fonte_header.setPointSize(25)

        tabela.horizontalHeader().setFont(fonte_header)

        fonte_linha = QFont()
        fonte_linha.setPointSize(18)
        tabela.setFont(fonte_linha)

        for linha, produto in enumerate(self._produtos):
            dados = [produto.nome, produto.codigo, produto.preco, produto.quant_estoque, produto.descricao]
            for coluna, informacao in enumerate(dados):
                tabela.setItem(linha, coluna, QTableWidgetItem(str(informacao)))

        tabela.resizeRowsToContents()
        tabela.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)

        tabela.setEditTriggers(QAbstractItemView.NoEditTriggers)

        layout.addWidget(tabela)

        self.janela_lista.setLayout(layout)

        self.janela_lista.show()


class TelaCadastroProdutos(QDialog):
    def __init__(self, tela_principal):
        super().__init__()
        self.tela_principal = tela_principal
        self.init_ui()

    def init_ui(self):
        self.setWindowTitle('Cadastrar Produto')
        self.setGeometry(500, 150, 500, 300)
        
        layout = QFormLayout()

        fonte_padrao = QFont("Arial", 25)
        fonte_label = fonte_padrao
        fonte_input = fonte_padrao

        atributos = ["Nome: ", "Código: ", "Preço: ", "Estoque: ", "Descrição: "]
        
        self.inputs = []

        for indice, nome in enumerate(atributos):
            self.inputs.append(QLineEdit(self))
            self.inputs[indice].setFont(fonte_input)
            self.inputs[indice].setFixedSize(250, 30)
            label = QLabel(nome, self)
            label.setFont(fonte_label)
            layout.addRow(label, self.inputs[indice])


        botao_salvar = QPushButton('Salvar')
        botao_salvar.clicked.connect(self.salvar_produto)
        layout.addWidget(botao_salvar)

        self.setLayout(layout)


    def salvar_produto(self):

        produto = Produto(self.inputs[0].text(), self.inputs[1].text(), self.inputs[2].text(), self.inputs[3].text(), self.inputs[4].text())
        self.tela_principal.adicionar_produto(produto)

        self.close()

class TelaBusca(QDialog):
    def __init__(self, tela_principal, remove: bool = False):
        super().__init__()
        self.tela_principal = tela_principal
        self._remove = remove
        self.init_ui()

    def init_ui(self):
        self.setWindowTitle('Buscar Produto')
        self.setGeometry(500, 150, 500, 300)
        
        layout = QFormLayout()

        fonte_padrao = QFont("Arial", 25)
        fonte_label = fonte_padrao
        fonte_input = fonte_padrao

        atributos = ["Nome: "]
        
        self.inputs = []

        for indice, nome in enumerate(atributos):
            self.inputs.append(QLineEdit(self))
            self.inputs[indice].setFont(fonte_input)
            self.inputs[indice].setFixedSize(250, 30)
            label = QLabel(nome, self)
            label.setFont(fonte_label)
            layout.addRow(label, self.inputs[indice])


        if(self._remove):
            button_func = self.remover_produto
        else:
            button_func = self.buscar_produto

        botao_buscar = QPushButton('Buscar')
        botao_buscar.clicked.connect(button_func)
        layout.addWidget(botao_buscar)

        self.setLayout(layout)

    def buscar_produto(self):
        self.tela_principal.buscar_produto(self.inputs[0].text())
    
    def remover_produto(self):
        self.tela_principal.remover_produto(self.inputs[0].text())
        

def iniciar_programa(cadastro: CadastroProdutos = CadastroProdutos()):
    app = QApplication([])
    
    tela = Menu(cadastro)
    tela.show()
    app.exec()

cadastro = CadastroProdutos()
cadastro.adicionar_produto(Produto("Banana", "123", 1.50, 25, "Prata"))
iniciar_programa(cadastro)