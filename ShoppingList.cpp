//
// Created by fagza on 17/03/2025.
//

#include "ShoppingList.h"

ShoppingList::ShoppingList(std::string n) : name(n) {}

void ShoppingList::addItem(const Item& item) {
    items.push_back(item);
    notify();
}

void ShoppingList::removeItem(const std::string& itemName) {
    items.erase(std::remove_if(items.begin(), items.end(),
                               [&](Item& item) { return item.getName() == itemName; }), items.end());
    notify();
}

void ShoppingList::attach(Observer* obs) {
    observers.push_back(obs);
}

void ShoppingList::detach(Observer* obs) {
    observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
}

void ShoppingList::notify() {
    for (auto* obs : observers) {
        obs->update(this);
    }
}

std::vector<Item> ShoppingList::getItems() const { return items; }
std::string ShoppingList::getName() const { return name; }