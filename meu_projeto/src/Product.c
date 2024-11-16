#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "products.h"

#define MAX_LINE_LENGTH 1024

// cadastra produtos novos no banco de dados
void cad_product(Product *products, int *quant){
    FILE* fp = fopen("data/produtos_cad.csv", "a");
    if (!fp){
        printf("Can't open file\n");
        return;
    }
    printf("Digite o codigo do produto: ");
    scanf("%d", &products[*quant].cod_product);

    printf("Digite o nome do produto: ");
    getchar();
    scanf("%[^\n]", products[*quant].product);

    printf("Digite a categoria do produto: ");
    getchar();
    scanf("%[^\n]", products[*quant].category);

    printf("Digite a quantidade do produto no estoque: ");
    scanf("%f", &products[*quant].quantity);

    printf("Digite o preço do produto: ");
    scanf("%f", &products[*quant].price);

    printf("Digite as calorias do produto: ");
    scanf("%f", &products[*quant].calories);

    printf("Digite as proteinas do produto: ");
    scanf("%f", &products[*quant].proteins);

    printf("Digite os carboidratos do produto: ");
    scanf("%f", &products[*quant].carbohydrate);

    printf("Digite as fibras do produto: ");
    scanf("%f", &products[*quant].fibers);

    printf("Digite a gordura do produto: ");
    scanf("%f", &products[*quant].fats);

    fprintf(fp, "%d,%s,%s,%f,%f,%f,%f,%f,%f,%f\n",
        products[*quant].cod_product, products[*quant].product, 
        products[*quant].category, products[*quant].quantity, 
        products[*quant].price, products[*quant].calories,
        products[*quant].proteins, products[*quant].carbohydrate, 
        products[*quant].fibers, products[*quant].fats);
    
    (*quant)++;

    fclose(fp);
    printf("\nNovo produto cadastrado!!!\n");
}

// mostra todos os produtos cadastrados
void list_product(Product *products, int quant) {
    printf("Produtos cadastrados:\n");
    for (int i = 0; i < quant; i++) {
        printf("Código: %d, Nome: %s, Preço: %.2f, Quantidade: %.2f, Categoria: %s\n",
               products[i].cod_product, products[i].product, products[i].price, products[i].quantity, products[i].category);
    }
}

// add na lista de produtos do codigo todos que estão no banco
void cad_all_products_DB(Product *products, int *quant){
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
                sscanf(value, "%s", products[*quant].category);

                value = strtok(NULL, ",");
                sscanf(value, "%f", &products[*quant].quantity);

                value = strtok(NULL, ",");
                sscanf(value, "%f", &products[*quant].price);

                value = strtok(NULL, ",");
                sscanf(value, "%f", &products[*quant].calories);

                value = strtok(NULL, ",");
                sscanf(value, "%f", &products[*quant].proteins);

                value = strtok(NULL, ",");
                sscanf(value, "%f", &products[*quant].carbohydrate);

                value = strtok(NULL, ",");
                sscanf(value, "%f", &products[*quant].fibers);

                value = strtok(NULL, ",");
                sscanf(value, "%f", &products[*quant].fats);

            }

            if(has_value==1){
                (*quant)++;
            }
        }

        fclose(fp);
    }
}

//Ler produto atualizado
Product read_product(int *cod_product){
    printf("procurando produto...\n");
    Product p;
        p.cod_product = *cod_product;

        printf("Digite o nome do produto: ");
        getchar();
        scanf("%[^\n]", p.product);

        printf("Digite a categoria: ");
        getchar();
        scanf("%[^\n]", p.category);

        printf("Digite a quantidade: ");
        scanf("%f", &p.quantity);

        printf("Digite o preço: ");
        scanf("%f", &p.price);

        printf("Digite as calorias: ");
        scanf("%f", &p.calories);

        printf("Digite as proteínas: ");
        scanf("%f", &p.proteins);

        printf("Digite os carboidratos: ");
        scanf("%f", &p.carbohydrate);

        printf("Digite as fibras: ");
        scanf("%f", &p.fibers);

        printf("Digite a gordura: ");
        scanf("%f", &p.fats);

        return p;
}


// Função para atualizar uma linha no arquivo CSV
void update_product(int *cod_product, Product new_product){
    FILE *fp = fopen("data/produtos_cad.csv", "r");
    FILE *temp_file = fopen("data/temp.csv", "w");
    
    if (fp == NULL || temp_file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[MAX_LINE_LENGTH];
    int updated_line = 0;

    while (fgets(linha, MAX_LINE_LENGTH, fp)) {
        char copy_line[MAX_LINE_LENGTH];
        strcpy(copy_line, linha);
        
        char *campoStr = strtok(copy_line, ",");
        if(campoStr != NULL){
            int campoID = atoi(campoStr);
            if( campoID == *cod_product) {
                fprintf(temp_file, "%d,%s,%s,%f,%f,%f,%f,%f,%f,%f\n", 
                    new_product.cod_product, new_product.product, 
                    new_product.category, new_product.quantity, 
                    new_product.price, new_product.calories,
                    new_product.proteins, new_product.carbohydrate, 
                    new_product.fibers, new_product.fats);
            updated_line = 1;
            }else fprintf(temp_file, "%s", linha);
        }
    }

    fclose(fp);
    fclose(temp_file);

    // Substitui o arquivo original pelo arquivo temporário
    remove("data/produtos_cad.csv");
    rename("data/temp.csv", "data/produtos_cad.csv");

    if (updated_line) {
        printf("Produto com o codigo %d atualizado com sucesso!\n", *cod_product);
    } else {
        printf("Codigo %d não encontrado!\n", *cod_product);
    }
}