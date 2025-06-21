# Documentación de proyecto.
## Diario de desarrollo.
### Miércoles 04/06/2025
* Inicialización del repositorio del proyecto de manera local con `git` y de manera remota con `github`.
### Lunes 09/06/2025
* Definición de las estructuras (propuestas por el profesor desde el documento) en el código:
    * Se ha __modularizado cada estructura__, teniendo que cada una está en su **propio archivo de cabeceras**. Sin embargo, no se han hecho prototipados de funciones.
### Martes 10/06/2025
* Definición de objetivo a corto plazo: **crear una interfaz funcional de un __login__**
* Estudio a fondo sobre la sintaxis de escritura del formato `md` para documentar el proyecto.
* Modificaciones en estructuras:
    * Se han añadido IDs a las estructuras de `Usuarios` y `Personas` para un mejor manejo de los datos a futuro.
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
* Desarrollo de inserción de datos sobre una persona si es que su dni no figura en los datos del archivo.
* Corrección de errores:
    * Validación de dni único y con dígitos exactos.
    * Optimización del registro de sesión acorde a las necesidades de la inserción de personas.
    * Código corregido en el inicio de sesión.
* Commit.
### Sábado 14/06/2025
* Planificación y estructuración de la experiencia de usuario dividido entre sus roles.
* Establecimiento de visuales en la cabecera `prints` del proyecto.
### Domingo 15/06/2025
* Desarrollo de inserción de datos de autos por parte de los usuario vendedores:
    * Desarrollo de visuales, abstrayendo en distintas funciones de menús (menú principal, de gestión de autos y vista de autos solo para vendedores).
    * Creación y desarrollo de una estructura de autos para uso exclusivo de memoria dinámica:
        * Inicializa un arreglo dinámico de autos.
        * Redimensiona un arreglo dinámico de autos.
        * Libera la memoria de un arreglo dinámico de autos.
    * Creación de un nivel de abstracción más profundo denominado `controllers`, donde se implementará la lógica requerida por los requerimientos del proyecto, los cuales son muy generales como para ser funciones de las estructuras, y muy específicos para el nivel de `opciones`.
    * Desarrollo de validación de errores en datos de entrada: Si el vendedor ingresa una patente existente tanto en el archivo de autos como en el arreglo dinámico de autos, el programa no guardará ese auto ni en el arreglo ni en el archivo, y le indicará al usuario que vuelva a ingresarlo si así lo desea.
### Lunes 16/06/2025
* Desarrollo de muestra de datos de autos para vendedores. En el controlador de autos se implementaron dos funciones:
    * Una que retorna un arreglo dinámico de autos.
    * Otra que recibe uno por parámetro y muestra todos sus datos de forma recursiva (para el titular del auto, se llamó a una función en `stPersonas` que devuelve el nombre completo de la persona a la que pertenece el dato de `dniTitular` de cada auto);
* Commit.
### Martes 17/06/2025
* Adaptación de las estructuras `stUsuario` y `stPersona`, añadiendo controladores, para la implementación de funciones con utilidades más allá de las propias estructuras.
* Corrección de errores:
    * Impresión del nombre de titular de cada auto: Bajo la función `buscarPersonaPorId()` en `ctrPersona` devolvía los nombre correspondientes pero con datos basura. Se intercambió un `strcat` por un `strcpy` en la primera asignación de valores string, así ningún dato basura de la variable de esa función interfiriera en la impresión de los datos deseados.
    * Problemas con el redimensionamiento de memoria de un arreglo dinámico de autos: Al ingresar datos en un arreglo dinámico de autos y este llegaba al tope de memoria asignada con malloc, al redimensionarse presentaba un error que hacía que se guardaran datos basura. El problema real estaba en el `fwrite` de la función `insertarAutos()` del controlador `ctrAutos`, haciendo que esta multiplicara la cantidad de datos a guardar en el archivo de autos. Este problema se solucionó quitando la indicación errónea de valores asignados a los parámetros del `fwrite`.
* Optimización de experiencia de usuario: Al cerrar sesión, antes el usuario salía del programa; ahora se le permite volver al menú del login para darle la opción de ingresar nuevamente o de hacerlo con otra cuenta.
* Commit.
### Miércoles 18/06/2025
* Comienzo del desarrollo de gestión de ventas para vendedores. No concluído:
    * Inserción de venta:
        * En `stVenta` se ha desarrollado la función para ingresar un solo datos de venta.
        * Se han hecho validaciones básicas, como ingresar un dni de comprador valido (el del vendedor se le asigna el del usuario que está ingresando los datos), una fecha válida, y validaciones de números positivos.
    * Validación de fecha: En `stFecha` se han desarrollado todas las funciones necesarias para validar la inserción de una fecha válida de forma tal que:
        * Se validan datos básicos de la fecha:
            * El mes no puede pasarse del número 12 ni ser menor a 1.
            * Cada mes tiene una cantidad exacta de días, por lo que si el usuario ingresa un día fuera del rango de el mes que ingresó antes, dará error y se pedirá ingresar otra.
        * Si la fecha ingresada se pasa de la actual, dará error y se pedirá ingresar otra.
        * Si la fecha ingresada es antes de 1900 (fecha límite permitida por la librería `time.h`), dará error y se pedirá ingresar otra.
        * Se valida si es un año bisiesto, así cuando se le asigna valor a cada mes, considerar cuando el mes de febrero debe tener 29 días. En caso de ingresar una fecha, con un año que no es bisiesto, e ingresar la fecha 29 de febrero, dará error y se pedirá ingresar otra.
### Jueves 19/06/2025
* Desarrollo de gestión de ventas terminado:
    * Creación del controlador `ctrVenta` para implementar todas las funciones necesarias que están en un nivel menos abstracto que el de la estructura.
    * Inserción de ventas de forma dinámica: se ha desarrollado una estructura que compone los datos de un arreglo dinámico de ventas, la dimensión total de este arreglo y la cantidad de datos válidos que se irán agregando. Esta estructura permite, a través de sus funciones "miembro", inicializar, redimensionar y liberar la memoria de un arreglo dinámico de ventas.
    * Inserción de ventas validadas: Se han desarrollado varios métodos de validación, los cuales fueron requeridos para realizar una inserción de ventas de forma óptima y sin errores:
        * Id único tanto en el arreglo de ventas como en el archivo. Si esto no se cumple, los datos no se guardan en el arreglo y, por consiguiente, tampoco en el archivo.
        * Si el usuario ingresa una patente de un auto que no existe en el archivo o si ésta pertenece a otro titular, los datos no se guardan en el arreglo y, por consiguiente, tampoco en el archivo.
        * Si el usuario ingresa una patente de un auto ya vendido, los datos no se guardan en el arreglo y, por consiguiente, tampoco en el archivo.
        * Si el margen de ganancia del vendedor es negativo (es decir, el precio de venta es menor al precio de adquisición), los datos no se guardan en el arreglo y, por consiguiente, tampoco en el archivo.
        * Si la fecha de la venta se indica antes de la fecha de fabricación/adquisición del auto, los datos no se guardan en el arreglo y, por consiguiente, tampoco en el archivo.
        * Si todo lo anterior se valida y la inserción sucede de forma óptima, se busca el auto en el archivo a través de su patente para cambiar su titular al del comprador (modificando el dato de DNI en el ítem correspondiente dentro del archivo de autos). Para esta función se han tenido problemas con el posicionamiento del puntero en el archivo de autos y con la modificación en sí del correspondiente. Esto se arregló agregando un `fseek` que posiciona el puntero en el comienzo del ítem necesario y, para que no se cambie ese ítem por un dato basura (como estaba sucediendo), se modificó la función `retornarAutoDeArchivo()` de `ctrAuto` para retornar un puntero a un dato de tipo `Auto` para poder retornar `NULL` en determinados casos y validar que no se ingrese el dato si se dan estos casos.
    * Muestra de ventas: Se han desarrollado dos opciones de muestra; Mostrar todas las ventas hechas (por vendedor) y buscar una venta (realizada por el vendedor). Para ello se ha debido desarrollar la lógica con las siguientes validaciones:
        * En `stVenta` se ha desarrollado la función base para mostrar una venta. Por consiguiente, también se desarrolló la función correspondiente en `stFecha` para mostrar una fecha en el formato `00/00/0000`.
        * Al pasar los datos del archivo a un arreglo dinámico, solo se pasan aquellas ventas realizadas por el vendedor que está gestionando esos datos, así no puede acceder a los datos de otros vendedores.
        * La muestra de todas las ventas del arreglo se hizo de forma recursiva.
        * Para la búsqueda de una venta y mostrarla se usó el id de la venta para localizarla en el arreglo.
* Correcciones en validación de datos en `ctrAuto`:
    * En las funciones de muestra:
        * En `mostrarTodosLosAutosDelSistema()` no se podrán visualizar aquellos autos que se encuentren vendidos.
        * Al buscar un auto y mostrarlo, no se tomará en cuenta aquellos que estén vendidos. Por lo que si el usuario ingresa una patente de un auto vendido, los datos de este no se mostrarán.
* Commit y despliegue al repositorio remoto.
### Viernes 20/06/2025
* Se ha desarrollado la opción para vendedores de ver los autos vendidos junto con sus titulares.
* Se ha desarrollado gran parte de la experiencia de usuario para compradores:
    * Vista de varios autos: Cada comprador puede ver la lista completa de todos los autos a la venta por distintos vendedors
    * Vista de un auto: El usuario comprador puede visualizar los datos de un solo auto (puesto a la venta) ingresando su patente.
    * Vista de varios vendedores: El comprador puede ver la lista de vendedores en el sistema, pudiendo ver sus numeros de telefono para contactare con ellos.
    * Vista de un vendedor: El comprador puede buscar por nombr a un solo vendedor, y podrá visualizar sus datos (esta función necesita pulirse conceptualmente, ya que si el usuario ingresa un nombre y resulta que el dato del nombre dentro del archivo de personas hay un nombre más a parte del buscado, este no se tomará en cuenta y la funión lo ignorará como si no fuera válido. Sin embargo, si el nombre buscado está presnte en dos vendedres distintos, se mostrarán a ambos como resultado de la búsqueda).
    * Para desarrollar lo anterior, se requirió implementar el uso arreglos dinámicos para guardar los datos de las personas (buscadas a traves de su dni, sacado del archivo de personas, en el archivo de usuarios con el rol de vendedores) para luego mostrar los datos de los vendedores que están en el sistema.
    También se requirió desarrollar las funciones de muestra, basadas en una función base de `stPersona` para implementar una función recursiva que recorra todo un arreglo dinámico de personas para mostrar aquellas con el rol de vendedor en un usuario.
* Commit.
<!-- ## Funciones del proyecto.  -->