#include <stdio.h>
#include<string.h>
#include "products.h"

int main(){
    Product products[100]; // Array para armazenar produtos
    int n = 0; // Número de produtos cadastrados
    int option, cod_product;
    cad_all_products_DB(products, &n);

    while (option != 3){
        printf("\nMenu:\n");
        printf("1. Modulo servidor\n");
        printf("2. Modulo caixa\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);
        switch (option){
        case 1:
            do {
                printf("\nMenu:\n\n");
                printf("1. Cadastrar produto\n");
                printf("2. Atualizar produto\n");
                printf("3. Listar produtos\n");
                printf("4. Voltar\n");
                printf("Escolha uma opção: ");
                scanf("%d", &option);
                switch (option) {
                case 1:
                    cad_product(products, &n);
                    break;
                case 2:
                    printf("Digite o código do produto:");
                    scanf("%d", &cod_product);

                    Product new_product = read_product(&cod_product);
                    update_product(&cod_product, new_product);
                    break;
                case 3:
                    list_product(products, n);
                    break;
                case 4:
                    printf("Saindo...\n");
                    break;
                default:
                    printf("Opção inválida! Tente novamente.\n");
                }
            }while (option != 4);
            break;
        case 2:
            do{
                printf("\nMenu:\n\n");
                printf("1. Passar produto\n");
                printf("2. Pesar produto\n");
                printf("3. Finalizar compra\n");
                printf("4. Voltar (cancelar compra)\n");
                printf("Escolha uma opção: ");
                scanf("%d", &option);
                switch (option){
                case 1:
                    printf("Digite o código do produto: \n");
                    scanf("%d", &cod_product);
                    // metodo buscar e add produto na nota fiscal
                    break;
                case 2:
                    printf("Digite o código do produto: \n");
                    scanf("%d", &cod_product);
                    // metodo buscar e cacular peso add nota fiscal
                case 3:
                    printf("Emitindo nota fiscal...\n");
                    // retorna nota fiscal
                case 4:
                    printf("Saindo...\n");
                default:
                    printf("Opção inválida! Tente novamente.\n");
                }
            }while (option != 4);
            break;
        case 3:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    }
    return 0;
}
