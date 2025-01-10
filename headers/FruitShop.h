#ifndef FRUITSHOP_H
#define FRUITSHOP_H

#include <string>
using namespace std;

class FruitShop {
public:
    struct Fruit {
        string name;
        double price;
        
        Fruit() : name(""), price(0.0) {}

        Fruit(const string& name, double price) : name(name), price(price) {}
    };

private:
    Fruit* fruits;
    int fruitCount;
    int capacity;

    void resize();

public:
    FruitShop();
    ~FruitShop();

    void displayFruits() const;
    int getFruitCount() const;
    const Fruit& getFruit(int index) const;
};

#endif
