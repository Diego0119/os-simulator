#include "header.h"

int main(int argc, char *argv[])
{
    int opt;
    char *nombre_archivo = NULL; // VARIABLE que GUARDA el NOMBRE del ARCHIVO de ENTRADA.
    // getopt devuelve -1 cuando ya ha leido los argumentos
    while ((opt = getopt(argc, argv, "hf:")) != -1)
    {
        switch (opt)
        {
        case 'h':
            fprintf(stdout, "Para leer sus procesos, porfavor coloque el parametro <-f> <nombre_archivo.txt>\n");
            break;
        case 'f':
            nombre_archivo = optarg; // 'optarg' contiene el argumento que viene despues de -f, es una variable global dada por la libreria
            printf("Archivo: %s\n", nombre_archivo);
            break;
        case '?':
            fprintf(stderr, "Opción no reconocida: -%c\n", optopt);
            exit(EXIT_FAILURE);
        default:
            fprintf(stderr, "Uso: %s [-h] [-f filename]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    int tamano_memoria;                // VARIABLE del tamaño de la memoria total (2048 KB).
    int tamano_bloque;                 // VARIABLE del tamaño del bloque de memoria (128 KB).
    char algoritmo_memoria[10];        // VARIABLE que GUARDA el algoritmo de memoria first fit (3 en caso de que se hagan los 3).
    char algoritmo_planificacion[10];  // VARIABLE que GUARDA el algoritmo de planificación FIFO (3 en caso de que se hagan los 3).
    Cola cola_procesos = {NULL, NULL}; // VARIABLE que GUARDA la COLA de PROCESOS.

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
