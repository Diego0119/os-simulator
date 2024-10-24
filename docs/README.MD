# Estructura de Datos: Simulador Sistema Operativo

Integrantes:

- Miguel Loaiza (miloaiza@umag.cl) [https://github.com/EhMigueh]
- Diego Sanhueza (disanhue@umag.cl) [https://github.com/Diego0119]
- Oscar Cifuentes (ocifuent@umag.cl) [https://github.com/iBluZiiZ]

# Descripción

Este proyecto es un Simulador de Sistemas Operativos, diseñado para emular el comportamiento de un sistema operativo básico. A través de esta simulación, puedes explorar cómo se manejan procesos, memoria y otros recursos del sistema. Nuestro enfoque es educativo, para ayudar a estudiantes a entender los conceptos fundamentales detrás de los sistemas operativos.

# Funcionamiento

Para poder ejecutar el proyecto de manera satisfactoria, realice los siguientes pasos.

  1. En caso de que falten carpetas (src, obj, incs, docs o build), ejecute el comando 'make folders' en la terminal.
  2. Asegurece de que los archivos '.c' estén ubicados correctamente en la carpeta 'src' y que el archivo '.h' esté en la carpeta 'incs'.
  3. Se recomienda limpiar los archivos '.o' con el comando 'make clean' antes de compilar.
  4. Ejecute el comando 'make' en su terminal para poder compilar los archivos '.c' y crear los archivos '.o'.
  5. Ejecute el comando 'make run' en su terminal para poder comenzar con la prueba del programa Simulador Sistema Operativo.
  6. En la carpera 'os-simulator' se encuentran dos archivos (.eps y .png) que contienen la carta gantt de los procesos ejecutados con el programa.
  7. En caso de querer eliminar los archivos '.o', ejecute el comando 'make clean' en su terminal para limpiar las carpetas.

# Documentación

Antes de generar la documentación, por favor vaya a la carpeta docs para verificar si ya existe la documentación. Para poder generar la documentación del proyecto, realice los siguientes pasos.

  1. Asegurece de que esté el archivo 'config' en la carpeta 'os-simulator'.
  2. Ejecute el comando 'doxygen config' en su terminal para poder ejecutar el archivo config y generar la documentación.
  3. En la carpeta docs, se encuentra la documentación en html y pdf.