#include <stdio.h>
#include <string.h>
#include "ctrAuto.h"
#include "../utils/utils.h"
#include "../structs/persona/stPersona.h"

#define VALOR_REDIMENSIONAMIENTO_AUTO 5

static const char* ARCHIVO_PERSONAS = "personas.bin";
static const char* ARCHIVO_AUTOS = "autos.bin";

void insertarAutos(char* dniTitular){
    Auto autoAux;
    AutoDinamico autoDin;
    inicializarAutoDinamico(&autoDin, VALOR_REDIMENSIONAMIENTO_AUTO);

    do{
        verificarRedimensionAutoDinamico(&autoDin);

        autoAux = ingresarAuto(dniTitular);

        if((datosDeAutoValidosArchivo(autoAux, ARCHIVO_AUTOS)) && (datosDeAutoValidosArreglo(autoAux, autoDin))){
            autoDin.arrayAuto[autoDin.validos] = autoAux;
            autoDin.validos++;
        }

        printf("\nDesea seguir ingresando datos? (s/n)");
    }while(confirmar('s'));

    FILE* fp = fopen(ARCHIVO_AUTOS, "ab");

    if(fp == NULL){
        perror("Error al abrir el archivo de autos");
        return;
    }

    if((autoDin.validos == 0) || (fwrite(autoDin.arrayAuto, autoDin.validos*sizeof(Auto), autoDin.validos, fp) != autoDin.validos)){
        perror("Error al escribir los datos del arreglo dinamico de autos en el archivo de autos");
        fclose(fp);
        return;
    }

    liberarAutoDinamico(&autoDin);
    fclose(fp);
}

int datosDeAutoValidosArchivo(Auto autoIngresado, const char* archivo){
    FILE* fp = fopen(archivo, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de autos");
        return 0;
    }

    Auto autoArchivo;

    while(fread(&autoArchivo, sizeof(Auto), 1, fp) == 1){
        if(strcmp(autoArchivo.patente, autoIngresado.patente) == 0){
            printf("La patente ingresada ya existe en el archivo. Vuelva a ingresar todos los datos.\n");
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}

int datosDeAutoValidosArreglo(Auto autoIngresado, AutoDinamico arregloAutos){
    for(int i=0; i<arregloAutos.validos; i++){
        if(strcmp(arregloAutos.arrayAuto[i].patente, autoIngresado.patente) == 0){
            printf("La patente ingresada ya existe en el arreglo. Vuelva a ingresar todos los datos.\n");
            return 0;
        }
    }

    return 1;
}

void mostrarTodosLosAutosDelSistema(AutoDinamico autoDin, int indice){
    if(indice < autoDin.validos){
        printf("Titular: %s\n", buscarPersonaPorId(ARCHIVO_PERSONAS, autoDin.arrayAuto[indice].dniTitular));
        mostrarUnAuto(autoDin.arrayAuto[indice]);
        mostrarTodosLosAutosDelSistema(autoDin, indice+1);
    }
}

AutoDinamico pasarArchivoAutosAlArregloDinamico(void){
    AutoDinamico autoDin;
    inicializarAutoDinamico(&autoDin, VALOR_REDIMENSIONAMIENTO_AUTO);

    FILE* fp = fopen(ARCHIVO_AUTOS, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de autos");
        return ;
    }

    Auto autoAuxiliar;

    while(fread(&autoAuxiliar, sizeof(Auto), 1, fp) == 1){
        verificarRedimensionAutoDinamico(&autoDin);
        autoDin.arrayAuto[autoDin.validos] = autoAuxiliar;
        autoDin.validos++;
    }

    return autoDin;
}
