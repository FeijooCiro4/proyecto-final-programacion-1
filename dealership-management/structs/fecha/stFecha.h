#ifndef STFECHA_H_INCLUDED
#define STFECHA_H_INCLUDED

typedef struct stFecha {
	int dia;
	int mes;
	int anio;
} Fecha;

Fecha ingresarUnaFecha(void);
Fecha fechaActual(void);
int esAnioBisiesto(int anio);
int cantMaximaDeDiasPorMes(int mes, int esAnioBisiesto);
int validarFecha(Fecha fechaIngresada);
void mostrarUnaFecha(Fecha fechaMostrar);

#endif // STFECHA_H_INCLUDED
