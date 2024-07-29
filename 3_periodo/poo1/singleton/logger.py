class Logger:
    __instance = None

    def __new__(cls):
        if Logger.__instance is None:
            Logger.__instance = super().__new__(cls)
            Logger.__instance._initialized = False
        return Logger.__instance


    def __init__(self):
        if not self._initialized:
            self._logs = []
            self.initialized = True


    @staticmethod
    def get_instance():
        if Logger.__instance is None:
            Logger()
        return Logger.__instance


    def log(self, mensagem):
        self._logs.append(mensagem)
        print(mensagem)

    @property
    def logs(self):
        return self._logs


    def reset_logs(self):
        self._logs = []


# Exercício 1: Verificação de Unicidade
logger1 = Logger.get_instance()
logger2 = Logger.get_instance()
# print(logger1 is logger2)  # Verifica se logger1 e logger2 são a mesma instância


# Exercício 2: Registro de Mensagens
logger1.log("Primeira mensagem")
logger2.log("Segunda mensagem")
# print(logger1.get_logs() == logger2.get_logs())  # Verifica se os logs são os mesmos
print(logger1.logs)  # Deve imprimir as duas mensagens logadas
print(logger2.logs)  # Deve imprimir as duas mensagens logadas


# Exercício 3: Expansão da Classe Singleton
logger1.reset_logs()
print(logger1.logs)  # Deve imprimir uma lista vazia []
