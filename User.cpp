//
// Created by fagza on 17/03/2025.
//

#include "User.h"

User::User(std::string u) : username(u) {}

void User::addList(std::shared_ptr<ShoppingList> list) {
    shoppingLists.push_back(list);
    list->attach(this); // Si registra come Observer
}

void User::update(ShoppingList* list) {
    std::cout << "🔔 " << username << " ha ricevuto un aggiornamento sulla lista: " << list->getName() << "\n";
}