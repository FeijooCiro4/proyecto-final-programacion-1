#include <stdlib.h>
#include "stUsuarioDinamico.h"
#include "../../constants/constants.h"

void inicializarUsuarioDinamico(UsuarioDinamico* usuarioDin, int dimensionInicial){
    usuarioDin->dimension = dimensionInicial;
    usuarioDin->arrayUsuario = (Usuario*)malloc(dimensionInicial*sizeof(Usuario));

    if(usuarioDin->arrayUsuario == NULL){
        perror("Error al asignar memoria a un arreglo de usuarios");
        return;
    }

    usuarioDin->validos = 0;
}

void verificarRedimensionUsuarioDinamico(UsuarioDinamico* usuarioDin){
    if(usuarioDin->validos < usuarioDin->dimension) return;

    usuarioDin->arrayUsuario = (Usuario*)realloc(usuarioDin->arrayUsuario, (usuarioDin->dimension + VALOR_DIMENSIONAMIENTO_USUARIODINAMICO) * sizeof(Usuario));
    usuarioDin->dimension += VALOR_DIMENSIONAMIENTO_USUARIODINAMICO;
}

void liberarUsuarioDinamico(UsuarioDinamico* usuarioDin){
    free(usuarioDin->arrayUsuario);
    usuarioDin->dimension = 0;
    usuarioDin->validos = 0;
}
