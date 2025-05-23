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
#include <map>
#include <functional>

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
    void forEachItem(const std::function<void(const Item&)>& func) const;
    size_t getItemCount() const; // Aggiunto
    const Item& getItem(size_t index) const; // Aggiunto
    std::string getName() const;

    //Restituire il numero di oggetti ancora da comprare
    int getUnboughtItemCount() const;

    std::map<std::string, std::vector<Item>> groupItemsByCategory() const;
};

#endif //LISTASPESA_P_SHOPPINGLIST_H
