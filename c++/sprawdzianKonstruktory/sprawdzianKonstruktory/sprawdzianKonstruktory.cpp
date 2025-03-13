#include <iostream>
#include <string>


class Ksiazka {
private:
    std::string tytul;
    std::string autor;
    int rokWydania;
    int numerEgzemplarza;

public:
    Ksiazka() : tytul(""), autor(""), rokWydania(0), numerEgzemplarza(0) {}

    Ksiazka(std::string tytul, std::string autor, int rokWydania, int numerEgzemplarza)
        : tytul(tytul), autor(autor), rokWydania(rokWydania), numerEgzemplarza(numerEgzemplarza) {}

    Ksiazka(const Ksiazka& other)
        : tytul(other.tytul), autor(other.autor), rokWydania(other.rokWydania), numerEgzemplarza(other.numerEgzemplarza) {}

    ~Ksiazka() {
        std::cout << "Obiekt usunieto z pamieci" << std::endl;
    }

    void Wypisz() const {
        std::cout << "Tytul: " << tytul << ", Autor: " << autor << ", Rok wydania: " << rokWydania
            << ", Numer egzemplarza: " << numerEgzemplarza << std::endl;
    }

    void UstawNumerEgzemplarza(int nowyNumer) {
        numerEgzemplarza = nowyNumer;
    }
};

int main() {
    Ksiazka ksiazka1("Harry Poter", "J.K Rowling", 2000, 1);
    ksiazka1.Wypisz();

    Ksiazka ksiazka2 = ksiazka1;
    ksiazka2.Wypisz();

    Ksiazka* ksiazka3 = new Ksiazka();
    ksiazka3->Wypisz();

    ksiazka1.UstawNumerEgzemplarza(2);

    std::cout << "\nPo zmianie numeru egzemplarza w pierwszej ksiazce:\n";
    ksiazka1.Wypisz();
    ksiazka2.Wypisz();
    ksiazka3->Wypisz();

    delete ksiazka3;

    return 0;
}
