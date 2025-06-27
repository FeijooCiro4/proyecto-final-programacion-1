#include "stVenta.h"

#ifndef STVENTADINAMICA_H_INCLUDED
#define STVENTADINAMICA_H_INCLUDED

typedef struct stVentaDinamica {
    Venta* arrayVenta;
    int dimension;
    int validos;
} VentaDinamica;

void inicializarVentaDinamica(VentaDinamica* ventaDin, int dimensionInicial);
void verificarRedimensionVentaDinamica(VentaDinamica* ventaDin);
void liberarVentaDinamica(VentaDinamica* ventaDin);

#endif // STVENTADINAMICA_H_INCLUDED
