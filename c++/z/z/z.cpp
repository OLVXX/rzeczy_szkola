#include <iostream>

bool isNumberInArray(int* array, int size, int number) {
    for (int i = 0; i < size; i++) {
        if (array[i] == number) {
            return true;
        }
    }
    return false;
}

int main() {
    int size;
    std::cout << "Podaj rozmiar tablicy: ";
    std::cin >> size;

    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        int number;
        do {
            std::cout << "Podaj liczbę dla indeksu " << i << ": ";
            std::cin >> number;
        } while (isNumberInArray(array, i, number));
        array[i] = number;
    }

    std::cout << "Tablica z unikalnymi liczbami: ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }

    delete[] array;

    return 0;
}
