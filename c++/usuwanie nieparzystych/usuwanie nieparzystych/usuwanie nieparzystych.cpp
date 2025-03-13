#include <iostream>

int main()

{
    int liczba;
    int cyfry =0;
    printf("Podaj liczbe : ");
    std::cin >> liczba;
    std::cout << "twoja liczba to: " << liczba;
    while (liczba!=0) {
        cyfry++;
        liczba /= 10;
    }
    std::cout << "\ntwoja liczba ma  : " << cyfry<<" cyfr";
    int* tab = new int [cyfry];




}