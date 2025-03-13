#include <iostream>
#include <string>

struct Student {
    std::string imie;
    std::string nazwisko;
    int numer;
};

int main() {
    int liczba_uczniow;
    std::cout << "Ile jest uczniów w klasie? ";
    std::cin >> liczba_uczniow;

    Student* klasa = new Student[liczba_uczniow];

    for (int i = 0; i < liczba_uczniow; i++) {
        std::cout << "Podaj imię ucznia: ";
        std::cin >> klasa[i].imie;
        std::cout << "Podaj nazwisko ucznia: ";
        std::cin >> klasa[i].nazwisko;
        std::cout << "Podaj numer ucznia w dzienniku: ";
        std::cin >> klasa[i].numer;
    }

    delete[] klasa;

    return 0;
}
