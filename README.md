# Documentación de proyecto.
## Diario de desarrollo.
### Miércoles 04/06/2025
* Inicialización del repositorio del proyecto de manera local con `git` y de manera remota con `github`.
### Lunes 09/06/2025
* Definición de las estructuras (propuestas por el profesor desde el documento) en el código:
    * Se ha __modularizado cada estructura__, teniendo que cada una está en su **propio archivo de cabeceras**. Sin embargo, no se han hecho prototipados de funciones.
### Martes 10/06/2025
* Definición de objetivo a corto plazo: **crear una interfaz funcional de un __login__**
* Estudio a fondo de la sintaxis de escritura sobre el formato `md` para documentar el proyecto.
* Modificaciones en estructuras:
    * Se ha añadido IDs a las estructuras de `Usuarios` y `Personas` para un mejor manejo de los datos a futuro.
    * Se ha quitado el dato `rol` de la estructura `Personas` y se ha añadido el dato a `Usuarios`, con la modificación de que este solo es de un carácter (con la idea de desarrollar, a futuro, una función que identifique el rol en base a ese carácter).
* Primera parte de la experiencia de usuario:
    * Se han desarrollado las pocas visuales que se tendrán para el login (que a su vez es el comienzo del programa), con la lógica necesaria para validar un registro o inicio de sesión exitosa o no (sin embargo todavía falta desarrollar la devolución que cada función debe dar para ejecutar esto último).
* Comienzo en el desarrollo del login:
    * Se han creado los archivos necesarios para desarrollar la lógica del login.
    * Se ha comenzado el desarrollo del registro de sesión, planificando que este usará un archivo de usuarios.
### Miércoles 11/06/2025
* Desarrollo completado del login con validaciones de datos. Se ha completado ambas partes del login de forma óptima y funcional; inicio y registro de sesión:
    * Si se intenta iniciar sesión sin que el archivo exista, no hayan datos en el mismo, o los ingresados no existan o no sean válidos, se vuelve al menú del login con un mensaje de error.
    * Si se inicia sesión con datos existentes en el archivo y válidos con respecto a estos, se entrará a una pantalla que solo dirá "Bienvenido!" para luego volver al menú del login.
    * Si se registra sesión con estos problemas:
        * id repetido -> se pedirá al usuario volver a ingresar ese dato.
        * nombre de usuario repetido -> se pedirá al usuario ingresar un nombre distinto.
* Commit y despliegue al repositorio remoto.
### Jueves 12/06/2025
* Corrección de errores: 
    * Validación de entrada de enteros.
    * Menú del login ligeramente optimizado.
    * Entorno del `main` preparado para siguientes modificaciones.
    * Se valida si hay un usuario que inició sesión (esto para acceder a las futuras funciones del programa que deberán ser desarrolladas).
* Commit y despliegue al repositorio remoto.
### Viernes 13/06/2025
* Dearrollo de inserción de datos sobre una persona si es que su dni no figura en los datos del archivo.
* Corrección de errores: 
    * Validación de dni unico y con digitos exactos.
    * Optimización del registro de sesión acorde a las necesidades de la inserción de personas.
    * Código corregido en el inicio de sesión.
* Commit.
### Sabado 14/06/2025
* Planificación y estructuración de la experiencia de usuario dividido entre sus roles.
* Establecimiento de visuales en la cabecera `prints` del proyecto.
### Domingo 15/06/2025
* Desarrollo de inserción de datos de autos por parte de los usuario vendedores:
    * Desarrolo de visuales, abstrayendo en distintas funciones de menús (menú principal, de gestión de autos y e vista de autas solo para vendedores).
    * Creación y desarrollo de una estructura de autos para uso exclusivo de memoria dinamica:
        * Inicializa un arreglo dinámico de autos.
        * Redimenciona un arreglo dinámico de autos.
        * Libera la memoria de un arreglo dinámico de autos.
    * Creación de un nivel de abstración más profundo denominado `controllers`, donde se implementará la lógica requerida por los requerimientos del proyecto, los cuales son muy generales como para ser funciones de las estructuras, y muy específicos para el nivel de `opciones`.
    * Desarrollo de validación de errores en datos de entrada: Si el vendedor ingresa una patente existente tanto en el archivo de autos como en el arreglo dinámico de autos, el programa no guardará ese auto ni en el arreglo ni en el archivo, y le indicara al usuario que vuelva a ingresarlo si asi lo desea.
### Lunes 16/06/2025
* Desarrollo de muestra de datos de autos para vendedores. En el controlador de autos se implementaron dos funciones: 
    * Una que retorna un arreglo dinámico de autos.
    * Otra que recibe uno por parámetro y muestra todos sus datos de forma recursiva (para el titular del auto, se llamó a una función en `stPersonas` que devuelve el nombre completo de la persona a la que pertenece el dato de `dniTitular` de cada auto);
* Commit.
### Martes 17/06/2025
* Adaptación de las estructuras `stUsuario` y `stPersona`, añadiemdo controladores, para la implementación de funciones con utilidades más allá de las propias estructuras.
* Corrección de errores:
    * Impresión del nombre de titular de cada auto: Bajo la función `buscarPersonaPorId()` en `ctrPersona` devolvía los nombre correspondientes pero con datos basura. Se intercambió un `strcat` por un `strcpy` en la primer asignación de valores string, así ningún dato basura de la variable de esa función interfiriera en la impresión de los datos deseados.
    * Problemas con el redimencionamiento de memoria de un arreglo dinámico de autos: Al ingresar datos en un arreglo dinámico de autos y este llegaba al tope de memoria asignada con malloc, al redimencionarse presentaba un error que hacía que se guardaran datos basura. El problema real estaba en el `fwrite` de la función `insertarAutos()` del controlador `ctrAutos`, haciendo que esta multiplicara la cantidad de datos a guardar en el arhivo de autos. Este problema se solucionó quitando la indicación errónea de valores asignados a los parámetros del `fwrite`.
* Optimización de experiencia de usuario: Al cerrar sesión, antes el usuario salía del programa; ahora se le permite volver al menú del login para darle la opción de ingresar nuevamente o de hacerlo con otra cuenta.
* Commit.
<!-- ## Funciones del proyecto.  -->