//
// Created by fagza on 17/03/2025.
//

#ifndef LISTASPESA_P_ITEM_H
#define LISTASPESA_P_ITEM_H


#include <string>

class Item {
private:
    std::string name;
    std::string category;
    int quantity;

public:
    Item()=default;
    Item(std::string n, std::string c, int q);

    std::string getName() const;
    std::string getCategory() const;
    int getQuantity() const;
    void setQuantity(int q);
};


#endif //LISTASPESA_P_ITEM_H
