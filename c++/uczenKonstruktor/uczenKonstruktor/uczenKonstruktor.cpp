#include <iostream>
#include <string>

class Uczen {
private:
    std::string imie;
    std::string nazwisko;
    int* oceny;
    int liczbaOcen;
    int maxOcen;

public:
    Uczen(const std::string& imie, const std::string& nazwisko, int maxOcen)
        : imie(imie), nazwisko(nazwisko), liczbaOcen(0), maxOcen(maxOcen) {
        oceny = new int[maxOcen];
    }

    ~Uczen() {
        delete[] oceny;
    }

    void dodajOcene(int ocena) {
        if (ocena >= 1 && ocena <= 6) {
            if (liczbaOcen < maxOcen) {
                oceny[liczbaOcen++] = ocena;
            }
            else {
                std::cout << "Brak miejsca na nowe oceny!" << std::endl;
            }
        }
        else {
            std::cout << "Niepoprawna ocena! Podaj ocenę od 1 do 6." << std::endl;
        }
    }

    void print() const {
        std::cout << "Imię: " << imie << std::endl;
        std::cout << "Nazwisko: " << nazwisko << std::endl;
        std::cout << "Oceny: ";
        for (int i = 0; i < liczbaOcen; i++) {
            std::cout << oceny[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::string imie, nazwisko;
    int liczbaOcen;

    std::cout << "Podaj imię ucznia: ";
    std::cin >> imie;

    std::cout << "Podaj nazwisko ucznia: ";
    std::cin >> nazwisko;

    std::cout << "Podaj maksymalną liczbę ocen: ";
    std::cin >> liczbaOcen;

    Uczen uczen(imie, nazwisko, liczbaOcen);

    int ocena;
    for (int i = 0; i < liczbaOcen; i++) {
        std::cout << "Podaj ocenę (od 1 do 6): ";
        std::cin >> ocena;
        uczen.dodajOcene(ocena);
    }

    uczen.print();

    return 0;
}
