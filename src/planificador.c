#include "header.h"

// aca se deberia implementar la funcuon que ejecuta los proceso
void ejecutar_proceso(BloqueMemoria *memoria, Proceso *proceso, int posicion)
{

    fprintf(stdout, "Proceso %d en ejecución\n", proceso->pid);
    sleep(proceso->tiempo_rafaga);
    fprintf(stdout, "Proceso %d ejecutado\n", proceso->pid);
    // aca se debe liberar la memoria
    memoria[posicion].estado = 1;
    memoria[posicion].tamano = 128;
}

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
