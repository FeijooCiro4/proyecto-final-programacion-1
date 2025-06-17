#include <stdbool.h>
#include "../structs/usuario/stUsuario.h"

#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED


bool opcLogin(Usuario *us, int opc);

void opcMenuVendedor(char* dniTitular, int opc);
void opcMenuVendedorGestAutos(char* dniTitular, int opc);
void opcMenuVendedorVistaAutos(int opc);


#endif // OPTIONS_H_INCLUDED
