#include "../headers/FruitShop.h"
#include <iostream>
#include <iomanip>
using namespace std;

FruitShop::FruitShop() {
    capacity = 10;
    fruitCount = 0;
    fruits = new Fruit[capacity];

    fruits[fruitCount++] = Fruit("1.Durian 'kampung(1kg)", 8.00);
    fruits[fruitCount++] = Fruit("2.Banana (1kg)        ", 4.50);
    fruits[fruitCount++] = Fruit("3.Guava(1kg)          ", 6.10);
    fruits[fruitCount++] = Fruit("4.Mango(1kg)          ", 6.50);
    fruits[fruitCount++] = Fruit("5.Rambutan(1kg)       ", 5.00);
    fruits[fruitCount++] = Fruit("6.Mangoesteen(1kg)    ", 8.00);
    fruits[fruitCount++] = Fruit("7.'Mata kucing'(1kg)  ", 4.00);
    fruits[fruitCount++] = Fruit("8.Papaya(1kg)         ", 3.00);
    fruits[fruitCount++] = Fruit("9.Pineapple(1kg)      ", 2.60);
    fruits[fruitCount++] = Fruit("10.Watermelon(1kg)    ", 1.80);
}

FruitShop::~FruitShop() {
    delete[] fruits;
}

void FruitShop::resize() {
    capacity *= 2;
    Fruit* newFruits = new Fruit[capacity];

    for (int i = 0; i < fruitCount; ++i) {
        newFruits[i] = fruits[i];
    }

    delete[] fruits;
    fruits = newFruits;
}

void FruitShop::displayFruits() const {
    if (fruitCount == 0) {
        cout << "No fruits available!" << endl;
        return;
    }
    cout << "\nFruit List:\n";
    cout << "--------------------------------------------\n";
    cout << left << setw(20) << "Fruit Name" << setw(10) << "Price" << endl;
    cout << "--------------------------------------------\n";
    for (int i = 0; i < fruitCount; ++i) {
        cout << left << setw(20) << fruits[i].name << "\t\t" << "RM " << setw(10) << fruits[i].price << endl;
    }
    cout << "--------------------------------------------\n";
}

int FruitShop::getFruitCount() const {
    return fruitCount;
}

const FruitShop::Fruit& FruitShop::getFruit(int index) const {
    return fruits[index];
}
