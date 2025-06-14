# Documentación de proyecto.
## Diario de desarrollo.
### Miércoles 04/06/2025
* Inicialización del repositorio del proyecto de manera local con ´git´ y de manera remota con ´github´.
### Lunes 09/06/2025
* Definición de las estructuras (propuestas por el profesor desde el documento) en el código:
    * Se ha __modularizado cada estructura__, teniendo que cada una está en su **propio archivo de cabeceras**. Sin embargo, no se han hecho prototipados de funciones.
### Martes 10/06/2025
* Definición de objetivo a corto plazo: **crear una interfaz funcional de un __login__**
* Estudio a fondo de la sintaxis de escritura sobre el formato ´md´ para documentar el proyecto.
* Modificaciones en estructuras:
    * Se ha añadido IDs a las estructuras de ´Usuarios´ y ´Personas´ para un mejor manejo de los datos a futuro.
    * Se ha quitado el dato ´rol´ de la estructura ´Personas´ y se ha añadido el dato a ´Usuarios´, con la modificación de que este solo es de un carácter (con la idea de desarrollar, a futuro, una función que identifique el rol en base a ese carácter).
* Primera parte de la experiencia de usuario:
    * Se han desarrollado las pocas visuales que se tendrán para el login (que a su vez es el comienzo del programa), con la lógica necesaria para validar un registro o inicio de sesión exitosa o no (sin embargo todavía falta desarrollar la devolución que cada función debe dar para ejecutar esto último).
* Comienzo en el desarrollo del login:
    * Se han creado los archivos necesarios para desarrollar la lógica del login.
    * Se ha comenzado el desarrollo del registro de sesión, planificando que este usará un archivo de usuarios con extensión ´.bin´.
### Miércoles 11/06/2025
* Desarrollo completado del login con validaciones de datos, Se ha completado ambas partes del login de forma óptima y funcional; inicio y registro de sesión:
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
    * Entorno del ´main´ preparado para siguientes modificaciones.
    * Se valida si hay un usuario que inició sesión (esto para acceder a las futuras funciones del programa que deberán ser desarrolladas).
* Commit y despliegue al repositorio remoto.
### Viernes 13/06/2025
* Dearrollo de inserción de datos sobre una persona si es que su dni no figura en los datos del archivo.
* Corrección de errores: 
    * Validación de dni unico y con digitos exastos.
    * Optimización del registro de sesión acorde a las necesidades de la inserción de personas.
    * Código corregido en el inicio de sesión.
* Commit y despliegue al repositorio remoto.
<!-- ## Funciones del proyecto.  -->