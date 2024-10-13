#include "header.h"

// Inserta un proceso en la cola.
void insertar(Queue *cola, Proceso *proceso)
{
    Node *nuevo_nodo = (Node *)malloc(sizeof(Node)); // Reserva memoria para el nuevo nodo.
    // Si no se pudo reservar memoria.
    if (nuevo_nodo == NULL)
    {
        printf("Error de asignación de memoria\n");
        return;
    }
    nuevo_nodo->proceso = proceso;
    nuevo_nodo->next = NULL;

    // Si la cola está vacía.
    if (cola->rear == NULL)
    {
        cola->front = nuevo_nodo;
        cola->rear = nuevo_nodo;
    }
    else
    {
        cola->rear->next = nuevo_nodo;
        cola->rear = nuevo_nodo;
    }

    fprintf(stdout, "Proceso %d insertado en la cola\n", proceso->pid);
}

// Extrae un proceso de la cola.
Proceso *extraer(Queue *cola)
{
    // Si la cola está vacía.
    if (cola->front == NULL)
    {
        printf("La cola de procesos esta vacia\n");
        return NULL;
    }

    Node *nodo_temporal = cola->front;
    Proceso *proceso = nodo_temporal->proceso;
    cola->front = cola->front->next;

    // Si la cola quedó vacía.
    if (cola->front == NULL)
    {
        cola->rear = NULL;
    }

    free(nodo_temporal);

    fprintf(stdout, "Proceso %d extraido de la cola\n", proceso->pid);

    return proceso;
}