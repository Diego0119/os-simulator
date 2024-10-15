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
}

// void planificador_fifo(Cola *cola_procesos, BloqueMemoria *memoria, int cantidad_bloques, int tamano_bloque)
// {
//     // Cola cola_espera = {NULL, NULL}; // COLA de procesos en ESPERA.
//     Proceso *proceso_actual = NULL; // PROCESO actual a evaluar.
// }
