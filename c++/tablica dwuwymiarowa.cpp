#include <iostream>
using namespace std;

int main() {
    int tablica[3][4];
    int liczba, ile_wystapien = 0;

    cout << "Podaj 12 liczb do tablicy 3x4:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> tablica[i][j];
        }
    }

    cout << "Tablica\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << tablica[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Jaką liczbę chcesz wyszukać?\n";
    cin >> liczba;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (tablica[i][j] == liczba) {
                ile_wystapien++;
            }
        }
    }

    if (ile_wystapien > 0) {
        cout << "Liczba " << liczba << " występuje " << ile_wystapien << " razy.\n";
    }
    else {
        cout << "Liczba " << liczba << " nie występuje w tablicy.\n";
    }

    return 0;
}
