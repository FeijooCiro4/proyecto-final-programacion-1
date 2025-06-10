#ifndef STUSUARIO_H_INCLUDED
#define STUSUARIO_H_INCLUDED

#include "../persona/stPersona.h"

#define MAX_CARACT_USUARIO_STANDARD 20

typedef struct stUsuario {
	char nombreUsuario[MAX_CARACT_USUARIO_STANDARD];
	char contrasenia[MAX_CARACT_USUARIO_STANDARD];
	Persona persona;
} Usuario;


#endif // STUSUARIO_H_INCLUDED
