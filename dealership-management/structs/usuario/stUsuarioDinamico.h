#include "stUsuario.h"

#ifndef STUSUARIODINAMICO_H_INCLUDED
#define STUSUARIODINAMICO_H_INCLUDED

typedef struct stUsuarioDinamico {
    Usuario* arrayUsuario;
    int dimension;
    int validos;
} UsuarioDinamico;

void inicializarUsuarioDinamico(UsuarioDinamico* usuarioDin, int dimensionInicial);
void verificarRedimensionUsuarioDinamico(UsuarioDinamico* usuarioDin);
void liberarUsuarioDinamico(UsuarioDinamico* usuarioDin);

#endif // STUSUARIODINAMICO_H_INCLUDED
