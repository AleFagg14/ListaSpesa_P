//
// Created by fagza on 17/03/2025.
//

#include "Item.h"

Item::Item(std::string n, std::string c, int q) : name(n), category(c), quantity(q) {}

std::string Item::getName() const { return name; }
std::string Item::getCategory() const { return category; }
int Item::getQuantity() const { return quantity; }
void Item::setQuantity(int q) { quantity = q; }