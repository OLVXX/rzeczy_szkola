#include <iostream>
#include <string>
#include <ctime>

class Przypomnienie {
private:
    int rok, miesiac, dzien;
    std::string tresc;

public:
    Przypomnienie() {
        std::time_t teraz = std::time(0);
        std::tm lokalnyCzas;
        localtime_s(&lokalnyCzas, &teraz);
        rok = 1900 + lokalnyCzas.tm_year;
        miesiac = 1 + lokalnyCzas.tm_mon;
        dzien = lokalnyCzas.tm_mday;
        tresc = "";
    }

    Przypomnienie(int r, int m, int d) : rok(r), miesiac(m), dzien(d), tresc("") {}

    Przypomnienie(const Przypomnienie& inne) {
        rok = inne.rok;
        miesiac = inne.miesiac;
        dzien = inne.dzien;
        tresc = inne.tresc;
    }

    void zapiszWiadomosc(const std::string& nowaTresc) {
        tresc = nowaTresc;
    }

    void wypisz() const {
        std::cout << "Data: " << rok << "-" << miesiac << "-" << dzien << std::endl;
        std::cout << "Przypomnienie: " << tresc << std::endl;
    }
};

int main() {
    Przypomnienie obiekt1;
    std::cout << "Obiekt 1 (statycznie):" << std::endl;
    obiekt1.wypisz();

    Przypomnienie* obiekt2 = new Przypomnienie(2025, 3, 11);
    std::cout << "Obiekt 2 (dynamicznie):" << std::endl;
    obiekt2->wypisz();

    std::string wiadomosc1, wiadomosc2;
    std::cout << "Podaj wiadomość dla obiektu 1: ";
    std::getline(std::cin, wiadomosc1);
    obiekt1.zapiszWiadomosc(wiadomosc1);

    std::cout << "Podaj wiadomość dla obiektu 2: ";
    std::getline(std::cin, wiadomosc2);
    obiekt2->zapiszWiadomosc(wiadomosc2);

    std::cout << "\nObiekt 1 po dodaniu wiadomości:" << std::endl;
    obiekt1.wypisz();

    std::cout << "\nObiekt 2 po dodaniu wiadomości:" << std::endl;
    obiekt2->wypisz();

    Przypomnienie obiekt3 = obiekt1;
    std::cout << "\nObiekt 3 (kopia obiektu 1):" << std::endl;
    obiekt3.wypisz();

    std::string wiadomosc3;
    std::cout << "Podaj dodatkową wiadomość dla obiektu 3: ";
    std::getline(std::cin, wiadomosc3);
    obiekt3.zapiszWiadomosc(wiadomosc3);

    std::cout << "\nObiekt 3 po dodaniu nowej wiadomości:" << std::endl;
    obiekt3.wypisz();

    delete obiekt2;

    return 0;
}
