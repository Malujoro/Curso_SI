from cadastro import *

from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout, QMainWindow, QTableWidget, QTableWidgetItem, QHeaderView, QAbstractItemView, QDialog, QFormLayout, QLineEdit, QLabel, QMessageBox
from PyQt5.QtGui import QFont


class Menu(QMainWindow):

    def __init__(self, cadastro: Cadastro):
        super().__init__()
        self._cadastro = cadastro
        self._clientes = cadastro.clientes
        self.iniciar_ui()

    def iniciar_ui(self):
        self.setWindowTitle("Gerenciador de clientes")
        self.setGeometry(650, 250, 500, 300)

        central_widget = QWidget(self)

        botoes = {"Adicionar Cliente": self.abrir_tela_adicionar_cliente, "Buscar Cliente": self.abrir_tela_buscar_cliente, "Alterar Cliente": self.abrir_tela_alterar_cliente, "Mostrar todos": self.mostrar_todos}
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

    def abrir_tela_adicionar_cliente(self):
        dialogo = TelaCadastro(self)
        dialogo.exec_()

    def adicionar_cliente(self, cliente: Cliente):
        self._cadastro.cadastrar(cliente)

    def abrir_tela_buscar_cliente(self):
        dialogo = TelaBusca(self)
        dialogo.exec_()

    def buscar_cliente(self, cpf: str):
        ret, msg, cliente = self._cadastro.verifica_cadastro(cpf)
    
        if(ret):
            mensagem = (
            f"<font size='10'>Nome: {cliente.nome}</font><br>"
            f"<font size='10'>CPF: {cliente.cpf}</font><br>"
            f"<font size='10'>Endereço: {cliente.endereco}</font><br>"
            f"<font size='10'>CEP: {cliente.cep}</font><br>"
            f"<font size='10'>Telefone: {cliente.telefone}</font>"
        )
            
            QMessageBox.information(self, msg, mensagem, QMessageBox.Ok)
        else:
            mensagem = (f"<font size='10'>Nenhum cliente encontrado com esse CPF.</font><br>")
            QMessageBox.warning(self, msg, mensagem, QMessageBox.Ok)

    def abrir_tela_alterar_cliente(self):
        dialogo = TelaBusca(self, True)
        dialogo.exec_()

    def alterar_cliente(self, cpf: str):
        ret, msg, cliente = self._cadastro.verifica_cadastro(cpf)
    
        if(ret):
            dialogo = TelaCadastro(self, cliente)
            dialogo.exec_()
        else:
            mensagem = (f"<font size='10'>Nenhum cliente encontrado com esse CPF.</font><br>")
            QMessageBox.warning(self, msg, mensagem, QMessageBox.Ok)

    def mostrar_todos(self):
        self.janela_lista = QWidget()
        self.janela_lista.setWindowTitle("Lista de Clientes")
        self.janela_lista.setGeometry(500, 150, 1000, 800)

        layout = QVBoxLayout()

        colunas = ["Nome", "CPF", "Endereco", "CEP", "Telefone"]

        tabela = QTableWidget()
        tabela.setColumnCount(len(colunas))
        tabela.setHorizontalHeaderLabels(colunas)

        tabela.setRowCount(self._cadastro.get_total())

        fonte_header = QFont()
        fonte_header.setBold(True)
        fonte_header.setPointSize(25)

        tabela.horizontalHeader().setFont(fonte_header)

        fonte_linha = QFont()
        fonte_linha.setPointSize(18)
        tabela.setFont(fonte_linha)

        for linha, cliente in enumerate(self._clientes):
            dados = [cliente.nome, cliente.cpf, cliente.endereco, cliente.cep, cliente.telefone]
            for coluna, informacao in enumerate(dados):
                tabela.setItem(linha, coluna, QTableWidgetItem(informacao))

        tabela.resizeRowsToContents()
        tabela.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)

        tabela.setEditTriggers(QAbstractItemView.NoEditTriggers)

        layout.addWidget(tabela)

        self.janela_lista.setLayout(layout)

        self.janela_lista.show()


class TelaCadastro(QDialog):
    def __init__(self, tela_principal, cliente: Cliente = None):
        super().__init__()
        self.tela_principal = tela_principal
        self._cliente = cliente
        self.init_ui()

    def init_ui(self):
        self.setWindowTitle('Cadastrar Cliente' if self._cliente else "Editar Cliente")
        self.setGeometry(500, 150, 500, 300)
        
        layout = QFormLayout()

        fonte_padrao = QFont("Arial", 25)
        fonte_label = fonte_padrao
        fonte_input = fonte_padrao

        atributos = ["Nome: ", "CPF: ", "Endereço: ", "CEP: ", "Telefone: "]
        
        self.inputs = []

        for indice, nome in enumerate(atributos):
            self.inputs.append(QLineEdit(self))
            self.inputs[indice].setFont(fonte_input)
            self.inputs[indice].setFixedSize(250, 30)
            label = QLabel(nome, self)
            label.setFont(fonte_label)
            layout.addRow(label, self.inputs[indice])


        botao_salvar = QPushButton('Salvar')
        botao_salvar.clicked.connect(self.salvar_cliente)
        layout.addWidget(botao_salvar)

        self.setLayout(layout)


    def salvar_cliente(self):

        if(self._cliente):
            if(self.inputs[0].text() != ""):
                print(self.inputs[0].text)
                self._cliente.nome = self.inputs[0].text()

            if(self.inputs[1].text() != ""):
                self._cliente.cpf = self.inputs[1].text()

            if(self.inputs[2].text() != ""):
                self._cliente.endereco = self.inputs[2].text()

            if(self.inputs[3].text() != ""):
                self._cliente.cep = self.inputs[3].text()

            if(self.inputs[4].text() != ""):
                self._cliente.telefone = self.inputs[4].text()

        else:
            cliente = Cliente(self.inputs[0].text(), self.inputs[1].text(), self.inputs[2].text(), self.inputs[3].text(), self.inputs[4].text())
            self.tela_principal.adicionar_cliente(cliente)

        self.close()

class TelaBusca(QDialog):
    def __init__(self, tela_principal, edit: bool = False):
        super().__init__()
        self.tela_principal = tela_principal
        self._edit = edit
        self.init_ui()

    def init_ui(self):
        self.setWindowTitle('Buscar Cliente')
        self.setGeometry(500, 150, 500, 300)
        
        layout = QFormLayout()

        fonte_padrao = QFont("Arial", 25)
        fonte_label = fonte_padrao
        fonte_input = fonte_padrao

        atributos = ["CPF: "]
        
        self.inputs = []

        for indice, nome in enumerate(atributos):
            self.inputs.append(QLineEdit(self))
            self.inputs[indice].setFont(fonte_input)
            self.inputs[indice].setFixedSize(250, 30)
            label = QLabel(nome, self)
            label.setFont(fonte_label)
            layout.addRow(label, self.inputs[indice])

        if(self._edit):
            button_func = self.alterar_cliente
        else:
            button_func = self.buscar_cliente

        botao_buscar = QPushButton('Buscar')
        botao_buscar.clicked.connect(button_func)
        layout.addWidget(botao_buscar)

        self.setLayout(layout)

    def buscar_cliente(self):
        self.tela_principal.buscar_cliente(self.inputs[0].text())
    
    def alterar_cliente(self):
        self.tela_principal.alterar_cliente(self.inputs[0].text())
        

def iniciar_programa(cadastro: Cadastro = Cadastro()):
    app = QApplication([])
    
    tela = Menu(cadastro)
    tela.show()
    app.exec()

cadastro = Cadastro()
cadastro.cadastrar(Cliente("Mateus", "123", "Av 123", "321", "(11) 123"))
iniciar_programa(cadastro)