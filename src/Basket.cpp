#include "../headers/Basket.h"
#include <iostream>
#include <iomanip>
using namespace std;

Basket::Basket() {
    capacity = 10;  // Initial capacity
    itemCount = 0;
    items = new BasketItem[capacity];
}

Basket::~Basket() {
    delete[] items;
}

void Basket::resize() {
    capacity *= 2;  // Double the capacity
    BasketItem* newItems = new BasketItem[capacity];

    for (int i = 0; i < itemCount; ++i) {
        newItems[i] = items[i];
    }

    delete[] items;
    items = newItems;
}

void Basket::addItem(const string& name, double price, int quantity) {
    if (itemCount == capacity) {
        resize();
    }
    items[itemCount++] = BasketItem(name, price, quantity);
}

void Basket::editItem(int index, int newQuantity) {
    if (index < 0 || index >= itemCount) {
        cout << "Invalid index!" << endl;
        return;
    }
    items[index].quantity = newQuantity;
}

void Basket::deleteItem(int index) {
    if (index < 0 || index >= itemCount) {
        cout << "Invalid index!" << endl;
        return;
    }

    for (int i = index; i < itemCount - 1; ++i) {
        items[i] = items[i + 1];
    }

    --itemCount;
}

void Basket::displayBasket() const {
    if (itemCount == 0) {
        cout << "Your basket is empty!" << endl;
        return;
    }

    cout << "\nYour Basket:\n";
    cout << "--------------------------------------------\n";
    cout << left << setw(20) << "Fruit Name" << setw(10) << "Quantity" << setw(10) << "Price" << setw(10) << "Total" << endl;
    cout << "--------------------------------------------\n";
    double total = 0.0;
    for (int i = 0; i < itemCount; ++i) {
        double itemTotal = items[i].price * items[i].quantity;
        total += itemTotal;
        cout << left << setw(20) << items[i].name << setw(10) << items[i].quantity
             << setw(10) << items[i].price << setw(10) << itemTotal << endl;
    }
    cout << "--------------------------------------------\n";
    cout << "Total: RM" << total << endl;
}

double Basket::getTotal() const {
    double total = 0.0;
    for (int i = 0; i < itemCount; ++i) {
        total += items[i].price * items[i].quantity;
    }
    return total;
}

void Basket::clear() {
    itemCount = 0;
}
