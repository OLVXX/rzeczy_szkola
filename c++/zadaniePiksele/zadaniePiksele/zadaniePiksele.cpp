#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("dane.txt");
    if (!file.is_open()) {
        std::cout << "Nie mozna otworzyc pliku!" << std::endl;
        return 1;
    }

    int max_brightness = -1;
    int min_brightness = 256;
    int max_line = 0, min_line = 0;
    int current_line = 0;
    int value;

    while (!file.eof()) {
        ++current_line;
        for (int i = 0; i < 320; ++i) {
            file >> value;
            if (file.fail()) break;
            if (value > max_brightness) {
                max_brightness = value;
                max_line = current_line;
            }
            if (value < min_brightness) {
                min_brightness = value;
                min_line = current_line;
            }
        }
    }

    std::cout << "Najjasniejszy piksel: " << max_brightness << " w linii " << max_line << std::endl;
    std::cout << "Najciemniejszy piksel: " << min_brightness << " w linii " << min_line << std::endl;

    file.close();
    return 0;
}
