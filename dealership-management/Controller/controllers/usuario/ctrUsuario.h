#include "../../../Model/structs/usuario/stUsuarioDinamico.h"

#ifndef CTRUSUARIO_H_INCLUDED
#define CTRUSUARIO_H_INCLUDED

Usuario ingresarUsuario(void);
int idUsuarioUnico(int id);
int nombreUsuarioUnico(char* nombre);
int validarContrasenia(char* nombreUsuario, char* contrasenia);
Usuario buscarUsuario(char* nombreUsuario);
Usuario buscarUsuarioPorDni(char* dniUsuario);
int cantidadDeCuentasPorDni(char* dni);
int vendedorExiste(char* dniVendedorBuscar);
UsuarioDinamico pasarArchivoUsuariosAUnArreglo(void);
void mostrarTodosLosUsuarios(UsuarioDinamico usuarioDin, int indice);
void mostrarUnUsuarioPorNombre(UsuarioDinamico usuarioDin, char* nombreUsuarioBuscar);
void mostrarTodosLosUsuariosDeUnRol(UsuarioDinamico usuarioDin, char rol, int indice);
void mostrarTodosLosUsuariosSinValidar(void);
void mostrarTodosLosUsuariosConAccesoAlSistema(void);
void ingresarVariosUsuarios(void);
void aceptarUsuarioEnSistema(char* dniUsuarioBuscar);
void negarAccesoUsuarioEnSistema(char* dniUsuarioBuscar);
void modificarNombreUsuario(char* dniUsuario, char* nombreUsuarioNuevo);
void modificarContraseniaUsuario(char* dniUsuario, char* contraseniaNueva);

#endif // CTRUSUARIO_H_INCLUDED
