#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

#include <stdbool.h>
#include "../structs/usuario/stUsuario.h"

extern bool iniciarSesion(Usuario *us);
extern bool registroSesion(void);

#endif // LOGIN_H_INCLUDED
