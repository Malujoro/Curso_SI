class Configuracoes:
    __instance = None

    def __new__(cls):
        if Configuracoes.__instance is None:
            # print("Configurações foi criada")
            Configuracoes.__instance = super().__new__(cls)
            Configuracoes.__instance._initialized = False
        return Configuracoes.__instance
    

    def __init__(self):
        if not self._initialized:
            self._volume = 75
            self._initialized = True
    
    @staticmethod
    def get_instance():
        if Configuracoes.__instance is None:
            Configuracoes()
        return Configuracoes.__instance

    @property
    def volume(self):
        return self._volume
    
    @volume.setter
    def volume(self, vol):
        self._volume = vol


config1 = Configuracoes.get_instance()
config2 = Configuracoes.get_instance()

print("Original")
print(f"Config 1 = {config1.volume}")
print(f"Config 2 = {config2.volume}")
print()

config1.volume = 90

print("Após alterar o config 1")
print(f"Config 1 = {config1.volume}")
print(f"Config 2 = {config2.volume}")
print()

config3 = Configuracoes.get_instance()
print("Após criar o config 3")
print(f"Config 1 = {config1.volume}")
print(f"Config 2 = {config2.volume}")
print(f"Config 3 = {config3.volume}")
print()

print("Instâncias")
print(f"Config 1 = {config1}")
print(f"Config 2 = {config2}")
print(f"Config 3 = {config3}")