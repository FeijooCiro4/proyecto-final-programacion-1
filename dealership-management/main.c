#include <stdio.h>
#include "options/options.h"
#include "prints/prints.h"
#include "utils/utils.h"

int main(){
    int opc;

    do {
        printLogin();
        opc = scanInt();
        while(esEnteroPositivo(opc) == 0){
            printf("Error: La opcion que ha ingresado no es valida.\nVuelva a ingresar una opcion: ");
            opc = scanInt();
        }
        opcLogin(opc);
    } while(opc != 0);

    return 0;
}
