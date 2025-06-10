#ifndef STVENTA_H_INCLUDED
#define STVENTA_H_INCLUDED

#include "../fecha/stFecha.h"

#define MAX_CARACT_VENTA_STANDARD 20

typedef struct stVenta {
	Fecha fecha;
	char patenteAutoVendido[MAX_CARACT_VENTA_STANDARD];
	float precioVenta;
	float ganancia;
	int dniComprador;
	int dniVendedor;
} Venta;


#endif // STVENTA_H_INCLUDED
