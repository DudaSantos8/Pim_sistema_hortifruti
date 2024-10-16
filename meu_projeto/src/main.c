#include <stdio.h>
#include<string.h>
#include "products.h"

int main() {
    Product produtos[100]; // Array para armazenar produtos
    int n = 0; // Número de produtos cadastrados
    int opcao;
    
    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar produto\n");
        printf("2. Listar produtos\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadProduct(produtos, &n);
                break;
            case 2:
                listProduct(produtos, n);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
