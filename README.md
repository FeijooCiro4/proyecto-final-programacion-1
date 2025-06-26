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
    * Vista de varios autos: Cada comprador puede ver la lista completa de todos los autos a la venta por distintos vendedores.
    * Vista de un auto: El usuario comprador puede visualizar los datos de un solo auto (puesto a la venta) ingresando su patente.
    * Vista de varios vendedores: El comprador puede ver la lista de vendedores en el sistema, pudiendo ver sus numeros de telefono para contactare con ellos.
    * Vista de un vendedor: El comprador puede buscar por nombre a un solo vendedor, y podrá visualizar sus datos (esta función necesita pulirse conceptualmente, ya que si el usuario ingresa un nombre y resulta que el dato del nombre dentro del archivo de personas hay un nombre más a parte del buscado, este no se tomará en cuenta y la función lo ignorará como si no fuera válido. Sin embargo, si el nombre buscado está presente en dos o más vendedres distintos, se mostrarán a ambos como resultado de la búsqueda).
    * Para desarrollar lo anterior, se requirió implementar el uso arreglos dinámicos para guardar los datos de las personas (buscadas a traves de su dni, sacado del archivo de personas, en el archivo de usuarios con el rol de vendedores) para luego mostrar los datos de los vendedores que están en el sistema.
    También se requirió desarrollar las funciones de muestra, basadas en una función base de `stPersona` para implementar una función recursiva que recorra todo un arreglo dinámico de personas para mostrar aquellas con el rol de vendedor en un usuario.
* Commit.
### Sábado 21/6 al Jueves 26/6 de 2025
* Se ha cambiado la lógica de `registroSesion()` en el `login`, añadiendo un campo en la estructura `stUsuario` llamada `permisoDeIngreso` donde se valida si el usuario tiene acceso al sistema o no. Si el valor de este campo es 0, por más de que el usuario intente iniciar sesión, no podrá acceder al sistema. Solo un administrador puede cambiar este valor. Si un usuario se registra como administrador, deberá ingresar un código propio del sistema para que su valor de ingreso sea 1. Si no es capaz de ingresar el código correcto, deberá esperar a que un administrador aparte lo valide.
* Se han completado funcionalidades para los vendedores:
    * Se ha añadido en el menú principal la opción para gestionar estadísticas. Allí se desarrollaron dos cálculos:
        * Ganancia mensual de un mes y un año ingresados por el usuario: A través de la función `calcularMargenGananciaMensual()` se calcula el margen de ganancia de un mes y un año (ingresado por el vendedor) de forma recursiva; se inicializa una estructura de tipo `stFecha` al comienzo de la función con los valores que se pasan por parámetros. También se pasa por parámetro un arreglo dinámico de ventas que contiene todas las ventas del vendedor. Si el índice actual (también pasado por parámetro) no es menor que la cantidad de datos válidos en el arreglo de ventas, se retorna la variable `gananciaTotal` que se inicializa en 0 al comienzo de la función. Dentro de la función `asignarFecha()` la cual asigna fecha a la variable de tipo `stFecha` de la función recursiva, si el día, el mes, o el año no son válidos, cada dato de la estructura de fecha se iguala a 0. Si esto sucede, en la función `calcularMargenGananciaMensual()` se retorna 0. En cambio, si se da la situación de que el dato del índice actual en el arreglo de ventas el año y el mes son distintos a los respectivos de la fecha con los valores pasados por parámetro, se retorna la variable `gananciaTotal` sumada a la llamada recursiva de la respectiva función sumando 1 al valor del índice actual (así se asegura el corte de las llamadas recursivas). En cambio, cuando sí se da lo anterior, se valida que el día del índice actual en la fecha del arreglo de ventas sea igual al día de la fecha asignada con los valores pasados por parámetro. Si este caso se da como válido, se suma el valor de `ganancia` del índice actual del arreglo de ventas a la variable `gananciaTotal` y se retorna dicha variable sumada a la llamada recursiva de la respectiva función sumando 1 al valor del índice actual (así se asegura el corte de las llamadas recursivas). Si este caso no se da, se retorna la variable `gananciaTotal` sumada a la llamada recursiva de la respectiva función sumando 1 a valor de `dia` (así, si se llega a la cantidad máxima de días en ese mes, los valores de la fecha asignadas por parámetro se igualan a 0, y se corta la última llamada recursiva retornando 0 por la asignación inicial de la variable al comienzo de la función recursiva).
        * Mes con mayor margen de ganancia en total.
    * Modificación de datos personales: El usuario vendedor puede elegir los datos que desea modificar, con la excepción de que no podrá modificar su id de usuario, su rol, su DNI ni su permiso de acceso al sistema. Esta opción figura en el menú principal, dirigiendo al usuario a otro menú donde elegir el dato que quiere cambiar. Cada opción dirige  una función específica que modifique el dato deseado, todas estas funciones fueron desarrolladas en el controlador `ctrUsuario`. Estas opciones también se aplican para el rol de comprador de la misma forma.
    * Gestión de autos:
        * Visualización de datos: El vendedor tiene la opción de ver todos los autos a la venta en orden de antigüedad (opción que los compradores también tienen). Esta función se desarrolló en el controlador `ctrAuto`, donde se ordena por selección un arreglo dinámico de autos y se retorna.
        * Modificación de autos: Ingresando la patente de un auto, se accede a un menú donde podrá ver los datos que el vendedor puede modificar. Los que no puede modificar son la patente y el DNI del titular. Cada dato modificable se le ha creado su respectiva función dentro del controlador `ctrAuto` donde se modifica el respectivo dato en el archivo.
        * Eliminación de datos de un auto: El vendedor ingresa la patente del auto que quiere eliminar y los datos de este se sustituyen por signos de eliminación a través de una función desarrollada en `ctrAuto`. Sin embargo, el vendedor no podrá ingresar la patente de un auto vendido, debido a que el titular de este ya no es él.
    * Gestión de ventas:
        * Visuales: Se ha desarrollado la opción para ver todos los clientes del vendedor usuario (esta función podría pulirse, ya que no se muestran la cantidad de ventas realizadas por ese cliente o los autos que ha comprado).
        * Cancelación de venta: Tal y como se desarrolló en el caso de los autos, la cancelación de venta parte desde la inserción de una clave primaria (en este caso el id de venta a eliminar), luego los datos se sustituyen por signos de eliminación y el titular del auto vuelve pasa a ser el vendedor, esto se desarrolló en el controlador `ctrVenta`.
* Se ha desarrollado toda la experiencia de usuario para administradores (reutilizando funciones de los controladores establecidos y creando otras pocas en los mismos):
    * Gestión de autos:
        * De han desarrollado varias funciones de visualización de datos:
            * Ver datos de todos los autos a la venta.
            * Ver datos de todos los autos vendidos en el sistema.
            * Buscar datos de un auto a través de su patente.
            * Ver datos de todos los autos puestos a la venta por un vendedor.
            * Ver datos de todos los autos vendidos por un vendedor.
        * Escribir datos de un auto asignándose a un vendedor a través de su DNI.
        * Modificar datos de un auto (ingresando el DNI del vendedor).
        * Eliminar datos de un auto (ingresando el DNI del vendedor).
    * Gestión de usuarios:
        * Visualización de datos (exceptuando datos comprometedores como la contraseña) mostrando datos parciales de la estructura `stPersona`:
            * Ver datos de todos los usuarios del sistema.
            * Buscar un usuario a través de su nombre de usuario.
            * Ver datos de todos los usuarios de un rol determinado.
        * Escribir datos de varios usuarios. Para esto se requirió desarrollar la estructura `stUsuarioDinamico` para gestionar arreglos dinámicos de usuarios. Esto con el fin de que el administrador pueda validar funcionalidades del sistema en otros roles.
        * Gestionar solicitudes de ingreso de nuevos usuarios, pudiendo elegir si darle permiso a un determinado usuario en el sistema.
        * Negar acceso al sistema a un usuario.
    * Gestión de ventas:
        * Visualización de ventas:
            * Ver datos de todas las ventas del sistema.
            * Buscar datos de una venta.
            * Ver datos de todas las ventas de un vendedor.
        * Escribir datos de una o varias ventas por vendedor (ingresando el DNI del mismo).
        * Eliminar una venta, de la misma forma que lo puede hacer un vendedor pero ingresando el DNI del mismo.
* Correcciones de diseño: Se ha decidido que en las funciones que utilizan archivos, estos no deben pasarse por parámetro. En su lugar, utilizan constantes hechas en la misma cabecera.
* Planificación para el siguiente desarrollo: Debido a cancelación de exposición de proyecto, se barajaron cambios en la estructura y el diseño del programa tales como:
    * Hacer que en cualquier parte donde se ingresen datos de manera constante y seguida, el usuario pueda desistir de hacerlo y volver al menú en donde se encontrara. Ejemplo, un vendedor insertando datos de un nuevo auto, pero el usuario se arrepiente y vuelve al menú de gestión de autos.
    * Cambiar el paradigma de rol comprador: Este sistema está notablemente orientado a que vendedores gestionen datos que ya tienen en su poder, un rol com `comprador` es contraproducente en el sistema, más aún cuando este necesita ser validado. Se considera la posibilidad de que usuarios generales, quienes no necesitan ingresar información y solo van a consultar datos de autos y vendedores, no se registren al sistema. Esto liberaría la carga de datos y facilitaría a la separación de roles. Esto implica que ningún dato del usuario general (antes comprador) será registrado en el sistema y, también, se quitará la opción de ver compras (ya que el sistema no se orientará a funcionar como un mercado. Al fin y al cabo, no se gestionan compras como tal). Esto implica, también, que en las vistas de autos no se vea el DNI del comprador, sino, más bien, su número de teléfono (esto puede implicar en eliminar la vista de vendedores, ya que en una situación de consulta de datos, al usuario le interesa el auto y a forma de contactar a su titular, como mucho puede servirle ver su nombre completo, mas no todos sus datos).
    * El proyecto propuesto por el profesor sugiere la utilización de varios métodos y formas de programación que en esta versión del sistema no se utilizan; tales son las matrices y las pilas, las cuales pueden llegar a tener una funcionalidad interesante en el desarrollo de nuevas funcionalidades del proyecto, u otras formas de ordenamiento de datos.
    * Para un mejor manejo de la abstracción que se pretende respetar en el sistema, sería de gran ayuda una única cabecera donde encontrar las constantes necesarias en todo el programa (algo parecido a la utilización de la librería `utils`, pero en vez de funciones, constantes). También, para el desarrollo de "escapar" de la inserción de datos continuos (el primer cambio mencionado) se debe realizar un gran cambio en la lógica de inserción, requiriendo manejar de forma manual una suerte de `buffer`, con la impresión en tiempo real de las teclas que va ingresando el usuario, hasta que llegue a un salto de línea, un terminador o apriete "esc" para cancelar la inserción. Es una forma de mezclar la forma canónica y no canónica de inserción de datos para hacer una experiencia de usuario más satisfactoria. Esto requiere de varios valores constantes que se deberán usar algunos valores constantes y enueradores en todos los puntos donde se quiera proporcionar esta utilidad, es decir que, la abstracción de valores constantes y enumeradores sería de gran ayuda.
* Commit y despliegue al repositorio remoto.
<!-- ## Funciones del proyecto.  -->