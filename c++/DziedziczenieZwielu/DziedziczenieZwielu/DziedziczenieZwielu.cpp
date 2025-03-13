#include <iostream>
#include <string>

class Mezczyzna {
public:
    Mezczyzna(const std::string& imie, int wiek) : imie(imie), wiek(wiek) {}
    std::string getImie() const { return imie; }
    int getWiek() const { return wiek; }

private:
    std::string imie;
    int wiek;
};

class Kobieta {
public:
    Kobieta(const std::string& imie, int wiek) : imie(imie), wiek(wiek) {}
    std::string getImie() const { return imie; }
    int getWiek() const { return wiek; }

private:
    std::string imie;
    int wiek;
};

class Dziecko : public Mezczyzna, public Kobieta {
public:
    Dziecko(const std::string& imieMezczyzny, int wiekMezczyzny, const std::string& imieKobiety, int wiekKobiety, const std::string& imieDziecka, int wiekDziecka)
        : Mezczyzna(imieMezczyzny, wiekMezczyzny), Kobieta(imieKobiety, wiekKobiety), imie(imieDziecka), wiek(wiekDziecka) {
    }

    std::string getImie() const { return imie; }
    int getWiek() const { return wiek; }

    void przedstawRodzicow() const {
        std::cout << "Ojciec: " << Mezczyzna::getImie() << ", Wiek: " << Mezczyzna::getWiek() << std::endl;
        std::cout << "Matka: " << Kobieta::getImie() << ", Wiek: " << Kobieta::getWiek() << std::endl;
    }

private:
    std::string imie;
    int wiek;
};

int main()
{
    Mezczyzna ojciec("Jan", 40);
    Kobieta matka("Anna", 38);
    Dziecko dziecko("Jan", 40, "Anna", 38, "Piotr", 10);

    std::cout << "Dziecko: " << dziecko.getImie() << ", Wiek: " << dziecko.getWiek() << std::endl;
    dziecko.przedstawRodzicow();

    return 0;
}
