//
// Created by fagza on 29/03/2025.
//
#include <gtest/gtest.h>
#include "ShoppingList.h"

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
    ShoppingList lista("Lista1");  // Ora passa un nome
    lista.addItem("Pane", 1);
    lista.removeItem("Pane");

    EXPECT_EQ(lista.getItemCount(), 0);
}

// Funzione principale per eseguire i test
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

