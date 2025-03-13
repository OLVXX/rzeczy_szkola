#include <iostream>

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void reverseArray(int* arr, int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int size;
    std::cout << "Podaj rozmiar tablicy: ";
    std::cin >> size;

    int* array = new int[size];
    std::cout << "Podaj elementy tablicy:\n";
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }

    std::cout << "Tablica przed odwróceniem:\n";
    printArray(array, size);

    reverseArray(array, size);

    std::cout << "Tablica po odwróceniu:\n";
    printArray(array, size);

   
    return 0;
}
