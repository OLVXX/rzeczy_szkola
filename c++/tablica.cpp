#include <iostream>
#include <vector>

int main()
{
	int suma;
	int r;
	std::cout << "Podaj wielkosć tablicy: ";
	std::cin >> r;
	std::vector<int> tab(r);
	for (int i = 0; i < r; i++) {
		std::cout << "Podaj liczbe do tablicy o indeksie " << i << ": ";
		std::cin >> tab[i];
	}
	std::cout << "\nWszystkie liczby w tablicy:\n";
	for (int i = 0; i < r; i++) {
		std::cout << "Indeks " << i << ": Liczba to " << tab[i] << "\n";
		suma =suma+ tab[i];
	}
	suma / r;
	std::cout << suma;
}
