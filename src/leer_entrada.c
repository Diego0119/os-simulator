#include "header.h"

void leer_entrada(const char *nombre_archivo, int *memoria_total, int *tamano_bloque, char *algoritmo_memoria, int *num_nucleos, char *algoritmo_planificacion, Queue *cola_lista)
{
    FILE *archivo_entrada = fopen(nombre_archivo, "r");
    // Si no se pudo abrir el archivo.
    if (archivo_entrada == NULL)
    {
        fprintf(stderr, "Error al abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    fscanf(archivo_entrada, "%d %d %s %d %s", memoria_total, tamano_bloque, algoritmo_memoria, num_nucleos, algoritmo_planificacion);

    int proceso_id;
    int tiempo_rafaga;
    int memoria_solicitada;

    // Leer los procesos del archivo y los asigna para luego mandarlos a la cola.
    while (fscanf(archivo_entrada, "%d %d %d", &proceso_id, &tiempo_rafaga, &memoria_solicitada) == 3)
    {
        Proceso *nuevo_proceso = (Proceso *)malloc(sizeof(Proceso));
        nuevo_proceso->pid = proceso_id;
        nuevo_proceso->tiempo_rafaga = tiempo_rafaga;
        nuevo_proceso->memoria_solicitada = memoria_solicitada;
        fprintf(stdout, "Proceso %d leido\n", proceso_id);
        insertar(cola_lista, nuevo_proceso);
    }
    fclose(archivo_entrada);
}
