#include<stdio.h>
#include<string.h>
#include "products.h"


void cadProduct (Product *products, int *quant){
    printf("Digite o nome do produto: ");
    scanf("%s", products[*quant].produto);

    printf("Digite as calorias do produto: ");
    scanf("%d", &products[*quant].calorias);

    printf("Digite as proteinas do produto: ");
    scanf("%f", &products[*quant].proteinas);

    printf("Digite os carboidratos do produto: ");
    scanf("%f", &products[*quant].carboidratos);

    printf("Digite as fibras do produto: ");
    scanf("%f", &products[*quant].fibras);

    printf("Digite a gordura do produto: ");
    scanf("%f", &products[*quant].gorduras);

    printf("Digite a porção do produto: ");
    scanf("%d", &products[*quant].porcao);

    printf("Digite o preço do produto: ");
    scanf("%d", &products[*quant].preco);

    printf("Digite a categoria do produto: ");
    scanf("%s", products[*quant].categoria);
    (*quant)++;
}