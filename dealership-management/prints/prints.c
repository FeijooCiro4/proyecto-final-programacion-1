#include "prints.h"

/**
* printLogin imprime las opciones que tendra todo usuario que
* ingrese al programa.
*/
void printLogin(){
    printf("\t\tINICIO O REGISTRO DE SESION\n"
           "\t1. Iniciar sesion.\n"
           "\t2. Registrarse.\n"
           "\t0. Salir del programa. \n"
           "Ingrese una opcion: ");
}

void printMenuVendedor(){
    printf("\t\tOPCIONES DE GESTION\n"
           "\t1. Gestionar autos.\n"
           "\t2. Gestionar ventas.\n"
           /*"\t3. Gestionar estadistica.\n"
           "\t4. Modificar datos personales.\n"*/
           "\t0. Cerrar sesion. \n"
           "Ingrese una opcion: ");
}

void printMenuVendedorGestAutos(){
    printf("---------------------------GESTION DE AUTOS--------------------------\n"
           "\t1. Acceder al menu de vista de datos.\n"
           "\t2. Escribir datos de uno o varios autos.\n"
           //"\t3. Modificar datos de un auto.\n"
           //"\t4. Eliminar datos de un auto.\n"
           "\t0. Salir. \n"
           "Ingrese una opcion: ");
}

void printMenuVendedorVistaAutos(){
    printf("GESTION DE VISTAS DE AUTOS\n"
           "\t1. Ver todos los autos en el sistema.\n"
           "\t2. Ver un auto.\n"
           "\t3. Ver autos puestos a la venta por usted.\n"
           "\t4. Ver autos vendidos.\n"
           //"\t5. Ver autos en orden de antiguedad.\n"
           "\t0. Salir. \n"
           "Ingrese una opcion: ");
}

void printMenuVendedorGestVentas(){
    printf("---------------------------GESTION DE VENTAS--------------------------\n"
           "\t1. Acceder al menu de vista de datos.\n"
           "\t2. Escribir datos de una o varias ventas.\n"
           "\t0. Salir. \n"
           "Ingrese una opcion: ");
}

void printMenuVendedorVistaVentas(){
    printf("GESTION DE VISTAS DE VENTAS\n"
           "\t1. Ver todas las ventas hechas por usted.\n"
           "\t2. Ver una venta.\n"
           //"\t3. Ver clientes.\n"
           "\t0. Salir. \n"
           "Ingrese una opcion: ");
}

void printMenuComprador(){
    printf("\t\tOPCIONES DE GESTION\n"
           "\t1. Ver autos.\n"
           "\t2. Ver vendedores.\n"
           /*"\t3. Ver compras realizadas.\n"
           "\t4. Modificar datos personales.\n"*/
           "\t0. Salir. \n"
           "Ingrese una opcion: ");
}

void printMenuCompradorVistaAutos(){
    printf("GESTION DE VISTAS DE AUTOS\n"
           "\t1. Ver datos de todos los autos a la venta.\n"
           "\t2. Buscar datos de un auto a la venta.\n"
           //"\t3. Ver autos en orden de antiguedad.\n"
           "\t0. Salir. \n"
           "Ingrese una opcion: ");
}

void printMenuCompradorVistaVendedores(){
    printf("GESTION DE VISTAS DE VENDEDORES\n"
           "\t1. Ver datos de todos los vendedores.\n"
           "\t2. Buscar datos de un vendedor.\n"
           "\t0. Salir. \n"
           "Ingrese una opcion: ");
}

/*void printMenuAdmin(void){
    printf("\t\tOPCIONES DE GESTION\n"
           "\t1. Gestionar autos.\n"
           "\t2. Gestionar usuarios.\n"
           "\t3. Gestionar ventas.\n"
           "\t4. Gestionar solicitudes de insercion al sistema.\n"
           "\t0. Salir. \n"
           "Ingrese una opcion: ");
}*/
