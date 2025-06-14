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

bool esDniValido(const char* dni){
    if(dni == NULL) return false;

    size_t longitud = strlen(dni);
    if(longitud != 8) return false;

    for(int i=0; i<longitud; i++){
        if(!isdigit(dni[i])){
            return false;
        }
    }

    return true;
}
