termos = int(input('Quantos termos de fibonacci você deseja? '))

if(termos > 0):
    t1 = 0
    print(t1, end = ' -> ')

    if(termos > 1):
        t2 = 1
        print(t2, end = ' -> ')

        if(termos > 2):
            for i in range(termos-2):
                t3 = t1 + t2
                print(t3, end = ' -> ')
                t1 = t2
                t2 = t3

print('FIM')