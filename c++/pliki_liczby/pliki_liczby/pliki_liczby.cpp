#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream liczby("liczby.txt");
    ofstream wynik("wynik.txt");

    if (!liczby.is_open()) {
        cout << "Błąd otwarcia pliku." << endl;
        return 1;
    }

    string liczba;
    int zadanie1 = 0;
    int zadanie2 = 0;

    while (liczby >> liczba) {
        int liczbaZer = 0;
        int liczbaJedynek = 0;

        for (char znak : liczba) {
            if (znak == '0') liczbaZer++;
            else liczbaJedynek++;
        }

        if (liczbaZer > liczbaJedynek) {
            zadanie1++;
        }


        if (liczba.back() == '0') {
            zadanie2++;
        }
    }

    wynik << "Zadanie 1: " << zadanie1 << endl;
    wynik << "Zadanie 2: " << zadanie2 << endl;

    liczby.close();
    wynik.close();

    cout << "Wyniki zostały zapisane do pliku wynik.txt" << endl;
    return 0;
}
