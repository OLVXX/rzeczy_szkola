#include <iostream>
#include <string>

struct Uczen {
    std::string imie;
    std::string nazwisko;
    int klasa;
    int wiek;
};

void wczytajUczniow(Uczen* tab, int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        std::cout << "Podaj dane " << i + 1 << " ucznia\n";
        std::cout << "Podaj imię: ";
        std::cin >> tab[i].imie;
        std::cout << "Podaj nazwisko: ";
        std::cin >> tab[i].nazwisko;
        std::cout << "Podaj klasę: ";
        std::cin >> tab[i].klasa;
        std::cout << "Podaj wiek: ";
        std::cin >> tab[i].wiek;

        // Wyświetlanie wprowadzonych danych w trakcie wprowadzania
        std::cout << "Wprowadzono: " << tab[i].imie << " " << tab[i].nazwisko
            << ", klasa: " << tab[i].klasa << ", wiek: " << tab[i].wiek << "\n\n";
    }
}

void wypiszUczniow(Uczen* tab, int rozmiar) {
    std::cout << "\nWypisywanie danych uczniów:\n";
    for (int i = 0; i < rozmiar; i++) {
        std::cout << "Uczeń " << i + 1 << ": " << tab[i].imie << " " << tab[i].nazwisko
            << ", klasa: " << tab[i].klasa << ", wiek: " << tab[i].wiek << std::endl;
    }
}

int main() {
    int rozmiar;

    std::cout << "Podaj rozmiar tablicy\n";
    std::cin >> rozmiar;

    Uczen* tab = new Uczen[rozmiar];
    wczytajUczniow(tab, rozmiar);
    wypiszUczniow(tab, rozmiar);

    delete[] tab;
    return 0;
}
