#include <stdio.h>
#include "login.h"
#include "../utils/utils.h"
#include "../structs/usuario/stUsuario.h"

static const char* ARCHIVO_USUARIOS = "usuarios.bin";

extern int iniciarSesion(){
    FILE* fp = fopen(ARCHIVO_USUARIOS, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de usuarios");
        return 0;
    }

    char nombreUsuario[20], contrasenia[20];

    printf("\t\t\tINICIO DE SESION\n");
    printf("Ingrese el nombre de usuario: ");
    scanString(nombreUsuario, 20);

    if(nombreUsuarioUnico(ARCHIVO_USUARIOS, nombreUsuario)){
        printf("El nombre de usuario ingresado no existe.\n");
        return 0;
    }

    printf("Ingrese su contrasenia: ");
    scanString(contrasenia, 20);

    if(validarContrasenia(ARCHIVO_USUARIOS, nombreUsuario, contrasenia)){
        printf("La contrasenia ingresada no es valida.\n");
        return 0;
    }

    fclose(fp);
    return 1;
}

extern int registroSesion(){
    FILE* fp = fopen(ARCHIVO_USUARIOS, "ab");

    if(fp == NULL){
        perror("Error al abrir el archivo de usuarios");
        return 0;
    }

    printf("\t\t\tREGISTRO DE SESION\n");
    Usuario usuario = ingresarUsuario(ARCHIVO_USUARIOS);

    if(fwrite(&usuario, sizeof(Usuario), 1, fp) != 1){
        perror("No se pudo escribir el el archivo de usuarios");
        return 0;
    }

    fclose(fp);
    return 1;
}
