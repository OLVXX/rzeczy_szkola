#include <iostream>
using namespace std;

float* utworzTablice(int rozmiar) {
    float* tablica = new float[rozmiar];
    return tablica;
}


void wypelnijTablcie(float* tab, int r) {
    cout << "Podaj liczby do tablicy: ";
    for (int i = 0; i < r; i++) {
        cin >> tab[i];
    }
}


int znajdzLiczbe(float* tab, int r) {
    int ileLiczb = 0;
    for (int i = 0; i < r - 1; i++) {
        if (tab[i] == tab[i + 1]) {
            ileLiczb++;
        }
    }
    return ileLiczb;
}

int main() {
    int rozmiar;
    cout << "Podaj rozmiar tablicy: ";
    cin >> rozmiar;
    float* tab = utworzTablice(rozmiar);
    wypelnijTablcie(tab, rozmiar);
    int liczba = znajdzLiczbe(tab, rozmiar);
    cout << "Liczba powtarzajacych sie elementow: " << liczba << endl;
    delete[] tab;
    return 0;
}
