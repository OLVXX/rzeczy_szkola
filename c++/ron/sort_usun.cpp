#include <iostream>

// Funkcja do wyświetlania tablicy
void wyswietlTablice(int* tablica, int rozmiar) {
    std::cout << "Tablica: ";
    for (int i = 0; i < rozmiar; ++i) {
        std::cout << tablica[i] << " ";
    }
    std::cout << std::endl;
}

// Funkcja do sortowania tablicy metodą bąbelkową
void sortujTablice(int* tablica, int& rozmiar) {
    for (int i = 0; i < rozmiar - 1; ++i) {
        for (int j = 0; j < rozmiar - i - 1; ++j) {
            if (tablica[j] > tablica[j + 1]) {
                // Zamiana miejscami
                int temp = tablica[j];
                tablica[j] = tablica[j + 1];
                tablica[j + 1] = temp;
            }
        }
    }

    // Usuwanie powtarzających się liczb
    int j = 0;
    for (int i = 0; i < rozmiar - 1; ++i) {
        if (tablica[i] != tablica[i + 1]) {
            tablica[j++] = tablica[i];
        }
    }
    tablica[j++] = tablica[rozmiar - 1];
    rozmiar = j;
}

int main() {
    int rozmiar;

    std::cout << "Podaj rozmiar tablicy: ";
    std::cin >> rozmiar;

    int* tablica = new int[rozmiar]; // Tworzenie tablicy dynamicznej

    std::cout << "Podaj " << rozmiar << " liczb do tablicy:" << std::endl;
    for (int i = 0; i < rozmiar; ++i) {
        std::cin >> tablica[i];
    }

    wyswietlTablice(tablica, rozmiar); // Wyświetlanie tablicy przed sortowaniem

    sortujTablice(tablica, rozmiar); // Sortowanie tablicy

    wyswietlTablice(tablica, rozmiar); // Wyświetlanie posortowanej i oczyszczonej tablicy

    delete[] tablica; // Zwolnienie pamięci po tablicy

    return 0;
}
