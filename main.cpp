
#include <iostream>
#include "User.h"
#include "ShoppingList.h"
#include "Item.h"

void printList(const std::shared_ptr<ShoppingList>& list) {
    std::cout << " # Lista \"" << list->getName() << "\" contiene:\n";
    for (const auto& item : list->getItems()) {
        std::cout << "   - " << item.getName() << " (" << item.getCategory()
                  << "), Quantita': " << item.getQuantity() << "\n";
    }
    std::cout << "--------------------------------------\n";
}

int main() {
    // Creazione utenti
    User user1("Franco");
    User user2("Aurora");


    // Creazione lista e condivisione
    auto list1 = std::make_shared<ShoppingList>("Spesa Settimanale");
    user1.addList(list1);
    user2.addList(list1);

    std::cout << " Lista della spesa creata e condivisa tra Franco e Aurora.\n";

    // Aggiunta prodotti
    list1->addItem(Item("Latte", "Alimentari", 2));
    list1->addItem(Item("Burro", "Alimentari", 1));
    list1->addItem(Item("Pane", "Panetteria", 1));
    list1->addItem(Item("Petto di pollo", "Macelleria", 2));
    list1->addItem(Item("Cipolle", "Banco Frutta e Verdura", 4));
    list1->addItem(Item("Paprika", "Reparto Spezie e condimenti", 1));
    list1->addItem(Item("Chianti GalloNero", "Reparto Alcolici", 1));
    list1->addItem(Item("Biscotti", "Panetteria", 1));

    printList(list1);

    // Rimozione prodotto
    list1->removeItem("Chianti GalloNero");
    std::cout << "X 'Chianti GalloNero' rimosso dalla lista.\n";
    printList(list1);

    return 0;
}
