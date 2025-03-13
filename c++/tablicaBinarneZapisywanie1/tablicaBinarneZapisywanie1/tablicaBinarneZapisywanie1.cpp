#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <bitset>

int main() {
    srand(static_cast<unsigned>(time(0)));

    int rozmiar;
    std::cout << "Podaj rozmiar tablicy: ";
    std::cin >> rozmiar;

    int* tablica = new int[rozmiar];

    for (int i = 0; i < rozmiar; i++) {
        tablica[i] = rand() % 100;
    }

    std::ofstream plik("dane.txt");

    if (plik.is_open()) {
        for (int i = 0; i < rozmiar; i++) {
            plik << std::bitset<32>(tablica[i]) << std::endl; 
        }
        std::cout << "Liczby zostały zapisane do pliku 'dane.txt' w formacie binarnym." << std::endl;
    }
    else {
        std::cerr << "Nie można otworzyć pliku do zapisu!" << std::endl;
    }

    plik.close();
    delete[] tablica;

    return 0;
}
