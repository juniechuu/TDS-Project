#ifndef BASKET_H
#define BASKET_H

#include <string>
using namespace std;

class Basket {
private:
    struct BasketItem {
        string name;
        double price;
        int quantity;

        // Default constructor
        BasketItem() : name(""), price(0.0), quantity(0) {}

        BasketItem(const string& name, double price, int quantity)
            : name(name), price(price), quantity(quantity) {}
    };

    BasketItem* items;
    int itemCount;
    int capacity;

    void resize();

public:
    Basket();
    ~Basket();

    void addItem(const string& name, double price, int quantity);
    void editItem(int index, int newQuantity);
    void deleteItem(int index);
    void displayBasket() const;
    double getTotal() const;
    void clear();
};

#endif
