#include <stdio.h>
#include "login.h"
#include "../utils/utils.h"
#include "../structs/persona/stPersona.h"

static const char* ARCHIVO_USUARIOS = "usuarios.bin";
static const char* ARCHIVO_PERSONAS = "personas.bin";

extern bool iniciarSesion(Usuario *us){
    char nombreUsuario[20], contrasenia[20];

    printf("\t\t\tINICIO DE SESION\n");
    printf("Ingrese el nombre de usuario: ");
    scanString(nombreUsuario, 20);

    if(nombreUsuarioUnico(ARCHIVO_USUARIOS, nombreUsuario)){
        printf("El nombre de usuario ingresado no existe.\n\n");
        limpiarPantalla();
        return false;
    }

    printf("Ingrese su contrasenia: ");
    scanString(contrasenia, 20);

    if(validarContrasenia(ARCHIVO_USUARIOS, nombreUsuario, contrasenia)){
        printf("La contrasenia ingresada no es valida.\n\n");
        limpiarPantalla();
        return false;
    }

    *us = buscarUsuario(ARCHIVO_USUARIOS, nombreUsuario);

    return true;
}

extern bool registroSesion(){
    FILE* fpUsuarios = fopen(ARCHIVO_USUARIOS, "ab");
    FILE* fpPersonas = fopen(ARCHIVO_PERSONAS, "ab");

    if(fpPersonas == NULL){
        perror("Error al abrir el archivo de personas");
        return false;
    }

    if(fpUsuarios == NULL){
        perror("Error al abrir el archivo de usuarios");
        return false;
    }

    printf("\t\t\tREGISTRO DE SESION\n");
    Usuario usuario = ingresarUsuario(ARCHIVO_USUARIOS);

    if(fwrite(&usuario, sizeof(Usuario), 1, fpUsuarios) != 1){
        perror("No se pudo escribir en el archivo de usuarios");
        return false;
    }

    if(dniUnicoPersona(ARCHIVO_PERSONAS, usuario.dniPersona)){
        Persona persona = ingresarPersona(ARCHIVO_PERSONAS, usuario.dniPersona);

        if(fwrite(&persona, sizeof(Persona), 1, fpPersonas) != 1){
            perror("No se pudo escribir en el archivo de personas");
            return false;
        }
    }

    fclose(fpUsuarios);
    fclose(fpPersonas);
    return true;
}
