#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctrVenta.h"
#include "../auto/ctrAuto.h"
#include "../persona/ctrPersona.h"
#include "../../../View/utils/utils.h"
#include "../../../Model/structs/fecha/stFecha.h"

static const char* ARCHIVO_VENTAS = "ventas.bin";

void ingresarVentas(char* dniVendedor){
    FILE* fp = fopen(ARCHIVO_VENTAS, "ab");

    if(fp == NULL){
        perror("Error al abrir el archivo de ventas");
        return;
    }

    int indice = 0;
    VentaDinamica ventaDin;
    inicializarVentaDinamica(&ventaDin, 2);
    Venta ventaAux;

    do {
        verificarRedimensionVentaDinamica(&ventaDin);
        printf("Dimension total: %d\nValidos: %d\n", ventaDin.dimension, ventaDin.validos);

        ventaAux = ingresarUnaVenta(dniVendedor);

        if(idVentaUnicoArchivo(ventaAux.idVenta) && idVentaUnicoArreglo(ventaDin, ventaAux.idVenta)){
            if(existeIdAutoDeUnVendedorEnArchivo(ventaAux.patenteAutoVendido, ventaAux.dniVendedor)){
                if(!existeIdAutoEnArchivoVentas(ventaAux.patenteAutoVendido)){
                    Auto* autoVendido = retornarAutoDeArchivo(ventaAux.patenteAutoVendido);
                    ventaAux.ganancia = ventaAux.precioVenta - autoVendido->precioDeAdquisicion;

                    if(ventaAux.ganancia >= 0){
                        if(ventaAux.fecha.anio >= autoVendido->anio){
                            if(autoVendido != NULL) modificarTitularAuto(autoVendido, ventaAux.dniComprador);
                            if(dniUnicoPersona(ventaAux.dniComprador)){
                                printf("Advertencia: Los datos de este comprador no estan en el sistema.\n"
                                       "Los datos de la venta seran guardados, pero al ver estos mismos no podra ver el nombre del comprador.\n");
                            }

                            ventaDin.arrayVenta[indice] = ventaAux;
                            ventaDin.validos++;
                            indice++;
                        } else {
                            printf("Error: La fecha de compra es inferior a la fecha de adquisicion del auto. "
                                   "Los datos de la venta no fueron guardados.\n");
                        }
                    } else {
                        printf("Error: El precio de venta es menor que el de adquisicion. Los datos de la venta no fueron guardados.\n");
                    }

                    free(autoVendido);
                } else {
                    printf("Error: El auto ingresado ya fue vendido. Los datos de la venta no fueron guardados.\n");
                }
            } else {
                printf("Error: La patente ingresada no pertenece a ningun auto registrado por usted.\n"
                       "Los datos de la venta no fueron guardados.\n");
            }
        } else {
            printf("Error: El id ingresado ya existe. Los datos de la venta no fueron guardados.\n");
        }

        printf("\nDesea seguir ingresando datos de ventas? (s/n): ");
    } while(confirmar('s'));

    if((indice == 0) || (fwrite(ventaDin.arrayVenta, sizeof(Venta), indice, fp) != indice)){
        perror("No se pudo escribir los datos del arreglo dinamico de ventas en el archivo de ventas");
    }

    liberarVentaDinamica(&ventaDin);
    fclose(fp);
}

int idVentaUnicoArchivo(int idIngresado){
    FILE* fp = fopen(ARCHIVO_VENTAS, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de ventas");
        return 0;
    }

    Venta ventaAux;

    while(fread(&ventaAux, sizeof(Venta), 1, fp) == 1){
        if(ventaAux.idVenta == idIngresado){
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}

int idVentaUnicoArreglo(VentaDinamica ventaDin, int idIngresado){
    for(int i=0; i<ventaDin.validos; i++){
        if(ventaDin.arrayVenta[i].idVenta == idIngresado){
            return 0;
        }
    }

    return 1;
}

int existeIdAutoEnArchivoVentas(char* patenteAuto){
    FILE* fp = fopen(ARCHIVO_VENTAS, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de ventas");
        return 0;
    }

    Venta ventaAuxiliar;

    while(fread(&ventaAuxiliar, sizeof(Venta), 1, fp) == 1){
        if(strcmp(ventaAuxiliar.patenteAutoVendido, patenteAuto) == 0){
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

VentaDinamica pasarArchivoTodasLasVentasAlArregloDinamico(){
    FILE* fp = fopen(ARCHIVO_VENTAS, "rb");

    VentaDinamica ventaDin;
    size_t tamanioArchivo = dimencionDeUnArchivo(fp) / sizeof(Venta);
    inicializarVentaDinamica(&ventaDin, tamanioArchivo);

    if(fp == NULL){
        perror("Error al abrir el archivo de ventas");
        return ventaDin;
    }

    int indice = 0;
    Venta ventaArchivo;

    while(fread(&ventaArchivo, sizeof(Venta), 1, fp) == 1){
        ventaDin.arrayVenta[indice] = ventaArchivo;
        ventaDin.validos++;
        indice++;
    }

    return ventaDin;
}

VentaDinamica pasarArchivoVentasAlArregloDinamico(char* dniVendedor){
    FILE* fp = fopen(ARCHIVO_VENTAS, "rb");

    VentaDinamica ventaDin;
    size_t tamanioArchivo = dimencionDeUnArchivo(fp) / sizeof(Venta);
    inicializarVentaDinamica(&ventaDin, tamanioArchivo);

    if(fp == NULL){
        perror("Error al abrir el archivo de ventas");
        return ventaDin;
    }

    int indice = 0;
    Venta ventaArchivo;

    while(fread(&ventaArchivo, sizeof(Venta), 1, fp) == 1){
        if(strcmp(ventaArchivo.dniVendedor, dniVendedor) == 0){
            ventaDin.arrayVenta[indice] = ventaArchivo;
            ventaDin.validos++;
            indice++;
        }
    }

    return ventaDin;
}

void mostrarTodasLasVentasDelSistema(VentaDinamica ventaDin, int indice){
    if(indice < ventaDin.validos){
        mostrarUnaVenta(ventaDin.arrayVenta[indice]);
        mostrarTodasLasVentasDelSistema(ventaDin, indice+1);
    }
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
                printf("Propietario: %s\n", buscarPersonaPorId(autoDin.arrayAuto[i].dniTitular));
                mostrarUnAuto(autoDin.arrayAuto[i]);
                break;
            }
        }
    }

    fclose(fp);
}

void buscarUnaVentaEnElSistema(VentaDinamica ventaDin, int idBuscar){
    for(int i=0; i<ventaDin.validos; i++){
        if((idBuscar == ventaDin.arrayVenta[i].idVenta)){
            mostrarUnaVenta(ventaDin.arrayVenta[i]);
            return;
        }
    }

    printf("\nEl ID ingresado no pertenece a ninguna venta realizada por usted.\n");
}

float calcularMargenGananciaMensual(VentaDinamica ventaDin, int anio, int mes, int dia, int indice){
    float gananciaTotal = 0;
    Fecha fecha = asignarFecha(anio, mes, dia);

    if(indice < ventaDin.validos){
        if(fecha.anio == 0 || fecha.mes == 0 || fecha.dia == 0){
            return 0;
        } else if((ventaDin.arrayVenta[indice].fecha.anio == fecha.anio) && (ventaDin.arrayVenta[indice].fecha.mes == fecha.mes)){
            if(ventaDin.arrayVenta[indice].fecha.dia == fecha.dia){
                gananciaTotal += ventaDin.arrayVenta[indice].ganancia;
                return gananciaTotal += calcularMargenGananciaMensual(ventaDin, anio, mes, 1, indice+1);
            } else {
                return gananciaTotal += calcularMargenGananciaMensual(ventaDin, anio, mes, dia+1, indice);
            }
        } else {
            return gananciaTotal += calcularMargenGananciaMensual(ventaDin, anio, mes, 1, indice+1);
        }
    }

    return gananciaTotal;
}

int calcularMargenDeGananciaMasAlto(VentaDinamica ventaDin){
    int gananciaMasAlta = ventaDin.arrayVenta[0].ganancia;
    int indiceGananciaAlta;

    for(int i=0; i<ventaDin.validos; i++){
        if(gananciaMasAlta < ventaDin.arrayVenta[i].ganancia){
            gananciaMasAlta = ventaDin.arrayVenta[i].ganancia;
            indiceGananciaAlta = i;
        }
    }

    return indiceGananciaAlta;
}

void pasarClientesArregloPersonas(PersonaDinamica* personaDin, VentaDinamica ventaDin){
    for(int i=0; i<ventaDin.validos; i++){
        int flag = 1;
        for(int j=0; j<personaDin->validos; j++){
            if(strcmp(personaDin->arrayPersona[j].dni, ventaDin.arrayVenta[i].dniComprador) == 0) flag = 0;
        }
        if(flag) pasarArchivoPesonasAlArregloPorId(personaDin, ventaDin.arrayVenta[i].dniComprador);
    }
}

void borrarVenta(char* dniVendedor, int idVentaEliminar){
    FILE* fp = fopen(ARCHIVO_VENTAS, "r+b");

    if(fp == NULL){
        perror("Error al abrir el archivo de ventas");
        return;
    }

    Venta ventaArchivo;

    while(fread(&ventaArchivo, sizeof(Venta), 1, fp) == 1){
        if((ventaArchivo.idVenta == idVentaEliminar) && (strcmp(ventaArchivo.dniVendedor, dniVendedor) == 0)){
            Auto* autoVendido = retornarAutoDeArchivo(ventaArchivo.patenteAutoVendido);
            modificarTitularAuto(autoVendido, dniVendedor);

            ventaArchivo.idVenta = 0;
            strcpy(ventaArchivo.dniVendedor, "Borrado");
            strcpy(ventaArchivo.dniComprador, "Borrado");
            strcpy(ventaArchivo.patenteAutoVendido, "Borrado");
            ventaArchivo.precioVenta = 0.0;
            ventaArchivo.ganancia = 0.0;
            ventaArchivo.fecha.anio = 0;
            ventaArchivo.fecha.mes = 0;
            ventaArchivo.fecha.dia = 0;

            fseek(fp, -(long)sizeof(Venta), SEEK_CUR);

            if(fwrite(&ventaArchivo, sizeof(Venta), 1, fp) != 1){
                perror("No se pudo escribir en el archivo de ventas");
                fclose(fp);
                return;
            }

            printf("\n\tVenta borrada con exito!\n\n");
            fclose(fp);
            return;
        }
    }

    printf("\nNo se encontro la venta buscada.\n");
    fclose(fp);
}
