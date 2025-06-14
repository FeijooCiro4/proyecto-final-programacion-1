#include <stdio.h>
#include <stdlib.h>
#include "options.h"
#include "../utils/utils.h"
#include "../login/login.h"

bool opcLogin(Usuario *us, int opc){
    bool val=false;

    switch(opc){
    case 1:
        system("cls");
        if(iniciarSesion(us)){
            val = true;
        } else {
            val = false;
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
        val = false;
        break;
    default:
        val = false;
        printf("Error: La opcion que ha ingresado no es valida...\n");
        limpiarPantalla();
        break;
    }

    return val;
}
