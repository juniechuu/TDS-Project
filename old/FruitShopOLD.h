#ifndef FRUITSHOP_H
#define FRUITSHOP_H

#include <string>
#include <vector>

class FruitShop {
public:
    struct Fruit {
        std::string name;
        double price;
        Fruit(const std::string& name, double price);
    };

    FruitShop();
    void displayFruits() const;
    int getFruitCount() const;
    const Fruit& getFruit(int index) const;

private:
    std::vector<Fruit> fruits;
};

#endif // FRUITSHOP_H
