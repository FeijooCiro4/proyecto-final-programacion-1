#include <malloc.h>
#include "stAutoDinamico.h"

#define VALOR_DIMENSIONAMIENTO_AUTODINAMICO 2

void inicializarAutoDinamico(AutoDinamico* autoDin, int valorDimension){
    autoDin->dimension = valorDimension;
    autoDin->arrayAuto = (Auto*)malloc(autoDin->dimension * sizeof(Auto));

    if(autoDin->arrayAuto == NULL){
        perror("Error al asignar memoria a arreglo de autos");
        autoDin->validos = -1;
        return;
    }

    autoDin->validos = 0;
}

void verificarRedimensionAutoDinamico(AutoDinamico* autoDin){
    if(autoDin->validos < autoDin->dimension) return;

    autoDin->arrayAuto = (Auto*)realloc(autoDin->arrayAuto, (autoDin->dimension + VALOR_DIMENSIONAMIENTO_AUTODINAMICO) * sizeof(Auto));
    autoDin->dimension += VALOR_DIMENSIONAMIENTO_AUTODINAMICO;
}

void liberarAutoDinamico(AutoDinamico* autoDin){
    free(autoDin->arrayAuto);
    autoDin->dimension = 0;
    autoDin->validos = 0;
}
