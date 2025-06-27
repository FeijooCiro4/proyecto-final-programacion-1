#include "../../constants/constants.h"

#ifndef STAUTO_H_INCLUDED
#define STAUTO_H_INCLUDED

typedef struct stAuto {
	char patente[MAX_CARACT_AUTO_STANDARD];
	char marca[MAX_CARACT_AUTO_STANDARD];
	char modelo[MAX_CARACT_AUTO_STANDARD];
	int anio;
	int kms;
	char dniTitular[MAX_CARACT_AUTO_DNITITULAR];
	float precioDeAdquisicion;
} Auto;

Auto ingresarAuto(char* dniTitular);
void mostrarUnAuto(Auto aut);
void mostrarUnAutoCompleto(Auto aut);

#endif // STAUTO_H_INCLUDED
