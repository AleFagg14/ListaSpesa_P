//
// Created by fagza on 17/03/2025.
//

#ifndef LISTASPESA_P_ITEM_H
#define LISTASPESA_P_ITEM_H


#include <string>
#include <stdexcept>

class Item {
private:
    std::string name;
    std::string category;
    int quantity;

    bool bought = false;

public:
    Item()=default;

    //Costruttore: lancia eccezione se la quantità negativa
    Item(std::string n, std::string c = "", int q = 0);


    std::string getName() const;
    std::string getCategory() const;
    int getQuantity() const;

    //Imposta la quantità: lancia eccezione se negativa
    void setQuantity(int q);

    bool isBought() const;
    void setBought(bool b);
};


#endif //LISTASPESA_P_ITEM_H
