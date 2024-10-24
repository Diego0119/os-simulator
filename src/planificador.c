/**
 * @file planificador.c
 * @date 24-10-2024
 * @authors Miguel Loaiza, Diego Sanhueza y Oscar Cifuentes
 * @brief Funciones de planificación.
 *
 * Contiene las funciones que son utilizadas para la correcta PLANIFICACIÓN de los PROCESOS.
 */

#include "auxiliar.h" ///< Librería que contiene las funciones auxiliares.

/**
 * @brief Coloca un PROCESO en la COLA.
 * @param id ID del proceso.
 * @param tiempo_llegada Tiempo de llegada del proceso.
 * @param tiempo_rafaga Tiempo de ráfaga del proceso.
 * @param memoria_solicitada Memoria solicitada por el proceso.
 * @param cola_procesos Cola de PROCESOS.
 */
void enqueue(Cola *cola, Proceso *proceso)
{
    /**
     * Si la COLA está VACÍA, el FRENTE y el FINAL de la COLA es el PROCESO. Se actualiza el SIGUIENTE PROCESO con NULL porque NO hay otro proceso DETRÁS. Imprime la cola de procesos.
     * @code
     *  if (cola->rear == NULL)
     *      cola->front = proceso;
     *  else
     *      cola->rear->next = proceso;
     *  cola->rear = proceso;
     *  proceso->next = NULL;
     *  fprintf(stdout, "Proceso %d encolado CORRECTANENTE.\n", proceso->pid);
     *  imprimir_cola_procesos(cola);
     *  fprintf(stdout, "\n");
     * @endcode
     */
    if (cola->rear == NULL)
        cola->front = proceso;
    else
        cola->rear->next = proceso;
    cola->rear = proceso;
    proceso->next = NULL;
    fprintf(stdout, "Proceso %d encolado CORRECTANENTE.\n", proceso->pid);
    imprimir_cola_procesos(cola);
    fprintf(stdout, "\n");
}

/**
 * @brief Extrae un PROCESO de la COLA.
 * @param cola Cola de PROCESOS.
 * @return Proceso* Proceso extraído.
 */
Proceso *dequeue(Cola *cola)
{
    /**
     * Si el FRENTE de la COLA es NULL, la COLA está VACÍA. Se imprime un MENSAJE de ERROR y se SALE del programa. Se EXTRAE el PROCESO del FRENTE de la COLA y se actualiza el FRENTE de la COLA. Si el FRENTE de la COLA es NULL, el FINAL de la COLA también es NULL (COLA VACÍA).
     * @code
     *  if (cola->front == NULL)
     *  {
     *      fprintf(stdout, "La cola está vacía.\n");
     *      exit(EXIT_FAILURE);
     *  }
     * @endcode
     */
    if (cola->front == NULL)
    {
        fprintf(stdout, "La cola está vacía.\n");
        exit(EXIT_FAILURE);
    }
    Proceso *proceso_extraido = cola->front;
    cola->front = cola->front->next;
    if (cola->front == NULL)
        cola->rear = NULL;
    return proceso_extraido;
}
