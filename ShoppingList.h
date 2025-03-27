//
// Created by fagza on 17/03/2025.
//

#ifndef LISTASPESA_P_SHOPPINGLIST_H
#define LISTASPESA_P_SHOPPINGLIST_H

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include "Item.h"
#include "Observer.h"


class ShoppingList {
private:
    std::string name;
    std::unordered_map<std::string, Item> items;
    std::vector<Observer*> observers;

public:
   explicit ShoppingList(std::string n);

    void addItem(const Item& item);
    void removeItem(const std::string& itemName);
    void attach(Observer* obs);
    void detach(Observer* obs) ;
    void notifyObserver() ;

    std::vector<Item> getItems() const;
    std::string getName() const;
};

#endif //LISTASPESA_P_SHOPPINGLIST_H
