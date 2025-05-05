//
// Created by fagza on 17/03/2025.
//

#ifndef LISTASPESA_P_SHOPPINGLIST_H
#define LISTASPESA_P_SHOPPINGLIST_H

#include "Item.h"
#include "Observer.h"
#include <unordered_map>
#include <vector>
#include <algorithm>

class ShoppingList {
private:
    std::string name;
    std::unordered_map<std::string, Item> items;
    std::vector<Observer*> observers;

public:
    // Costruttori
    explicit ShoppingList(std::string n);
    ShoppingList();  // Costruttore di default

    // Metodi per gestire gli item
    void addItem(const Item& item);
    void addItem(const std::string& name, int quantity); // Overload
    void removeItem(const std::string& itemName);

    // Observer pattern
    void attach(Observer* obs);
    void detach(Observer* obs);
    void notifyObserver();

    // Getter
    std::vector<Item> getItems() const; //FIX ME cancellare
    size_t getItemCount() const; // Aggiunto
    const Item& getItem(size_t index) const; // Aggiunto
    std::string getName() const;
};

#endif //LISTASPESA_P_SHOPPINGLIST_H
