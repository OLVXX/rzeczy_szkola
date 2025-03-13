#include <iostream>
#include <cstdlib>
#include <ctime>
int main()
{
	/* zad 1
	float a;
	float b;
	std::cout << "Podaj a : ";
	std::cin >> a;
	std::cout << "Podaj b : ";
	std::cin >> b;
	float wynik = a * b;
	std::cout << "wynik wynosi: "<<wynik;
	*/
	
	/* zad 2
	float r;
	std::cout << "podaj promien ";
	std::cin >> r;
	float objetosc_kuli = (4 / 3) * 3.14159*r*r*r;
	std::cout << "objetosc kuli wynosi: " << objetosc_kuli;
	*/
	
	/*zad3
	float a;
	float b;
	std::cout << "Podaj a : ";
	std::cin >> a;
	std::cout << "Podaj b : ";
	std::cin >> b;
	if (a > b) {
		std::cout << b << " "<< a;
	}
	if(b>a){
		std::cout << a << " " << b;
	}
	if (a==b){
		std::cout << "liczby sa rowne";
	}
	*/
	
	/*zad 4
	float a;
	float b;
	std::cout << "Podaj a : ";
	std::cin >> a;
	std::cout << "Podaj b : ";
	std::cin >> b;
	float suma = a + b;
	float roznica = a - b;
	if (suma>roznica)
	{
		std::cout << "suma wieksza od roznicy";
	}
	if (suma < roznica)
	{
		std::cout << "suma mniejsza od roznicy";
	}
	if (suma == roznica)
	{
		std::cout << "suma jest rowna roznicy";
	}
	*/
	std::cout << " Wybierz : \n 1 papier \n 2 kamien \n 3 nozyce \n";
	srand(0);
	int wybor;
	int los;
	std::cin >> wybor;
	los  = rand() % 3 + 1;
	std::cout << los;
	if (wybor = 1) {
		std::cout << "Wygrywasz komputer wybral kamien";
	}
	if (wybor = 2) {
		std::cout << "Przegrywasz komputer wybral kamien";
	}
	if (wybor = 3) {
		std::cout << "Remis komputer tez wybral kamien";
	}
}