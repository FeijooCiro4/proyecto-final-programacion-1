#include <stdlib.h>
#include "stPersonaDinamica.h"
#include "../../constants/constants.h"

void inicializarPersonaDinamica(PersonaDinamica* personaDin, int dimensionInicial){
    personaDin->dimension = dimensionInicial;
    personaDin->arrayPersona = (Persona*)malloc(dimensionInicial*sizeof(Persona));

    if(personaDin->arrayPersona == NULL){
        perror("Error al asignar memoria al arreglo de personas");
        return;
    }

    personaDin->validos = 0;
}

void redimencionarPersonaDinamica(PersonaDinamica* personaDin){
    if(personaDin->validos < personaDin->dimension) return;

    personaDin->arrayPersona = (Persona*)realloc(personaDin->arrayPersona, (personaDin->dimension + VALOR_DIMENSIONAMIENTO_PERSONADINAMICA) * sizeof(Persona));
    personaDin->dimension += VALOR_DIMENSIONAMIENTO_PERSONADINAMICA;
}

void liberarPersonaDinamica(PersonaDinamica* personaDin){
    free(personaDin->arrayPersona);
    personaDin->dimension = 0;
    personaDin->validos = 0;
}
