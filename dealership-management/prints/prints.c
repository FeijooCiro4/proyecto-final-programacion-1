#include "prints.h"

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
           "\t3. Gestionar estadistica.\n"
           "\t4. Modificar datos personales.\n"
           "\t0. Cerrar sesion. \n"
           "Ingrese una opcion: ");
}

void printMenuVendedorGestAutos(){
    printf("---------------------------GESTION DE AUTOS--------------------------\n"
           "\t1. Acceder al menu de vista de datos.\n"
           "\t2. Escribir datos de uno o varios autos.\n"
           "\t3. Modificar datos de un auto.\n"
           "\t4. Eliminar datos de un auto.\n"
           "\t0. Salir. \n"
           "Ingrese una opcion: ");
}

void printMenuVendedorVistaAutos(){
    printf("GESTION DE VISTAS DE AUTOS\n"
           "\t1. Ver todos los autos a la venta en el sistema.\n"
           "\t2. Ver un auto.\n"
           "\t3. Ver autos puestos a la venta por usted.\n"
           "\t4. Ver autos vendidos.\n"
           "\t5. Ver autos en orden de antiguedad.\n"
           "\t0. Salir. \n"
           "Ingrese una opcion: ");
}

void printMenuVendedorGestVentas(){
    printf("---------------------------GESTION DE VENTAS--------------------------\n"
           "\t1. Acceder al menu de vista de datos.\n"
           "\t2. Escribir datos de una o varias ventas.\n"
           "\t3. Cancelar una venta.\n"
           "\t0. Salir. \n"
           "Ingrese una opcion: ");
}

void printMenuVendedorVistaVentas(){
    printf("GESTION DE VISTAS DE VENTAS\n"
           "\t1. Ver todas las ventas hechas por usted.\n"
           "\t2. Ver una venta.\n"
           "\t3. Ver clientes.\n"
           "\t0. Salir. \n"
           "Ingrese una opcion: ");
}

void printMenuVendedorGestEstadisticas(){
    printf("GESTION DE ESTADISTICAS\n"
           "\t1. Calcular cuanto se recaudo en determinado mes, de determinado anio.\n"
           "\t2. Calcular cual fue la venta que genero mayor ganancia hasta el momento.\n"
           "\t0. Salir. \n"
           "Ingrese una opcion: ");
}

void printMenuComprador(){
    printf("\t\tOPCIONES DE GESTION\n"
           "\t1. Ver autos.\n"
           "\t2. Ver vendedores.\n"
           "\t3. Ver compras realizadas.\n"
           "\t4. Modificar datos personales.\n"
           "\t0. Cerrar sesion. \n"
           "Ingrese una opcion: ");
}

void printMenuCompradorVistaAutos(){
    printf("GESTION DE VISTAS DE AUTOS\n"
           "\t1. Ver datos de todos los autos a la venta.\n"
           "\t2. Buscar datos de un auto a la venta.\n"
           "\t3. Ver autos en orden de antiguedad.\n"
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

void printMenuAdmin(){
    printf("\t\tOPCIONES DE GESTION\n"
           "\t1. Gestionar autos.\n"
           "\t2. Gestionar usuarios.\n"
           "\t3. Gestionar ventas.\n"
           "\t4. Modificar datos personales.\n"
           "\t0. Cerrar sesion. \n"
           "Ingrese una opcion: ");
}

void printMenuAdminGestAutos(){
    printf("---------------------------GESTION DE AUTOS--------------------------\n"
           "\t1. Acceder al menu de vista de datos.\n"
           "\t2. Escribir datos de uno o varios autos.\n"
           "\t3. Modificar datos de un auto.\n"
           "\t4. Eliminar datos de un auto.\n"
           "\t0. Salir. \n"
           "Ingrese una opcion: ");
}

void printMenuAdminVistaAutos(){
    printf("GESTION DE VISTAS DE AUTOS\n"
           "\t1. Ver datos de todos los autos a la venta.\n"
           "\t2. Ver datos de todos los autos vendidos.\n"
           "\t3. Buscar datos de un auto a la venta.\n"
           "\t4. Ver todos los autos a la venta de un vendedor.\n"
           "\t5. Ver todos los autos vendidos de un vendedor.\n"
           "\t0. Salir. \n"
           "Ingrese una opcion: ");
}

void printMenuAdminGestUsuarios(){
    printf("--------------------------GESTION DE USUARIOS------------------------\n"
           "\t1. Acceder al menu de vista de datos.\n"
           "\t2. Escribir datos de uno o varios usuarios.\n"
           "\t3. Gestionar solicitudes de inggreso al sistema de nuevos usuarios.\n"
           "\t4. Negar acceso al sistema a un usuario.\n"
           "\t0. Salir. \n"
           "Ingrese una opcion: ");
}

void printMenuAdminVistaUsuarios(){
    printf("GESTION DE VISTAS DE USUARIOS\n"
           "\t1. Ver datos de todos los usuarios del sistema.\n"
           "\t2. Ver datos de un usuario.\n"
           "\t3. Ver datos de todos los vendedores.\n"
           "\t4. Ver datos de todos los compradores.\n"
           "\t5. Ver datos de todos los administradores.\n"
           "\t0. Salir. \n"
           "Ingrese una opcion: ");
}

void printMenuAdminGestVentas(){
    printf("---------------------------GESTION DE VENTAS--------------------------\n"
           "\t1. Acceder al menu de vista de datos.\n"
           "\t2. Escribir datos de una o varias ventas.\n"
           "\t3. Eliminar datos de una venta.\n"
           "\t0. Salir. \n"
           "Ingrese una opcion: ");
}

void printMenuAdminVistaVentas(){
    printf("GESTION DE VISTAS DE VENTAS\n"
           "\t1. Ver datos de todas las ventas del sistema.\n"
           "\t2. Buscar datos de una venta.\n"
           "\t3. Ver todas las ventas de un vendedor.\n"
           "\t0. Salir. \n"
           "Ingrese una opcion: ");
}

void printMenuModificarDatosPesonales(){
    printf("GESTION DE DATOS PERSONALES\n"
           "\t1. Modficar nombre de usuario.\n"
           "\t2. Modiicar contrasenia.\n"
           "\t3. Modificar nombre.\n"
           "\t4. Modificar apellido.\n"
           "\t5. Modificar telefono.\n"
           "\t6. Modificar ciudad de residencia.\n"
           "\t0. Salir. \n"
           "Ingrese una opcion: ");
}

void printMenuModificarAutos(){
    printf("GESTION DE DATOS DE UN AUTO\n"
           "\t1. Modficar marca.\n"
           "\t2. Modiicar modelo.\n"
           "\t3. Modificar anio de fabricacion/adquisicion.\n"
           "\t4. Modificar kilmetraje.\n"
           "\t5. Modificar precio de adquisicion.\n"
           "\t0. Salir. \n"
           "Ingrese una opcion: ");
}
