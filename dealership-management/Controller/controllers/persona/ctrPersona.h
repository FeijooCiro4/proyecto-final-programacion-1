#include "../../../Model/structs/persona/stPersonaDinamica.h"

#ifndef CTRPERSONA_H_INCLUDED
#define CTRPERSONA_H_INCLUDED

Persona ingresarPersona(const char* dniRegistrado);
void guardarPersonaEnArchivo(Persona* personaGuardar);
int dniUnicoPersona(const char *dni);
int validarNumeroTelefonoPersona(const char *telefono);
char* buscarPersonaPorId(char* dni);

PersonaDinamica pasarArchivoPesonasAlArreglo(char rol);
PersonaDinamica pasarArchivoTodasLasPesonasAlArreglo(void);
void mostrarTodasLasPersonas(PersonaDinamica personaDin, int indice);
void pasarArchivoPesonasAlArregloPorId(PersonaDinamica* personaDin, char* dni);
int esUsarioVendedor(char* dniBuscar);
int buscarPersonaEnArregloPorDni(PersonaDinamica personaDin, char* dniBuscar);
void mostrarUnaPersonaPorDni(char* dniBuscar);
void mostrarDatosResumidosDeUnaPersonaPorDni(char* dniBuscar);

void modificarNombrePersona(char* dniPersona, char* nombreNuevo);
void modificarApellidoPersona(char* dniPersona, char* apellidoNuevo);
void modificarCiudadPersona(char* dniPersona, char* ciudadNueva);
void modificarTelefonoPersona(char* dniPersona, char* telefonoNuevo);

#endif // CTRPERSONA_H_INCLUDED
