#include <stdio.h>
#include <string.h>
#include "ctrAuto.h"
#include "../../utils/utils.h"
#include "../persona/ctrPersona.h"

#define VALOR_REDIMENSIONAMIENTO_AUTO 2

static const char* ARCHIVO_PERSONAS = "personas.bin";
static const char* ARCHIVO_AUTOS = "autos.bin";

void insertarAutos(char* dniTitular){
    FILE* fp = fopen(ARCHIVO_AUTOS, "ab");

    int indice = 0;
    Auto autoAux;
    AutoDinamico autoDin;
    inicializarAutoDinamico(&autoDin, VALOR_REDIMENSIONAMIENTO_AUTO);

    do{
        verificarRedimensionAutoDinamico(&autoDin);
        printf("Dimension total: %d\nValidos: %d\n", autoDin.dimencion, autoDin.validos);

        autoAux = ingresarAuto(dniTitular);

        if((datosDeAutoValidosArchivo(autoAux, ARCHIVO_AUTOS)) && (datosDeAutoValidosArreglo(autoAux, autoDin))){
            autoDin.arrayAuto[indice] = autoAux;
            autoDin.validos++;
            indice++;
        }

        printf("\nDesea seguir ingresando datos? (s/n)");
    }while(confirmar('s'));


    if(fp == NULL){
        perror("Error al abrir el archivo de autos");
        return;
    }

    if((indice == 0) || (fwrite(autoDin.arrayAuto, sizeof(Auto), indice, fp) != indice)){
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
    FILE* fp = fopen(ARCHIVO_AUTOS, "rb");

    AutoDinamico autoDin;
    size_t dimensionAutos = dimencionDeUnArchivo(fp) / sizeof(Auto);
    inicializarAutoDinamico(&autoDin, dimensionAutos);

    if(fp == NULL){
        perror("Error al abrir el archivo de autos");
        return autoDin;
    }

    Auto autoAuxiliar;

    while(fread(&autoAuxiliar, sizeof(Auto), 1, fp) == 1){
        verificarRedimensionAutoDinamico(&autoDin);
        autoDin.arrayAuto[autoDin.validos] = autoAuxiliar;
        autoDin.validos++;
    }

    return autoDin;
}

void buscarUnAutoEnElSistema(AutoDinamico autoDin, char* patenteBuscar){
    for(int i=0; i<autoDin.validos; i++){
        if(strcmp(patenteBuscar, autoDin.arrayAuto[i].patente) == 0){
            printf("\nTitular: %s\n", buscarPersonaPorId(ARCHIVO_PERSONAS, autoDin.arrayAuto[i].dniTitular));
            mostrarUnAuto(autoDin.arrayAuto[i]);
            return;
        }
    }

    printf("\nLa patente ingresada no erttenece a ningun auto registrado en el sistema.\n");
}

void mostrarAutosDeUnVendedor(AutoDinamico autoDin, char* dniTitular){
    for(int i=0; i<autoDin.validos; i++){
        if(strcmp(autoDin.arrayAuto[i].dniTitular, dniTitular) == 0){
            printf("Titular: %s\n", buscarPersonaPorId(ARCHIVO_PERSONAS, autoDin.arrayAuto[i].dniTitular));
            mostrarUnAuto(autoDin.arrayAuto[i]);
        }
    }
}
