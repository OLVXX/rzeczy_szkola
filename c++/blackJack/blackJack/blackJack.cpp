#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <string>
#include <map>

std::map<std::string, int> numerosWartoscios = {
    {"2", 2},
    {"3", 3},
    {"4", 4},
    {"5", 5},
    {"6", 6},
    {"7", 7},
    {"8", 8},
    {"9", 9},
    {"10", 10},
    {"J", 10},
    {"Q", 10},
    {"K", 10},
    {"A", 11}
};

std::string numery[13] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K","A" };
std::string kolory[4] = { "Pik", "Kier", "Karo", "Trefl" };

int as_count_gracz = 0;
int as_count_krupier = 0;

int losuj(std::string* tab, int* licznik, bool gracz = true);

int main() {
    srand((unsigned int)time(NULL)); // Rzutowanie na unsigned int
    std::string talia[52];
    std::cout << "Podaj budzet: ";
    int budzet_gracza;
    std::cin >> budzet_gracza;
    int budzet_krupiera = budzet_gracza;
    std::cout << "Budzet gracza i krupiera wynosi: " << budzet_gracza << std::endl;
    double minimalna_stawka = std::round(0.05 * budzet_gracza);

    std::string karty_gracza[10];
    std::string karty_krupiera[10];

    while (budzet_gracza > 0 && budzet_krupiera > 0) {
        int stawka;
        std::cout << "Podaj stawke, za ktora grasz w tej rundzie (minimalna stawka: " << minimalna_stawka << "): ";
        std::cin >> stawka;

        while (stawka < minimalna_stawka || stawka > budzet_gracza || stawka > budzet_krupiera) {
            std::cout << "Nieprawidlowa stawka. Podaj stawke od " << minimalna_stawka << " do " << std::min(budzet_gracza, budzet_krupiera) << ": ";
            std::cin >> stawka;
        }

        int index_gracza = 0;
        int index_krupiera = 0;

        int suma_punktow_gracza = 0;
        int suma_punktow_krupiera = 0;

        suma_punktow_gracza += losuj(karty_gracza, &index_gracza);
        suma_punktow_gracza += losuj(karty_gracza, &index_gracza);

        suma_punktow_krupiera += losuj(karty_krupiera, &index_krupiera, false);
        suma_punktow_krupiera += losuj(karty_krupiera, &index_krupiera, false);

        std::cout << "Karty gracza: " << karty_gracza[0] << ", " << karty_gracza[1] << std::endl;
        std::cout << "Karty krupiera: " << karty_krupiera[0] << ", " << karty_krupiera[1] << std::endl;

        bool koniec = false;

        budzet_gracza -= stawka;

        while (!koniec) {
            std::cout << "Wybierz opcję:\n 1. Hit \n 2. Stand \n 3. Double down \n 4. Split" << std::endl;
            int opcja;
            std::cin >> opcja;
            switch (opcja) {
            case 1: // hit
                suma_punktow_gracza += losuj(karty_gracza, &index_gracza);
                std::cout << "Dobierasz: " << karty_gracza[index_gracza - 1] << std::endl;
                if (suma_punktow_gracza > 21) {
                    if (as_count_gracz > 0) {
                        suma_punktow_gracza -= 10;
                        as_count_gracz--;
                    }
                    koniec = true;
                }
                break;
            case 2: // stand
                std::cout << "Wybrales stand." << std::endl;
                koniec = true;
                break;
            case 3: // double down
                if (stawka > budzet_gracza) {
                    std::cout << "Nie stac cie \n";
                    break;
                }
                budzet_gracza -= stawka;
                stawka *= 2;
                std::cout << "Wybrales double down. Twoj nowy zaklad to: " << stawka << ". Dobierasz: ";
                suma_punktow_gracza += losuj(karty_gracza, &index_gracza);
                std::cout << karty_gracza[index_gracza - 1] << std::endl;
                if (suma_punktow_gracza > 21) {
                    if (as_count_gracz > 0) {
                        suma_punktow_gracza -= 10;
                        as_count_gracz--;
                    }
                    koniec = true;
                }
                break;
            case 4: // split
                if (karty_gracza[0][0] == karty_gracza[1][0]) {
                    std::cout << "Podwoiłeś karty! Twój nowy zakład to: " << 2 * stawka << ". Dobierasz dla pierwszej karty: ";
                    suma_punktow_gracza += losuj(karty_gracza, &index_gracza);
                    std::cout << karty_gracza[index_gracza - 1] << std::endl;
                    std::cout << "Dobierasz dla drugiej karty: ";
                    suma_punktow_gracza += losuj(karty_gracza, &index_gracza);
                    std::cout << karty_gracza[index_gracza - 1] << std::endl;
                }
                else {
                    std::cout << "Nie mozesz podzielic, poniewaz twoje karty nie sa takie same." << std::endl;
                }
                break;
            default:
                std::cout << "Nieprawidlowa opcja. Wybierz ponownie." << std::endl;
                break;
            }
            if (suma_punktow_krupiera > 21) {
                if (as_count_krupier > 0) {
                    suma_punktow_krupiera -= 10;
                    as_count_krupier--;
                }
                else {
                    koniec = true;
                }
            }
            if (suma_punktow_krupiera < 17) {
                suma_punktow_krupiera += losuj(karty_krupiera, &index_krupiera, false);
                std::cout << "Krupier dobiera: " << karty_krupiera[index_krupiera - 1] << std::endl;
            }
        }

        if (suma_punktow_gracza == suma_punktow_krupiera) {
            std::cout << "Remis!" << std::endl;
            budzet_gracza += stawka;
        }
        else if (suma_punktow_gracza > 21 || (suma_punktow_krupiera <= 21 && suma_punktow_krupiera > suma_punktow_gracza)) {
            if (as_count_gracz > 0) {
                suma_punktow_gracza -= 10;
                as_count_gracz--;
            }
            if (suma_punktow_gracza > 21 || (suma_punktow_krupiera <= 21 && suma_punktow_krupiera > suma_punktow_gracza)) {
                budzet_krupiera += stawka;
                std::cout << "Przegrales!" << std::endl;
            }
            else {
                std::cout << "Wygrales!" << std::endl;
                budzet_gracza += stawka * 2;
                budzet_krupiera -= stawka;
            }
        }
        else {
            std::cout << "Wygrales!" << std::endl;
            budzet_gracza += stawka * 2;
            budzet_krupiera -= stawka;
        }

        std::cout << "Budzet gracza: " << budzet_gracza << std::endl;
        std::cout << "Budzet krupiera: " << budzet_krupiera << std::endl;

        if (budzet_gracza < minimalna_stawka || budzet_krupiera < minimalna_stawka) {
            return 0;
        }

        std::cout << "Czy chcesz zagrac kolejna runde? (tak/nie): ";
        std::string decyzja;
        std::cin >> decyzja;
        if (decyzja != "tak") {
            std::cout << "Dziekujemy za gre! Zyczymy milego dnia!" << std::endl;
            return 0;
        }
    }
    return 0;
}

int losowanie_numery;
int losowanie_kolory;

int losuj(std::string* tab, int* licznik, bool gracz) {
    losowanie_numery = rand() % 13;
    losowanie_kolory = rand() % 4;
    if (losowanie_numery == 12) {
        if (gracz) {
            as_count_gracz++;
        }
        else {
            as_count_krupier++;
        }
    }
    tab[*licznik] = numery[losowanie_numery] + " " + kolory[losowanie_kolory];
    *licznik += 1;
    return numerosWartoscios[numery[losowanie_numery]];
}

