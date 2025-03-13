#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string word = "Hello";
    std::vector<char> letters;

    for (char c : word) {
        letters.push_back(c);
    }

    // Print the letters
    for (char c : letters) {
        std::cout << c << std::endl;
    }

    return 0;
}
