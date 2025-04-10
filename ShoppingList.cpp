//
// Created by fagza on 17/03/2025.
//

#include "ShoppingList.h"

ShoppingList::ShoppingList(std::string n) : name(std::move(n)) {}

ShoppingList::ShoppingList() : name("Default") {}

void ShoppingList::addItem(const Item& item) {
    items[item.getName()] = item;
    notifyObserver();
}

void ShoppingList::addItem(const std::string& name, int quantity) {
    addItem(Item(name, "default_category", quantity));
    ;  // Crea un Item e lo aggiunge
}

void ShoppingList::removeItem(const std::string& itemName) {
    if (items.erase(itemName) > 0) {
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

void ShoppingList::notifyObserver() {
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

size_t ShoppingList::getItemCount() const {
    return items.size();
}

const Item& ShoppingList::getItem(size_t index) const {
    auto it = items.begin();
    std::advance(it, index);
    return it->second;
}

std::string ShoppingList::getName() const { return name; }
