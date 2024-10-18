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
