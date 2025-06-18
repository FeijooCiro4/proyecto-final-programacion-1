#define MAX_CARACT_USUARIO_STANDARD 20
#define MAX_CARACT_USUARIO_DNI 10

#ifndef STUSUARIO_H_INCLUDED
#define STUSUARIO_H_INCLUDED


typedef struct stUsuario {
    int idUsuario;
	char nombreUsuario[MAX_CARACT_USUARIO_STANDARD];
	char contrasenia[MAX_CARACT_USUARIO_STANDARD];
	char rol; //c = comprador o v = vendedor o a = administrador
	char dniPersona[MAX_CARACT_USUARIO_DNI];
} Usuario;

Usuario inicializarUsuario(void);
char* nombreRolUsuario(Usuario us);

#endif // STUSUARIO_H_INCLUDED
