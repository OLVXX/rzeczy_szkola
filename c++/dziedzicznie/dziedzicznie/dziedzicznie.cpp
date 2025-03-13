#include <iostream>

class Ksztalt {
public:
    virtual void rysuj() const {
        std::cout << "Rysowanie kształtu" << std::endl;
    }
};

class Kolo : public Ksztalt {
public:
    void rysuj() const override {
        std::cout << "Rysowanie koła" << std::endl;
    }
};

class Prostokat : public Ksztalt {
public:
    void rysuj() const override {
        std::cout << "Rysowanie prostokąta" << std::endl;
    }
};

class Wektor2D {
public:
    float x, y;

    Wektor2D(float x = 0, float y = 0) : x(x), y(y) {}

    Wektor2D operator+(const Wektor2D& inny) const {
        return Wektor2D(x + inny.x, y + inny.y);
    }

    Wektor2D operator-(const Wektor2D& inny) const {
        return Wektor2D(x - inny.x, y - inny.y);
    }

    void wypisz() const {
        std::cout << "Wektor(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Ksztalt* ksztalty[2];
    ksztalty[0] = new Kolo();
    ksztalty[1] = new Prostokat();

    for (int i = 0; i < 2; ++i) {
        ksztalty[i]->rysuj();
    }

    Wektor2D w1(1.0f, 2.0f);
    Wektor2D w2(3.0f, 4.0f);
    Wektor2D w3 = w1 + w2;
    Wektor2D w4 = w1 - w2;

    w3.wypisz();
    w4.wypisz();

    delete ksztalty[0];
    delete ksztalty[1];

    return 0;
}
