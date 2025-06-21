#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctrAuto.h"
#include "../../utils/utils.h"
#include "../persona/ctrPersona.h"
#include "../venta/ctrVenta.h"

#define VALOR_REDIMENSIONAMIENTO_AUTO 2

static const char* ARCHIVO_PERSONAS = "personas.bin";
static const char* ARCHIVO_AUTOS = "autos.bin";
static const char* ARCHIVO_VENTAS = "ventas.bin";

void insertarAutos(char* dniTitular){
    FILE* fp = fopen(ARCHIVO_AUTOS, "ab");

    int indice = 0;
    Auto autoAux;
    AutoDinamico autoDin;
    inicializarAutoDinamico(&autoDin, VALOR_REDIMENSIONAMIENTO_AUTO);

    do{
        verificarRedimensionAutoDinamico(&autoDin);
        printf("Dimension total: %d\nValidos: %d\n", autoDin.dimension, autoDin.validos);

        autoAux = ingresarAuto(dniTitular);

        if((datosDeAutoValidosArchivo(autoAux, ARCHIVO_AUTOS)) && (datosDeAutoValidosArreglo(autoAux, autoDin))){
            autoDin.arrayAuto[indice] = autoAux;
            autoDin.validos++;
            indice++;
        } else {
            printf("La patente ingresada ya existe. Vuelva a ingresar todos los datos.\n");
        }

        printf("\nDesea seguir ingresando datos? (s/n)");
    }while(confirmar('s'));


    if(fp == NULL){
        perror("Error al abrir el archivo de autos");
        return;
    }

    if((indice == 0) || (fwrite(autoDin.arrayAuto, sizeof(Auto), indice, fp) != indice)){
        perror("Error al escribir los datos del arreglo dinamico de autos en el archivo de autos");
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
            return 0;
        }
    }

    return 1;
}

void mostrarTodosLosAutosDelSistema(AutoDinamico autoDin, int indice){
    if(indice < autoDin.validos){
        if(!existeIdAutoEnArcivoVentas(ARCHIVO_VENTAS, autoDin.arrayAuto[indice].patente)){
            printf("Titular: %s\n", buscarPersonaPorId(ARCHIVO_PERSONAS, autoDin.arrayAuto[indice].dniTitular));
            mostrarUnAuto(autoDin.arrayAuto[indice]);
        }
        mostrarTodosLosAutosDelSistema(autoDin, indice+1);
    }
}

AutoDinamico pasarArchivoAutosAlArregloDinamico(){
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
        if(!existeIdAutoEnArcivoVentas(ARCHIVO_VENTAS, autoDin.arrayAuto[i].patente)){
            if(strcmp(patenteBuscar, autoDin.arrayAuto[i].patente) == 0){
                printf("\nTitular: %s\n", buscarPersonaPorId(ARCHIVO_PERSONAS, autoDin.arrayAuto[i].dniTitular));
                mostrarUnAuto(autoDin.arrayAuto[i]);
                return;
            }
        }
    }

    printf("\nLa patente ingresada no pertenece a ningun auto a la venta o registrado en el sistema.\n");
}

void mostrarAutosDeUnVendedor(AutoDinamico autoDin, char* dniTitular){
    for(int i=0; i<autoDin.validos; i++){
        if(strcmp(autoDin.arrayAuto[i].dniTitular, dniTitular) == 0){
            printf("Titular: %s\n", buscarPersonaPorId(ARCHIVO_PERSONAS, autoDin.arrayAuto[i].dniTitular));
            mostrarUnAuto(autoDin.arrayAuto[i]);
        }
    }
}

int existeIdAutoDeUnVendedorEnArchivo(const char* archivo, char* patenteAuto, char* dniVendeor){
    FILE*fp = fopen(archivo, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de autos");
        return 0;
    }

    Auto autoAuxiliar;

    while(fread(&autoAuxiliar, sizeof(Auto), 1, fp) == 1){
        if(strcmp(autoAuxiliar.dniTitular, dniVendeor) == 0){
            if(strcmp(autoAuxiliar.patente, patenteAuto) == 0){
                fclose(fp);
                return 1;
            }
        }
    }

    fclose(fp);
    return 0;
}

void modificarTitularAuto(const char* archivo, Auto* autoCambiar, char* dniNuevoTitular){
    FILE* fp = fopen(archivo, "r+b");

    if(fp == NULL){
        perror("Error al abrir el archivo de autos");
        return;
    }

    Auto autoAuxiliar;

    while(fread(&autoAuxiliar, sizeof(Auto), 1, fp) == 1){
        if(strcmp(autoCambiar->patente, autoAuxiliar.patente) == 0){
            strcpy(autoCambiar->dniTitular, dniNuevoTitular);

            fseek(fp, -(long)sizeof(Auto), SEEK_CUR);

            if(fwrite(autoCambiar, sizeof(Auto), 1, fp) != 1){
                perror("No se pudo escribir en el archivo de autos");
            }

            fflush(fp);

            fclose(fp);
            return;
        }
    }

    fclose(fp);
}

Auto* retornarAutoDeArchivo(const char* archivo, char* patenteAuto){
    FILE* fp = fopen(archivo, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de autos");
        return NULL;
    }

    Auto autoAuxiliar;

    while(fread(&autoAuxiliar, sizeof(Auto), 1, fp) == 1){
        if(strcmp(autoAuxiliar.patente, patenteAuto) == 0){
            fclose(fp);

            Auto* autoEncontrado = (Auto*)malloc(sizeof(Auto));

            if(autoEncontrado == NULL){
                perror("Error en la asignacion de memoria");
                return NULL;
            }

            *autoEncontrado = autoAuxiliar;

            return autoEncontrado;
        }
    }

    fclose(fp);
    return NULL;
}

void mostrarAutosVendidosPorVendedor(AutoDinamico autoDin, char* dniVendedor){
    FILE* fp = fopen(ARCHIVO_VENTAS, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de ventas");
        return;
    }

    Venta ventaArchivo;

    while(fread(&ventaArchivo, sizeof(Venta), 1, fp) == 1){
        for(int i=0; i<autoDin.validos; i++){
            if((strcmp(ventaArchivo.dniVendedor, dniVendedor) == 0) && (strcmp(ventaArchivo.patenteAutoVendido, autoDin.arrayAuto[i].patente) == 0)){
                printf("Propietario: %s\n", buscarPersonaPorId(ARCHIVO_PERSONAS, autoDin.arrayAuto[i].dniTitular));
                mostrarUnAuto(autoDin.arrayAuto[i]);
                break;
            }
        }
    }

    fclose(fp);
}
