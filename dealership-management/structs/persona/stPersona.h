#define MAX_CARACT_PERSONA_STANDARD 30
#define MAX_CARACT_PERSONA_DNI 8

#ifndef STPERSONA_H_INCLUDED
#define STPERSONA_H_INCLUDED

typedef struct stPersona {
	char dni[MAX_CARACT_PERSONA_STANDARD];
	char nombrePersona[MAX_CARACT_PERSONA_STANDARD];
	char apellidoPersona[MAX_CARACT_PERSONA_STANDARD];
	char telefono[MAX_CARACT_PERSONA_STANDARD];
	char ciudad[MAX_CARACT_PERSONA_STANDARD];
} Persona;

void mostrarUnaPersona(Persona personaMostrar);

#endif // STPERSONA_H_INCLUDED
