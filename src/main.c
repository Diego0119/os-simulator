#include "header.h"

int main(int argc, char *argv[])
{
    // Verificar argumentos para la ejecución del programa.
    if (argc != 3 || strcmp(argv[1], "--file") != 0)
    {
        printf("Error!\nUso: ./simulador --file entrada.txt\n");
        return EXIT_FAILURE;
    }

    const char *nombre_archivo = argv[2];
    int tamano_memoria;              // VARIABLE del tamaño de la memoria total (2048 KB).
    int tamano_bloque;               // VARIABLE del tamaño del bloque de memoria (128 KB).
    char algoritmo_memoria[3];       // VARIABLE que GUARDA el algoritmo de memoria first fit (3 en caso de que se hagan los 3).
    char algoritmo_planificacion[3]; // VARIABLE que GUARDA el algoritmo de planificación FIFO (3 en caso de que se hagan los 3).

    leer_entrada(nombre_archivo, &tamano_memoria, &tamano_bloque, algoritmo_memoria, algoritmo_planificacion);
    fprintf(stdout, "Archivo leído correctamente.\n"); // MENSAJE TEMPORAL.

    // EN PROCESO...
    // BloqueMemoria *memoria;
    // memoria = leer_entrada(argc, argv); // aca se asignara la memoria que necesita el programa
    //  char algoritmo_memoria[10], algoritmo_planificacion[10];
    //  Queue *cola_lista;
    //  Llamada función lectura archivo.
    //  Planificar y ejecutar procesos.
    //  Llamada función output carta gantt (?).

    return EXIT_SUCCESS;
}
