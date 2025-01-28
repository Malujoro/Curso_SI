def arredonda(num):
    aux = num * 10
    result = aux - int(aux)
    if(result == 0.5):
        num += 0.1
    return num

def media(vetor, horas):
    media = sum(vetor)
    media /= len(vetor)
    media = round(arredonda(media), 1)
    return media * horas

def calcular_periodo(matriz_notas):
    lista_horas = []

    periodo = 0
    for notas_materia in matriz_notas:
        med = media(notas_materia[0], notas_materia[1])
        periodo += med
        lista_horas.append(notas_materia[1])

    matriz_horas.append(lista_horas)
    total_periodos.append(periodo)

########## Início ##########
disciplinas = [
    # 1º Período
    {
        "alg1": [[10, 10, 9, 9], 90],
        "gestao": [[8.7, 9.5, 8.8], 60],
        "logica": [[10, 10, 10], 60],
        "metodologia": [[9.2, 9.5, 10], 60],
        "introducao": [[10], 15],
        "si1": [[7.5, 10, 10], 60],
    },
    # 2º Período
    {
        "alg2": [[10, 8.5, 8.5, 10], 90],
        "calculo": [[10, 10, 10], 60],
        "circuitos": [[10, 9.5, 9.7], 60],
        "empreendedorismo": [[8.3, 9.4, 8.8], 60],
        "discreta": [[8.3, 9.1, 9], 60],
        "prolog": [[10, 8.5], 30],
        "si2": [[9.2, 10, 10], 60],
    },
    # 3º Período
    {
        "arquitetura": [[10, 10, 9.8], 60],
        "bd1": [[9.8, 9.3, 9.5], 60],
        "engenharia1": [[10, 10, 10], 60],
        "estatistica": [[10, 9.5, 10], 60],
        "ed1": [[10, 9.2, 7.7], 60],
        "poo1": [[9.9, 8.4, 10], 60],
        "so": [[9.5, 9.5, 10], 60],
    },
    # 4º Período
    {
        "bd2": [[9.1, 9.3, 9.5], 60],
        "engenharia2": [[10, 10, 7.5], 60],
        "ed2": [[9.5, 8.9, 8.8], 60],
        "ihc": [[10, 9.8, 10], 60],
        "poo2": [[9.7, 9.8, 10], 60],
        "pweb1": [[10, 10, 10], 60],
        "redes1": [[10, 9.8, 10], 60],
    },
]

total_periodos = []
matriz_horas = []
quant_periodos = len(disciplinas)

usar_periodos = 4
utilizar_periodo = ([True] * usar_periodos) + ([False] * (quant_periodos -  usar_periodos))

for periodo, materias in enumerate(disciplinas):
    if(utilizar_periodo[periodo]):
        calcular_periodo(materias.values())

########## Cálculo ##########
total_horas = 0
for hora in matriz_horas:
    total_horas += sum(hora)

if(total_horas > 0):
    ira = sum(total_periodos) / total_horas

    for i, periodo in enumerate(total_periodos):
        print(f"IRA isolado do {i+1}º período: {periodo / sum(matriz_horas[i])}")

    print(f"IRA final: {ira}")
else:
    print("Não há nenhum período iniciado")