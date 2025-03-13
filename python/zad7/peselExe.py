import collections


def sprawdz_pesel(pesel):
    weights = [1, 3, 7, 9, 1, 3, 7, 9, 1, 3]
    sprawdz_sume = 0
    i = 0
    # Obliczanie sumy kontrolnej numeru PESEL
    while i < 10:
        sprawdz_sume += float(pesel[i]) * weights[i]
        i += 1
    # Sprawdzanie, czy ostatnia cyfra numeru PESEL jest zgodna z obliczoną sumą kontrolną
    return str((10 - sprawdz_sume % 10) % 10) == pesel[-1]

# Funkcja do przetwarzania numerów PESEL z pliku
def otw_pesele(filename):
    with open(filename, 'r') as file:
        pesele = file.readlines()

    urodzeni_grudzien = 0
    kobiety = 0
    lata_urodzen = []
    zle_pesele = []
    dekady = collections.Counter()
    i = 0
    # Przetwarzanie każdego numeru PESEL
    while i < len(pesele):
        pesel = pesele[i].strip()
        # Sprawdzanie, czy osoba urodziła się w grudniu
        if pesel[2:4] == '12':
            urodzeni_grudzien += 1
        # Sprawdzanie, czy osoba jest kobietą
        if float(pesel[9]) % 2 == 0:
            kobiety += 1
        # Zapisywanie roku urodzenia osoby
        birth_rok = float(pesel[:2])
        lata_urodzen.append(birth_rok)
        # Sprawdzanie, czy numer PESEL jest poprawny
        if not sprawdz_pesel(pesel):
            zle_pesele.append(pesel)
        # Zapisywanie dekady urodzenia osoby
        decade = (1900 + birth_rok) // 10
        if decade in dekady:
            dekady[decade] += 1
        else:
            dekady[decade] = 1
        i += 1

    # Sortowanie niepoprawnych numerów PESEL ręcznie
    j = 0
    while j < len(zle_pesele):
        k = j + 1
        while k < len(zle_pesele):
            if float(zle_pesele[j]) > float(zle_pesele[k]):
                zle_pesele[j], zle_pesele[k] = zle_pesele[k], zle_pesele[j]
            k += 1
        j += 1

    # Znajdowanie najczęściej występującego roku ręcznie
    najczestszy_rok = None
    maks_wartosc = 0
    for rok, wartosc in dekady.items():
        if wartosc > maks_wartosc:
            najczestszy_rok = rok
            maks_wartosc = wartosc

    return urodzeni_grudzien, kobiety, najczestszy_rok, zle_pesele, dekady

urodzeni_grudzien, kobiety, najczestszy_rok, zle_pesele, dekady = otw_pesele('pesel.txt')

# Wyświetlanie wyników
print(f'zad 1) Ilość osób urodzonych w grudniu: {urodzeni_grudzien}')
print(f'zad 2) Ilość kobiet pracujących w biurze: {kobiety}')
print(f'zad 3) Rok, w którym urodziło się najwięcej osób: {najczestszy_rok}')
print(f'zad 4) Nieprawidłowe numery PESEL: {zle_pesele}')
print('zad 4) Liczba osób urodzonych w kolejnych dziesięcioleciach:')
rok_dekady_klu = list(dekady.keys())
# Sortowanie kluczy dekad ręcznie
j = 0
while j < len(rok_dekady_klu):
    k = j + 1
    while k < len(rok_dekady_klu):
        if rok_dekady_klu[j] > rok_dekady_klu[k]:
            rok_dekady_klu[j], rok_dekady_klu[k] = rok_dekady_klu[k], rok_dekady_klu[j]
        k += 1
    j += 1
i = 0
# Wyświetlanie liczby osób urodzonych w każdej dekadzie
while i < len(rok_dekady_klu):
    decade = rok_dekady_klu[i]
    print(f'   {decade}s: {dekady[decade]}')
    i += 1