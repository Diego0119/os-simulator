#include "header.h"

void enqueue(Cola *cola, Proceso *proceso)
{
    // Si la COLA está VACÍA, se pone el PROCESO al PRINCIPIO de la COLA, si la COLA no está VACÍA, se pone el PROCESO al FINAL de la COLA.
    if (cola->rear == NULL)
        cola->front = proceso;
    else
        cola->rear->next = proceso;

    cola->rear = proceso; // Se actualiza el FINAL de la COLA.
    proceso->next = NULL; // Se actualiza el SIGUIENTE PROCESO con NULL poque NO hay otro proceso DETRÁS.
    fprintf(stdout, "Proceso %d encolado CORRECTANENTE.\n", proceso->pid);

    imprimir_cola_procesos(cola);
    fprintf(stdout, "\n");
}

Proceso *dequeue(Cola *cola)
{
    // Comprueba si la COLA está VACÍA.
    if (cola->front == NULL)
    {
        fprintf(stdout, "La cola está vacía.\n");
        exit(EXIT_FAILURE);
    }

    Proceso *proceso_extraido = cola->front; // Se EXTRAE el PROCESO del FRENTE de la COLA.
    cola->front = cola->front->next;         // Se actualiza el FRENTE de la COLA.

    // Si el FRENTE de la COLA es NULL, el FINAL de la COLA también es NULL (COLA VACÍA).
    if (cola->front == NULL)
        cola->rear = NULL;

    return proceso_extraido;
}
