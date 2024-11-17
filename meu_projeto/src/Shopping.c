#include <stdio.h>
#include "shopping.h"
#include <time.h>
#include <string.h>

void get_date(char *date) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

Invoice register_purchase(Product *products, int *quant){
    Invoice invoice;
    invoice.products = products;
    invoice.quan_products = *quant;
    get_date(invoice.date);
    return invoice;
}

void show_invoice(Invoice *invoice, int *count, int price_final){
    printf("Nota Fiscal\n\n");
    printf("Data: %s\n", invoice[*count].date);
    for (int i = 0; i < invoice[*count].quan_products; i++) {
        show_product(invoice[*count].products[i]);  
    }
    invoice[*count].price = price_final;
    printf("Preço: %.2f\n", invoice[*count].price);
}

// Função para contar quantas linhas estão preenchidas
int count_lines(Product *products, int tamanho) {
    int count = 0;
    
    // Percorre o array de structs
    for (int i = 0; i < tamanho; i++) {
        // Verifica se o código de busca ou nome estão preenchidos
        if (products[i].cod_product != 0 || strlen(products[i].product) > 0) {
            count++;
        }
    }

    return count;
}

void save_invoice(Invoice *invoice) {
    FILE *fp = fopen("data/historico_compras.csv", "a");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de histórico.\n");
        return;
    }

    fprintf(fp, "Data: %s\n", invoice->date);
    fprintf(fp, "Quantidade de produtos: %d\n", invoice->quan_products);
    fprintf(fp, "Preço Total: %.2f\n", invoice->price);
    fprintf(fp, "Produtos:\n");

    for (int i = 0; i < invoice->quan_products; i++) {
        fprintf(fp, "%d,%s,%c,%.2f,%.2f\n", 
                invoice->products[i].cod_product,
                invoice->products[i].product,
                invoice->products[i].type,
                invoice->products[i].price,
                invoice->products[i].quantity);
    }

    fprintf(fp, "\n");  // Adiciona uma linha em branco entre as notas fiscais

    fclose(fp);
    printf("Nota fiscal salva com sucesso!\n");
}
