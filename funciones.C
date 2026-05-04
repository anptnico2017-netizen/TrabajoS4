#include <stdio.h>
#include <string.h>
#include "S4.h"
void ingdato(char nombres[maxprod][maxnom], float precios[maxprod], int n) {
    for (int i = 0; i < n; i++) {
        printf("Producto %d:\n", i + 1);
        printf("Ingrese el nombre: \n");
        scanf("%s", nombres[i]); 
        printf("Ingrese el precio: \n");
        scanf("%f", &precios[i]);
    }
}
float total(float precios[maxprod], int n) {
    float acu = 0;
    for (int i = 0; i < n; i++) {
        acu += precios[i];
    }
    return acu;
}
void prodbajoyalto(char nombres[maxprod][maxnom], float precios[maxprod], int n) {
    int prodcaro = 0;
    int prodbarato = 0;
    for (int i = 1; i < n; i++) {
        if (precios[i] > precios[prodcaro]) {
            prodcaro = i;
        }
        if (precios[i] < precios[prodbarato]) {
            prodbarato = i;
        }
    }
    printf("El producto mas caro es: %s ($%.2f)\n", nombres[prodcaro], precios[prodcaro]);
    printf("El producto mas barato es: %s ($%.2f)\n", nombres[prodbarato], precios[prodbarato]);
}
void buscprod(char nombres[maxprod][maxnom], float precios[maxprod], int n) {
    char buscar[maxnom];
    int encon = 0;
    printf("Ingrese el nombre del producto a ver: \n");
    scanf("%s", buscar);
    for (int i = 0; i < n; i++) {
        int j = 0;
        int coinciden = 1; 
        while (nombres[i][j] != '\0' || buscar[j] != '\0') {
            if (nombres[i][j] != buscar[j]) {
                coinciden = 0; 
                break;
            }
            j++;
        }
        if (coinciden == 1) {
            printf("Resultado: El producto %s cuesta $%.2f\n", nombres[i], precios[i]);
            encon = 1;
            break; 
        }
    }
    if (encon == 0) {
        printf("Lo sentimos, el producto '%s' no existe.\n", buscar);
    }
}