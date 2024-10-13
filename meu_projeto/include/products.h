#if !defined PRODUCT_h
#define PRODUCT_h

typedef struct Products{
    char produto[100];
    int calorias;
    float proteinas;
    float carboidratos;
    float fibras;
    float gorduras;
    int porcao;
    int preco;
    char categoria[100];
};

void cadProduct (Products *products, int *quant ){

}

#endif 
