#include "stAuto.h"
#include "../../../View/utils/utils.h"

Auto ingresarAuto(char* dniTitular){
    Auto varAuto;

    printf("Ingrese la patente: ");
    scanString(varAuto.patente, MAX_CARACT_AUTO_STANDARD);

    printf("Ingrese la marca: ");
    scanString(varAuto.marca, MAX_CARACT_AUTO_STANDARD);

    printf("Ingrese el modelo: ");
    scanString(varAuto.modelo, MAX_CARACT_AUTO_STANDARD);

    printf("Ingrese el anio de fabricacion: ");
    varAuto.anio = scanInt();
    while(!esEnteroPositivo(varAuto.anio) || !anioAnteriorAlActual(varAuto.anio)){
        printf("El anio ingresado no es valido. Ingrese otro: ");
        varAuto.anio = scanInt();
    }

    printf("Ingrese el kilometraje: ");
    varAuto.kms = scanInt();
    while(!esEnteroPositivo(varAuto.kms)){
        printf("El kilometraje ingresado no es valido. Ingrese otro: ");
        varAuto.kms = scanInt();
    }

    strcpy(varAuto.dniTitular, dniTitular);

    printf("Ingrese el precio de adquisicion: ");
    varAuto.precioDeAdquisicion = scanFloat();
    while(!esEnteroPositivo((int)varAuto.precioDeAdquisicion)){
        printf("El precio de asquisicion ingresado no es valido. Ingrese otro: ");
        varAuto.precioDeAdquisicion = scanFloat();
    }

    return varAuto;
}

void mostrarUnAuto(Auto aut){
    printf("\tPatente: %s\n"
           "\tMarca: %s\n"
           "\tModelo: %s\n"
           "\tAnio: %d\n"
           "\tKilometros: %dkm\n",
           aut.patente,
           aut.marca,
           aut.modelo,
           aut.anio,
           aut.kms);
}

void mostrarUnAutoCompleto(Auto aut){
    printf("\tPatente: %s\n"
           "\tMarca: %s\n"
           "\tModelo: %s\n"
           "\tAnio: %d\n"
           "\tKilometros: %dkm\n"
           "\tPrecio de adquisicion: $%1.f\n",
           aut.patente,
           aut.marca,
           aut.modelo,
           aut.anio,
           aut.kms,
           aut.precioDeAdquisicion);
}
