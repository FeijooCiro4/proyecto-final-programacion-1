#include <stdbool.h>
#include "../structs/usuario/stUsuario.h"

#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED


bool opcLogin(Usuario *us, int opc);

void opcMenuVendedor(char* dniTitular, int opc);
void opcMenuVendedorGestAutos(char* dniTitular, int opc);
void opcMenuVendedorVistaAutos(char* dniTitular, int opc);
void opcMenuVendedorGestVentas(char* dniVendedor, int opc);
void opcMenuVendedorVistaVentas(char* dniVendedor, int opc);

void opcMenuComprador(int opc);
void opcMenuCompradorVistaAutos(int opc);
void opcMenuCompradorVistaVendedores(int opc);

#endif // OPTIONS_H_INCLUDED
