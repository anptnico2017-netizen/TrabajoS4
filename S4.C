#include <stdio.h>
#include "S4.h"
int main() {
    char nombres[maxprod][maxnom];
    float precios[maxprod];
    int n;
    int numeroderep;
    do {
        printf("---PRODUCTOS Y INVENTARIO---\n");
        printf("¿Cuantos productos desea ingresar? (Maximo %d): ", maxprod);
        scanf("%d", &n);
        if (n > maxprod) n = maxprod;
        if (n <= 0) n = 1;
        ingdato(nombres, precios, n);
        float resultadoTotal = total(precios, n);
        printf("--- RESULTADOS ---");
        printf("Total Inventario: $%.2f", resultadoTotal);
        printf("Precio Promedio:  $%.2f\n", resultadoTotal / n);
        prodbajoyalto(nombres, precios, n);
        buscprod(nombres, precios, n);
        printf("¿Quieres volver al menu? (1=si, 2=no): \n ");
        scanf("%d", &numeroderep);
    } while (numeroderep == 1);
    printf("Gracias\n");
    return 0;
}