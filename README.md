# ListaSpesa_P
 ShoppingList
 Elaborato di Laboratorio di Programmazione

 Lista della spesa dove si possono inserire oggetti, rimuovere oggetti e in base ad ogni modifica della lista ricevere una notifica. La Classe Item rappresenta un prodotto con attributi nome, categoria e quantità.La Classe ShoppingList gestisce la lista vera e propria, contenente nome, prodotti aggiunti e il numero totale di articoli da acquistare. La Classe User appresenta un utente che può essere associato a una o più liste. Nel progetto è stato utilizzato il pattern Observer per gestire in modo efficace la comunicazione tra le liste della spesa (ShoppingList) e gli utenti (User) che le seguono o ne fanno parte.Quando più utenti condividono la stessa lista della spesa, è fondamentale che tutti vengano informati automaticamente ogni volta che la lista viene modificata (ad esempio, quando un oggetto viene aggiunto o rimosso).
