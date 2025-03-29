//
// Created by fagza on 29/03/2025.
//
#include <gtest/gtest.h>
#include "ShoppingList.h"  // Includi il file della tua classe da testare

// Test per il metodo di aggiunta di un item
TEST(ShoppingListTest, TestAggiuntaItem) {
ShoppingList lista;
lista.addItem("Mela", 3);

EXPECT_EQ(lista.getItemCount(), 1);  // Verifica che ci sia un elemento nella lista
EXPECT_EQ(lista.getItem(0).name, "Mela");  // Verifica che il nome sia corretto
EXPECT_EQ(lista.getItem(0).quantity, 3);  // Verifica che la quantità sia corretta
}

// Test per la rimozione di un item
TEST(ShoppingListTest, TestRimozioneItem) {
ShoppingList lista;
lista.addItem("Pane", 1);
lista.removeItem("Pane");

EXPECT_EQ(lista.getItemCount(), 0);  // La lista dovrebbe essere vuota dopo la rimozione
}

// Funzione principale per eseguire i test
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
