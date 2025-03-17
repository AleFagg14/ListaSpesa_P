#include "User.h"
#include "ShoppingList.h"
#include "Item.h"

int main() {
    // Creazione utenti
    User user1("Alice");
    User user2("Bob");

    // Creazione lista e condivisione
    auto list1 = std::make_shared<ShoppingList>("Spesa Settimanale");
    user1.addList(list1);
    user2.addList(list1);

    // Aggiunta prodotti
    list1->addItem(Item("Latte", "Alimentari", 2));
    list1->addItem(Item("Pane", "Panetteria", 1));

    // Rimozione prodotto
    list1->removeItem("Pane");

    return 0;
}