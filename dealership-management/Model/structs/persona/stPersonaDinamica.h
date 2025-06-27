#include "stPersona.h"

#ifndef STPERSONADINAMICA_H_INCLUDED
#define STPERSONADINAMICA_H_INCLUDED

typedef struct stPersonaDinaica{
    Persona* arrayPersona;
    int dimension;
    int validos;
} PersonaDinamica;

void inicializarPersonaDinamica(PersonaDinamica* personaDin, int dimensionInicial);
void redimencionarPersonaDinamica(PersonaDinamica* personaDin);
void liberarPersonaDinamica(PersonaDinamica* personaDin);

#endif // STPERSONADINAMICA_H_INCLUDED
