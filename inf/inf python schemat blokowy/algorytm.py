import math

def czynniki_pierwsze(n):
    czynniki = []
    while n % 2 == 0:
        czynniki.append(2),
        n = n / 2
    for i in range(3,int(math.sqrt(n))+1,2):
        while n % i== 0:
            czynniki.append(i),
            n = n / i
    if n > 2:
        czynniki.append(n)
    return czynniki

def zadanie1():
    with open('liczby.txt', 'r') as f:
        linie = f.readlines()
    licznik = 0
    pierwsza_taka_liczba = None
    for linia in linie:
        liczba = int(linia.strip())
        if str(liczba)[0] == str(liczba)[-1]:
            licznik += 1
            if pierwsza_taka_liczba is None:
                pierwsza_taka_liczba = liczba
    return licznik, pierwsza_taka_liczba

def zadanie2():
    with open('liczby.txt', 'r') as f:
        linie = f.readlines()
    max_czynniki = 0
    max_rozne_czynniki = 0
    liczba_z_max_czynnikami = None
    liczba_z_max_roznymi_czynnikami = None
    for linia in linie:
        liczba = int(linia.strip())
        czynniki = czynniki_pierwsze(liczba)
        if len(czynniki) > max_czynniki:
            max_czynniki = len(czynniki)
            liczba_z_max_czynnikami = liczba
        if len(set(czynniki)) > max_rozne_czynniki:
            max_rozne_czynniki = len(set(czynniki))
            liczba_z_max_roznymi_czynnikami = liczba
    return liczba_z_max_czynnikami, max_czynniki, liczba_z_max_roznymi_czynnikami, max_rozne_czynniki

print(zadanie1())
print(zadanie2())
