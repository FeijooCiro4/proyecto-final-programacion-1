#include "../fecha/stFecha.h"
#include "../../constants/constants.h"

#ifndef STVENTA_H_INCLUDED
#define STVENTA_H_INCLUDED


typedef struct stVenta {
    int idVenta;
    char dniComprador[MAX_CARACT_VENTA_DNI];
	char dniVendedor[MAX_CARACT_VENTA_DNI];
	char patenteAutoVendido[MAX_CARACT_VENTA_STANDARD]; //
	float precioVenta;
	float ganancia; //
	Fecha fecha;
} Venta;

Venta ingresarUnaVenta(char* dniVendedor);
void mostrarUnaVenta(Venta ventaMostrar);

#endif // STVENTA_H_INCLUDED
