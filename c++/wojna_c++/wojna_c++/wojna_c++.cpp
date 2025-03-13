#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, int> cardValues;

    cardValues["2"] = 2;
    cardValues["3"] = 3;
    cardValues["4"] = 4;
    cardValues["5"] = 5;
    cardValues["6"] = 6;
    cardValues["7"] = 7;
    cardValues["8"] = 8;
    cardValues["9"] = 9;
    cardValues["J"] = 11; 
    cardValues["Q"] = 12;
    cardValues["K"] = 13;
    cardValues["Joker"] = 14;

    std::string card = "J";
    int numericValue = cardValues[card];

    std::cout << "Numeric value of " << card << ": " << numericValue << std::endl;

    return 0;
}
