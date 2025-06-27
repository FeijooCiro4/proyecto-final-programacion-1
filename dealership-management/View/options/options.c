#include <stdio.h>
#include <stdlib.h>
#include "options.h"
#include "../utils/utils.h"
#include "../prints/prints.h"
#include "../../Model/constants/constants.h"
#include "../../Model/structs/auto/stAutoDinamico.h"
#include "../../Model/structs/venta/stVentaDinamica.h"
#include "../../Model/structs/persona/stPersonaDinamica.h"
#include "../../Controller/login/login.h"
#include "../../Controller/controllers/auto/ctrAuto.h"
#include "../../Controller/controllers/venta/ctrVenta.h"
#include "../../Controller/controllers/usuario/ctrUsuario.h"
#include "../../Controller/controllers/persona/ctrPersona.h"

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
        printf("\t\t\tREGISTRO DE SESION\n");
        if(registroSesion()){
            printf("\n\tAhora debera iniciar sesion.\n\n");
        }
        limpiarPantalla();
        break;
    case 3:
        printf("\n\t\tIngresando como usuario anonimo.\n\n");
        val = false;
        limpiarPantalla();
        break;
    case 0:
        val = false;
        break;
    default:
        printf("Error: La opcion que ha ingresado no es valida...\n");
        val = false;
        limpiarPantalla();
        break;
    }

    return val;
}

void opcMenuUsuarioGeneral(int opc){
    AutoDinamico autoDin = pasarArchivoAutosAlArregloDinamico();

    switch(opc){
    case 1:
        system("cls");
        mostrarTodosLosAutosALaVenta(autoDin, START_INDEX);
        limpiarPantalla();
        break;
    case 2:
        system("cls");
        char patente[MAX_CARACT_STRING];

        printf("Ingrese la patente del auto que quiere buscar: ");
        scanString(patente, MAX_CARACT_STRING);

        buscarUnAutoEnElSistema(autoDin, patente);
        limpiarPantalla();
        break;
    case 3:
        system("cls");
        AutoDinamico autoDinOrdenado = ordenarArregloDeAutos(autoDin);
        mostrarTodosLosAutosALaVenta(autoDinOrdenado, START_INDEX);
        limpiarPantalla();
        break;
    case 0:
        printf("\nCerrando sesion...\n");
        limpiarPantalla();
        break;
    default:
        printf("\n\tError: La opcion que ha ingresado no es valida.\n");
        limpiarPantalla();
        break;
    }

    liberarAutoDinamico(&autoDin);
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
        } while(subOpc != EXIT_VALUE);
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
        } while(subOpc != EXIT_VALUE);
        break;
    case 3:
        do{
            system("cls");
            printMenuVendedorGestEstadisticas();
            subOpc = scanInt();
            while(!esEnteroPositivo(subOpc)){
                printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
                subOpc = scanInt();
            }
            opcMenuVendedorGestEstadisticas(dniTitular, subOpc);
        } while(subOpc != EXIT_VALUE);
        break;
    case 4:
        do{
            system("cls");
            printMenuModificarDatosPesonales();
            subOpc = scanInt();
            while(!esEnteroPositivo(subOpc)){
                printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
                subOpc = scanInt();
            }
            opcMenuModificarDatosPesonales(dniTitular, subOpc);
        } while(subOpc != EXIT_VALUE);
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
        } while(subOpc != EXIT_VALUE);
        break;
    case 2:
        limpiarPantalla();
        printf("\t\t\tINSERION DE DATOS DE AUTOS\n");
        printf("\t---------------------------------------------------------------------\n");
        insertarAutos(dniTitular);
        limpiarPantalla();
        break;
    case 3:
        do{
           system("cls");
            printMenuModificarAutos();
            subOpc = scanInt();
            while(!esEnteroPositivo(subOpc)){
                printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
                subOpc = scanInt();
            }
            opcMenuModificarAutos(dniTitular, subOpc);
        } while(subOpc != EXIT_VALUE);
        break;
    case 4:
        system("cls");

        printf("Usted esta seguro de querer eliminar un auto del sistema? (s/n): ");
        if(confirmar('s')){
            char patenteAutoBorrar[MAX_CARACT_STRING];

            printf("Ingrese la patente del auto que desea borrar: ");
            scanString(patenteAutoBorrar, MAX_CARACT_STRING);

            if(existeIdAutoDeUnVendedorEnArchivo(patenteAutoBorrar, dniTitular)){
                borrarAuto(dniTitular, patenteAutoBorrar);
            } else {
                printf("\nLa patente ingresada no pertenece a ningun auto en el sistema.\n\n");
            }
        }
        system("pause");
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
        mostrarTodosLosAutosALaVenta(autoDin, START_INDEX);
        system("pause");
        break;
    case 2:
        system("cls");
        char patente[MAX_CARACT_STRING];

        printf("Ingrese la patente del auto que quiere buscar: ");
        scanString(patente, MAX_CARACT_STRING);

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
        break;
    case 5:
        system("cls");
        AutoDinamico autoDinOrdenado = ordenarArregloDeAutos(autoDin);
        mostrarTodosLosAutosALaVenta(autoDinOrdenado, START_INDEX);
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
        } while(subOpc != EXIT_VALUE);
        break;
    case 2:
        limpiarPantalla();
        printf("\t\t\tINSERION DE DATOS DE VENTAS\n");
        printf("\t---------------------------------------------------------------------\n");
        ingresarVentas(dniVendedor);
        limpiarPantalla();
        break;
    case 3:
        system("cls");

        printf("Ingrese el id de la venta que desea eliminar: ");
        int idVentaBuscar = scanInt();

        if(!idVentaUnicoArchivo(idVentaBuscar)){
            printf("\nEsta seguro de querer eliminar esta venta? (s/n): ");
            if(confirmar('s')){
                borrarVenta(dniVendedor, idVentaBuscar);
            }
        } else {
            printf("\nEl id ingresado no pertenece a ninguna venta registrada en el sistema.\n\n");
        }

        system("pause");
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
        mostrarTodasLasVentasDelSistema(ventaDin, START_INDEX);
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
    case 3:
        system("cls");

        PersonaDinamica personaClientes;
        inicializarPersonaDinamica(&personaClientes, VALOR_DIMENSIONAMIENTO_PERSONADINAMICA);

        pasarClientesArregloPersonas(&personaClientes, ventaDin);
        mostrarTodasLasPersonas(personaClientes, START_INDEX);

        liberarPersonaDinamica(&personaClientes);
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

void opcMenuVendedorGestEstadisticas(char* dniVendedor, int opc){
    VentaDinamica ventaDin = pasarArchivoVentasAlArregloDinamico(dniVendedor);

    switch(opc){
    case 1:
        system("cls");
        printf("Ingrese el anio: ");
        int anio = scanInt();

        printf("Ingrese el mes de calculo: ");
        int mes = scanInt();

        printf("\n\t\tLa ganancia en el mes de %s del anio %04d es de $%1.f\n\n",
               identificarMesDelAnio(mes), anio, calcularMargenGananciaMensual(ventaDin, anio, mes, START_INDEX+1, START_INDEX));
        system("pause");
        break;
    case 2:
        system("cls");
        int indiceGananciaAlta = calcularMargenDeGananciaMasAlto(ventaDin);

        printf("\t\tLa ganancia mas alta es de $%1.f"
               "\n\t\tEl %d de %s del anio %04d\n\n",
               ventaDin.arrayVenta[indiceGananciaAlta].ganancia,
               ventaDin.arrayVenta[indiceGananciaAlta].fecha.dia,
               identificarMesDelAnio(ventaDin.arrayVenta[indiceGananciaAlta].fecha.mes),
               ventaDin.arrayVenta[indiceGananciaAlta].fecha.anio);

        printf("---------------------------Datos de la venta-------------------------\n");
        mostrarUnaVenta(ventaDin.arrayVenta[indiceGananciaAlta]);
        system("pause");
        break;
    case 0:
        printf("\nVolviendo...\n");
        break;
    default:
        printf("\nError: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
        break;
    }

    liberarVentaDinamica(&ventaDin);
}

void opcMenuAdmin(char* dniPersona, int opc){
    int subOpc;

    switch(opc){
    case 1:
        do{
            system("cls");
            printMenuAdminGestAutos();
            subOpc = scanInt();
            while(!esEnteroPositivo(subOpc)){
                printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
                subOpc = scanInt();
            }
            opcMenuAdminGestAutos(subOpc);
        } while(subOpc != EXIT_VALUE);
        break;
    case 2:
        do{
            system("cls");
            printMenuAdminGestUsuarios();
            subOpc = scanInt();
            while(!esEnteroPositivo(subOpc)){
                printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
                subOpc = scanInt();
            }
            opcMenuAdminGestUsuarios(subOpc);
        } while(subOpc != EXIT_VALUE);
        break;
    case 3:
        do{
            system("cls");
            printMenuAdminGestVentas();
            subOpc = scanInt();
            while(!esEnteroPositivo(subOpc)){
                printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
                subOpc = scanInt();
            }
            opcMenuAdminGestVentas(subOpc);
        } while(subOpc != EXIT_VALUE);
        break;
    case 4:
        do{
            system("cls");
            printMenuModificarDatosPesonales();
            subOpc = scanInt();
            while(!esEnteroPositivo(subOpc)){
                printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
                subOpc = scanInt();
            }
            opcMenuModificarDatosPesonales(dniPersona, subOpc);
        } while(subOpc != EXIT_VALUE);
        break;
    case 0:
        printf("\nCerrando sesion...\n");
        break;
    default:
        printf("\nError: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
        break;
    }
}

void opcMenuAdminGestAutos(int opc){
    int subOpc;
    char dniVendedorBuscar[MAX_CARACT_STRING_DNI];

    switch(opc){
    case 1:
        do{
            system("cls");
            printMenuAdminVistaAutos();
            subOpc = scanInt();
            while(!esEnteroPositivo(subOpc)){
                printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
                subOpc = scanInt();
            }
            opcMenuAdminVistaAutos(subOpc);
        } while(subOpc != EXIT_VALUE);
        break;
    case 2:
        system("cls");

        printf("Ingrese el DNI del vendedor: ");
        scanString(dniVendedorBuscar, MAX_CARACT_STRING_DNI);
        if((dniUnicoPersona(dniVendedorBuscar) || !esDniValido(dniVendedorBuscar))){
            printf("El DNI ingresado no es valido o no existe en el sistema.\n\n");
            system("pause");
            break;
        }

        if(vendedorExiste(dniVendedorBuscar)){
            limpiarPantalla();
            printf("\t\t\tINSERION DE DATOS DE AUTOS\n");
            printf("\t---------------------------------------------------------------------\n");
            insertarAutos(dniVendedorBuscar);
        } else {
            printf("\nEl dni ingresado no pertenece a ningun vendedor.\n");
        }

        limpiarPantalla();
        break;
    case 3:
        system("cls");

        printf("Ingrese el DNI del vendedor: ");
        scanString(dniVendedorBuscar, MAX_CARACT_STRING_DNI);
        if((dniUnicoPersona(dniVendedorBuscar) || !esDniValido(dniVendedorBuscar))){
            printf("El DNI ingresado no es valido o no existe en el sistema.\n\n");
            system("pause");
            break;
        }

        if(vendedorExiste(dniVendedorBuscar)){
            do{
               system("cls");
                printMenuModificarAutos();
                subOpc = scanInt();
                while(!esEnteroPositivo(subOpc)){
                    printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
                    subOpc = scanInt();
                }
                opcMenuModificarAutos(dniVendedorBuscar, subOpc);
            } while(subOpc != EXIT_VALUE);
        } else {
            printf("\nEl dni ingresado no pertenece a ningun vendedor.\n");
            system("pause");
        }
        break;
    case 4:
        system("cls");

        printf("Usted esta seguro de querer eliminar un auto del sistema? (s/n): ");
        if(confirmar('s')){
            printf("Ingrese el DNI del vendedor: ");
            scanString(dniVendedorBuscar, MAX_CARACT_STRING_DNI);
            if((dniUnicoPersona(dniVendedorBuscar) || !esDniValido(dniVendedorBuscar))){
                printf("El DNI ingresado no es valido o no existe en el sistema.\n\n");
                system("pause");
                break;
            }

            if(vendedorExiste(dniVendedorBuscar)){
                char patenteAutoBorrar[MAX_CARACT_STRING];

                printf("Ingrese la patente del auto que desea borrar: ");
                scanString(patenteAutoBorrar, MAX_CARACT_STRING);

                if(existeIdAutoDeUnVendedorEnArchivo(patenteAutoBorrar, dniVendedorBuscar)){
                    borrarAuto(dniVendedorBuscar, patenteAutoBorrar);
                } else {
                    printf("\nLa patente ingresada no pertenece a ningun auto en el sistema.\n\n");
                }
            }
        }
        system("pause");
        break;
    case 0:
        printf("\nVolviendo...\n");
        break;
    default:
        printf("\nError: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
        break;
    }
}

void opcMenuAdminVistaAutos(int opc){
    AutoDinamico autosALaVenta = pasarArchivoAutosALaVentaAlArregloDinamico();
    AutoDinamico autosVendidos = pasarArchivoAutosVendidosAlArregloDinamico();
    PersonaDinamica personasVendedores = pasarArchivoPesonasAlArreglo('v');
    char dniVendedorBuscar[MAX_CARACT_STRING_DNI];

    switch(opc){
    case 1:
        system("cls");
        mostrarTodosLosAutosALaVenta(autosALaVenta, START_INDEX);
        system("pause");
        break;
    case 2:
        system("cls");
        mostrarTodosLosAutosDeUnArreglo(autosVendidos, START_INDEX);
        system("pause");
        break;
    case 3:
        system("cls");
        char patenteBuscar[MAX_CARACT_STRING];

        printf("Ingrese la patente del auto que quiere buscar: ");
        scanString(patenteBuscar, MAX_CARACT_STRING);

        buscarUnAutoEnElSistema(autosALaVenta, patenteBuscar);
        system("pause");
        break;
    case 4:
        system("cls");

        printf("Ingrese el DNI del vendedor a buscar: ");
        scanString(dniVendedorBuscar, MAX_CARACT_STRING_DNI);
        if((dniUnicoPersona(dniVendedorBuscar) || !esDniValido(dniVendedorBuscar))){
            printf("El DNI ingresado no es valido o no existe en el sistema.\n\n");
            system("pause");
            break;
        }

        printf("\n");

        if(buscarPersonaEnArregloPorDni(personasVendedores, dniVendedorBuscar) == 1){
            printf("\n--------------------------AUTOS A LA VENTA---------------------------\n");
            mostrarAutosDeUnVendedor(autosALaVenta, dniVendedorBuscar);
        }

        system("pause");
        break;
    case 5:
        system("cls");

        printf("Ingrese el DNI del vendedor a buscar: ");
        scanString(dniVendedorBuscar, MAX_CARACT_STRING_DNI);
        if((dniUnicoPersona(dniVendedorBuscar) || !esDniValido(dniVendedorBuscar))){
            printf("El DNI ingresado no es valido o no existe en el sistema.\n\n");
            system("pause");
            break;
        }

        printf("\n");

        if(buscarPersonaEnArregloPorDni(personasVendedores, dniVendedorBuscar)){
            printf("\n--------------------------AUTOS VENDIDOS-----------------------------\n");
            mostrarAutosVendidosPorVendedor(autosVendidos, dniVendedorBuscar);
        }

        system("pause");
        break;
    case 0:
        printf("\nVolviendo...\n");
        break;
    default:
        printf("\nError: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
        break;
    }

    liberarPersonaDinamica(&personasVendedores);
    liberarAutoDinamico(&autosALaVenta);
    liberarAutoDinamico(&autosVendidos);
}

void opcMenuAdminGestUsuarios(int opc) {
    UsuarioDinamico usuarioDin = pasarArchivoUsuariosAUnArreglo();
    PersonaDinamica personaDin = pasarArchivoTodasLasPesonasAlArreglo();
    int subOpc;

    switch(opc){
    case 1:
        do{
            system("cls");
            printMenuAdminVistaUsuarios();
            subOpc = scanInt();
            while(!esEnteroPositivo(subOpc)){
                printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
                subOpc = scanInt();
            }
            opcMenuAdminVistaUsuarios(subOpc);
        } while(subOpc != EXIT_VALUE);
        break;
    case 2:
        system("cls");
        printf("\t\t\tINSERION DE DATOS DE USUARIOS\n");
        printf("\t---------------------------------------------------------------------\n");
        ingresarVariosUsuarios();
        limpiarPantalla();
        break;
    case 3:
        system("cls");

        char dniValidar[MAX_CARACT_STRING_DNI];

        printf("\t\t\tLISTA DE USUARIOS PENDIENTES DE ENTRAR AL SISTEMA\n");
        printf("\t---------------------------------------------------------------------\n");

        mostrarTodosLosUsuariosSinValidar();

        printf("Ingrese el DNI del usuario a aceptar el ingreso (si no hay usuarios en lista, haga un salto de linea): ");
        scanString(dniValidar, MAX_CARACT_STRING_DNI);
        if((dniUnicoPersona(dniValidar) || !esDniValido(dniValidar))){
            printf("El DNI ingresado no es valido o no existe en el sistema.\n\n");
            system("pause");
            break;
        }

        system("cls");

        if(buscarPersonaEnArregloPorDni(personaDin, dniValidar)){
            aceptarUsuarioEnSistema(dniValidar);
        }

        system("pause");
        break;
    case 4:
        system("cls");

        char dniDenegar[MAX_CARACT_STRING_DNI];

        printf("\t\t\tLISTA DE USUARIOS CON ACCESO AL SISTEMA\n");
        printf("\t---------------------------------------------------------------------\n");

        mostrarTodosLosUsuariosConAccesoAlSistema();

        printf("Ingrese el DNI del usuario a aceptar el ingreso (si no hay usuarios en lista, haga un salto de linea): ");
        scanString(dniDenegar, MAX_CARACT_STRING_DNI);
        if((dniUnicoPersona(dniDenegar) || !esDniValido(dniDenegar))){
            printf("El DNI ingresado no es valido o no existe en el sistema.\n\n");
            system("pause");
            break;
        }

        system("cls");

        if(buscarPersonaEnArregloPorDni(personaDin, dniDenegar)){
            negarAccesoUsuarioEnSistema(dniDenegar);
        }

        system("pause");
        break;
    case 0:
        printf("\nVolviendo...\n");
        break;
    default:
        printf("\nError: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
        break;
    }

    liberarUsuarioDinamico(&usuarioDin);
    liberarPersonaDinamica(&personaDin);
}

void opcMenuAdminVistaUsuarios(int opc){
    UsuarioDinamico usuarioDin = pasarArchivoUsuariosAUnArreglo();

    switch(opc){
    case 1:
        system("cls");
        mostrarTodosLosUsuarios(usuarioDin, START_INDEX);
        system("pause");
        break;
    case 2:
        system("cls");
        char nombreUsuarioBuscar[MAX_CARACT_STRING];

        printf("Ingrese el nombre del usuario que quiere buscar: ");
        scanString(nombreUsuarioBuscar, MAX_CARACT_STRING);

        mostrarUnUsuarioPorNombre(usuarioDin, nombreUsuarioBuscar);
        system("pause");
        break;
    case 3:
        system("cls");
        mostrarTodosLosUsuariosDeUnRol(usuarioDin, 'v', START_INDEX);
        system("pause");
        break;
    case 4:
        system("cls");
        mostrarTodosLosUsuariosDeUnRol(usuarioDin, 'a', START_INDEX);
        system("pause");
        break;
    case 0:
        printf("\nVolviendo...\n");
        system("pause");
        break;
    default:
        printf("\nError: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
        break;
    }
    liberarUsuarioDinamico(&usuarioDin);
}

void opcMenuAdminGestVentas(int opc){
    PersonaDinamica personasVendedores = pasarArchivoPesonasAlArreglo('v');
    int subOpc;
    char dniVendedorBuscar[MAX_CARACT_STRING_DNI];

    switch(opc){
    case 1:
        do{
           system("cls");
            printMenuAdminVistaVentas();
            subOpc = scanInt();
            while(!esEnteroPositivo(subOpc)){
                printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
                subOpc = scanInt();
            }
            opcMenuAdminVistaVentas(subOpc);
        } while(subOpc != START_INDEX);
        break;
        break;
    case 2:
        system("cls");

        printf("Ingrese el DNI del vendedor a buscar: ");
        scanString(dniVendedorBuscar, MAX_CARACT_STRING_DNI);
        if((dniUnicoPersona(dniVendedorBuscar) || !esDniValido(dniVendedorBuscar))){
            printf("El DNI ingresado no es valido o no existe en el sistema.\n\n");
            system("pause");
            break;
        }

        printf("\n");

        if(buscarPersonaEnArregloPorDni(personasVendedores, dniVendedorBuscar) == 1){
            limpiarPantalla();
            printf("\t\t\tINSERION DE DATOS DE VENTAS\n");
            printf("\t---------------------------------------------------------------------\n");
            ingresarVentas(dniVendedorBuscar);
        }

        limpiarPantalla();
        break;
    case 3:
        system("cls");

        printf("Ingrese el DNI del vendedor a buscar: ");
        scanString(dniVendedorBuscar, MAX_CARACT_STRING_DNI);
        if((dniUnicoPersona(dniVendedorBuscar) || !esDniValido(dniVendedorBuscar))){
            printf("El DNI ingresado no es valido o no existe en el sistema.\n\n");
            system("pause");
            break;
        }

        printf("\n");

        if(buscarPersonaEnArregloPorDni(personasVendedores, dniVendedorBuscar) == 1){
            limpiarPantalla();
            printf("Ingrese el id de la venta que desea eliminar: ");
            int idVentaBuscar = scanInt();

            if(!idVentaUnicoArchivo(idVentaBuscar)){
                printf("\nEsta seguro de querer eliminar esta venta? (s/n): ");
                if(confirmar('s')){
                    borrarVenta(dniVendedorBuscar, idVentaBuscar);
                }
            } else {
                printf("\nEl id ingresado no pertenece a ninguna venta registrada en el sistema.\n\n");
            }
        }

        system("pause");
        break;
    case 0:
        printf("\nVolviendo...\n");
        break;
    default:
        printf("\nError: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
        break;
    }

    liberarPersonaDinamica(&personasVendedores);
}

void opcMenuAdminVistaVentas(int opc){
    VentaDinamica ventaDin = pasarArchivoTodasLasVentasAlArregloDinamico();
    PersonaDinamica personasVendedores = pasarArchivoPesonasAlArreglo('v');

    switch(opc){
    case 1:
        system("cls");
        mostrarTodasLasVentasDelSistema(ventaDin, START_INDEX);
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
    case 3:
        system("cls");
        char dniVendedorBuscar[MAX_CARACT_STRING_DNI];

        printf("Ingrese el DNI del vendedor a buscar: ");
        scanString(dniVendedorBuscar, MAX_CARACT_STRING_DNI);
        if((dniUnicoPersona(dniVendedorBuscar) || !esDniValido(dniVendedorBuscar))){
            printf("El DNI ingresado no es valido o no existe en el sistema.\n\n");
            system("pause");
            break;
        }

        printf("\n");

        if(buscarPersonaEnArregloPorDni(personasVendedores, dniVendedorBuscar)){
            VentaDinamica ventasVendedor = pasarArchivoVentasAlArregloDinamico(dniVendedorBuscar);
            mostrarTodasLasVentasDelSistema(ventasVendedor, START_INDEX);
            liberarVentaDinamica(&ventasVendedor);
        }
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

    liberarPersonaDinamica(&personasVendedores);
    liberarVentaDinamica(&ventaDin);
}

void opcMenuModificarDatosPesonales(char* dniUsuario, int opc){
    switch(opc){
    case 1:
        system("cls");
        char nombreUsuarioNuevo[MAX_CARACT_STRING];

        printf("Ingrese el nuevo nombre de usuario: ");
        scanString(nombreUsuarioNuevo, MAX_CARACT_STRING);

        modificarNombreUsuario(dniUsuario, nombreUsuarioNuevo);
        system("pause");
        break;
    case 2:
        system("cls");
        printf("Esta usted seguro de cambiar su contrasenia? (s/n): ");

        if(confirmar('s')){
            char contraseniaNueva[MAX_CARACT_STRING];

            printf("Ingrese la nueva contrasenia: ");
            scanString(contraseniaNueva, MAX_CARACT_STRING);

            modificarContraseniaUsuario(dniUsuario, contraseniaNueva);
        }
        system("pause");
        break;
    case 3:
        system("cls");
        char nombreNuevo[MAX_CARACT_STRING];

        printf("Ingrese el nuevo nombre: ");
        scanString(nombreNuevo, MAX_CARACT_STRING);

        modificarNombrePersona(dniUsuario, nombreNuevo);
        system("pause");
        break;
    case 4:
        system("cls");
        char apellidoNuevo[MAX_CARACT_STRING];

        printf("Ingrese el nuevo apellido: ");
        scanString(apellidoNuevo, MAX_CARACT_STRING);

        modificarApellidoPersona(dniUsuario, apellidoNuevo);
        system("pause");
        break;
    case 5:
        system("cls");
        char telefonoNuevo[MAX_CARACT_STRING];

        printf("Ingrese el nuevo telefono: ");
        scanString(telefonoNuevo, MAX_CARACT_STRING);

        modificarTelefonoPersona(dniUsuario, telefonoNuevo);
        system("pause");
        break;
    case 6:
        system("cls");
        char ciudadNueva[MAX_CARACT_STRING];

        printf("Ingrese la nueva ciudad: ");
        scanString(ciudadNueva, MAX_CARACT_STRING);

        modificarCiudadPersona(dniUsuario, ciudadNueva);
        system("pause");
        break;
    case 0:
        printf("\nVolviendo...\n");
        break;
    default:
        printf("\nError: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
        break;
    }
}

void opcMenuModificarAutos(char* dniTitular, int opc){
    char patenteAutoModificar[MAX_CARACT_STRING];

    switch(opc){
    case 1:
        system("cls");
        char marcaNueva[MAX_CARACT_STRING];

        printf("Ingrese la patente del auto: ");
        scanString(patenteAutoModificar, MAX_CARACT_STRING);

        printf("Ingrese la nueva marca del auto: ");
        scanString(marcaNueva, MAX_CARACT_STRING);

        modificarMarcaAuto(patenteAutoModificar, dniTitular, marcaNueva);
        system("pause");
        break;
    case 2:
        system("cls");
        char modeloNuevo[MAX_CARACT_STRING];

        printf("Ingrese la patente del auto: ");
        scanString(patenteAutoModificar, MAX_CARACT_STRING);

        printf("Ingrese el nuevo modelo del auto: ");
        scanString(modeloNuevo, MAX_CARACT_STRING);

        modificarModeloAuto(patenteAutoModificar, dniTitular, modeloNuevo);
        system("pause");
        break;
    case 3:
        system("cls");
        int anioDeAdqNuevo;

        printf("Ingrese la patente del auto: ");
        scanString(patenteAutoModificar, MAX_CARACT_STRING);

        printf("Ingrese el nuevo anio de fabricacion/adquisicion del auto: ");
        anioDeAdqNuevo = scanInt();

        modificarAnioAdqAuto(patenteAutoModificar, dniTitular, anioDeAdqNuevo);
        system("pause");
        break;
    case 4:
        system("cls");
        int kmNuevo;

        printf("Ingrese la patente del auto: ");
        scanString(patenteAutoModificar, MAX_CARACT_STRING);

        printf("Ingrese el nuevo kilometraje del auto: ");
        kmNuevo = scanInt();

        modificarKmAuto(patenteAutoModificar, dniTitular, kmNuevo);
        system("pause");
        break;
    case 5:
        system("cls");
        float precioAdqNuevo;

        printf("Ingrese la patente del auto: ");
        scanString(patenteAutoModificar, MAX_CARACT_STRING);

        printf("Ingrese el nuevo kilometraje del auto: ");
        precioAdqNuevo = scanFloat();

        modificarPrecioAdqAuto(patenteAutoModificar, dniTitular, precioAdqNuevo);
        system("pause");
        break;
    case 0:
        printf("\nVolviendo...\n");
        break;
    default:
        printf("\nError: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
        break;
    }
}
