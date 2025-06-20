#include <stdlib.h>
#include <stdio.h>
#include "stVentaDinamica.h"

#define VALOR_DIMENSIONAMIENTO_VENTADINAMICA 2

void inicializarVentaDinamica(VentaDinamica *ventaDin, int dimensionInicial){
    ventaDin->dimension = dimensionInicial;
    ventaDin->arrayVenta = (Venta*)malloc(dimensionInicial*sizeof(Venta));

    if(ventaDin->arrayVenta == NULL){
        perror("Error al asignar memoria a un arreglo de ventas");
        ventaDin->validos = -1;
        return;
    }

    ventaDin->validos = 0;
}

void verificarRedimensionVentaDinamica(VentaDinamica* ventaDin){
    if(ventaDin->validos < ventaDin->dimension){
        return;
    }

    ventaDin->arrayVenta = (Venta*)realloc(ventaDin->arrayVenta, (ventaDin->dimension + VALOR_DIMENSIONAMIENTO_VENTADINAMICA) * sizeof(Venta));
    ventaDin->dimension += VALOR_DIMENSIONAMIENTO_VENTADINAMICA;
    printf("\n-----------------Redimencionamiento del arreglo-----------------\n");
}

void liberarVentaDinamica(VentaDinamica* ventaDin){
    free(ventaDin->arrayVenta);
    ventaDin->dimension = 0;
    ventaDin->validos = 0;
}
