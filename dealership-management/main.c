#include <stdio.h>
#include "options/options.h"
#include "prints/prints.h"
#include "utils/utils.h"
#include "structs/usuario/stUsuario.h"

int main(){
    int opc, loginValido;
    Usuario us;

    do {
        printLogin();
        opc = scanInt();
        while(esEnteroPositivo(opc) == 0){
            printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
            opc = scanInt();
        }
        loginValido = opcLogin(&us, opc);
        if(loginValido) opc = 0;
    } while(opc != 0);

    if(loginValido){
        printf("\n\tBienvenido %s %s!\n\n", nombreRolUsuario(us), us.nombreUsuario);
    }

    limpiarPantalla();
    printf("Gracias por probar el programa!\n");

    return 0;
}
