#if !defined SHOPPING_h
#define SHOPPING_h

#include "products.h"

typedef struct{
    Product *products;
    int quan_products;
    float price;
    char date[11];
}Invoice;
// codigo_produto,quantidade,Preco,data,cliente

void register_purchase(Invoice *invoice, Product *products);
void show_invoice(Invoice *invoice);

#endif 
