#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <string>
using namespace std;

// Definicja tablic numery i kolory
string numery[14] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K","A" };
string kolory[4] = { "Pik", "Kier", "Karo", "Trefl" };

int main() {
    srand(time(NULL));
    string talia[56];

    cout << "Podaj budżet : " << endl;
    int budzet_gracza;
    cin >> budzet_gracza;
    int budzet_krupiera = budzet_gracza;
    cout << "Budżet gracza i krupiera wynosi : " << budzet_gracza << endl;
    do {
        int stawka;
        cout << "Podaj stawkę, za którą grasz w tej rundzie (minimalna stawka: 50): " << endl;
        cin >> stawka;

        while (stawka < 50 || stawka > budzet_gracza || stawka > budzet_krupiera) {
            cout << "Nieprawidłowa stawka. Podaj stawkę od 50 do " << min(budzet_gracza, budzet_krupiera) << ": ";
            cin >> stawka;
        }

        string kartyGracza[10]; // zwiększenie rozmiaru tablicy, aby pomieścić więcej kart w przypadku wielokrotnego dobierania
        string kartyKrupiera[10];
        int indeksGracza = 2; // indeks początkowy dla kolejnych kart gracza
        int indeksKrupiera = 2; // indeks początkowy dla kolejnych kart krupiera

        int losowanieGracznumery = rand() % 14;
        int losowanieGraczkolory = rand() % 4;
        kartyGracza[0] = numery[losowanieGracznumery] + " " + kolory[losowanieGraczkolory];
        losowanieGracznumery = rand() % 14;
        losowanieGraczkolory = rand() % 4;
        kartyGracza[1] = numery[losowanieGracznumery] + " " + kolory[losowanieGraczkolory];

        int losowanieKrupiernumery = rand() % 14;
        int losowanieKrupierkolory = rand() % 4;
        kartyKrupiera[0] = numery[losowanieKrupiernumery] + " " + kolory[losowanieKrupierkolory];
        losowanieKrupiernumery = rand() % 14;
        losowanieKrupierkolory = rand() % 4;
        kartyKrupiera[1] = numery[losowanieKrupiernumery] + " " + kolory[losowanieKrupierkolory];

        cout << "Karty gracza: " << kartyGracza[0] << ", " << kartyGracza[1] << endl;
        cout << "Karty krupiera: " << kartyKrupiera[0] << ", " << kartyKrupiera[1] << endl;

        int suma_punktow_gracza = 0;
        int suma_punktow_krupiera = 0;

        suma_punktow_gracza += stoi(numery[losowanieGracznumery]);
        suma_punktow_gracza += stoi(numery[losowanieGraczkolory]);

        suma_punktow_krupiera += stoi(numery[losowanieKrupiernumery]);
        suma_punktow_krupiera += stoi(numery[losowanieKrupierkolory]);

        if (suma_punktow_gracza == 21) {
            cout << "Blackjack! Gratulacje, wygrywasz!" << endl;
            budzet_gracza += stawka * 1.5;
            budzet_krupiera -= stawka * 1.5;
            cout << "Budżet gracza: " << budzet_gracza << endl;
            cout << "Budżet krupiera: " << budzet_krupiera << endl;
            return 0;
        }
        else if (suma_punktow_krupiera == 21) {
            cout << "Krupier ma Blackjacka! Przegrałeś!" << endl;
            budzet_gracza -= stawka;
            budzet_krupiera += stawka;
            cout << "Budżet gracza: " << budzet_gracza << endl;
            cout << "Budżet krupiera: " << budzet_krupiera << endl;
            return 0;
        }

        cout << "Minimalna stawka: 50" << endl;
        cout << "Podaj stawkę, za którą grasz w tej rundzie (minimalna stawka: 50)" << endl;

        while (stawka < 50 || stawka > budzet_gracza || stawka > budzet_krupiera) {
            cout << "Nieprawidłowa stawka. Podaj stawkę od 50 do " << min(budzet_gracza, budzet_krupiera) << ": ";
            cin >> stawka;
        }

        string newCard;
        bool koniec = false;

        while (!koniec) {
            cout << "wybierz opcję :\n 1 hit \n 2 stand \n 3 double down \n 4 split " << endl;
            int opcja;
            cin >> opcja;

            switch (opcja) {
            case 1: // hit
                losowanieGracznumery = rand() % 14;
                losowanieGraczkolory = rand() % 4;
                newCard = numery[losowanieGracznumery] + " " + kolory[losowanieGraczkolory];
                cout << "Dobierasz: " << newCard << endl;
                kartyGracza[indeksGracza++] = newCard;
                suma_punktow_gracza += stoi(numery[losowanieGracznumery]);
                if (suma_punktow_gracza > 21) {
                    cout << "Przegrałeś! Przekroczyłeś 21 punktów." << endl;
                    budzet_gracza -= stawka;
                    budzet_krupiera += stawka;
                    koniec = true;
                }
                break;
            case 2: // stand
                cout << "Wybrałeś stand." << endl;
                koniec = true;
                break;
            case 3: // double down
                stawka *= 2;
                cout << "Wybrałeś double down. Twój nowy zakład to: " << stawka << ". Dobierasz: " << newCard << endl;
                losowanieGracznumery = rand() % 14;
                losowanieGraczkolory = rand() % 4;
                newCard = numery[losowanieGracznumery] + " " + kolory[losowanieGraczkolory];
                kartyGracza[indeksGracza++] = newCard;
                suma_punktow_gracza += stoi(numery[losowanieGracznumery]);
                if (suma_punktow_gracza > 21) {
                    cout << "Przegrałeś! Przekroczyłeś 21 punktów." << endl;
                    budzet_gracza -= 2 * stawka;
                    budzet_krupiera += 2 * stawka;
                    koniec = true;
                }
                break;
            case 4: // split
                cout << "Nie możesz podzielić, ponieważ twoje karty nie są takie same." << endl;
                break;
            default:
                cout << "Nieprawidłowa opcja. Wybierz ponownie." << endl;
                break;
            }
        }

        while (suma_punktow_krupiera < 17 && !koniec) {
            losowanieKrupiernumery = rand() % 14;
            losowanieKrupierkolory = rand() % 4;
            newCard = numery[losowanieKrupiernumery] + " " + kolory[losowanieKrupierkolory];
            cout << "Krupier dobiera: " << newCard << endl;
            kartyKrupiera[indeksKrupiera++] = newCard;
            suma_punktow_krupiera += stoi(numery[losowanieKrupiernumery]);
        }

        // Sprawdzenie wyników
        if (suma_punktow_gracza == suma_punktow_krupiera) {
            cout << "Remis!" << endl;
        }
        else if (suma_punktow_gracza > 21 || (suma_punktow_krupiera <= 21 && suma_punktow_krupiera > suma_punktow_gracza)) {
            cout << "Przegrałeś!" << endl;
            budzet_gracza -= stawka;
            budzet_krupiera += stawka;
        }
        else {
            cout << "Wygrałeś!" << endl;
            budzet_gracza += stawka;
            budzet_krupiera -= stawka;
        }

        cout << "Budżet gracza: " << budzet_gracza << endl;
        cout << "Budżet krupiera: " << budzet_krupiera << endl;
    }
    while (budzet_gracza > 50);
    cout << "Czy chcesz zagrać kolejną rundę? (tak/nie): ";
    string decyzja;
    cin >> decyzja;
    if (decyzja == "tak") {
        main();
    }
    else {
        cout << "Dziękujemy za grę! Życzymy miłego dnia!" << endl;
    }

    return 0;
}
