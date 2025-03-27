//
// Created by fagza on 17/03/2025.
//

#include "User.h"

User::User( const std::string& u) : username(std::move(u)) {}

void User::addList(const std::shared_ptr<ShoppingList>& list) {
    shoppingLists.push_back(list);
    list->attach(this); // Si registra come Observer
}

void User::update(ShoppingList* list) {
    std::cout << "! " << username << " ha ricevuto un aggiornamento sulla lista: "
    << list->getName() << "\n";

}std::string User::getUsername() const {
    return username;
}

std::vector<std::shared_ptr<ShoppingList>> User::getLists() const {
    return shoppingLists;
}