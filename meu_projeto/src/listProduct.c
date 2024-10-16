#include <stdio.h>
#include<string.h>
#include "products.h"

void listProduct(Product *products, int quant) {
    printf("Produtos cadastrados:\n");
    for (int i = 0; i < quant; i++) {
        printf("Nome: %s, Preço: %.d, Quantidade: %d, Categoria: %s\n",
               products[i].produto, products[i].preco, products[i].porcao, products[i].categoria);
    }
}
