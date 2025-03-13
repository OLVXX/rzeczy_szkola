#include <iostream>

class Macierz {
private:
    static const int rozmiar = 3;
    float tablica[rozmiar][rozmiar];

public:
    Macierz() {
        for (int i = 0; i < rozmiar; ++i) {
            for (int j = 0; j < rozmiar; ++j) {
                tablica[i][j] = 0.0f;
            }
        }
    }

    friend std::istream& operator>>(std::istream& is, Macierz& m) {
        for (int i = 0; i < rozmiar; ++i) {
            for (int j = 0; j < rozmiar; ++j) {
                is >> m.tablica[i][j];
            }
        }
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Macierz& m) {
        for (int i = 0; i < rozmiar; ++i) {
            for (int j = 0; j < rozmiar; ++j) {
                os << m.tablica[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    Macierz* operator+(const Macierz& other) const {
        Macierz* wynik = new Macierz();
        for (int i = 0; i < rozmiar; ++i) {
            for (int j = 0; j < rozmiar; ++j) {
                wynik->tablica[i][j] = this->tablica[i][j] + other.tablica[i][j];
            }
        }
        return wynik;
    }

    Macierz* operator-(const Macierz& other) const {
        Macierz* wynik = new Macierz();
        for (int i = 0; i < rozmiar; ++i) {
            for (int j = 0; j < rozmiar; ++j) {
                wynik->tablica[i][j] = this->tablica[i][j] - other.tablica[i][j];
            }
        }
        return wynik;
    }

    bool operator==(const Macierz& other) const {
        for (int i = 0; i < rozmiar; ++i) {
            for (int j = 0; j < rozmiar; ++j) {
                if (this->tablica[i][j] != other.tablica[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Macierz m1, m2;
    std::cout << "Wprowadz dane dla pierwszej macierzy (3x3):" << std::endl;
    std::cin >> m1;
    std::cout << "Wprowadz dane dla drugiej macierzy (3x3):" << std::endl;
    std::cin >> m2;

    std::cout << "Pierwsza macierz:" << std::endl;
    std::cout << m1;
    std::cout << "Druga macierz:" << std::endl;
    std::cout << m2;

    Macierz* suma = *m1 + m2;
    Macierz* roznica = *m1 - m2;

    std::cout << "Suma macierzy:" << std::endl;
    std::cout << *suma;
    std::cout << "Roznica macierzy:" << std::endl;
    std::cout << *roznica;

    if (m1 == m2) {
        std::cout << "Macierze są równe" << std::endl;
    }
    else {
        std::cout << "Macierze nie są równe" << std::endl;
    }

    delete suma;
    delete roznica;

    return 0;
}
