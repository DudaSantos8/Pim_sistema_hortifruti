#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "products.h"

#define MAX_LINE_LENGTH 1024

// cadastra produtos novos no banco de dados
void cad_product(Product *products, int *quant) {
    FILE *fp = fopen("data/produtos_cad.csv", "a");
    if (!fp) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Product *p = &products[*quant];

    // Inputs gerais
    printf("Digite o codigo, nome e categoria do produto:\n");
    scanf("%d%*c%99[^\n]%*c%99[^\n]", &p->cod_product, p->product, p->category);

    // Input de tipo e quantidade
    printf("Digite (q) se o produto for por quilo ou (u) se for por unidade:\n");
    scanf(" %c", &p->type);
    printf("Digite a quantidade do produto no estoque e o preço:\n");
    scanf("%f %f", &p->quantity, &p->price);

    // Inputs nutricionais
    printf("Digite calorias, proteinas, carboidratos, fibras e gorduras:\n");
    scanf("%f %f %f %f %f", &p->calories, &p->proteins, &p->carbohydrate, &p->fibers, &p->fats);

    // Escreve os dados no arquivo CSV
    fprintf(fp, "%d,%s,%s,%c,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f\n",
            p->cod_product, p->product, p->category, p->type, p->quantity, 
            p->price, p->calories, p->proteins, p->carbohydrate, p->fibers, p->fats);

    (*quant)++; // Incrementa a quantidade de produtos
    fclose(fp);

    puts("\nNovo produto cadastrado com sucesso!");
}


// mostra todos os produtos cadastrados
void list_product(Product *products, int quant) {
    printf("Produtos cadastrados:\n");
    for (int i = 0; i < quant; i++) {
        printf("Código: %d, Nome: %s, Preço: %.2f, Quantidade: %.2f, Categoria: %s\n",
               products[i].cod_product, products[i].product, products[i].price, products[i].quantity, products[i].category);
    }
}

void show_product(Product product) {
    if(product.product[0] != '\0'){
        printf("%s (R$ %.2f cada)\n", product.product, product.price);
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

                sscanf(value, "%d", &products[*quant].cod_product);

                value = strtok(NULL, ",");
                strcpy(products[*quant].product, value);

                value = strtok(NULL, ",");
                strcpy(products[*quant].category, value);

                value = strtok(NULL, ",");
                sscanf(value, "%c", &products[*quant].type);

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
Product read_product(int *cod_product) {
    Product p = {.cod_product = *cod_product}; // Inicializa a struct e define o código do produto

    // Leitura dos dados do produto
    printf("procurando produto...\nDigite o nome e a categoria do produto:\n");
    getchar(); // Limpa o buffer
    scanf("%99[^\n]%*c%99[^\n]%*c", p.product, p.category);

    printf("Digite o tipo (q) para quilo ou (u) para unidade, quantidade e preço:\n");
    scanf(" %c%f%f", &p.type, &p.quantity, &p.price);

    // Leitura dos dados nutricionais
    printf("Digite calorias, proteínas, carboidratos, fibras e gordura:\n");
    scanf("%f %f %f %f %f", &p.calories, &p.proteins, &p.carbohydrate, &p.fibers, &p.fats);

    return p;
}



// Add produto atualizado a lista
void update_product(int *cod_product, Product new_product){
    FILE *fp = fopen("data/produtos_cad.csv", "r");
    FILE *temp_file = fopen("data/temp.csv", "w");
    if (fp == NULL || temp_file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int updated_line = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        char copy_line[MAX_LINE_LENGTH];
        strcpy(copy_line, line);
        
        char *campoStr = strtok(copy_line, ",");
        if(campoStr != NULL){
            int campoID = atoi(campoStr);
            if( campoID == *cod_product) {
                fprintf(temp_file, "%d,%s,%s,%c,%f,%f,%f,%f,%f,%f,%f\n", 
                    new_product.cod_product, new_product.product, 
                    new_product.category, new_product.type, new_product.quantity, 
                    new_product.price, new_product.calories,
                    new_product.proteins, new_product.carbohydrate, 
                    new_product.fibers, new_product.fats);
            updated_line = 1;
            }else fprintf(temp_file, "%s", line);
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

void find_product(int *cod_product_find, Product *product, int *quant) {
    FILE *fp = fopen("data/produtos_cad.csv", "r");
    if (fp == NULL) {
        printf("Can't open file\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        int cod_product;
        char product_name[100];
        char category[100];
        char type;
        float quantity, price, calories, proteins, carbohydrate, fibers, fats;

        if (sscanf(line, "%d,%99[^,],%99[^,], %c, %f,%f,%f,%f,%f,%f,%f",
                   &cod_product, product_name, category, &type,
                   &quantity, &price, &calories, &proteins, 
                   &carbohydrate, &fibers, &fats) == 11) {
            
            if (cod_product == *cod_product_find) {
                if (product != NULL) {
                    product[*quant].cod_product = cod_product;
                    strcpy(product[*quant].product, product_name);
                    strcpy(product[*quant].category, category);
                    product[*quant].type = type;
                    product[*quant].quantity = quantity;
                    product[*quant].price = price;
                    product[*quant].calories = calories;
                    product[*quant].proteins = proteins;
                    product[*quant].carbohydrate = carbohydrate;
                    product[*quant].fibers = fibers;
                    product[*quant].fats = fats;

                    fclose(fp);
                    return;
                } else {
                    printf("Erro: Ponteiro para produto é nulo.\n");
                    fclose(fp);
                    return;
                }
            }
        }
    }

    fclose(fp);
    printf("Produto com código %d não encontrado.\n", *cod_product_find);
}