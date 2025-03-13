#include <iostream>
#include <string>

struct Osoba {
    std::string imie;
    std::string nazwisko;
};

Osoba* wczytajOsoby(int rozmiar) {
    Osoba* tab = new Osoba[rozmiar];
    for (int i = 0; i < rozmiar; i++) {
        std::cout << "Podaj dane " << i + 1 << " ucznia\n";
        std::cout << "Podaj imię: ";
        std::cin >> tab[i].imie;
        std::cout << "Podaj nazwisko: ";
        std::cin >> tab[i].nazwisko;

        std::cout << "Wprowadzono: " << tab[i].imie << " " << tab[i].nazwisko << std::endl;
    }
    return tab;
}

void wypiszOsoby(Osoba* tab, int rozmiar) {
    std::cout << "\nWypisywanie danych osób:\n";
    for (int i = 0; i < rozmiar; i++) {
        std::cout << "Osoba " << i + 1 << ": " << tab[i].imie << " " << tab[i].nazwisko << std::endl;
    }
}

void wypiszNajkrotsze(Osoba* tab, int rozmiar) {
    if (rozmiar == 0) {
        std::cout << "Brak uczniów" << std::endl;
        return;
    }

    int indeksNajkrotszego = 0;
    for (int i = 1; i < rozmiar; i++) {
        if (tab[i].imie.size() < tab[indeksNajkrotszego].imie.size()) {
            indeksNajkrotszego = i;
        }
    }

    std::cout << "Imię z najmniejszą liczbą znaków to: " << tab[indeksNajkrotszego].imie
        << " i ma " << tab[indeksNajkrotszego].imie.size() << " znaków." << std::endl;
}

int main() {
    int rozmiar;

    std::cout << "Podaj rozmiar tablicy\n";
    std::cin >> rozmiar;

    Osoba* tab = wczytajOsoby(rozmiar);
    wypiszOsoby(tab, rozmiar);
    wypiszNajkrotsze(tab, rozmiar);

    delete[] tab;
    return 0;
}
