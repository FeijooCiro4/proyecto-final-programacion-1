#include <stdio.h>
#include "stPersona.h"

void mostrarUnaPersona(Persona personaMostrar){
    printf("Nombre completo: %s %s\n"
           "\tDNI: %s\n"
           "\tCiudad de residencia: %s\n"
           "\tNumero de telefono: %s\n",
           personaMostrar.nombrePersona,
           personaMostrar.apellidoPersona,
           personaMostrar.dni,
           personaMostrar.ciudad,
           personaMostrar.telefono);
    printf("---------------------------------------------------------------------\n");
}

void mostrarNombreTelefonoDeUnaPersona(Persona personaMostrar){
    printf("\tNombre completo: %s %s\n"
           "\tNumero de telefono: %s\n",
           personaMostrar.nombrePersona,
           personaMostrar.apellidoPersona,
           personaMostrar.telefono);
    printf("---------------------------------------------------------------------\n");
}
