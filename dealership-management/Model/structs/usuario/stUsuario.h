#include "../../constants/constants.h"

#ifndef STUSUARIO_H_INCLUDED
#define STUSUARIO_H_INCLUDED


typedef struct stUsuario {
    int idUsuario;
	char nombreUsuario[MAX_CARACT_USUARIO_STANDARD];
	char contrasenia[MAX_CARACT_USUARIO_STANDARD];
	char rol;
	char dniPersona[MAX_CARACT_USUARIO_DNI];
	int permisoDeIngreso;
} Usuario;

Usuario inicializarUsuario(void);
char* nombreRolUsuario(Usuario us);
void mostrarUnUsuario(Usuario us);

#endif // STUSUARIO_H_INCLUDED
