#include <malloc.h>
#include "stAutoDinamico.h"

#define VALOR_DIMENSIONAMIENTO_AUTODINAMICO 2

void inicializarAutoDinamico(AutoDinamico* autoDin, int valorDimension){
    autoDin->dimencion = valorDimension;
    autoDin->arrayAuto = (Auto*)malloc(autoDin->dimencion * sizeof(Auto));

    if(autoDin->arrayAuto == NULL){
        perror("Error al asignar memoria a arreglo de autos");
        autoDin->validos = -1;
        return;
    }

    autoDin->validos = 0;
}

void verificarRedimensionAutoDinamico(AutoDinamico* autoDin){
    if(autoDin->validos < autoDin->dimencion) return;

    autoDin->arrayAuto = (Auto*)realloc(autoDin->arrayAuto, (autoDin->dimencion + VALOR_DIMENSIONAMIENTO_AUTODINAMICO) * sizeof(Auto));
    autoDin->dimencion += VALOR_DIMENSIONAMIENTO_AUTODINAMICO;
    printf("\n-----------------Redimencionamiento del arreglo-----------------\n");
}

void liberarAutoDinamico(AutoDinamico* autoDin){
    free(autoDin->arrayAuto);
    autoDin->dimencion = 0;
    autoDin->validos = 0;
}
