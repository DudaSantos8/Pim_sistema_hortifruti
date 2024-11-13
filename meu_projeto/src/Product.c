#include<stdio.h>
#include<string.h>
#include "products.h"

// cadastra produtos novos no banco de dados
void cadProduct (Product *products, int *quant){
    FILE* fp = fopen("data/produtos_cad.csv", "a");
    if (!fp){
        printf("Can't open file\n");
        return;
    }

    printf("Digite o codigo do produto: ");
    scanf("%d", &products[*quant].cod_product);

    printf("Digite o nome do produto: ");
    scanf("%s", products[*quant].product);

    printf("Digite as calorias do produto: ");
    scanf("%d", &products[*quant].calories);

    printf("Digite as proteinas do produto: ");
    scanf("%f", &products[*quant].proteins);

    printf("Digite os carboidratos do produto: ");
    scanf("%f", &products[*quant].carbohydrate);

    printf("Digite as fibras do produto: ");
    scanf("%f", &products[*quant].fibers);

    printf("Digite a gordura do produto: ");
    scanf("%f", &products[*quant].fats);

    printf("Digite a porção do produto: ");
    scanf("%d", &products[*quant].portion);

    printf("Digite o preço do produto: ");
    scanf("%d", &products[*quant].price);

    printf("Digite a categoria do produto: ");
    scanf("%s", products[*quant].category);

    fprintf(fp, "%d,%s,%d,%.2f,%.2f,%.2f,%.2f,%d,%d,%s\n",
            products[*quant].cod_product,
            products[*quant].product,
            products[*quant].calories,
            products[*quant].proteins,
            products[*quant].carbohydrate,
            products[*quant].fibers,
            products[*quant].fats,
            products[*quant].portion,
            products[*quant].price,
            products[*quant].category);

    (*quant)++;

    fclose(fp);
    printf("\nNovo produto cadastrado!!!\n");
}

// mostra todos os produtos cadastrados
void listProduct(Product *products, int quant) {
    printf("Produtos cadastrados:\n");
    for (int i = 0; i < quant; i++) {
        printf("Código: %d, Nome: %s, Preço: %.d, Quantidade: %d, Categoria: %s\n",
               products[i].cod_product, products[i].product, products[i].price, products[i].portion, products[i].category);
    }
}

// add na lista de produtos do codigo todos que estão no banco
void cadAllProductsDB(Product *products, int *quant){
    FILE* fp = fopen("data/produtos_cad.csv", "r");
    if (!fp){
        printf("Can't open file\n");
        return;
    }

    else {
        char buffer[1024];

        int row = 0;

        while (fgets(buffer, 1024, fp)) {
            row++;

            if (row == 1){
                continue;
            }

            int has_value = 0;
            char* value = strtok(buffer, ",");

            if (value) {
                has_value = 1;

                value = strtok(NULL, ",");
                sscanf(value, "%d", &products[*quant].cod_product);

                strcpy(products[*quant].product, value);

                value = strtok(NULL, ",");
                sscanf(value, "%d", &products[*quant].calories);

                value = strtok(NULL, ",");
                sscanf(value, "%f", &products[*quant].proteins);

                value = strtok(NULL, ",");
                sscanf(value, "%f", &products[*quant].carbohydrate);

                value = strtok(NULL, ",");
                sscanf(value, "%f", &products[*quant].fibers);

                value = strtok(NULL, ",");
                sscanf(value, "%f", &products[*quant].fats);

                value = strtok(NULL, ",");
                sscanf(value, "%d", &products[*quant].portion);

                value = strtok(NULL, ",");
                sscanf(value, "%d", &products[*quant].price);

                value = strtok(NULL, ",");
                sscanf(value, "%s", products[*quant].category);
            }

            if(has_value==1){
                (*quant)++;
            }
        }

        fclose(fp);
    }
}

//
void updateProduct(Product *product, int *quant, int cod_product){
    printf("procurando produto...");
    for (int i = 0; i < *quant; i++) {
        if (product[i].cod_product == cod_product) {
            printf("\nAtualizando o produto: %s\n", product[i].product);

            printf("Digite as novas calorias: ");
            scanf("%d", &product[i].calories);

            printf("Digite as novas proteínas: ");
            scanf("%f", &product[i].proteins);

            printf("Digite os novos carboidratos: ");
            scanf("%f", &product[i].carbohydrate);

            printf("Digite as novas fibras: ");
            scanf("%f", &product[i].fibers);

            printf("Digite a nova gordura: ");
            scanf("%f", &product[i].fats);

            printf("Digite a nova porção: ");
            scanf("%d", &product[i].portion);

            printf("Digite o novo preço: ");
            scanf("%d", &product[i].price);

            printf("Digite a nova categoria: ");
            scanf("%s", product[i].category);

            printf("\nProduto atualizado com sucesso!!!\n");
            return;
        }
    }
    printf("\nProduto não encontrado.\n");
}