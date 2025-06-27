#include <stdio.h>
#include "View/options/options.h"
#include "View/prints/prints.h"
#include "View/utils/utils.h"
#include "Model/structs/usuario/stUsuario.h"

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

        int opcMenu;

        if(opcLog == 3){
            do {
                printf("---------------------------------------------------------------------\n");
                printf("\t\tBienvenido usuario anonimo!");
                printf("\n---------------------------------------------------------------------\n");

                printMenuUsuarioGeneral();

                opcMenu = scanInt();
                while(esEnteroPositivo(opcMenu) == 0){
                    printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
                    opcMenu = scanInt();
                }

                opcMenuUsuarioGeneral(opcMenu);
            } while(opcMenu != 0);
        } else if(loginValido && opcLog != 3){
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
                } else if(us.rol == 'a'){
                    printMenuAdmin();

                    opcMenu = scanInt();
                    while(esEnteroPositivo(opcMenu) == 0){
                        printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
                        opcMenu = scanInt();
                    }

                    opcMenuAdmin(us.dniPersona, opcMenu);
                } else {
                    printf("\t\t\t\nPestania no disponble.\n");
                    opcMenu = 0;
                }

                limpiarPantalla();
            } while(opcMenu != 0);
        }
    } while(opcLog != 0);

    limpiarPantalla();
    printf("Gracias por probar el programa!\n");

    return 0;
}
