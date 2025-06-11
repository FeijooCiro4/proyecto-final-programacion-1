#include <stdio.h>
#include <string.h>
#include "stUsuario.h"
#include "../../utils/utils.h"

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

    printf("Rol [Comprador (c) o Vendedor (v)]: ");
    us.rol = scanChar();

    printf("Ingrese su dni: ");
    us.dniPersona = scanInt();
    while (!esEnteroPositivo(us.idUsuario)){
        printf("El dni ingresado no es valido. Ingrese otro: ");
        us.dniPersona = scanInt();
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
