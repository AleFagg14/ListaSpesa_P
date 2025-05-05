//
// Created by fagza on 17/03/2025.
//

#include "Item.h"
#include <stdexcept> //Questa serve peer invalid_argument


Item::Item(std::string n, std::string c, int q)
        : name(std::move(n)), category(std::move(c)) {
    if (q < 0) {
        throw std::invalid_argument("La quantità non può essere negativa.");
    }
    quantity = q;
}

std::string Item::getName() const { return name; }
std::string Item::getCategory() const { return category; }
int Item::getQuantity() const { return quantity; }

void Item::setQuantity(const int q) { if (q < 0) {
        throw std::invalid_argument("La quantità non può essere negativa.");
    }
    quantity = q;
}

bool Item::isBought() const {
    return bought;
}

void Item::setBought(bool b) {
    bought = b;
}