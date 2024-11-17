#include <stdio.h>
#include "shopping.h"
#include <time.h>

void get_date(char *date) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

void register_purchase(Invoice *invoice, Product *products){
    int quantity = sizeof(products) / sizeof(products[0]);
    float price = 0;
    for(int i = 0; i<quantity; i++){
        price += products[i].price;
    }
    invoice->products = products;
    invoice->quan_products = quantity;
    invoice->price = price;
    get_date(invoice->date);
}

void show_invoice(Invoice *invoice){
    printf("Nota Fiscal\n");
    printf("Data: %s\n", invoice->date);
    for (int i = 0; i < invoice->quan_products; i++) {
        show_product(invoice->products[i]);
    }
    printf("Preço: %.2f\n", invoice->price);
}
