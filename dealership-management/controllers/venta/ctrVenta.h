#include "../../structs/venta/stVentaDinamica.h"
#include "../../structs/persona/stPersonaDinamica.h"
#include "../../structs/auto/stAutoDinamico.h"

#ifndef CTRVENTA_H_INCLUDED
#define CTRVENTA_H_INCLUDED

void ingresarVentas(char* dniVendedor);
int idVentaUnicoArchivo(int idIngresado);
int idVentaUnicoArreglo(VentaDinamica ventaDin, int idIngresado);
int existeIdAutoEnArchivoVentas(char* patenteAuto);

VentaDinamica pasarArchivoTodasLasVentasAlArregloDinamico(void);
VentaDinamica pasarArchivoVentasAlArregloDinamico(char* dniVendedor);
void mostrarTodasLasVentasDelSistema(VentaDinamica ventaDin, int indice);
void mostrarAutosVendidosPorVendedor(AutoDinamico autoDin, char* dniVendedor);
void buscarUnaVentaEnElSistema(VentaDinamica ventaDin, int idBuscar);

float calcularMargenGananciaMensual(VentaDinamica ventaDin, int anio, int mes, int dia, int indice);
int calcularMargenDeGananciaMasAlto(VentaDinamica ventaDin);
void pasarClientesArregloPersonas(PersonaDinamica* personaDin, VentaDinamica ventaDin);

int ventasDeUnCliente(VentaDinamica* ventasCliente, char* dniCliente);

void borrarVenta(char* dniVendedor, int idVentaEliminar);

#endif // CTRVENTA_H_INCLUDED
