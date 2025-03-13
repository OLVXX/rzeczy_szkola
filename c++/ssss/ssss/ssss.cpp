#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

// Funkcja do sortowania znaków w słowie
std::string sortWord(const std::string& word) {
    std::string sortedWord = word;
    std::sort(sortedWord.begin(), sortedWord.end());
    return sortedWord;
}

int main() {
    std::ifstream file("anagram.txt");
    if (!file) {
        std::cerr << "Nie można otworzyć pliku 'anagram.txt'" << std::endl;
        return 1;
    }

    std::map<std::string, std::vector<std::string>> anagramDict;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string word;

        while (iss >> word) {
            std::string sortedWord = sortWord(word);
            anagramDict[sortedWord].push_back(word);
        }
    }

    file.close();

    for (const auto& pair : anagramDict) {
        const std::vector<std::string>& anagrams = pair.second;
        if (anagrams.size() > 1) {
            std::cout << "Anagramy: ";
            for (size_t i = 0; i < anagrams.size(); ++i) {
                std::cout << anagrams[i];
                if (i < anagrams.size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
