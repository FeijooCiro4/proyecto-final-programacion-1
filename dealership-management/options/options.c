#include <stdio.h>
#include <stdlib.h>
#include "options.h"
#include "../utils/utils.h"
#include "../login/login.h"
#include "../prints/prints.h"
#include "../controllers/auto/ctrAuto.h"
#include "../structs/auto/stAutoDinamico.h"

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

void opcMenuVendedor(char* dniTitular, int opc){
    int subOpc;

    switch(opc){
    case 1:
        do{
            system("cls");
            printMenuVendedorGestAutos();
            subOpc = scanInt();
            while(!esEnteroPositivo(subOpc)){
                printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
                subOpc = scanInt();
            }
            opcMenuVendedorGestAutos(dniTitular, subOpc);
        } while(subOpc != 0);
        break;
    case 0:
        printf("\nCerrando sesion...\n");
        break;
    default:
        printf("\nError: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
        break;
    }
}

void opcMenuVendedorGestAutos(char* dniTitular, int opc){
    int subOpc;

    switch(opc){
    case 1:
        do{
           system("cls");
            printMenuVendedorVistaAutos();
            subOpc = scanInt();
            while(!esEnteroPositivo(subOpc)){
                printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
                subOpc = scanInt();
            }
            opcMenuVendedorVistaAutos(dniTitular, subOpc);
        } while(subOpc != 0);
        break;
    case 2:
        limpiarPantalla();
        printf("\t\t\tINSERION DE DATOS DE AUTOS\n");
        printf("\t---------------------------------------------------------------------\n");
        insertarAutos(dniTitular);
        limpiarPantalla();
        break;
    case 0:
        printf("\nVolviendo...\n");
        break;
    default:
        printf("\nError: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
        break;
    }
}

void opcMenuVendedorVistaAutos(char* dniTitular, int opc){
    AutoDinamico autoDin = pasarArchivoAutosAlArregloDinamico();

    switch(opc){
    case 1:
        system("cls");
        mostrarTodosLosAutosDelSistema(autoDin, 0);
        system("pause");
        break;
    case 2:
        system("cls");
        char patente[20];

        printf("Ingrese la patente del auto que quiere buscar: ");
        scanString(patente, 20);

        buscarUnAutoEnElSistema(autoDin, patente);
        system("pause");
        break;
    case 3:
        system("cls");
        mostrarAutosDeUnVendedor(autoDin, dniTitular);
        system("pause");
        break;
    case 0:
        printf("\nVolviendo...\n");
        break;
    default:
        printf("\nError: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
        break;
    }

    liberarAutoDinamico(&autoDin);
}
