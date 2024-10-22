#include "header.h"

void leer_entrada(const char *nombre_archivo, int *tamano_memoria, int *tamano_bloque, char *algoritmo_memoria, char *algoritmo_planificacion, Cola *cola_procesos)
{
    // ABRIR el archivo de entrada en modo LECTURA y VERIFICAR que se abra correctamente.
    FILE *archivo_entrada = fopen(nombre_archivo, "r");
    if (archivo_entrada == NULL)
    {
        fprintf(stderr, "ERROR al abrir el archivo, saliendo...\n");
        exit(EXIT_FAILURE);
    }

    // LEER la cabecera del archivo de entrada (2048 128 ff) y VERIFICA si los valores son 3.
    if (fscanf(archivo_entrada, "%d %d %s", tamano_memoria, tamano_bloque, algoritmo_memoria) != 3)
    {
        fprintf(stderr, "ERROR al leer los valores de la memoria o bloque, saliendo...\n");
        exit(EXIT_FAILURE);
    }

    // LEER el algoritmo de planificación (FIFO) y VERIFICA si el valor es 1.
    if (fscanf(archivo_entrada, "%s", algoritmo_planificacion) != 1)
    {
        fprintf(stderr, "Error al leer el algoritmo de planificación\n");
        exit(EXIT_FAILURE);
    }

    // VARIABLES del PROCESO (vienen de entrada.txt).
    int id, tiempo_llegada, tiempo_rafaga, memoria_solicitada;

    // LEER los PROCESOS del archivo de entrada hasta que llegue al FINAL DEL ARCHIVO.
    while (fscanf(archivo_entrada, "%d %d %d %d", &id, &tiempo_llegada, &tiempo_rafaga, &memoria_solicitada) != EOF)
        asignar_valores_procesos(id, tiempo_llegada, tiempo_rafaga, memoria_solicitada, cola_procesos);

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
    fprintf(stdout, "Proceso %d - T. Llegada %d - T. Ráfaga %d - M. Solicitada %d\n", id, tiempo_llegada, tiempo_rafaga, memoria_solicitada);

    enqueue(cola_procesos, nuevo_proceso);
}

void imprimir_cola_procesos(Cola *cola)
{
    // VARIABLES para la impresión de la COLA.
    Proceso *actual = cola->front;
    fprintf(stdout, "\nCola de procesos:\n");
    long actual_next = (long)actual->next;

    // Imprimir los PROCESOS que están en la COLA.
    while (actual != NULL)
    {
        fprintf(stdout, "[PID: %d]\t[Memoria Solicitada: %d]\t[Next: %ld]->\n", actual->pid, actual->memoria_solicitada, actual_next);
        actual = actual->next;
    }
}

void imprimir_memoria(BloqueMemoria *memoria, int cantidad_bloques)
{
    // Imprimir los BLOQUES de MEMORIA INICIALIZADOS.
    fprintf(stdout, "Bloques de memoria del SISTEMA OPERATIVO:\n\n");
    for (int i = 0; i < cantidad_bloques; i++)
        fprintf(stdout, "[Bloque %d]\t[Tamaño %d]\t[Estado %d][LIBRE]\n", i, memoria[i].tamano, memoria[i].estado);
    fprintf(stdout, "\n");
}

void registrar_tiempos(Gantt *diagrama_gantt, int pid, int tiempo_inicio, int tiempo_rafaga, int *indice)
{
    // REGISTRAR los TIEMPOS de los PROCESOS.
    diagrama_gantt[*indice].pid = pid;
    diagrama_gantt[*indice].tiempo_inicio = tiempo_inicio;
    diagrama_gantt[*indice].tiempo_final = tiempo_inicio + tiempo_rafaga;
    (*indice)++;
}

void imprimir_gantt(Gantt *diagrama_gantt, int num_procesos)
{
    // Imprimir el DIAGRAMA de GANTT.
    fprintf(stdout, "\nDiagrama de Gantt:\n\n");
    for (int i = 0; i < num_procesos; i++)
        fprintf(stdout, "[PID: %d]\t[Tiempo Inicio: %d]\t[Tiempo Final: %d]\n", diagrama_gantt[i].pid, diagrama_gantt[i].tiempo_inicio, diagrama_gantt[i].tiempo_final);
    fprintf(stdout, "\n");
}