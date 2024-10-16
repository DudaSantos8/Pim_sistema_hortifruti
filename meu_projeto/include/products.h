#if !defined PRODUCT_h
#define PRODUCT_h

typedef struct{
    char produto[100];
    int calorias;
    float proteinas;
    float carboidratos;
    float fibras;
    float gorduras;
    int porcao;
    int preco;
    char categoria[100];
}Product;

void cadProduct (Product *product, int *quant);
void listProduct (Product *Products, int quant);

#endif 
