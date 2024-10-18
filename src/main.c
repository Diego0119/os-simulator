#include "header.h"

int main(int argc, char *argv[])
{
    // VERIFICAR argumentos para la ejecución del programa.
    if (argc != 3 || strcmp(argv[1], "--file") != 0)
    {
        printf("Error!\nUso: ./simulador --file entrada.txt\n");
        return EXIT_FAILURE;
    }

    const char *nombre_archivo = argv[2]; // VARIABLE que GUARDA el NOMBRE del ARCHIVO de ENTRADA.
    int tamano_memoria;                   // VARIABLE del tamaño de la memoria total (2048 KB).
    int tamano_bloque;                    // VARIABLE del tamaño del bloque de memoria (128 KB).
    char algoritmo_memoria[10];           // VARIABLE que GUARDA el algoritmo de memoria first fit (3 en caso de que se hagan los 3).
    char algoritmo_planificacion[10];     // VARIABLE que GUARDA el algoritmo de planificación FIFO (3 en caso de que se hagan los 3).
    Cola cola_procesos = {NULL, NULL};    // VARIABLE que GUARDA la COLA de PROCESOS.

    leer_entrada(nombre_archivo, &tamano_memoria, &tamano_bloque, algoritmo_memoria, algoritmo_planificacion, &cola_procesos);
    fprintf(stdout, "Archivo leído correctamente.\n"); // MENSAJE TEMPORAL.

    int cantidad_bloques = tamano_memoria / tamano_bloque; // VARIABLE que GUARDA la cantidad de bloques de memoria.
    BloqueMemoria memoria[cantidad_bloques];               // ARREGLO de BLOQUES de MEMORIA.

    inicializar_bloques_memoria(memoria, cantidad_bloques, tamano_bloque);
    imprimir_memoria(memoria, cantidad_bloques);
    fprintf(stdout, "Memoria inicializada correctamente.\n"); // MENSAJE TEMPORAL.
    asignar_memoria_procesos(&cola_procesos, memoria, cantidad_bloques);

    return EXIT_SUCCESS;
}
