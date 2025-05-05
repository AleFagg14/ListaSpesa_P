//
// Created by fagza on 29/03/2025.
//
#include <gtest/gtest.h>
#include "ShoppingList.h"
#include "Item.h"

// Test per il metodo di aggiunta di un item
TEST(ShoppingListTest, TestAggiuntaItem) {
    ShoppingList lista("Lista1");
    lista.addItem("Mela", 3);

    EXPECT_EQ(lista.getItemCount(), 1);
    EXPECT_EQ(lista.getItem(0).getName(), "Mela");
    EXPECT_EQ(lista.getItem(0).getQuantity(), 3);
}

// Test per la rimozione di un item
TEST(ShoppingListTest, TestRimozioneItem) {
    ShoppingList lista("Lista1");
    lista.addItem("Pane", 1);
    lista.removeItem("Pane");

    EXPECT_EQ(lista.getItemCount(), 0);
}





// Test aggiunta di item duplicato (aggiorna o sovrascrive)
TEST(ShoppingListTest, TestAggiuntaDuplicato) {
    ShoppingList lista("Duplicati");
    lista.addItem("Latte", 1);
    lista.addItem("Latte", 2);  // Aggiunto con quantità diversa

    EXPECT_EQ(lista.getItemCount(), 1);  // Deve restare uno solo
    EXPECT_EQ(lista.getItem(0).getQuantity(), 2);  // Quantità aggiornata
}

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




// Test nome lista
TEST(ShoppingListTest, TestGetName) {
    ShoppingList lista("SpesaSabato");
    EXPECT_EQ(lista.getName(), "SpesaSabato");
}

// Test rimozione item inesistente
TEST(ShoppingListTest, TestRimozioneItemInesistnte) {
    ShoppingList lista("SpesaVuota");
    lista.addItem("Zucchero", 1);
    lista.removeItem("Sale");  // Non presente

    EXPECT_EQ(lista.getItemCount(), 1);  // Zucchero deve restare
}





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

// Funzione principale per eseguire i test
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

