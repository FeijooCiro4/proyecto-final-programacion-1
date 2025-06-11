#include <stdio.h>
#include "options.h"
#include "../utils/utils.h"
#include "../login/login.h"

void opcLogin(int opc){
    switch(opc){
    case 1:
        system("cls");
        if(iniciarSesion()){
            system("cls");
            printf("Bienvenido!\n\n");
        } else {
            limpiarPantalla();
            printf("Error en el inicio de sesion.\n\n");
        }
        limpiarPantalla();
        break;
    case 2:
        system("cls");
        if(registroSesion()){
            printf("\n\tAhora debera iniciar sesion.\n\n");
        }
        limpiarPantalla();
        break;
    case 0:
        limpiarPantalla();
        printf("Gracias por probar el programa!\n");
        break;
    default:
        printf("Error: La opcion que ha ingresado no es valida...\n");
        limpiarPantalla();
        break;
    }
}
