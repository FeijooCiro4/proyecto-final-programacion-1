#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctrVenta.h"
#include "../../utils/utils.h"
#include "../persona/ctrPersona.h"
#include "../auto/ctrAuto.h"

static const char* ARCHIVO_PERSONAS = "personas.bin";
static const char* ARCHIVO_AUTOS = "autos.bin";
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

        if(idVentaUnicoArchivo(ARCHIVO_VENTAS, ventaAux.idVenta) && idVentaUnicoArreglo(ventaDin, ventaAux.idVenta)){
            if(existeIdAutoDeUnVendedorEnArchivo(ARCHIVO_AUTOS, ventaAux.patenteAutoVendido, ventaAux.dniVendedor)){
                if(!existeIdAutoEnArcivoVentas(ARCHIVO_VENTAS, ventaAux.patenteAutoVendido)){
                    Auto* autoVendido = retornarAutoDeArchivo(ARCHIVO_AUTOS, ventaAux.patenteAutoVendido);
                    ventaAux.ganancia = ventaAux.precioVenta - autoVendido->precioDeAdquisicion;

                    if(ventaAux.ganancia >= 0){
                        if(ventaAux.fecha.anio >= autoVendido->anio){
                            if(autoVendido != NULL) modificarTitularAuto(ARCHIVO_AUTOS, autoVendido, ventaAux.dniComprador);
                            if(dniUnicoPersona(ARCHIVO_PERSONAS, ventaAux.dniComprador)){
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

int idVentaUnicoArchivo(const char* archivo, int idIngresado){
    FILE* fp = fopen(archivo, "rb");

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

int existeIdAutoEnArcivoVentas(const char* archivo, char* patenteAuto){
    FILE* fp = fopen(archivo, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de ventas");
        return 1;
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

void buscarUnaVentaEnElSistema(VentaDinamica ventaDin, int idBuscar){
    for(int i=0; i<ventaDin.validos; i++){
        if((idBuscar == ventaDin.arrayVenta[i].idVenta)){
            mostrarUnaVenta(ventaDin.arrayVenta[i]);
            return;
        }
    }

    printf("\nEl ID ingresado no pertenece ninguna venta realizada por usted.\n");
}
