#include <time.h>
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

size_t dimencionDeUnArchivo(FILE* fp){
    fseek(fp, 0, SEEK_END);
    size_t resultado = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return resultado;
}

char* identificarMesDelAnio(int mes){
    switch(mes){
    case 1:
        return "Enero";
        break;
    case 2:
        return "Febrero";
        break;
    case 3:
        return "Marzo";
        break;
    case 4:
        return "Abril";
        break;
    case 5:
        return "Mayo";
        break;
    case 6:
        return "Junio";
        break;
    case 7:
        return "Julio";
        break;
    case 8:
        return "Agosto";
        break;
    case 9:
        return "Septiembre";
        break;
    case 10:
        return "Octubre";
        break;
    case 11:
        return "Noviembre";
        break;
    case 12:
        return "Diciembre";
        break;
    default:
        return "(Error)";
        break;
    }
}

int anioAnteriorAlActual(int anio){
    time_t tiempoActual = time(NULL);
    struct tm *tiempoLocal = localtime(&tiempoActual);

    int anioActual = tiempoLocal->tm_year + 1900;

    if(anio<=anioActual && anio>=1900){
        return 1;
    }

    return 0;
}
