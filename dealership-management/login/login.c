#include <stdio.h>
#include "login.h"
#include "../utils/utils.h"
#include "../controllers/usuario/ctrUsuario.h"
#include "../controllers/persona/ctrPersona.h"

static const char* ARCHIVO_USUARIOS = "usuarios.bin";
static const char* ARCHIVO_PERSONAS = "personas.bin";

extern bool iniciarSesion(Usuario *us){
    char nombreUsuario[20], contrasenia[20];

    printf("\t\t\tINICIO DE SESION\n");
    printf("Ingrese el nombre de usuario: ");
    scanString(nombreUsuario, 20);

    if(nombreUsuarioUnico(nombreUsuario)){
        printf("El nombre de usuario ingresado no existe.\n\n");
        limpiarPantalla();
        return false;
    }

    printf("Ingrese su contrasenia: ");
    scanString(contrasenia, 20);

    if(validarContrasenia(nombreUsuario, contrasenia)){
        printf("La contrasenia ingresada no es valida.\n\n");
        limpiarPantalla();
        return false;
    }

    *us = buscarUsuario(nombreUsuario);

    if(us->permisoDeIngreso == 0){
        printf("\nUsted no tiene permiso para entrar al sistema.\nEspere a que un administrador lo acepte.\n\n");
        limpiarPantalla();
        return false;
    }

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
        fclose(fpPersonas);
        return false;
    }

    Usuario usuario = ingresarUsuario();

    if(usuario.rol == 'a'){
        char codigoDeControl[] = "salamaneco%&!";
        char codigoInsercion[15];

        printf("Ingrese el codigo de control: ");
        scanString(codigoInsercion, 15);

        if(strcmp(codigoDeControl, codigoInsercion) == 0){
            usuario.permisoDeIngreso = 1;
        }
    }

    if(fwrite(&usuario, sizeof(Usuario), 1, fpUsuarios) != 1){
        perror("No se pudo escribir en el archivo de usuarios");
        fclose(fpUsuarios);
        fclose(fpPersonas);
        return false;
    }

    if(dniUnicoPersona(usuario.dniPersona)){
        printf("-------Sus datos no se encuentran en el sistema-------\n");
        Persona persona = ingresarPersona(usuario.dniPersona);

        if(fwrite(&persona, sizeof(Persona), 1, fpPersonas) != 1){
            perror("No se pudo escribir en el archivo de personas");
            fclose(fpUsuarios);
            fclose(fpPersonas);
            return false;
        }
    }

    if(usuario.permisoDeIngreso == 0){
        printf("\nUsted debera esperar a ser validado por un administrador.\n\n");
        fclose(fpUsuarios);
        fclose(fpPersonas);
        return false;
    }

    fclose(fpUsuarios);
    fclose(fpPersonas);
    return true;
}
