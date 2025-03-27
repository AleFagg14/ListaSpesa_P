//
// Created by fagza on 17/03/2025.
//

#include "ShoppingList.h"

ShoppingList::ShoppingList(std::string n) : name(n) {}

void ShoppingList::addItem(const Item& item) {
    items [item.getName()] = item;
    notifyObserver();
}

void ShoppingList::removeItem(const std::string& itemName) {
    if (items.erase(itemName) > 0) {  // Rimuove e verifica se esisteva
        notifyObserver();
        }
}

void ShoppingList::attach(Observer* obs) {
    if (std::find(observers.begin(), observers.end(), obs) == observers.end()) {
        observers.push_back(obs);
    }
}

void ShoppingList::detach(Observer* obs) {
    observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
}

void ShoppingList::notifyObserver()  {
    for (auto* obs : observers) {
        obs->update(this);
    }
}

std::vector<Item> ShoppingList::getItems() const {
    std::vector<Item> itemList;
    for (const auto& pair : items) {
        itemList.push_back(pair.second);
    }
    return itemList;
}

std::string ShoppingList::getName() const { return name; }