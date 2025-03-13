# Zadanie 1
def zadanie1():
    with open('demografia.txt', 'r') as f:
        lines = f.readlines()
    count = 0
    for line in lines:
        data = line.split('\t')
        if data[1] == 'mazowieckie' and float(data[5].replace(',', '.')) < 0:
            count += 1
    with open('wyniki.txt', 'a') as f:
        f.write(f'Liczba powiatów należących do województwa mazowieckiego, w których saldo migracji było ujemne: {count}\n')

# Zadanie 2
def zadanie2():
    with open('demografia.txt', 'r') as f:
        lines = f.readlines()
    przyrost_ludzi = []
    for line in lines:
        data = line.split('\t')
        przyrost = float(data[3].replace(',', '.')) - float(data[4].replace(',', '.'))
        przyrost_ludzi.append((data[0], przyrost))
    przyrost_ludzi.sort(key=lambda x: (-x[1], x[0]))
    with open('wyniki.txt', 'a') as f:
        f.write('10 powiatów o największym współczynniku przyrostu naturalnego:\n')
        for i in range(10):
            f.write(f'{przyrost_ludzi[i][0]}: {przyrost_ludzi[i][1]}\n')

# Zadanie 3
def zadanie3():
    with open('demografia.txt', 'r') as f:
        lines = f.readlines()
    populacja = {}
    for line in lines:
        data = line.split('\t')
        if data[1] not in populacja:
            populacja[data[1]] = 0
        populacja[data[1]] += int(data[2])
    populacja = sorted(populacja.items(), key=lambda x: -x[1])
    with open('wyniki.txt', 'a') as f:
        f.write('Cztery województwa o największej liczbie ludności:\n')
        for i in range(4):
            f.write(f'{populacja[i][0]}: {populacja[i][1]}\')

# Zadanie 4
def zadanie4():
    with open('demografia.txt', 'r') as f:
        lines = f.readlines()
    births = []
    for line in lines:
        data = line.split('\t')
        if data[1] == 'opolskie':
            birth = int(data[2]) * float(data[3].replace(',', '.')) / 1000
            births.append((data[0], int(birth)))
    births.sort(key=lambda x: x[0])
    with open('wyniki.txt', 'a') as f:
        f.write('Zestawienie powiatów oraz liczby urodzeń w 2009 roku w każdym powiecie dla województwa opolskiego:\n')
        for birth in births:
            f.write(f'{birth[0]}: {birth[1]}\n')

zadanie1()
zadanie2()
zadanie3()
