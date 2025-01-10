#ifndef BASKET_H
#define BASKET_H

#include <string>
#include <vector>

class Basket {
private:
    struct BasketItem {
        std::string name;
        double price;
        int quantity;
        BasketItem(const std::string& name, double price, int quantity);
    };

    std::vector<BasketItem> items;

public:
    void addItem(const std::string& name, double price, int quantity);
    void editItem(int index, int newQuantity);
    void deleteItem(int index);
    void displayBasket() const;
    double getTotal() const;
    void clear();
};

#endif 
