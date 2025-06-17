#include <stdio.h>
#include "options/options.h"
#include "prints/prints.h"
#include "utils/utils.h"
#include "structs/usuario/stUsuario.h"

int main(){
    int opcLog, loginValido;
    Usuario us;

    do {
        printLogin();
        opcLog = scanInt();
        while(esEnteroPositivo(opcLog) == 0){
            printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
            opcLog = scanInt();
        }
        loginValido = opcLogin(&us, opcLog);
        //if(loginValido) opcLog = 0;
        if(loginValido){
            int opcMenu;

            limpiarPantalla();

            do {
                printf("---------------------------------------------------------------------\n");
                printf("\t\tBienvenido %s %s!", nombreRolUsuario(us), us.nombreUsuario);
                printf("\n---------------------------------------------------------------------\n");

                if(us.rol == 'v'){
                    printMenuVendedor();

                    opcMenu = scanInt();
                    while(esEnteroPositivo(opcMenu) == 0){
                        printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
                        opcMenu = scanInt();
                    }

                    opcMenuVendedor(us.dniPersona, opcMenu);
                } else if(us.rol == 'c'){
                    printf("\t\t\t\nPestania no disponble.\n");
                } else if(us.rol == 'a'){
                    printf("\t\t\t\nPestania no disponble.\n");
                }

                limpiarPantalla();
            } while(opcMenu != 0);
        }
    } while(opcLog != 0);

    limpiarPantalla();
    printf("Gracias por probar el programa!\n");

    return 0;
}
