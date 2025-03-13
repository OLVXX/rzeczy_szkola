
#include <iostream>
float liczba;
float liczba_l(float l) {
    return l * 10;
}
float liczba_x(float x) {
    return x - 10;
}
float liczba_y(float y) {
    return y / 10;
}
int main()
{
 
    std::cin >> liczba;
    int wybor;
    std::cout << " Wybierz opcje :\n 1 liczba *10\n 2 liczba -10\n 3 liczba/10\n";
    std::cin >> wybor;
    if (wybor != 1 && wybor != 2 && wybor != 3) {
        std::cout << "podaj wybor ponownie" << std::endl;
        std::cin >> wybor;
    }
    else {
        switch (wybor) {
        case 1:
            std::cout << liczba_l(liczba);
                break;
        case 2:
            std::cout << liczba_x(liczba);
            break;
        case 3:
            std::cout << liczba_y(liczba);
            break;

        }
    }
}
