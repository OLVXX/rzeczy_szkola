#include <iostream>
using namespace std;

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

    void wczytajDane() {
        cout << "Wprowadz elementy macierzy 3x3:" << endl;
        for (int i = 0; i < rozmiar; ++i) {
            for (int j = 0; j < rozmiar; ++j) {
                cout << "Element [" << i << "][" << j << "]: ";
                cin >> tablica[i][j];
            }
        }
    }

    void wypisz() const {
        for (int i = 0; i < rozmiar; ++i) {
            for (int j = 0; j < rozmiar; ++j) {
                cout << tablica[i][j] << "\t";
            }
            cout << endl;
        }
    }

    friend Macierz* dodajMacierze(const Macierz& m1, const Macierz& m2);
};

Macierz* dodajMacierze(const Macierz& m1, const Macierz& m2) {
    Macierz* wynik = new Macierz();
    for (int i = 0; i < Macierz::rozmiar; ++i) {
        for (int j = 0; j < Macierz::rozmiar; ++j) {
            wynik->tablica[i][j] = m1.tablica[i][j] + m2.tablica[i][j];
        }
    }
    return wynik;
}

int main() {
    Macierz* macierz1 = new Macierz();
    Macierz* macierz2 = new Macierz();

    cout << "Macierz 1:" << endl;
    macierz1->wczytajDane();
    cout << "Macierz 2:" << endl;
    macierz2->wczytajDane();

    cout << "Zawartosc macierzy 1:" << endl;
    macierz1->wypisz();
    cout << "Zawartosc macierzy 2:" << endl;
    macierz2->wypisz();

    Macierz* sumaMacierzy = dodajMacierze(*macierz1, *macierz2);
    cout << "Suma macierzy:" << endl;
    sumaMacierzy->wypisz();

    delete macierz1;
    delete macierz2;
    delete sumaMacierzy;

    return 0;
}
