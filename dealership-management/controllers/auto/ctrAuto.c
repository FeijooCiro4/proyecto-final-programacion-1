#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctrAuto.h"
#include "../../utils/utils.h"
#include "../persona/ctrPersona.h"
#include "../venta/ctrVenta.h"

#define VALOR_REDIMENSIONAMIENTO_AUTO 2

static const char* ARCHIVO_AUTOS = "autos.bin";

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

        if((datosDeAutoValidosArchivo(autoAux)) && (datosDeAutoValidosArreglo(autoAux, autoDin))){
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

int datosDeAutoValidosArchivo(Auto autoIngresado){
    FILE* fp = fopen(ARCHIVO_AUTOS, "rb");

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

void mostrarTodosLosAutosALaVenta(AutoDinamico autoDin, int indice){
    if(indice < autoDin.validos){
        if(!existeIdAutoEnArchivoVentas(autoDin.arrayAuto[indice].patente)){
            printf("Titular: %s\n", buscarPersonaPorId(autoDin.arrayAuto[indice].dniTitular));
            mostrarUnAuto(autoDin.arrayAuto[indice]);
        }
        mostrarTodosLosAutosALaVenta(autoDin, indice+1);
    }
}

void mostrarTodosLosAutosDeUnArreglo(AutoDinamico autoDin, int indice){
    if(indice < autoDin.validos){
        printf("Titular: %s\n", buscarPersonaPorId(autoDin.arrayAuto[indice].dniTitular));
        mostrarUnAuto(autoDin.arrayAuto[indice]);
        mostrarTodosLosAutosDeUnArreglo(autoDin, indice+1);
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

    fclose(fp);
    return autoDin;
}

AutoDinamico pasarArchivoAutosALaVentaAlArregloDinamico(void){
    FILE* fp = fopen(ARCHIVO_AUTOS, "rb");

    AutoDinamico autoDin;
    inicializarAutoDinamico(&autoDin, 2);

    if(fp == NULL){
        perror("Error al abrir el archivo de autos");
        return autoDin;
    }

    Auto autoAuxiliar;

    while(fread(&autoAuxiliar, sizeof(Auto), 1, fp) == 1){
        if(!existeIdAutoEnArchivoVentas(autoAuxiliar.patente)){
            verificarRedimensionAutoDinamico(&autoDin);
            autoDin.arrayAuto[autoDin.validos] = autoAuxiliar;
            autoDin.validos++;
        }
    }

    fclose(fp);
    return autoDin;
}

AutoDinamico pasarArchivoAutosVendidosAlArregloDinamico(void){
    FILE* fp = fopen(ARCHIVO_AUTOS, "rb");

    AutoDinamico autoDin;
    inicializarAutoDinamico(&autoDin, 2);

    if(fp == NULL){
        perror("Error al abrir el archivo de autos");
        return autoDin;
    }

    Auto autoAuxiliar;

    while(fread(&autoAuxiliar, sizeof(Auto), 1, fp) == 1){
        if(existeIdAutoEnArchivoVentas(autoAuxiliar.patente)){
            verificarRedimensionAutoDinamico(&autoDin);
            autoDin.arrayAuto[autoDin.validos] = autoAuxiliar;
            autoDin.validos++;
        }
    }

    fclose(fp);
    return autoDin;
}

void buscarUnAutoEnElSistema(AutoDinamico autoDin, char* patenteBuscar){
    for(int i=0; i<autoDin.validos; i++){
        if(!existeIdAutoEnArchivoVentas(autoDin.arrayAuto[i].patente)){
            if(strcmp(patenteBuscar, autoDin.arrayAuto[i].patente) == 0){
                printf("\nTitular: %s\n", buscarPersonaPorId(autoDin.arrayAuto[i].dniTitular));
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
            printf("Titular: %s\n", buscarPersonaPorId(autoDin.arrayAuto[i].dniTitular));
            mostrarUnAuto(autoDin.arrayAuto[i]);
        }
    }
}

int existeIdAutoDeUnVendedorEnArchivo(char* patenteAuto, char* dniVendeor){
    FILE*fp = fopen(ARCHIVO_AUTOS, "rb");

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

void modificarTitularAuto(Auto* autoCambiar, char* dniNuevoTitular){
    FILE* fp = fopen(ARCHIVO_AUTOS, "r+b");

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

            fclose(fp);
            return;
        }
    }

    fclose(fp);
}

void modificarMarcaAuto(char* patente, char* dniTitular, char* marcaNueva){
    FILE* fp = fopen(ARCHIVO_AUTOS, "r+b");

    if(fp == NULL){
        perror("Error al abrir el archivo de autos");
        return;
    }

    Auto autoAuxiliar;

    while(fread(&autoAuxiliar, sizeof(Auto), 1, fp) == 1){
        if((strcmp(patente, autoAuxiliar.patente) == 0) && (strcmp(dniTitular, autoAuxiliar.dniTitular) == 0)){
            strcpy(autoAuxiliar.marca, marcaNueva);

            fseek(fp, -(long)sizeof(Auto), SEEK_CUR);

            if(fwrite(&autoAuxiliar, sizeof(Auto), 1, fp) != 1){
                perror("No se pudo escribir en el archivo de autos");
            }

            fclose(fp);
            return;
        }
    }

    fclose(fp);
    printf("\nNo se pudo cambiar la marca del auto.\n");
}

void modificarModeloAuto(char* patente, char* dniTitular, char* modeloNuevo){
    FILE* fp = fopen(ARCHIVO_AUTOS, "r+b");

    if(fp == NULL){
        perror("Error al abrir el archivo de autos");
        return;
    }

    Auto autoAuxiliar;

    while(fread(&autoAuxiliar, sizeof(Auto), 1, fp) == 1){
        if((strcmp(patente, autoAuxiliar.patente) == 0) && (strcmp(dniTitular, autoAuxiliar.dniTitular) == 0)){
            strcpy(autoAuxiliar.modelo, modeloNuevo);

            fseek(fp, -(long)sizeof(Auto), SEEK_CUR);

            if(fwrite(&autoAuxiliar, sizeof(Auto), 1, fp) != 1){
                perror("No se pudo escribir en el archivo de autos");
            }

            fclose(fp);
            return;
        }
    }

    fclose(fp);
    printf("\nNo se pudo cambiar el modelo del auto.\n");
}

void modificarAnioAdqAuto(char* patente, char* dniTitular, int anioAdqNuevo){
    FILE* fp = fopen(ARCHIVO_AUTOS, "r+b");

    if(fp == NULL){
        perror("Error al abrir el archivo de autos");
        return;
    }

    Auto autoAuxiliar;

    while(fread(&autoAuxiliar, sizeof(Auto), 1, fp) == 1){
        if((strcmp(patente, autoAuxiliar.patente) == 0) && (strcmp(dniTitular, autoAuxiliar.dniTitular) == 0)){
            autoAuxiliar.anio = anioAdqNuevo;

            fseek(fp, -(long)sizeof(Auto), SEEK_CUR);

            if(fwrite(&autoAuxiliar, sizeof(Auto), 1, fp) != 1){
                perror("No se pudo escribir en el archivo de autos");
            }

            fclose(fp);
            return;
        }
    }

    fclose(fp);
    printf("\nNo se pudo cambiar el anio de fabricacion/adquisicion del auto.\n");
}

void modificarKmAuto(char* patente, char* dniTitular, int kmNuevo){
    FILE* fp = fopen(ARCHIVO_AUTOS, "r+b");

    if(fp == NULL){
        perror("Error al abrir el archivo de autos");
        return;
    }

    Auto autoAuxiliar;

    while(fread(&autoAuxiliar, sizeof(Auto), 1, fp) == 1){
        if((strcmp(patente, autoAuxiliar.patente) == 0) && (strcmp(dniTitular, autoAuxiliar.dniTitular) == 0)){
            autoAuxiliar.kms = kmNuevo;

            fseek(fp, -(long)sizeof(Auto), SEEK_CUR);

            if(fwrite(&autoAuxiliar, sizeof(Auto), 1, fp) != 1){
                perror("No se pudo escribir en el archivo de autos");
            }

            fclose(fp);
            return;
        }
    }

    fclose(fp);
    printf("\nNo se pudo cambiar el kilometraje del auto.\n");
}

void modificarPrecioAdqAuto(char* patente, char* dniTitular, float precioAdqNuevo){
    FILE* fp = fopen(ARCHIVO_AUTOS, "r+b");

    if(fp == NULL){
        perror("Error al abrir el archivo de autos");
        return;
    }

    Auto autoAuxiliar;

    while(fread(&autoAuxiliar, sizeof(Auto), 1, fp) == 1){
        if((strcmp(patente, autoAuxiliar.patente) == 0) && (strcmp(dniTitular, autoAuxiliar.dniTitular) == 0)){
            autoAuxiliar.precioDeAdquisicion = precioAdqNuevo;

            fseek(fp, -(long)sizeof(Auto), SEEK_CUR);

            if(fwrite(&autoAuxiliar, sizeof(Auto), 1, fp) != 1){
                perror("No se pudo escribir en el archivo de autos");
            }

            fclose(fp);
            return;
        }
    }

    fclose(fp);
    printf("\nNo se pudo cambiar el precio de adquisicion del auto.\n");
}

Auto* retornarAutoDeArchivo(char* patenteAuto){
    FILE* fp = fopen(ARCHIVO_AUTOS, "rb");

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

AutoDinamico ordenarArregloDeAutos(AutoDinamico autoDin){
    for(int i=0; i<autoDin.validos; i++){
        for(int j=0; j<autoDin.validos; j++){
            if(autoDin.arrayAuto[i].anio < autoDin.arrayAuto[j].anio){
                Auto autoAux = autoDin.arrayAuto[i];
                autoDin.arrayAuto[i] = autoDin.arrayAuto[j];
                autoDin.arrayAuto[j] = autoAux;
            }
        }
    }

    return autoDin;
}

void borrarAuto(char* dniTitular, char* patenteAutoBorrar){
    FILE* fp = fopen(ARCHIVO_AUTOS, "r+b");

    if(fp == NULL){
        perror("Error al abrir el archivo de autos");
        return;
    }

    Auto autoAuxiliar;

    while(fread(&autoAuxiliar, sizeof(Auto), 1, fp) == 1){
        if((strcmp(patenteAutoBorrar, autoAuxiliar.patente) == 0) && (strcmp(dniTitular, autoAuxiliar.dniTitular) == 0)){
            strcpy(autoAuxiliar.patente, "Borrado");
            strcpy(autoAuxiliar.marca, "Borrado");
            strcpy(autoAuxiliar.modelo, "Borrado");
            autoAuxiliar.kms = 0;
            autoAuxiliar.anio = 0;
            strcpy(autoAuxiliar.dniTitular, "Borrado");
            autoAuxiliar.precioDeAdquisicion = 0.0;

            fseek(fp, -(long)sizeof(Auto), SEEK_CUR);

            if(fwrite(&autoAuxiliar, sizeof(Auto), 1, fp) != 1){
                perror("No se pudo escribir en el archivo de autos");
                fclose(fp);
                return;
            }

            printf("\nLos datos han sido eliminados con exito!\n\n");
            fclose(fp);
            return;
        }
    }

    fclose(fp);
    printf("\nNo se pudo borrar el auto. La patente ingresada es invalida\n");
}
