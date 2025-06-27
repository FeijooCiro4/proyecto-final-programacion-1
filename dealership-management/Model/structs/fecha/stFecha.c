#include <stdio.h>
#include <time.h>
#include "stFecha.h"
#include "../../../View/utils/utils.h"

Fecha ingresarUnaFecha(){
    Fecha fecha;

    printf("Ingrese anio: ");
    fecha.anio = scanInt();
    while(fecha.anio < 1900){
        printf("El anio ingresado no es valido. Vuelva a ingresar el dato: ");
        fecha.anio = scanInt();
    }

    printf("Ingrese mes (1-12): ");
    fecha.mes = scanInt();
    while(fecha.mes > 12 || fecha.mes < 1){
        printf("El numero ingresado no pertenece a un mes valido. Vuelva a ingresar el dato: ");
        fecha.mes = scanInt();
    }

    printf("Ingrese dia: ");
    fecha.dia = scanInt();
    while(fecha.dia > cantMaximaDeDiasPorMes(fecha.mes, esAnioBisiesto(fecha.anio)) || fecha.dia < 1) {
        printf("El dia ingresado no es valido. Ingrese otro: ");
        fecha.dia = scanInt();
    }

    return fecha;
}

Fecha fechaActual(){
    Fecha fecha;
    time_t tiempoActual = time(NULL);
    struct tm *tiempoLocal = localtime(&tiempoActual);

    fecha.anio = tiempoLocal->tm_year + 1900;
    fecha.mes = tiempoLocal->tm_mon + 1;
    fecha.dia = tiempoLocal->tm_mday;

    return fecha;
}

Fecha inicializarFecha(){
    Fecha fecha;

    fecha.anio = 0;
    fecha.mes = 0;
    fecha.dia = 0;

    return fecha;
}

Fecha asignarFecha(int anio, int mes, int dia){
    Fecha fecha = inicializarFecha();

    if(anio < 1900){
        return fecha;
    }

    if(mes > 12 || mes < 1){
        return fecha;
    }

    if(dia > cantMaximaDeDiasPorMes(mes, esAnioBisiesto(anio)) || dia < 1) {
        return fecha;
    }

    fecha.anio = anio;
    fecha.mes = mes;
    fecha.dia = dia;

    return fecha;
}

int esAnioBisiesto(int anio){
    int flag = 0;

    if(anio % 4 == 1){
        if(anio % 100 == 1){
            if(anio % 400 == 1){
                flag = 1;
            } else {
                flag = 0;
            }
        } else {
            flag = 1;
        }
    } else {
        flag = 0;
    }

    return flag;
}

int cantMaximaDeDiasPorMes(int mes, int esAnioBisiesto){
    int cantDiasMes;

    if(mes == 1 || mes == 3 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        cantDiasMes = 31;
    } else if(mes == 2) {
        if(esAnioBisiesto){
            cantDiasMes = 29;
        } else {
            cantDiasMes = 28;
        }
    } else if(mes == 4 || mes == 5 || mes == 6 || mes == 9 || mes == 11){
        cantDiasMes = 30;
    } else {
        cantDiasMes = 0;
    }
    return cantDiasMes;
}

int validarFecha(Fecha fechaIngresada){
    Fecha fechaAct = fechaActual();

    if(fechaIngresada.anio > fechaAct.anio) return 0;

    if(fechaIngresada.anio == fechaAct.anio){
        if(fechaIngresada.mes > fechaAct.mes) return 0;

        if(fechaIngresada.mes == fechaAct.mes){
            if(fechaIngresada.dia > fechaAct.dia) return 0;
        }
    }

    return 1;
}

void mostrarUnaFecha(Fecha fechaMostrar){
    printf("Fecha: %02d/%02d/%04d\n", fechaMostrar.dia, fechaMostrar.mes, fechaMostrar.anio);
}
