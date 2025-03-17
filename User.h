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
    User(std::string u);
    void addList(std::shared_ptr<ShoppingList> list);
    void update(ShoppingList* list) override;
};

#endif //LISTASPESA_P_USER_H
