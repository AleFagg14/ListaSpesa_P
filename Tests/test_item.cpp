//
// Created by fagza on 06/05/2025.
//
#include <gtest/gtest.h>
#include "Item.h"

// Test del costruttore con quantità negativa
TEST(ItemTest, CostruttoreQuantitaNegativa) {
EXPECT_THROW(Item("Latte", "Alimentari", -2), std::invalid_argument);
}

// Test del setter setQuantity con quantità negativa
TEST(ItemTest, SetterQuantitaNegativa) {
Item item("Pasta", "Alimentari", 1);
EXPECT_THROW(item.setQuantity(-5), std::invalid_argument);
}

// Test positivo per quantità valida
TEST(ItemTest, QuantitaValida) {
Item item("Acqua", "Bevande", 3);
EXPECT_EQ(item.getQuantity(), 3);

item.setQuantity(10);
EXPECT_EQ(item.getQuantity(), 10);
}