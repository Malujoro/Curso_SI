# Slide - 0 a 40
'''
limite = 40
num = 0
while(num < limite):
    if((num % 4 == 0) or (num % 10 == 0)):
        print('PIN')
    else:
        print(num)
    num += 1
print('FIM')
'''

# Slide - Tabuada
'''
for i in range(1, 10):
    for j in range(1, 11):
        print(f'{i} x {j} = {i * j}')
    print('\n')
'''

# try except


a = int(input('A: '))
while True:
    try:
        b = int(input('B: '))
        r = a/b
        break
    except:
        print('\nB não pode ser 0, Digite novamente\n')

print(f'\n{a}/{b} = {r}')