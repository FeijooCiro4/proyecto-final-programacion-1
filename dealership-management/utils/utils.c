#include "utils.h"

int esEnteroPositivo(int num){
    if(num < 0) return 0;

    return 1;
}

int scanString(char* cadena, int maxCaract){
    if(fgets(cadena, maxCaract, stdin) == NULL){
        return -1;
    }

    int ultimaPosicion = strlen(cadena) -1;

    if(cadena[ultimaPosicion] == '\n'){
        cadena[ultimaPosicion] = '\0';
    } else {
        limpiarBufferDeEntrada();
    }

    return strlen(cadena);
}
