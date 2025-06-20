#include "../../structs/venta/stVentaDinamica.h"

#ifndef CTRVENTA_H_INCLUDED
#define CTRVENTA_H_INCLUDED

void ingresarVentas(char* dniVendedor);
int idVentaUnicoArchivo(const char* archivo, int idIngresado);
int idVentaUnicoArreglo(VentaDinamica ventaDin, int idIngresado);
int existeIdAutoEnArcivoVentas(const char* archivo, char* patenteAuto);

VentaDinamica pasarArchivoVentasAlArregloDinamico(char* dniVendedor);
void mostrarTodasLasVentasDelSistema(VentaDinamica ventaDin, int indice);
void buscarUnaVentaEnElSistema(VentaDinamica ventaDin, int idBuscar);

#endif // CTRVENTA_H_INCLUDED
