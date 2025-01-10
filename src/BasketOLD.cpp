#include "../headers/Basket.h"
#include <iostream>
#include <iomanip>

Basket::BasketItem::BasketItem(const std::string& name, double price, int quantity) : name(name), price(price), quantity(quantity) {}

void Basket::addItem(const std::string& name, double price, int quantity) {
    for (auto& item : items) {
        if (item.name == name) {
            item.quantity += quantity;
            return;
        }
    }
    items.push_back(BasketItem(name, price, quantity));
}

void Basket::editItem(int index, int newQuantity) {
    if (index < 1 || index > items.size()) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    items[index - 1].quantity = newQuantity;
}

void Basket::deleteItem(int index) {
    if (index < 1 || index > items.size()) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    items.erase(items.begin() + index - 1);
}

void Basket::displayBasket() const {
    if (items.empty()) {
        std::cout << "Your basket is empty!" << std::endl;
        return;
    }

    std::cout << "\nYour Basket:\n";
    std::cout << "--------------------------------------------\n";
    std::cout << std::left << std::setw(20) << "Fruit Name" << std::setw(10) << "Quantity" << std::setw(10) << "Price" << std::setw(10) << "Total" << std::endl;
    std::cout << "--------------------------------------------\n";
    double total = 0.0;
    for (int i = 0; i < items.size(); ++i) {
        double itemTotal = items[i].price * items[i].quantity;
        total += itemTotal;
        std::cout << std::left << std::setw(20) << items[i].name << std::setw(10) << items[i].quantity
                  << std::setw(10) << items[i].price << std::setw(10) << itemTotal << std::endl;
    }
    std::cout << "--------------------------------------------\n";
    std::cout << "Total: RM" << total << std::endl;
}

double Basket::getTotal() const {
    double total = 0.0;
    for (const auto& item : items) {
        total += item.price * item.quantity;
    }
    return total;
}

void Basket::clear() {
    items.clear();
}
