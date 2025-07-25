#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

static inline void limpiarBufferDeEntrada(void){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

static inline int confirmar(char condicion){
    char aux = '\0';
    scanf("%c", &aux);
    limpiarBufferDeEntrada();
    return tolower(aux) == tolower(condicion);
}

static inline void limpiarPantalla(void){
    system("pause");
    system("cls");
}

static inline int scanInt(void){
    int aux;

    if(scanf("%d", &aux) != 1){
        limpiarBufferDeEntrada();
        return -1;
    }
    limpiarBufferDeEntrada();

    return aux;
}

static inline float scanFloat(void){
    float aux;

    if(scanf("%f", &aux) != 1){
        limpiarBufferDeEntrada();
        return -1;
    }
    limpiarBufferDeEntrada();

    return aux;
}

static inline char scanChar(void){
    char aux = '\0';
    scanf("%c", &aux);
    limpiarBufferDeEntrada();
    return aux;
}

int esEnteroPositivo(int num);
int scanString(char* cadena, int maxCaract);
bool esDniValido(const char* dni);
size_t dimencionDeUnArchivo(FILE* fp);
char* identificarMesDelAnio(int mes);
int anioAnteriorAlActual(int anio);

#endif // UTILS_H_INCLUDED
