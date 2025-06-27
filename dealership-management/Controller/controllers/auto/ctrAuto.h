#include "../../../Model/structs/auto/stAutoDinamico.h"

#ifndef CTRAUTO_H_INCLUDED
#define CTRAUTO_H_INCLUDED

void insertarAutos(char* dniTitular);
int datosDeAutoValidosArchivo(Auto autoIngresado);
int datosDeAutoValidosArreglo(Auto autoIngresado, AutoDinamico arregloAutos);

AutoDinamico pasarArchivoAutosAlArregloDinamico(void);
AutoDinamico pasarArchivoAutosALaVentaAlArregloDinamico(void);
AutoDinamico pasarArchivoAutosVendidosAlArregloDinamico(void);
void mostrarTodosLosAutosALaVenta(AutoDinamico autoDin, int indice);
void mostrarTodosLosAutosDeUnArreglo(AutoDinamico autoDin, int indice);
void buscarUnAutoEnElSistema(AutoDinamico autoDin, char* patenteBuscar);
void mostrarAutosDeUnVendedor(AutoDinamico autoDin, char* dniTitular);

int existeIdAutoDeUnVendedorEnArchivo(char* patenteAuto, char* dniVendeor);
Auto* retornarAutoDeArchivo(char* patenteAuto);

void modificarTitularAuto(Auto* autoCambiar, char* dniNuevoTitular);
void modificarMarcaAuto(char* patente, char* dniTitular, char* marcaNueva);
void modificarModeloAuto(char* patente, char* dniTitular, char* modeloNuevo);
void modificarAnioAdqAuto(char* patente, char* dniTitular, int anioAdqNuevo);
void modificarKmAuto(char* patente, char* dniTitular, int kmNuevo);
void modificarPrecioAdqAuto(char* patente, char* dniTitular, float precioAdqNuevo);

AutoDinamico ordenarArregloDeAutos(AutoDinamico autoDin);

void borrarAuto(char* dniTitular, char* patenteAutoBorrar);

#endif // CTRAUTO_H_INCLUDED
