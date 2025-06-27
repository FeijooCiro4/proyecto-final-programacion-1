#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ctrUsuario.h"
#include "../persona/ctrPersona.h"
#include "../../../View/utils/utils.h"

static const char* ARCHIVO_USUARIOS= "usuarios.bin";

Usuario ingresarUsuario(){
    Usuario us;

    printf("Id del Usuario: ");
    us.idUsuario = scanInt();
    while (!esEnteroPositivo(us.idUsuario) || !idUsuarioUnico(us.idUsuario)){
        printf("El id ingresado no es valido. Ingrese otro: ");
        us.idUsuario = scanInt();
    }

    printf("Nombre de usuario: ");
    scanString(us.nombreUsuario, MAX_CARACT_USUARIO_STANDARD);
    while(!nombreUsuarioUnico(us.nombreUsuario)){
        printf("El nombre ingresado no es valido. Ingrese otro: ");
        scanString(us.nombreUsuario, MAX_CARACT_USUARIO_STANDARD);
    }

    printf("Contrasenia: ");
    scanString(us.contrasenia, MAX_CARACT_USUARIO_STANDARD);

    printf("Rol [Vendedor (v)- Administrador (a)]: ");
    us.rol = scanChar();
    us.rol = tolower(us.rol);
    while (us.rol != 'v' && us.rol != 'a') {
        printf("El rol ingresado es invalido. Ingrese otro: ");
        us.rol = scanChar();
        us.rol = tolower(us.rol);
    }

    printf("Ingrese su dni: ");
    scanString(us.dniPersona, MAX_CARACT_USUARIO_DNI);
    while(!esDniValido(us.dniPersona)){
        printf("El dni ingresado es invalido. Ingrese otro: ");
        scanString(us.dniPersona, MAX_CARACT_USUARIO_DNI);
    }

    us.permisoDeIngreso = 0;

    return us;
}

int idUsuarioUnico(int id){
    FILE* fp = fopen(ARCHIVO_USUARIOS, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de usuarios");
        return 0;
    }

    Usuario usAux;

    while(fread(&usAux, sizeof(Usuario), 1, fp) == 1){
        if(usAux.idUsuario == id){
            return 0;
        }
    }
    fclose(fp);

    return 1;
}

int nombreUsuarioUnico(char* nombre){
    FILE* fp = fopen(ARCHIVO_USUARIOS, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de usuarios");
        return 0;
    }

    Usuario usAux;

    while(fread(&usAux, sizeof(Usuario), 1, fp) == 1){
        if(strcmp(usAux.nombreUsuario, nombre) == 0){
            return 0;
        }
    }
    fclose(fp);

    return 1;
}

int validarContrasenia(char* nombreUsuario, char* contrasenia){
    FILE* fp = fopen(ARCHIVO_USUARIOS, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de usuarios");
        return 0;
    }

    Usuario usAux;

    while(fread(&usAux, sizeof(Usuario), 1, fp) == 1){
        if(strcmp(usAux.nombreUsuario, nombreUsuario) == 0){
            if(strcmp(usAux.contrasenia, contrasenia) == 0){
                return 0;
            }
        }
    }
    fclose(fp);

    return 1;
}

Usuario buscarUsuario(char* nombreUsuario){
    FILE* fp = fopen(ARCHIVO_USUARIOS, "rb");
    Usuario usAux = inicializarUsuario();

    if(fp == NULL){
        perror("Error al abrir el archivo de usuarios");
        return usAux;
    }

    while(fread(&usAux, sizeof(Usuario), 1, fp) == 1){
        if((strcmp(usAux.nombreUsuario, nombreUsuario) == 0) && (usAux.permisoDeIngreso == 1)){
            fclose(fp);
            return usAux;
        }
    }

    fclose(fp);
    return usAux;
}

Usuario buscarUsuarioPorDni(char* dniUsuario){
    FILE* fp = fopen(ARCHIVO_USUARIOS, "rb");
    Usuario usAux = inicializarUsuario();

    if(fp == NULL){
        perror("Error al abrir el archivo de usuarios");
        return usAux;
    }

    while(fread(&usAux, sizeof(Usuario), 1, fp) == 1){
        if((strcmp(usAux.dniPersona, dniUsuario) == 0) && (usAux.permisoDeIngreso == 1)){
            fclose(fp);
            return usAux;
        }
    }

    fclose(fp);
    return usAux;
}

int cantidadDeCuentasPorDni(char* dni){
    FILE* fp = fopen(ARCHIVO_USUARIOS, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de usuarios");
        return -1;
    }

    Usuario usuarioArchivo;
    int contador=0;

    while(fread(&usuarioArchivo, sizeof(Usuario), 1, fp) == 1){
        if(strcmp(usuarioArchivo.dniPersona, dni) == 0){
            contador++;
        }
    }

    fclose(fp);
    return contador;
}

int vendedorExiste(char* dniVendedorBuscar){
    FILE* fp = fopen(ARCHIVO_USUARIOS, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de uuarios");
        return 0;
    }

    Usuario usuarioArchivo;

    while(fread(&usuarioArchivo, sizeof(Usuario), 1, fp) == 1){
        if((strcmp(usuarioArchivo.dniPersona, dniVendedorBuscar) == 0) && (usuarioArchivo.permisoDeIngreso == 1)){
            if(usuarioArchivo.rol == 'v') return 1;
        }
    }

    fclose(fp);
    return 0;
}

UsuarioDinamico pasarArchivoUsuariosAUnArreglo(){
    FILE* fp = fopen(ARCHIVO_USUARIOS, "rb");
    UsuarioDinamico usuarioDin;
    inicializarUsuarioDinamico(&usuarioDin, 2);

    if(fp == NULL){
        perror("Error al abrir el archivo de usuarios");
        return usuarioDin;
    }

    Usuario usuarioArchivo;

    while(fread(&usuarioArchivo, sizeof(Usuario), 1, fp) == 1){
        verificarRedimensionUsuarioDinamico(&usuarioDin);

        usuarioDin.arrayUsuario[usuarioDin.validos].idUsuario = usuarioArchivo.idUsuario;
        strcpy(usuarioDin.arrayUsuario[usuarioDin.validos].nombreUsuario, usuarioArchivo.nombreUsuario);
        usuarioDin.arrayUsuario[usuarioDin.validos].rol = usuarioArchivo.rol;
        strcpy(usuarioDin.arrayUsuario[usuarioDin.validos].dniPersona, usuarioArchivo.dniPersona);
        usuarioDin.arrayUsuario[usuarioDin.validos].permisoDeIngreso = usuarioArchivo.permisoDeIngreso;

        usuarioDin.validos += 1;
    }

    fclose(fp);
    return usuarioDin;
}

void mostrarTodosLosUsuarios(UsuarioDinamico usuarioDin, int indice){
    if(indice < usuarioDin.validos){
        mostrarUnUsuario(usuarioDin.arrayUsuario[indice]);
        printf("\tIngreso al sistema: %s\n", usuarioDin.arrayUsuario[indice].permisoDeIngreso ? "Aceptado" : "Denegado");
        printf("\n");
        mostrarUnaPersonaPorDni(usuarioDin.arrayUsuario[indice].dniPersona);
        mostrarTodosLosUsuarios(usuarioDin, indice+1);
    }
}

void mostrarUnUsuarioPorNombre(UsuarioDinamico usuarioDin, char* nombreUsuarioBuscar){
    for(int i=0; i<usuarioDin.validos; i++){
        if(strcmp(usuarioDin.arrayUsuario[i].nombreUsuario, nombreUsuarioBuscar) == 0){
            mostrarUnUsuario(usuarioDin.arrayUsuario[i]);
            printf("\tIngreso al sistema: %s\n", usuarioDin.arrayUsuario[i].permisoDeIngreso ? "Aceptado" : "Denegado");
            printf("\n");
            mostrarUnaPersonaPorDni(usuarioDin.arrayUsuario[i].dniPersona);
        }
    }
}

void mostrarTodosLosUsuariosDeUnRol(UsuarioDinamico usuarioDin, char rol, int indice){
    if(indice < usuarioDin.validos){
        if(usuarioDin.arrayUsuario[indice].rol == rol){
            mostrarUnUsuario(usuarioDin.arrayUsuario[indice]);
            printf("\tIngreso al sistema: %s\n", usuarioDin.arrayUsuario[indice].permisoDeIngreso ? "Aceptado" : "Denegado");
            printf("\n");
            mostrarUnaPersonaPorDni(usuarioDin.arrayUsuario[indice].dniPersona);
        }
        mostrarTodosLosUsuariosDeUnRol(usuarioDin, rol, indice+1);
    }
}

void mostrarTodosLosUsuariosSinValidar(){
    FILE* fp = fopen(ARCHIVO_USUARIOS, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de usuarios");
        return;
    }

    Usuario usuarioArchivo;

    while(fread(&usuarioArchivo, sizeof(Usuario), 1, fp) == 1){
        if(usuarioArchivo.permisoDeIngreso == 0){
            mostrarUnUsuario(usuarioArchivo);
            printf("\n");
            mostrarUnaPersonaPorDni(usuarioArchivo.dniPersona);
        }
    }

    fclose(fp);
}

void mostrarTodosLosUsuariosConAccesoAlSistema(){
    FILE* fp = fopen(ARCHIVO_USUARIOS, "rb");

    if(fp == NULL){
        perror("Error al abrir el archivo de usuarios");
        return;
    }

    Usuario usuarioArchivo;

    while(fread(&usuarioArchivo, sizeof(Usuario), 1, fp) == 1){
        if(usuarioArchivo.permisoDeIngreso == 1){
            mostrarUnUsuario(usuarioArchivo);
            printf("\n");
            mostrarUnaPersonaPorDni(usuarioArchivo.dniPersona);
        }
    }

    fclose(fp);
}

void ingresarVariosUsuarios(){
    FILE* fp = fopen(ARCHIVO_USUARIOS, "ab");

    if(fp == NULL){
        perror("Error al abrir el archivo de usuarios");
        return;
    }

    int indice = 0;
    UsuarioDinamico usuarioDin;
    inicializarUsuarioDinamico(&usuarioDin, 2);

    do {
        verificarRedimensionUsuarioDinamico(&usuarioDin);

        usuarioDin.arrayUsuario[indice] = ingresarUsuario();
        usuarioDin.arrayUsuario[indice].permisoDeIngreso = 1;
        if(dniUnicoPersona(usuarioDin.arrayUsuario[indice].dniPersona)){
            printf("-------Los datos no se encuentran en el sistema-------\n");
            Persona persona = ingresarPersona(usuarioDin.arrayUsuario[indice].dniPersona);
            guardarPersonaEnArchivo(&persona);
        }
        usuarioDin.validos += 1;
        indice++;

        printf("\nDesea seguir ingresando datos? (s/n): ");
    } while(confirmar('s'));

    if((indice == 0)|| (fwrite(usuarioDin.arrayUsuario, sizeof(Usuario), indice, fp) != indice)){
        perror("No se pudo escribir en el archivo de usuarios");
        liberarUsuarioDinamico(&usuarioDin);
        fclose(fp);
        return;
    }

    liberarUsuarioDinamico(&usuarioDin);
    fclose(fp);
    return;
}

void aceptarUsuarioEnSistema(char* dniUsuarioBuscar){
    FILE* fp = fopen(ARCHIVO_USUARIOS, "r+b");

    if(fp == NULL){
        perror("Error al abrir el archivo de usuarios");
        return;
    }

    Usuario usuarioArchivo;

    while(fread(&usuarioArchivo, sizeof(Usuario), 1, fp) == 1){
        if(strcmp(usuarioArchivo.dniPersona, dniUsuarioBuscar) == 0){
            usuarioArchivo.permisoDeIngreso = 1;

            fseek(fp, -(long)sizeof(Usuario), SEEK_CUR);

            if(fwrite(&usuarioArchivo, sizeof(Usuario), 1, fp) != 1){
                perror("Error al escribir en el archivo de usuarios");
                fclose(fp);
                return;
            }

            printf("Usuario validado con exito!\n\n");
            fclose(fp);
            return;
        }
    }

    fclose(fp);
    printf("No se encontro el usuario.\n");
}

void negarAccesoUsuarioEnSistema(char* dniUsuarioBuscar){
    FILE* fp = fopen(ARCHIVO_USUARIOS, "r+b");

    if(fp == NULL){
        perror("Error al abrir el archivo de usuarios");
        return;
    }

    Usuario usuarioArchivo;

    while(fread(&usuarioArchivo, sizeof(Usuario), 1, fp) == 1){
        if(strcmp(usuarioArchivo.dniPersona, dniUsuarioBuscar) == 0){
            usuarioArchivo.permisoDeIngreso = 0;

            fseek(fp, -(long)sizeof(Usuario), SEEK_CUR);

            if(fwrite(&usuarioArchivo, sizeof(Usuario), 1, fp) != 1){
                perror("Error al escribir en el archivo de usuarios");
                fclose(fp);
                return;
            }

            printf("Usuario validado con exito!\n\n");
            fclose(fp);
            return;
        }
    }

    fclose(fp);
    printf("No se encontro el usuario.\n");
}

void modificarNombreUsuario(char* dniUsuario, char* nombreUsuarioNuevo){
    FILE* fp = fopen(ARCHIVO_USUARIOS, "r+b");

    if(fp == NULL){
        perror("Error al abrir el archivo de usuarios");
        return;
    }

    Usuario usuarioArchivo;

    while(fread(&usuarioArchivo, sizeof(Usuario), 1, fp) == 1){
        if(strcmp(usuarioArchivo.dniPersona, dniUsuario) == 0){
            strcpy(usuarioArchivo.nombreUsuario, nombreUsuarioNuevo);

            fseek(fp, -(long)sizeof(Usuario), SEEK_CUR);

            if(fwrite(&usuarioArchivo, sizeof(Usuario), 1, fp) != 1){
                perror("Error al escribir en el archivo de usuarios");
                fclose(fp);
                return;
            }

            printf("\nEl nombre de usuario ha sido modificado con exito!\n\n");
            break;
        }
    }

    fclose(fp);
}

void modificarContraseniaUsuario(char* dniUsuario, char* contraseniaNueva){
    FILE* fp = fopen(ARCHIVO_USUARIOS, "r+b");

    if(fp == NULL){
        perror("Error al abrir el archivo de usuarios");
        return;
    }

    Usuario usuarioArchivo;

    while(fread(&usuarioArchivo, sizeof(Usuario), 1, fp) == 1){
        if(strcmp(usuarioArchivo.dniPersona, dniUsuario) == 0){
            strcpy(usuarioArchivo.contrasenia, contraseniaNueva);

            fseek(fp, -(long)sizeof(Usuario), SEEK_CUR);

            if(fwrite(&usuarioArchivo, sizeof(Usuario), 1, fp) != 1){
                perror("Error al escribir en el archivo de usuarios");
                fclose(fp);
                return;
            }

            printf("\nLa contrasenia ha sido modificada con exito!\n\n");
            break;
        }
    }

    fclose(fp);
}
