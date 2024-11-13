#include <stdio.h>
#include<string.h>
#include "products.h"

int main() {
    Product products[100]; // Array para armazenar produtos
    int n = 0; // Número de produtos cadastrados
    int option;
    cadAllProductsDB(products, &n);
    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar produto\n");
        printf("2. Atualizar produto\n");
        printf("3. Listar produtos\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                cadProduct(products, &n);
                break;
            case 2:
                int codProduct;
                printf("Digite o código do produto:");
                scanf("%d", &codProduct);
                updateProduct(products, &n, codProduct);
            case 3:
                listProduct(products, n);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (option != 4);

    return 0;
}
