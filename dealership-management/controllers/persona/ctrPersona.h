#include "../../structs/persona/stPersonaDinamica.h"

#ifndef CTRPERSONA_H_INCLUDED
#define CTRPERSONA_H_INCLUDED

Persona ingresarPersona(const char* archivo, const char* dniRegistrado);
int dniUnicoPersona(const char* archivo, const char *dni);
int validarNumeroTelefonoPersona(const char *telefono);
char* buscarPersonaPorId(const char* archivo, char* dni);

PersonaDinamica pasarArchivoPesonasAlArreglo(char rol);
void mostrarTodasLasPersonas(PersonaDinamica personaDin, int indice);
void buscarPersonaEnArreglo(PersonaDinamica personaDin, char* nombreBuscar);

#endif // CTRPERSONA_H_INCLUDED
