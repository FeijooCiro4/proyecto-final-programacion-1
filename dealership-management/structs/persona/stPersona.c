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
