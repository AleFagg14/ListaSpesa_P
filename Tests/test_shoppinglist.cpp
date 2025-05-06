//
// Created by fagza on 06/05/2025.
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

// Test rimozione item inesistente
TEST(ShoppingListTest, TestRimozioneItemInesistnte) {
ShoppingList lista("SpesaVuota");
lista.addItem("Zucchero", 1);
lista.removeItem("Sale");  // Non presente

EXPECT_EQ(lista.getItemCount(), 1);  // Zucchero deve restare
}

TEST(ShoppingListTest, ContaOggettiNonComprati) {
ShoppingList lista("Spesa");

Item latte("Latte", "Alimentari", 1);
Item pane("Pane", "Alimentari", 2);
Item detersivo("Detersivo", "Casa", 1);

pane.setBought(true);  // Solo questo è stato comprato

lista.addItem(latte);
lista.addItem(pane);
lista.addItem(detersivo);

EXPECT_EQ(lista.getUnboughtItemCount(), 2);  // Solo 2 non comprati
}

TEST(ShoppingListTest, RaggruppaPerCategoria) {
ShoppingList lista("Spesa");

lista.addItem(Item("Latte", "Alimentari", 1));
lista.addItem(Item("Pane", "Alimentari", 2));
lista.addItem(Item("Sapone", "Igiene", 1));

auto raggruppati = lista.groupItemsByCategory();

EXPECT_EQ(raggruppati["Alimentari"].size(), 2);
EXPECT_EQ(raggruppati["Igiene"].size(), 1);
EXPECT_EQ(raggruppati["Igiene"][0].getName(), "Sapone");
}
