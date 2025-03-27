//
// Created by fagza on 17/03/2025.
//

#ifndef LISTASPESA_P_USER_H
#define LISTASPESA_P_USER_H

#include <iostream>
#include <vector>
#include <memory>
#include "Observer.h"
#include "ShoppingList.h"

class User : public Observer {
private:
    std::string username;
    std::vector<std::shared_ptr<ShoppingList>> shoppingLists;

public:
    explicit User(const std::string& u);

    void addList(const std::shared_ptr<ShoppingList>& list);
    void update(ShoppingList* list) ;

    std::string getUsername() const;
    std::vector<std::shared_ptr<ShoppingList>> getLists() const;

    ~User() override = default;
};

#endif //LISTASPESA_P_USER_H
