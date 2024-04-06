def fatorial(num):
    result = 1
    for i in range(num, 1, -1):
        result *= i
    return result

n = int(input('Digite um número: '))
p = int(input('Digite outro número: '))

arranjo = fatorial(n) / fatorial(n-p)
combinacao = fatorial(n) / (fatorial(p) * fatorial(n-p))

print(f'Arranjo de {n} e {p} = {arranjo}')
print(f'Combinação de {n} e {p} = {combinacao}')