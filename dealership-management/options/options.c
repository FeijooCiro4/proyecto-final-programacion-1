#include <stdio.h>
#include "options.h"
#include "../utils/utils.h"
#include "../login/login.h"

int opcLogin(Usuario *us, int opc){
    int val=0;

    switch(opc){
    case 1:
        system("cls");
        if(iniciarSesion(us)){
            val = 1;
        } else {
            val = 0;
        }
        break;
    case 2:
        system("cls");
        if(registroSesion()){
            printf("\n\tAhora debera iniciar sesion.\n\n");
        }
        limpiarPantalla();
        break;
    case 0:
        val = 0;
        break;
    default:
        val = 0;
        printf("Error: La opcion que ha ingresado no es valida...\n");
        limpiarPantalla();
        break;
    }

    return val;
}
