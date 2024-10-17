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
    cola->rear = proceso;                                  // Se actualiza el FINAL de la COLA.
    proceso->next = NULL;                                  // Se actualiza el SIGUIENTE PROCESO.
    fprintf(stdout, "Proceso %d en COLA\n", proceso->pid); // MENSAJE TEMPORAL.
}

Proceso *dequeue(Cola *cola)
{
    // Sacar de la COLA un PROCESO.
    if (cola->front == NULL)
    {
        return NULL;
    }
    Proceso *proceso = cola->front;  // Se obtiene el PROCESO del FRENTE de la COLA.
    cola->front = cola->front->next; // Se actualiza el FRENTE de la COLA.
    // Si la COLA está VACÍA, se actualiza el FINAL de la COLA.
    if (cola->front == NULL)
    {
        cola->rear = NULL;
    }
    fprintf(stdout, "Proceso %d fuera de COLA\n", proceso->pid); // MENSAJE TEMPORAL.
    return proceso;
}

void planificador_fifo(Cola *cola_procesos, BloqueMemoria *memoria, int cantidad_bloques, int tamano_bloque)
{
    Cola cola_espera = {NULL, NULL}; // COLA de procesos en ESPERA.
    Proceso *proceso_actual = NULL;  // PROCESO actual a evaluar.
}