#include <iostream>
#include <fstream>
#include <bitset> 
#include <string>

int main() {
    std::string nazwaPliku;
    std::cout << "Podaj nazwę pliku do odczytu: ";
    std::cin >> nazwaPliku;

    std::ifstream plik(nazwaPliku);

    if (plik.is_open()) {
        std::string linia;
        while (std::getline(plik, linia)) {
            std::bitset<32> bity(linia);
            unsigned long liczba = bity.to_ulong();
            std::cout << liczba << std::endl;
        }
        plik.close();
    }
    else {
        std::cerr << "Nie można otworzyć pliku!" << std::endl;
    }

    return 0;
}
