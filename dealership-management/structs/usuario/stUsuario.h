#ifndef STUSUARIO_H_INCLUDED
#define STUSUARIO_H_INCLUDED

#define MAX_CARACT_USUARIO_STANDARD 20

typedef struct stUsuario {
    int idUsuario;
	char nombreUsuario[MAX_CARACT_USUARIO_STANDARD];
	char contrasenia[MAX_CARACT_USUARIO_STANDARD];
	char rol; //c = comprador o v = vendedor
	int dniPersona;
} Usuario;

Usuario ingresarUsuario(char* archivo);
int idUsuarioUnico(char* archivo, int id);
int nombreUsuarioUnico(char* archivo, char* nombre);
int validarContrasenia(char* archivo, char* nombreUsuario, char* contrasenia);
Usuario buscarUsuario(char* archivo, char* nombreUsuario);
char* nombreRolUsuario(Usuario us);

#endif // STUSUARIO_H_INCLUDED
