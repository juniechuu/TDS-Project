#include "../headers/FruitShop.h"
#include <iostream>
#include <iomanip>

FruitShop::Fruit::Fruit(const std::string& name, double price) : name(name), price(price) {}

FruitShop::FruitShop() {
    fruits.push_back(Fruit("1.Durian 'kampung(1kg)", 8.00));
    fruits.push_back(Fruit("2.Banana (1kg)        ", 4.50));
    fruits.push_back(Fruit("3.Guava(1kg)          ", 6.10));
    fruits.push_back(Fruit("4.Mango(1kg)          ", 6.50));
    fruits.push_back(Fruit("5.Rambutan(1kg)       ", 5.00));
    fruits.push_back(Fruit("6.Mangoesteen(1kg)    ", 8.00));
    fruits.push_back(Fruit("7.'Mata kucing'(1kg)  ", 4.00));
    fruits.push_back(Fruit("8.Papaya(1kg)         ", 3.00));
    fruits.push_back(Fruit("9.Pineapple(1kg)      ", 2.60));
    fruits.push_back(Fruit("10.Watermelon(1kg)    ", 1.80));

}

void FruitShop::displayFruits() const {
    if (fruits.empty()) {
        std::cout << "No fruits available!" << std::endl;
        return;
    }
    std::cout << "\nFruit List:\n";
    std::cout << "--------------------------------------------\n";
    std::cout << std::left << std::setw(20) << "Fruit Name" << std::setw(10) << "Price" << std::endl;
    std::cout << "--------------------------------------------\n";
    for (int i = 0; i < fruits.size(); ++i) {
        std::cout << std::left << std::setw(20) << fruits[i].name << "\t\t" << "RM " << std::setw(10) << fruits[i].price << std::endl;
    }
    std::cout << "--------------------------------------------\n";
}

int FruitShop::getFruitCount() const {
    return fruits.size();
}

const FruitShop::Fruit& FruitShop::getFruit(int index) const {
    return fruits[index];
}
