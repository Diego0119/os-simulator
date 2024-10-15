#include "header.h"

void leer_entrada(const char *nombre_archivo, int *tamano_memoria, int *tamano_bloque, char *algoritmo_memoria, char *algoritmo_planificacion, Cola *cola_procesos)
{
    // ABRIR el archivo de entrada en modo LECTURA y VERIFICAR que se abra correctamente.
    FILE *archivo_entrada = fopen(nombre_archivo, "r");
    if (archivo_entrada == NULL)
    {
        fprintf(stderr, "Error al abrir el archivo.\n");
        exit(EXIT_FAILURE);
    }

    // LEER la cabecera del archivo de entrada (2048 128 ff).
    fscanf(archivo_entrada, "%d %d %s", tamano_memoria, tamano_bloque, algoritmo_memoria);
    // LEER el algoritmo de planificación (FIFO).
    fscanf(archivo_entrada, "%s", algoritmo_planificacion);
    fprintf(stdout, "Configuración leída correctamente.\n"); // MENSAJE TEMPORAL.

    // VARIABLES del PROCESO (vienen del entrada.txt).
    int id;
    int tiempo_llegada;
    int tiempo_rafaga;
    int memoria_solicitada;

    // LEER los PROCESOS del archivo de entrada hasta que llegue al FINAL DEL ARCHIVO.
    while (fscanf(archivo_entrada, "%d %d %d %d", &id, &tiempo_llegada, &tiempo_rafaga, &memoria_solicitada) != EOF)
    {
        asignar_valores_procesos(id, tiempo_llegada, tiempo_rafaga, memoria_solicitada, cola_procesos);
        fprintf(stdout, "Procesos leídos CORRECTAMENTE.\n"); // MENSAJE TEMPORAL.
    }

    fclose(archivo_entrada); // CERRAR el archivo de entrada.
}

void asignar_valores_procesos(int id, int tiempo_llegada, int tiempo_rafaga, int memoria_solicitada, Cola *cola_procesos)
{
    // CREAR un NUEVO PROCESO y ASIGNA la MEMORIA necesaria junto a otros VALORES.
    Proceso *nuevo_proceso = (Proceso *)malloc(sizeof(Proceso));
    nuevo_proceso->pid = id;
    nuevo_proceso->tiempo_llegada = tiempo_llegada;
    nuevo_proceso->tiempo_rafaga = tiempo_rafaga;
    nuevo_proceso->memoria_solicitada = memoria_solicitada;
    nuevo_proceso->next = NULL;
    fprintf(stdout, "Proceso %d - T. Llegada %d - T. Ráfaga %d - M. Solicitada %d\n", id, tiempo_llegada, tiempo_rafaga, memoria_solicitada); // MENSAJE TEMPORAL.

    enqueue(cola_procesos, nuevo_proceso);
    fprintf(stdout, "Proceso %d encolado CORRECTAMENTE.\n", id); // MENSAJE TEMPORAL.
}