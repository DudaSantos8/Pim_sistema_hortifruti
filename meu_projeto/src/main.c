#include <stdio.h>
#include <string.h>

struct compra{
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

int main(){

    struct compra compras[100];
    int n=0;

    FILE* fp = fopen("data/produtos_cad.csv", "r");
    if (!fp){
        printf("Can't open file\n");
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
            char* value = strtok(buffer, ";");

            if (value) {
                has_value = 1;

                strcpy(compras[n].produto, value);

                value = strtok(NULL, ";");
                sscanf(value, "%d", &compras[n].calorias);

                value = strtok(NULL, ";");
                sscanf(value, "%f", &compras[n].proteinas);

                value = strtok(NULL, ";");
                sscanf(value, "%f", &compras[n].carboidratos);

                value = strtok(NULL, ";");
                sscanf(value, "%f", &compras[n].fibras);

                value = strtok(NULL, ";");
                sscanf(value, "%f", &compras[n].gorduras);

                value = strtok(NULL, ";");
                sscanf(value, "%d", &compras[n].porcao);

                value = strtok(NULL, ";");
                sscanf(value, "%d", &compras[n].preco);

                value = strtok(NULL, ";");
                sscanf(value, "%s", compras[n].categoria);
            }

            if(has_value==1){
                n++;
            }
        }

        fclose(fp);
    }

    for(int i=0; i<n; i++){
        printf("produto %d\n", i+1);
        printf("nome %s\n", compras[i].produto);
        printf("categoria %s\n", compras[i].categoria);
        printf("preco %d\n", compras[i].preco);
        printf("\n");
    }
    getchar();
    return 0;
}