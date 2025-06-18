#include "../../structs/usuario/stUsuario.h"

#ifndef CTRUSUARIO_H_INCLUDED
#define CTRUSUARIO_H_INCLUDED

Usuario ingresarUsuario(const char* archivo);
int idUsuarioUnico(const char* archivo, int id);
int nombreUsuarioUnico(const char* archivo, char* nombre);
int validarContrasenia(const char* archivo, char* nombreUsuario, char* contrasenia);
Usuario buscarUsuario(const char* archivo, char* nombreUsuario);

#endif // CTRUSUARIO_H_INCLUDED
