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

########## Início ##########
total_periodos = []
matriz_horas = []

utilizar_periodo = [False, False, False]

########## 1 Período ##########
if(utilizar_periodo[0]):
    matriz_horas.append([90, 60, 60, 60, 15, 60])

    alg1 = media([10, 10, 9, 9], matriz_horas[0][0])
    gestao = media([8.7, 9.5, 8.8], matriz_horas[0][1])
    logica = media([10, 10, 10], matriz_horas[0][2])
    metodologia = media([9.2, 9.5, 10], matriz_horas[0][3])
    introducao = media([10], matriz_horas[0][4])
    si1 = media([7.5, 10, 10], matriz_horas[0][5])

    periodo1 = alg1 + gestao + logica + metodologia + introducao + si1

    total_periodos.append(periodo1)

########## 2 Período ##########
if(utilizar_periodo[1]):
    matriz_horas.append([90, 60, 60, 60, 60, 30, 60])

    alg2 = media([10, 8.5, 8.5, 10], matriz_horas[1][0])
    calculo = media([10, 10, 10], matriz_horas[1][1])
    circuitos = media([10, 9.5, 9.7], matriz_horas[1][2])
    empreendedorismo = media([8.3, 9.4, 8.8], matriz_horas[1][3])
    discreta = media([8.3, 9.1, 9], matriz_horas[1][4])
    prolog = media([10, 8.5], matriz_horas[1][5])
    si2 = media([9.2, 10, 10], matriz_horas[1][6])

    periodo2 = alg2 + calculo + circuitos + empreendedorismo + discreta + prolog + si2

    total_periodos.append(periodo2)

########## 3 Período ##########
if(utilizar_periodo[2]):
    matriz_horas.append([60, 60, 60, 60, 60, 60, 60])

    arquitetura = media([10, 10, 9.8], matriz_horas[2][0])
    bd1 = media([9.8, 9.3, 9.5], matriz_horas[2][1])
    engenharia1 = media([10, 10, 10], matriz_horas[2][2])
    estatistica = media([10, 9.5, 10], matriz_horas[2][3])
    ed1 = media([10, 9.2, 7.7], matriz_horas[2][4])
    poo1 = media([9.9, 8.4, 10], matriz_horas[2][5])
    so = media([9.5, 9.5, 10], matriz_horas[2][6])

    periodo3 = arquitetura + bd1 + engenharia1 + estatistica + ed1 + poo1 + so

    total_periodos.append(periodo3)

########## Cálculo ##########
total_horas = 0
for hora in matriz_horas:
    total_horas += sum(hora)

if(total_horas > 0):
    IRA = sum(total_periodos) / total_horas

    for i, periodo in enumerate(total_periodos):
        print(f"IRA isolado do {i+1}º período: {periodo / sum(matriz_horas[i])}")

    print(f"IRA final: {IRA}")
else:
    print("Não há nenhum período")