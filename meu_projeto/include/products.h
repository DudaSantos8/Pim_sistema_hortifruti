#if !defined PRODUCT_h
#define PRODUCT_h

typedef struct{
    int cod_product;
    char product[100];
    int calories;
    float proteins;
    float carbohydrate;
    float fibers;
    float fats;
    int portion;
    int price;
    char category[100];
}Product;

void cadProduct (Product *product, int *quant);
void updateProduct(Product *product, int *quant, int cod_product);
void listProduct (Product *Products, int quant);
void cadAllProductsDB(Product *products, int *quant);

#endif 
