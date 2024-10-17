#include "header.h"

void enqueue(Cola *cola, Proceso *proceso)
{
    // Poner a la COLA un PROCESO.
    if (cola->rear == NULL)
    {
        cola->front = proceso;
    }
    else // Si la COLA no está VACÍA, se pone el PROCESO al FINAL de la COLA.
    {
        cola->rear->next = proceso;
    }
    cola->rear = proceso;                                   // Se actualiza el FINAL de la COLA.
    proceso->next = NULL;                                   // Se actualiza el SIGUIENTE PROCESO.
    fprintf(stdout, "Proceso %d encolado\n", proceso->pid); // MENSAJE TEMPORAL.
    imprimir_cola_procesos(cola);
}

Proceso *dequeue(Cola *cola)
{
    if (cola->front == NULL)
    {
        fprintf(stdout, "La cola esta vacia\n");
        exit(EXIT_FAILURE);
    }
    Proceso *proceso_extraido = cola->front;

    cola->front = cola->front->next;

    if (cola->front == NULL)
    {
        cola->rear = NULL;
    }

    return proceso_extraido;
}

void imprimir_cola_procesos(Cola *cola)
{
    Proceso *actual = cola->front;
    fprintf(stdout, "Cola de procesos:\n");
    long actual_next = (long)actual->next;
    while (actual != NULL)
    {
        fprintf(stdout, "[PID: %d | Memoria Solicitada: %d | Next: %ld]->\n", actual->pid, actual->memoria_solicitada, actual_next);
        actual = actual->next;
    }
}

// void planificador_fifo(Cola *cola_procesos, BloqueMemoria *memoria, int cantidad_bloques, int tamano_bloque)
// {
//     // Cola cola_espera = {NULL, NULL}; // COLA de procesos en ESPERA.
//     Proceso *proceso_actual = NULL; // PROCESO actual a evaluar.
// }

// aca se debe implementar el planificador de short job first
// void planificador_sjf(Cola *cola_procesos, BloqueMemoria *memoria, int cantidad_bloques)
// {
// }
