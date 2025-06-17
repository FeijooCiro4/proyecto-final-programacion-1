#include "stAuto.h"

#ifndef STAUTODINAMICO_H_INCLUDED
#define STAUTODINAMICO_H_INCLUDED

typedef struct stAutoDinamico
{
    Auto* arrayAuto;
    int dimencion;
    int validos;
} AutoDinamico;

void inicializarAutoDinamico(AutoDinamico* autoDin, int valorDimencion);
void verificarRedimensionAutoDinamico(AutoDinamico* autoDin);
void liberarAutoDinamico(AutoDinamico* autoDin);

#endif // STAUTODINAMICO_H_INCLUDED
