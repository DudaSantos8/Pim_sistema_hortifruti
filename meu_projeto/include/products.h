#if !defined PRODUCT_h
#define PRODUCT_h

typedef struct{
    int cod_product;
    char product[100];
    char category[100];
    char type;
    float quantity;
    float price;
    float calories;
    float proteins;
    float carbohydrate;
    float fibers;
    float fats;
}Product;

void cad_product(Product *product, int *quant);
void list_product(Product *Products, int quant);
void show_product(Product product);
void cad_all_products_DB(Product *products, int *quant);
Product read_product(int *cod_product);
void update_product(int *cod_product, Product new_product);
void find_product(int *cod_product_find, Product *product, int *quant);

#endif 
