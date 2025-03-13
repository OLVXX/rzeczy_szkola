#include <iostream>

int main() {

	int koniec_programu;
	while (koniec_programu ==1) {
		int opcja;
		std::cout << "Wybierz opcje\n 1 dodawanie\n 2 odejmowanie\n 3 mnozenie\n 4 dzielenie\n 5 modulo\n 0 zamknij program";
			int a, b;
			std::cout << "Podaj liczbe a : \n";
			std::cin >> a;
			std::cout << "Podaj liczbe b : \n";
			std::cin >> b;
			switch (opcja) {

			case 1:
				int wynik_dodawanie;
				wynik_dodawanie = a + b;
				std::cout << "Wynik dodawania wynosi " << wynik_dodawanie << "\n";
				std::cout << "jesli chcesz kontynuowac dzialanie programu kliknij 1 \n";
				std::cin >> koniec_programu;
				break;
			case 2:
				int wynik_odejmowania;
				wynik_odejmowania = a - b;
				std::cout << "Wynik odejmowania wynosi " << wynik_odejmowania << "\n";
				std::cout << "jesli chcesz kontynuowac dzialanie programu kliknij 1" << "\n";
				std::cin >> koniec_programu;
				break;

			case 3:
				int wynik_mnożenia;
				wynik_mnożenia = a * b;
				std::cout << "Wynik mnozenia wynosi " << wynik_mnożenia << "\n";
				std::cout << "jesli chcesz kontynuowac dzialanie programu kliknij 1" << "\n";
				std::cin >> koniec_programu;
				break;

			case 4:
				if (a > 0 && b > 0) {
					int wynik_dzielenia;
					wynik_dzielenia = a / b;
					std::cout << "Wynik dzielenia wynosi " << wynik_dzielenia << "\n";
					std::cout << "jesli chcesz kontynuowac dzialanie programu kliknij 1" << "\n";
					std::cin >> koniec_programu;
					break;
				}
				else {
					std::cout << "Nie mozna dzielic przez zero" << "\n";
				}

			case 5:
				if (a > 0 && b > 0) {
					int wynik_modulo;
					wynik_modulo = a % b;
					std::cout << "Wynik dzielenia z resztą wynosi " << wynik_modulo << "\n";
					std::cout << "jesli chcesz kontynuowac dzialanie programu kliknij 1" << "\n";
					std::cin >> koniec_programu;
					break;
				}
				else {
					std::cout << "Nie mozna dzielic przez zero" << "\n";

				}
			}
		}
	}

