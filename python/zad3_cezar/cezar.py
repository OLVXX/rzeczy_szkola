def szyfruj_litere(litera, klucz):
    if litera.isalpha():
        if litera.isupper():
            poczatek = ord('A')
        else:
            poczatek = ord('a')
        przesuniecie = ord(litera) - poczatek
        zaszyfrowana_litera = chr((przesuniecie + klucz) % 26 + poczatek)
        return zaszyfrowana_litera
    else:
        return litera

def szyfruj_slowo(slowo, klucz):
    zaszyfrowane_slowo = ''
    for litera in slowo:
        zaszyfrowane_slowo += szyfruj_litere(litera, klucz)
    return zaszyfrowane_slowo

def odszyfruj_litere(litera, klucz):
    if litera.isalpha():
        if litera.isupper():
            poczatek = ord('A')
        else:
            poczatek = ord('a')
        przesuniecie = ord(litera) - poczatek
        odszyfrowana_litera = chr((przesuniecie - klucz) % 26 + poczatek)
        return odszyfrowana_litera
    else:
        return litera

def odszyfruj_slowo(slowo, klucz):
    odszyfrowane_slowo = ''
    for litera in slowo:
        odszyfrowane_slowo += odszyfruj_litere(litera, klucz)
    return odszyfrowane_slowo

# Zad0: Szyfrowanie
with open('dane_1.txt', 'r') as plik_wejsciowy:
    dane = plik_wejsciowy.readlines()

with open('wyniki_1.txt', 'w') as plik_wyjsciowy:
    for slowo in dane:
        slowo = slowo.strip()
        zaszyfrowane_slowo = szyfruj_slowo(slowo, 107)
        plik_wyjsciowy.write(zaszyfrowane_slowo + '\n')

print("Zadanie 0 (Szyfrowanie) zakończone. Wyniki zapisane w pliku wyniki_1.txt.")

# Zad1: Odszyfrowywanie
with open('dane_2.txt', 'r') as plik_wejsciowy:
    dane = plik_wejsciowy.readlines()

with open('wyniki_2.txt', 'w') as plik_wyjsciowy:
    for linia in dane:
        szyfrogram, klucz = linia.strip().split()
        odszyfrowane_slowo = odszyfruj_slowo(szyfrogram, int(klucz))
        plik_wyjsciowy.write(odszyfrowane_slowo + '\n')

print("Zadanie 1 (Odszyfrowywanie) zakończone. Wyniki zapisane w pliku wyniki_2.txt.")

# Zad2
with open('dane_3.txt', 'r') as plik_wejsciowy:
    dane = plik_wejsciowy.readlines()

znalezione_bledy = False

with open('wyniki_3.txt', 'w') as plik_wyjsciowy:
    for linia in dane:
        slowo, szyfrogram = linia.strip().split()
        if len(slowo) != len(szyfrogram):
            plik_wyjsciowy.write(slowo + '\n')
            znalezione_bledy = True

if not znalezione_bledy:
    print("Zadanie 2 (Wyszukiwanie błędnych szyfrogramów) zakończone. Brak błędów.")
else:
    print("Zadanie 2 (Wyszukiwanie błędnych szyfrogramów) zakończone. Wyniki zapisane w pliku wyniki_3.txt.")
with open('dane_3.txt', 'r') as plik_wejsciowy:
    dane = plik_wejsciowy.readlines()

with open('wyniki_3.txt', 'w') as plik_wyjsciowy:
    for linia in dane:
        slowo, szyfrogram = linia.strip().split()
        odszyfrowane_slowo = odszyfruj_slowo(szyfrogram, 107)
        if odszyfrowane_slowo == slowo:
            continue  # Pomijaj poprawnie zaszyfrowane pary
        plik_wyjsciowy.write(slowo + '\n')

print("Zadanie 3 (Wyszukiwanie błędnych szyfrogramów) zakończone. Wyniki zapisane w pliku wyniki_3.txt.")