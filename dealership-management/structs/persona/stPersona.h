#ifndef STPERSONA_H_INCLUDED
#define STPERSONA_H_INCLUDED

#define MAX_CARACT_PERSONA_STANDARD 30
#define MAX_CARACT_PERSONA_DNI 8

typedef struct stPersona {
	char dni[MAX_CARACT_PERSONA_STANDARD];
	char nombrePersona[MAX_CARACT_PERSONA_STANDARD];
	char apellidoPersona[MAX_CARACT_PERSONA_STANDARD];
	char telefono[MAX_CARACT_PERSONA_STANDARD];
	char ciudad[MAX_CARACT_PERSONA_STANDARD];
} Persona;

Persona ingresarPersona(char* archivo, const char* dniRegistrado);
int dniUnicoPersona(char* archivo, const char *dni);
int validarNumeroTelefonoPersona(const char *telefono);

#endif // STPERSONA_H_INCLUDED
