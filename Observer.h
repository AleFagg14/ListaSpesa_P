//
// Created by fagza on 17/03/2025.
//

#ifndef LISTASPESA_P_OBSERVER_H
#define LISTASPESA_P_OBSERVER_H

class ShoppingList; // Forward declaration

class Observer {
public:
    virtual void update(ShoppingList* list) = 0;
    virtual ~Observer() = default;
};

#endif //LISTASPESA_P_OBSERVER_H
