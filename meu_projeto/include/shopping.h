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

Invoice register_purchase(Product *products, int *quant);
void show_invoice(Invoice *invoice, int *count, int price_final);
int count_lines(Product *products, int tamanho);
void save_invoice(Invoice *invoice);

#endif 
