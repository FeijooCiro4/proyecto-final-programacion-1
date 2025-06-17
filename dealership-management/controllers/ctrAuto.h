#include "../structs/auto/stAutoDinamico.h"

#ifndef CTRAUTO_H_INCLUDED
#define CTRAUTO_H_INCLUDED

void insertarAutos(char* dniTitular);
int datosDeAutoValidosArchivo(Auto autoIngresado, const char* archivo);
int datosDeAutoValidosArreglo(Auto autoIngresado, AutoDinamico arregloAutos);

void mostrarTodosLosAutosDelSistema(AutoDinamico autoDin, int indice);
AutoDinamico pasarArchivoAutosAlArregloDinamico(void);

#endif // CTRAUTO_H_INCLUDED
