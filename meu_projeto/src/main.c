#include <stdio.h>
#include<string.h>
#include "products.h"
#include "shopping.h"

int main(){
    Product products[100]; // Array para armazenar produtos
    Invoice invoice[100]; // Array da nota fiscal
    Product products_invoice[100];
    int n = 0; // Número de produtos cadastrados
    int option = 0, cod_product = 0, option_geral = 0;
    cad_all_products_DB(products, &n);

    while (option_geral != 3){
        printf("\nMenu:\n");
        printf("1. Modulo servidor\n"); // products.h
        printf("2. Modulo caixa\n"); // shopping.h
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option_geral);
        switch (option_geral){
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
            int count = 0;
            int invoice_count = 0;
            int price_total = 0;
            do{
                printf("\nMenu:\n\n");
                printf("1. Passar produto\n");
                printf("2. Finalizar compra\n");
                printf("3. Voltar (cancelar compra)\n");
                printf("Escolha uma opção: ");
                scanf("%d", &option);
                switch (option){
                case 1:
                    int add = 0;
                    while (add != 1){
                        int codigo = 0;
                        printf("Digite o código do produto: \n");
                        scanf("%d", &codigo);
                        find_product(&codigo, products_invoice, &count);

                        if(products_invoice[count].product[0] == '\0' && count > 0){
                            count --;
                        }
                        switch (add){
                        case 0:
                            if((products_invoice[count].type) == 'q'){
                                printf("Produto: %s\n", products_invoice[count].product);
                                int quant_product = 0;
                                printf("Digite quantos quilos são: \n");
                                scanf("%d", &quant_product); 
                                price_total += products_invoice[count].price * quant_product;
                            }else if(products_invoice[count].type == 'u'){
                                printf("Produto: %s\n", products_invoice[count].product);
                                int quant_product = 0;
                                printf("Digite quantas unidades são: \n");
                                scanf("%d", &quant_product); 
                                price_total += products_invoice[count].price * quant_product;
                            }
                            count++;
                            printf("0 para adicionar mais produtos 1 para sair: \n");
                            scanf("%d", &add); 

                            break;
                        case 1:
                            printf("Saindo...\n");
                            break;
                        default:
                            printf("Opção inválida! Tente novamente.\n");
                        }
                    }
                    break;
                case 2:
                    printf("\nEmitindo nota fiscal...\n");
                    invoice[invoice_count] = register_purchase(products_invoice, &count);
                    show_invoice(invoice, &invoice_count, price_total);
                    save_invoice(invoice);
                    invoice_count++;
                    // retorna nota fiscal
                    break;
                case 3:
                    printf("Saindo...\n");
                    break;
                default:
                    printf("Opção inválida! Tente novamente.\n");
                }
            }while (option != 3);
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
