#include <stdio.h>
#include <string.h>
#include "ctrPersona.h"
#include "../../utils/utils.h"

Persona ingresarPersona(const char* archivo, const char* dniRegistrado){
    Persona per;

    if(strlen(dniRegistrado) == 0){
        printf("Ingrese su DNI: ");
        scanString(per.dni, MAX_CARACT_PERSONA_DNI);
        while(!esDniValido(per.dni) || !dniUnicoPersona(archivo, per.dni)){
            printf("El DNI ingresado no es valido. Ingrese otro: ");
            scanString(per.dni, MAX_CARACT_PERSONA_DNI);
        }
    } else {
        strcpy(per.dni, dniRegistrado);
    }

    printf("Ingrese su nombre: ");
    scanString(per.nombrePersona, MAX_CARACT_PERSONA_STANDARD);

    printf("Ingrese su apellido: ");
    scanString(per.apellidoPersona, MAX_CARACT_PERSONA_STANDARD);

    printf("Ingrese su numero de telefono: ");
    scanString(per.telefono, MAX_CARACT_PERSONA_STANDARD);
    while(!validarNumeroTelefonoPersona(per.telefono)){
        printf("El numero de telefono ingresado no es valido. Ingrese otro: ");
        scanString(per.telefono, MAX_CARACT_PERSONA_STANDARD);
    }

    printf("Ingrese su ciudad de residencia: ");
    scanString(per.ciudad, MAX_CARACT_PERSONA_STANDARD);

    return per;
}

int dniUnicoPersona(const char* archivo, const char *dni){
    FILE* fp = fopen(archivo, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de personas");
        return 0;
    }

    Persona perAux;

    while(fread(&perAux, sizeof(Persona), 1, fp) == 1){
        if(strcmp(perAux.dni, dni) == 0){
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}

int validarNumeroTelefonoPersona(const char *telefono){
    for(int i=0; i<strlen(telefono); i++){
        if(!isdigit(telefono[i])) return 0;
    }

    return 1;
}

char* buscarPersonaPorId(const char* archivo, char* dni){
    FILE* fp = fopen(archivo, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de personas");
        return "(no se encontro)";
    }

    Persona per;

    while(fread(&per, sizeof(Persona), 1, fp) == 1){
        if(strcmp(dni, per.dni) == 0){
            char *nombreCompleto = (char*)malloc(50*sizeof(char));
            strcpy(nombreCompleto, per.nombrePersona);
            strcat(nombreCompleto, " ");
            strcat(nombreCompleto, per.apellidoPersona);

            fclose(fp);
            return nombreCompleto;
        }
    }

    fclose(fp);
    return "(no se encontro)";
}
