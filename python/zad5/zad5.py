def czytaj_dane(nazwa_pliku):
    with open(nazwa_pliku, 'r') as plik:
        wiersze = plik.readlines()
    return [[int(p) for p in wiersz.split()] for wiersz in wiersze]

def zadanie_1(obraz):
    najjasniejszy = max(max(wiersz) for wiersz in obraz)
    najciemniejszy = min(min(wiersz) for wiersz in obraz)
    return najjasniejszy, najciemniejszy

def zadanie_2(obraz):
    def czy_symetryczny(wiersz):
        return all(wiersz[i] == wiersz[-i-1] for i in range(len(wiersz)//2))
    
    liczba_usunietych = 0
    while obraz:
        if czy_symetryczny(obraz[0]):
            break
        obraz.pop(0)
        liczba_usunietych += 1
    return liczba_usunietych

def zadanie_3(obraz):
    def czy_kontrastujace(piksel1, piksel2):
        return abs(piksel1 - piksel2) > 128
    
    kontrastujace = 0
    for i in range(len(obraz)):
        for j in range(len(obraz[i])):
            if (i > 0 and czy_kontrastujace(obraz[i][j], obraz[i-1][j])) or \
               (j > 0 and czy_kontrastujace(obraz[i][j], obraz[i][j-1])):
                kontrastujace += 1
    return kontrastujace

def zadanie_4(obraz):
    def najdluzsza_linia_pionowa(wiersz):
        aktualna_dlugosc = 1
        maks_dlugosc = 1
        for i in range(1, len(wiersz)):
            if wiersz[i] == wiersz[i-1]:
                aktualna_dlugosc += 1
            else:
                maks_dlugosc = max(maks_dlugosc, aktualna_dlugosc)
                aktualna_dlugosc = 1
        return max(maks_dlugosc, aktualna_dlugosc)
    
    najdluzsza_linia = max(najdluzsza_linia_pionowa([obraz[i][j] for i in range(len(obraz))]) for j in range(len(obraz[0])))
    return najdluzsza_linia

def zadanie_5(obraz):
    liczba_wystapien = {}
    for wiersz in obraz:
        for piksel in wiersz:
            if piksel in liczba_wystapien:
                liczba_wystapien[piksel] += 1
            else:
                liczba_wystapien[piksel] = 1
    
    najczestszy = max(liczba_wystapien, key=liczba_wystapien.get)
    najrzadszy = min(liczba_wystapien, key=liczba_wystapien.get)
    return najczestszy, najrzadszy

# Wczytaj dane z pliku
obraz = czytaj_dane('dane.txt')

# Rozwiązanie zadań
odpowiedzi = []
odpowiedzi.append(zadanie_1(obraz))
odpowiedzi.append(zadanie_2(obraz))
odpowiedzi.append(zadanie_3(obraz))
odpowiedzi.append(zadanie_4(obraz))
odpowiedzi.append(zadanie_5(obraz))

# Zapisz odpowiedzi do pliku wyniki.txt
with open('wyniki.txt', 'w') as plik_wyniki:
    for i, odpowiedz in enumerate(odpowiedzi, start=1):
        plik_wyniki.write(f'Zadanie_{i}: {odpowiedz}\n')
