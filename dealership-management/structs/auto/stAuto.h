#ifndef STAUTO_H_INCLUDED
#define STAUTO_H_INCLUDED

#include "../persona/stPersona.h"

#define MAX_CARACT_AUTO_STANDARD 20

typedef struct stAuto {
	char patente[MAX_CARACT_AUTO_STANDARD]; // puede ser AB-1234-CD o AB1234CD
	char marca[MAX_CARACT_AUTO_STANDARD];   // o ABC-123 o ABC123
	char modelo[MAX_CARACT_AUTO_STANDARD];
	int año;
	int kms;
	Persona titular;
	float precioDeAdquisición;
} Auto;


#endif // STAUTO_H_INCLUDED
