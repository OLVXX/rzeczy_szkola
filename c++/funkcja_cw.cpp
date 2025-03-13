#include <iostream>
#include <cstdlib>
#include <ctime>


void wypelnijTablice(int tablica[], const int rozmiar) {
    for (int i = 0; i < rozmiar; ++i) {
        tablica[i] = rand() % 100; 
    }
}

int znajdzMax(const int tablica[], const int rozmiar) {
    int max = tablica[0];
    for (int i = 1; i < rozmiar; ++i) {
        if (tablica[i] > max) {
            max = tablica[i];
        }
    }
    return max;
}

int znajdzMin(const int tablica[], const int rozmiar) {
    int min = tablica[0];
    for (int i = 1; i < rozmiar; ++i) {
        if (tablica[i] < min) {
            min = tablica[i];
        }
    }
    return min;
}

double obliczSrednia(const int tablica[], const int rozmiar) {
    int suma = 0;
    for (int i = 0; i < rozmiar; ++i) {
        suma += tablica[i];
    }
    return static_cast<double>(suma) / rozmiar;
}

int main() {
    const int ROZMIAR_TABLICY = 5;
    int tablica[ROZMIAR_TABLICY];

    srand(static_cast<unsigned>(time(nullptr)));

    wypelnijTablice(tablica, ROZMIAR_TABLICY);

    std::cout << "Tablica losowych liczb:\n";
    for (int i = 0; i < ROZMIAR_TABLICY; ++i) {
        std::cout << tablica[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Maksimum: " << znajdzMax(tablica, ROZMIAR_TABLICY) << "\n";
    std::cout << "Minimum: " << znajdzMin(tablica, ROZMIAR_TABLICY) << "\n";
    std::cout << "Średnia: " << obliczSrednia(tablica, ROZMIAR_TABLICY) << "\n";

    return 0;
}
