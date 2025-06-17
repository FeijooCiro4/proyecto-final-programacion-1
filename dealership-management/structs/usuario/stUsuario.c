#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stUsuario.h"
#include "../../utils/utils.h"

Usuario inicializarUsuario(void){
    Usuario us;

    us.idUsuario = 0;
    us.nombreUsuario[0] = '\0';
    us.contrasenia[0] = '\0';
    us.rol = '\0';
    us.dniPersona[0] = '\0';

    return us;
}

Usuario ingresarUsuario(char* archivo){
    Usuario us;

    printf("Id del Usuario: ");
    us.idUsuario = scanInt();
    while (!esEnteroPositivo(us.idUsuario) || !idUsuarioUnico(archivo, us.idUsuario)){
        printf("El id ingresado no es valido. Ingrese otro: ");
        us.idUsuario = scanInt();
    }

    printf("Nombre de usuario: ");
    scanString(us.nombreUsuario, MAX_CARACT_USUARIO_STANDARD);
    while(!nombreUsuarioUnico(archivo, us.nombreUsuario)){
        printf("El nombre ingresado no es valido. Ingrese otro: ");
        scanString(us.nombreUsuario, MAX_CARACT_USUARIO_STANDARD);
    }

    printf("Contrasenia: ");
    scanString(us.contrasenia, MAX_CARACT_USUARIO_STANDARD);

    printf("Rol [Comprador (c) - Vendedor (v)- Administrador (a)]: ");
    us.rol = scanChar();
    us.rol = tolower(us.rol);
    while (us.rol != 'c' && us.rol != 'v' && us.rol != 'a') {
        printf("El rol ingresado es invalido. Ingrese otro: ");
        us.rol = scanChar();
        us.rol = tolower(us.rol);
    }

    printf("Ingrese su dni: ");
    scanString(us.dniPersona, MAX_CARACT_USUARIO_DNI);
    while(!esDniValido(us.dniPersona)){
        printf("El dni ingresado es invalido. Ingrese otro: ");
        scanString(us.dniPersona, MAX_CARACT_USUARIO_DNI);
    }

    return us;
}

int idUsuarioUnico(char* archivo, int id){
    FILE* fp = fopen(archivo, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de usuarios");
        return 0;
    }

    Usuario usAux;

    while(fread(&usAux, sizeof(Usuario), 1, fp) == 1){
        if(usAux.idUsuario == id){
            return 0;
        }
    }
    fclose(fp);

    return 1;
}

int nombreUsuarioUnico(char* archivo, char* nombre){
    FILE* fp = fopen(archivo, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de usuarios");
        return 0;
    }

    Usuario usAux;

    while(fread(&usAux, sizeof(Usuario), 1, fp) == 1){
        if(strcmp(usAux.nombreUsuario, nombre) == 0){
            return 0;
        }
    }
    fclose(fp);

    return 1;
}

int validarContrasenia(char* archivo, char* nombreUsuario, char* contrasenia){
    FILE* fp = fopen(archivo, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de usuarios");
        return 0;
    }

    Usuario usAux;

    while(fread(&usAux, sizeof(Usuario), 1, fp) == 1){
        if(strcmp(usAux.nombreUsuario, nombreUsuario) == 0){
            if(strcmp(usAux.contrasenia, contrasenia) == 0){
                return 0;
            }
        }
    }
    fclose(fp);

    return 1;
}

Usuario buscarUsuario(char* archivo, char* nombreUsuario){
    FILE* fp = fopen(archivo, "rb");
    Usuario usAux = inicializarUsuario();

    if(fp == NULL){
        perror("Error al abrir el archivo de usuarios");
        return usAux;
    }

    while(fread(&usAux, sizeof(Usuario), 1, fp) == 1){
        if(strcmp(usAux.nombreUsuario, nombreUsuario) == 0){
            fclose(fp);
            return usAux;
        }
    }

    fclose(fp);
    return usAux;
}

char* nombreRolUsuario(Usuario us){
    if(us.rol == 'c'){
        return "comprador";
    } else if (us.rol == 'v'){
        return "vendedor";
    } else if (us.rol == 'a'){
        return "admin";
    }

    return "desconosido";
}
