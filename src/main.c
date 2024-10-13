#include "header.h"

int main(int argc, char *argv[])
{
    // Si la cantidad de argumentos no es la esperada.
    if (argc != 3 || strcmp(argv[1], "--file") != 0)
    {
        fprintf(stderr, "Error de utilización. Uso: %s --file <archivo>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *nombre_archivo = argv[2];

    int memoria_total;
    int tamano_bloque;
    int num_nucleos;

    char algoritmo_memoria[3];
    char algoritmo_planificacion[3];

    Queue cola_lista = {NULL, NULL};

    leer_entrada(nombre_archivo, &memoria_total, &tamano_bloque, algoritmo_memoria, &num_nucleos, algoritmo_planificacion, &cola_lista);

    int numero_bloques = memoria_total / tamano_bloque;

    BloqueMemoria *memoria = inicializar_memoria(memoria_total, numero_bloques, tamano_bloque);
    imprimir_memoria(*memoria, numero_bloques);

    Gantt diagrama_gantt[100];
    int contador_gantt = 0;

    // // Si el algoritmo de planificación es FIFO.
    // if (strcmp(algoritmo_planificacion, "fifo") == 0)
    // {
    //     exit(EXIT_FAILURE);
    //     // FIFO
    // }
    // else
    // {
    //     fprintf(stderr, "Algoritmo de planificación no reconocido.\n");
    //     exit(EXIT_FAILURE);
    // }

    // imprimir_diagrama_gantt(diagrama_gantt, contador_gantt);

    return EXIT_SUCCESS;
}
