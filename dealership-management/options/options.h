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
void opcMenuVendedorGestEstadisticas(char* dniVendedor, int opc);

void opcMenuComprador(char* dniPersona, int opc);
void opcMenuCompradorVistaAutos(int opc);
void opcMenuCompradorVistaVendedores(int opc);

void opcMenuAdmin(char* dniPersona, int opc);
void opcMenuAdminGestAutos(int opc);
void opcMenuAdminVistaAutos(int opc);
void opcMenuAdminGestUsuarios(int opc);
void opcMenuAdminVistaUsuarios(int opc);
void opcMenuAdminGestVentas(int opc);
void opcMenuAdminVistaVentas(int opc);

void opcMenuModificarDatosPesonales(char* dniUsuario, int opc);
void opcMenuModificarAutos(char* dniTitular, int opc);

#endif // OPTIONS_H_INCLUDED
