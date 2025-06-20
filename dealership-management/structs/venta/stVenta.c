#include <stdio.h>
#include <string.h>
#include "stVenta.h"
#include "../../utils/utils.h"
#include "../fecha/stFecha.h"

Venta ingresarUnaVenta(char* dniVendedor){
    Venta vent;

    printf("Ingrese el id de la venta: ");
    vent.idVenta = scanInt();
    while(!esEnteroPositivo(vent.idVenta)){
        printf("El id ingresado no es valido. Ingrese otro: ");
        vent.idVenta = scanInt();
    }

    printf("Ingrese el DNI del comprador: ");
    scanString(vent.dniComprador, MAX_CARACT_VENTA_DNI);
    while(!esDniValido(vent.dniComprador)){
        printf("El dni ingresado es invalido. Ingrese otro: ");
        scanString(vent.dniComprador, MAX_CARACT_VENTA_DNI);
    }

    strcpy(vent.dniVendedor, dniVendedor);

    printf("Ingrese la patente del auto: ");
    scanString(vent.patenteAutoVendido, MAX_CARACT_VENTA_STANDARD);

    printf("Ingrese el precio de venta: ");
    vent.precioVenta = scanFloat();
    while(!esEnteroPositivo((int)vent.precioVenta)){
        printf("El precio ingresado no es valido. Ingrese otro: ");
        vent.precioVenta = scanFloat();
    }

    printf("\tInsercion de fecha.\n");
    vent.fecha = ingresarUnaFecha();
    while(!validarFecha(vent.fecha)){
        printf("La fecha ingresada no es valida. Ingrese otra:\n");
        vent.fecha = ingresarUnaFecha();
    }

    return vent;
}

void mostrarUnaVenta(Venta ventaMostrar){
    printf("Numero de Id: %d\n"
           "\tDNI del comprador: %s\n"
           "\tDNI del vendedor: %s\n"
           "\tPatente del auto vendido: %s\n"
           "\tPrecio de venta: $%1.f\n"
           "\tMargen de ganancia: $%1.f\n"
           , ventaMostrar.idVenta
           , ventaMostrar.dniComprador
           , ventaMostrar.dniVendedor
           , ventaMostrar.patenteAutoVendido
           , ventaMostrar.precioVenta
           , ventaMostrar.ganancia);
    mostrarUnaFecha(ventaMostrar.fecha);
    printf("---------------------------------------------------------------------\n");
}
