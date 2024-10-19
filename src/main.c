#include "header.h"

int main(int argc, char *argv[])
{
    int opt;                     // VARIABLE que GUARDA el ARGUMENTO que se pasa por la TERMINAL.
    char *nombre_archivo = NULL; // VARIABLE que GUARDA el NOMBRE del ARCHIVO de ENTRADA.

    // getopt devuelve -1 cuando ya LEYÓ los ARGUMENTOS
    while ((opt = getopt(argc, argv, "hf:")) != -1)
    {
        switch (opt)
        {
        case 'h': // Si se pasa el ARGUMENTO <-h>, se imprime un MENSAJE de AYUDA.
            fprintf(stdout, "\nPara leer sus procesos, porfavor coloque el parametro <-f> <nombre_archivo.txt>\n\n");
            break;
        case 'f': // 'optarg' contiene el ARGUMENTO que viene después de -f, es una VARIABLE GLOBAL dada por la LIBRERÍA.
            nombre_archivo = optarg;
            printf("\nArchivo: %s\n\n", nombre_archivo);
            break;
        case '?': // Si el ARGUMENTO no es reconocido, se imprime un MENSAJE de ERROR.
            fprintf(stderr, "Opción no reconocida: -%c\n", optopt);
            exit(EXIT_FAILURE);
        default: // Si no se pasan ARGUMENTOS, se imprime un MENSAJE de ERROR.
            fprintf(stderr, "Uso: %s [-h] [-f filename]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    int tamano_memoria, tamano_bloque;                       // VARIABLE del tamaño de la memoria total (2048 KB) y tamaño del bloque de memoria (128 KB).
    char algoritmo_memoria[10], algoritmo_planificacion[10]; // VARIABLE que GUARDA el algoritmo de memoria first fit y VARIABLE que GUARDA el algoritmo de planificación FIFO.
    Cola cola_procesos = {NULL, NULL};                       // VARIABLE que GUARDA la COLA de PROCESOS.

    leer_entrada(nombre_archivo, &tamano_memoria, &tamano_bloque, algoritmo_memoria, algoritmo_planificacion, &cola_procesos);

    int cantidad_bloques = tamano_memoria / tamano_bloque; // VARIABLE que GUARDA la cantidad de bloques de memoria.
    BloqueMemoria memoria[cantidad_bloques];               // ARREGLO de BLOQUES de MEMORIA.

    inicializar_bloques_memoria(memoria, cantidad_bloques, tamano_bloque);

    imprimir_memoria(memoria, cantidad_bloques);

    asignar_memoria_procesos(&cola_procesos, memoria, cantidad_bloques);

    return EXIT_SUCCESS;
}
