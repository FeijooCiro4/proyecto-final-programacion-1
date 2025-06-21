#include <stdio.h>
#include <stdlib.h>
#include "options.h"
#include "../utils/utils.h"
#include "../login/login.h"
#include "../prints/prints.h"
#include "../controllers/auto/ctrAuto.h"
#include "../controllers/venta/ctrVenta.h"
#include "../controllers/usuario/ctrUsuario.h"
#include "../controllers/persona/ctrPersona.h"
#include "../structs/auto/stAutoDinamico.h"
#include "../structs/venta/stVentaDinamica.h"
#include "../structs/persona/stPersonaDinamica.h"

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
    case 2:
        do{
            system("cls");
            printMenuVendedorGestVentas();
            subOpc = scanInt();
            while(!esEnteroPositivo(subOpc)){
                printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
                subOpc = scanInt();
            }
            opcMenuVendedorGestVentas(dniTitular, subOpc);
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
    case 4:
        system("cls");
        mostrarAutosVendidosPorVendedor(autoDin, dniTitular);
        system("pause");
    case 0:
        printf("\nVolviendo...\n");
        limpiarPantalla();
        break;
    default:
        printf("\nError: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
        break;
    }

    liberarAutoDinamico(&autoDin);
}

void opcMenuVendedorGestVentas(char* dniVendedor, int opc){
    int subOpc;

    switch(opc){
    case 1:
        do{
           system("cls");
            printMenuVendedorVistaVentas();
            subOpc = scanInt();
            while(!esEnteroPositivo(subOpc)){
                printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
                subOpc = scanInt();
            }
            opcMenuVendedorVistaVentas(dniVendedor, subOpc);
        } while(subOpc != 0);
        break;
        break;
    case 2:
        limpiarPantalla();
        printf("\t\t\tINSERION DE DATOS DE VENTAS\n");
        printf("\t---------------------------------------------------------------------\n");
        ingresarVentas(dniVendedor);
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

void opcMenuVendedorVistaVentas(char* dniVendedor, int opc){
    VentaDinamica ventaDin = pasarArchivoVentasAlArregloDinamico(dniVendedor);

    switch(opc){
    case 1:
        system("cls");
        mostrarTodasLasVentasDelSistema(ventaDin, 0);
        system("pause");
        break;
    case 2:
        system("cls");
        int idBuscar;

        printf("Ingrese el numero de ID de la venta que quiere buscar: ");
        idBuscar = scanInt();

        buscarUnaVentaEnElSistema(ventaDin, idBuscar);
        system("pause");
        break;
    case 0:
        printf("\nVolviendo...\n");
        limpiarPantalla();
        break;
    default:
        printf("\nError: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
        break;
    }

    liberarVentaDinamica(&ventaDin);
}

void opcMenuComprador(int opc){
    int subOpc;

    switch(opc){
    case 1:
        do{
            system("cls");
            printMenuCompradorVistaAutos();
            subOpc = scanInt();
            while(!esEnteroPositivo(subOpc)){
                printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
                subOpc = scanInt();
            }
            opcMenuCompradorVistaAutos(subOpc);
        } while(subOpc != 0);
        break;
    case 2:
        do{
            system("cls");
            printMenuCompradorVistaVendedores();
            subOpc = scanInt();
            while(!esEnteroPositivo(subOpc)){
                printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
                subOpc = scanInt();
            }
            opcMenuCompradorVistaVendedores(subOpc);
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

void opcMenuCompradorVistaAutos(int opc){
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
    case 0:
        printf("\nVolviendo...\n");
        limpiarPantalla();
        break;
    default:
        printf("\nError: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
        break;
    }

    liberarAutoDinamico(&autoDin);
}

void opcMenuCompradorVistaVendedores(int opc){
    PersonaDinamica personaDin = pasarArchivoPesonasAlArreglo('v');

    switch(opc){
    case 1:
        system("cls");
        mostrarTodasLasPersonas(personaDin, 0);
        system("pause");
        break;
    case 2:
        system("cls");
        char nombre[30];

        printf("Ingrese el nombre del vendedor que quiere buscar: ");
        scanString(nombre, 30);

        buscarPersonaEnArreglo(personaDin, nombre);
        system("pause");
        break;
    case 0:
        printf("\nVolviendo...\n");
        limpiarPantalla();
        break;
    default:
        printf("\nError: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
        break;
    }

    liberarPersonaDinamica(&personaDin);
}
