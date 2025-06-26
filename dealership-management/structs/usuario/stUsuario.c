#include <stdio.h>
#include "stUsuario.h"

Usuario inicializarUsuario(void){
    Usuario us;

    us.idUsuario = 0;
    us.nombreUsuario[0] = '\0';
    us.contrasenia[0] = '\0';
    us.rol = '\0';
    us.dniPersona[0] = '\0';

    return us;
}

char* nombreRolUsuario(Usuario us){
    if(us.rol == 'c'){
        return "comprador";
    } else if (us.rol == 'v'){
        return "vendedor";
    } else if (us.rol == 'a'){
        return "administrador";
    }

    return "desconosido";
}

void mostrarUnUsuario(Usuario us){
    printf("Id: %d\n"
           "\tNombre de Usuario: %s\n"
           "\tRol: %s\n",
           us.idUsuario,
           us.nombreUsuario,
           nombreRolUsuario(us));
}
