//
// Created by fagza on 06/05/2025.
//
#include <gtest/gtest.h>
#include "ShoppingList.h"
#include "Item.h"


// Mock observer per test notifica
class MockObserver : public Observer {
public:
    bool notified = false;
    void update(ShoppingList* list) override {
        notified = true;
    }
};

// Test observer notificato su addItem
TEST(ShoppingListTest, TestObserverNotificato) {
ShoppingList lista("ObserverTest");
MockObserver obs;
lista.attach(&obs);

lista.addItem("Banane", 4);

EXPECT_TRUE(obs.notified);
}