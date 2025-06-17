#include "../fecha/stFecha.h"

#define MAX_CARACT_VENTA_STANDARD 20

#ifndef STVENTA_H_INCLUDED
#define STVENTA_H_INCLUDED


typedef struct stVenta {
    int idVenta;
	Fecha fecha;
	char patenteAutoVendido[MAX_CARACT_VENTA_STANDARD];
	float precioVenta;
	float ganancia;
	int dniComprador;
	int dniVendedor;
	int estado[MAX_CARACT_AUTO_STANDARD]; // normal o cancelado
} Venta;


#endif // STVENTA_H_INCLUDED
