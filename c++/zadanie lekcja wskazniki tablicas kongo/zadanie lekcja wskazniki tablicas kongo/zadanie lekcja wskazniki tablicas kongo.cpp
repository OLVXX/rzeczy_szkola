#include <iostream>
#include <vector>

std::vector<float>* funkcja(int rozmiar, float* srednia) {
    std::vector<float>* tablica = new std::vector<float>(rozmiar);
    float suma = 0.0;

    for (int i = 0; i < rozmiar; i++) {
        std::cout << "Podaj liczbę " << i + 1 << ":\n";
        std::cin >> (*tablica)[i];
        suma += (*tablica)[i];
    }

    *srednia = suma / rozmiar;
    return tablica;
}

int main() {
    int rozmiar;
    float srednia;

    std::cout << "Podaj rozmiar tablicy:\n";
    std::cin >> rozmiar;

    std::vector<float>* tablica = funkcja(rozmiar, &srednia);

    std::cout << "W tablicy są następujące liczby:\n";
    for (int i = 0; i < rozmiar; i++) {
        std::cout << (*tablica)[i] << " ";
    }

    std::cout << "\nŚrednia wynosi: " << srednia << "\n";
    std::cout << "Wskaźnik na tablicę to: " << tablica << "\n";

    delete tablica;
    return 0;
}
