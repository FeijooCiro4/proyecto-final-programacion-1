#include <stdio.h>
#include <string.h>
#include "ctrPersona.h"
#include "../usuario/ctrUsuario.h"
#include "../../../View/utils/utils.h"

static const char* ARCHIVO_PERSONAS = "personas.bin";

Persona ingresarPersona(const char* dniRegistrado){
    Persona per;

    if(strlen(dniRegistrado) == 0){
        printf("Ingrese su DNI: ");
        scanString(per.dni, MAX_CARACT_PERSONA_DNI);
        while(!esDniValido(per.dni) || !dniUnicoPersona(per.dni)){
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

void guardarPersonaEnArchivo(Persona* personaGuardar){
    if(personaGuardar != NULL){
        FILE* fp = fopen(ARCHIVO_PERSONAS, "ab");

        if(fp == NULL){
            perror("Error al abrir el archivo de personas");
            return;
        }

        if(fwrite(personaGuardar, sizeof(Persona), 1, fp) != 1){
            perror("No se pudo escribir en el archivo de personas");
        }

        fclose(fp);
    } else {
        printf("\nError en los valores de la estructura.\n\n");
        system("pause");
    }
}

int dniUnicoPersona(const char *dni){
    FILE* fp = fopen(ARCHIVO_PERSONAS, "rb");

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

char* buscarPersonaPorId(char* dni){
    FILE* fp = fopen(ARCHIVO_PERSONAS, "rb");

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
    return "(datos de persona no encontrados en el sistema)";
}

PersonaDinamica pasarArchivoPesonasAlArreglo(char rol){
    PersonaDinamica personaDin;
    inicializarPersonaDinamica(&personaDin, 2);

    FILE* fp = fopen(ARCHIVO_PERSONAS, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de personas");
        return personaDin;
    }

    Persona personaArchivo;

    while(fread(&personaArchivo, sizeof(Persona), 1, fp) == 1){
        int cantCuentas = cantidadDeCuentasPorDni(personaArchivo.dni);

        if(cantCuentas > 0){
            Usuario us = buscarUsuarioPorDni(personaArchivo.dni);

            if(us.rol == rol){
                redimencionarPersonaDinamica(&personaDin);

                personaDin.arrayPersona[personaDin.validos] = personaArchivo;
                personaDin.validos++;
            }
        }
    }

    fclose(fp);
    return personaDin;
}

PersonaDinamica pasarArchivoTodasLasPesonasAlArreglo(){
    PersonaDinamica personaDin;
    inicializarPersonaDinamica(&personaDin, 2);

    FILE* fp = fopen(ARCHIVO_PERSONAS, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de personas");
        return personaDin;
    }

    Persona personaArchivo;

    while(fread(&personaArchivo, sizeof(Persona), 1, fp) == 1){
        redimencionarPersonaDinamica(&personaDin);

        personaDin.arrayPersona[personaDin.validos] = personaArchivo;
        personaDin.validos++;
    }

    fclose(fp);
    return personaDin;
}

void mostrarTodasLasPersonas(PersonaDinamica personaDin, int indice){
    if(indice < personaDin.validos){
        mostrarUnaPersona(personaDin.arrayPersona[indice]);
        mostrarTodasLasPersonas(personaDin, indice+1);
    }
}

void pasarArchivoPesonasAlArregloPorId(PersonaDinamica* personaDin, char* dni){
    FILE* fp = fopen(ARCHIVO_PERSONAS, "rb");

    if(fp == NULL){
        perror("Error al brir el archivo de personas");
        return;
    }

    Persona personaAux;

    while(fread(&personaAux, sizeof(Persona), 1, fp) == 1){
        if(strcmp(personaAux.dni, dni) == 0){
            redimencionarPersonaDinamica(personaDin);
            personaDin->arrayPersona[personaDin->validos] = personaAux;
            personaDin->validos += 1;
        }
    }

    fclose(fp);
}

int buscarPersonaEnArregloPorDni(PersonaDinamica personaDin, char* dniBuscar){
    for(int i=0; i<personaDin.validos; i++){
        if(strcmp(personaDin.arrayPersona[i].dni, dniBuscar) == 0){
            mostrarUnaPersona(personaDin.arrayPersona[i]);
            return 1;
        }
    }

    printf("El dni ingresado no pertenece a ninguna persona en el sistema");
    return 0;
}

void mostrarUnaPersonaPorDni(char* dniBuscar){
    FILE* fp = fopen(ARCHIVO_PERSONAS, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de personas");
        return;
    }

    Persona personaArchivo;

    while(fread(&personaArchivo, sizeof(Persona), 1, fp) == 1){
        if(strcmp(personaArchivo.dni, dniBuscar) == 0){
            mostrarUnaPersona(personaArchivo);
            fclose(fp);
            return;
        }
    }

    fclose(fp);
    printf("\nNo hay datos de esta persona en el sistema.\n");
    printf("---------------------------------------------------------------------\n");
}

void mostrarDatosResumidosDeUnaPersonaPorDni(char* dniBuscar){
    FILE* fp = fopen(ARCHIVO_PERSONAS, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de personas");
        return;
    }

    Persona personaArchivo;

    while(fread(&personaArchivo, sizeof(Persona), 1, fp) == 1){
        if(strcmp(personaArchivo.dni, dniBuscar) == 0){
            mostrarNombreTelefonoDeUnaPersona(personaArchivo);
            fclose(fp);
            return;
        }
    }

    fclose(fp);
    printf("No hay datos de esta persona en el sistema.\n");
    printf("---------------------------------------------------------------------\n");
}

void modificarNombrePersona(char* dniPersona, char* nombreNuevo){
    FILE* fp = fopen(ARCHIVO_PERSONAS, "r+b");

    if(fp == NULL){
        perror("Error al abrir el archivo de personas");
        return;
    }

    Persona personaArchivo;

    while(fread(&personaArchivo, sizeof(Persona), 1, fp) == 1){
        if(strcmp(personaArchivo.dni, dniPersona) == 0){
            strcpy(personaArchivo.nombrePersona, nombreNuevo);

            fseek(fp, -(long)sizeof(Persona), SEEK_CUR);

            if(fwrite(&personaArchivo, sizeof(Persona), 1, fp) != 1){
                perror("Error al escribir en el archivo de personas");
                fclose(fp);
                return;
            }

            printf("\nEl nombre ha sido modificado con exito!\n\n");
            break;
        }
    }

    fclose(fp);
}

void modificarApellidoPersona(char* dniPersona, char* apellidoNuevo){
    FILE* fp = fopen(ARCHIVO_PERSONAS, "r+b");

    if(fp == NULL){
        perror("Error al abrir el archivo de personas");
        return;
    }

    Persona personaArchivo;

    while(fread(&personaArchivo, sizeof(Persona), 1, fp) == 1){
        if(strcmp(personaArchivo.dni, dniPersona) == 0){
            strcpy(personaArchivo.apellidoPersona, apellidoNuevo);

            fseek(fp, -(long)sizeof(Persona), SEEK_CUR);

            if(fwrite(&personaArchivo, sizeof(Persona), 1, fp) != 1){
                perror("Error al escribir en el archivo de personas");
                fclose(fp);
                return;
            }

            printf("\nEl apellido ha sido modificado con exito!\n\n");
            break;
        }
    }

    fclose(fp);
}

void modificarTelefonoPersona(char* dniPersona, char* telefonoNuevo){
    FILE* fp = fopen(ARCHIVO_PERSONAS, "r+b");

    if(fp == NULL){
        perror("Error al abrir el archivo de personas");
        return;
    }

    Persona personaArchivo;

    while(fread(&personaArchivo, sizeof(Persona), 1, fp) == 1){
        if(strcmp(personaArchivo.dni, dniPersona) == 0){
            strcpy(personaArchivo.telefono, telefonoNuevo);

            fseek(fp, -(long)sizeof(Persona), SEEK_CUR);

            if(fwrite(&personaArchivo, sizeof(Persona), 1, fp) != 1){
                perror("Error al escribir en el archivo de personas");
                fclose(fp);
                return;
            }

            printf("\nEl telefono ha sido modificado con exito!\n\n");
            break;
        }
    }

    fclose(fp);
}

void modificarCiudadPersona(char* dniPersona, char* ciudadNueva){
    FILE* fp = fopen(ARCHIVO_PERSONAS, "r+b");

    if(fp == NULL){
        perror("Error al abrir el archivo de personas");
        return;
    }

    Persona personaArchivo;

    while(fread(&personaArchivo, sizeof(Persona), 1, fp) == 1){
        if(strcmp(personaArchivo.dni, dniPersona) == 0){
            strcpy(personaArchivo.ciudad, ciudadNueva);

            fseek(fp, -(long)sizeof(Persona), SEEK_CUR);

            if(fwrite(&personaArchivo, sizeof(Persona), 1, fp) != 1){
                perror("Error al escribir en el archivo de personas");
                fclose(fp);
                return;
            }

            printf("\nLa ciudad ha sido modificada con exito!\n\n");
            break;
        }
    }

    fclose(fp);
}
