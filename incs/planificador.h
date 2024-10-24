/**
 * @file planificador.h
 * @date 24-10-2024
 * @authors Miguel Loaiza, Diego Sanhueza y Oscar Cifuentes
 * @brief Prototipos de funciones dedicadas a la planificación (FIFO) y estructuras.
 *
 * Contiene los prototipos de las funciones dedicadas a la planificación de los procesos (FIFO) y las estructuras de un PROCESO, la COLA y la CARTA GANTT.
 */

#ifndef PLANIFICADOR_H
#define PLANIFICADOR_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * @struct Proceso
 * @brief Estructura de un PROCESO.
 * @code
 *  typedef struct Proceso
 *  {
 *      int pid;
 *      int tiempo_llegada;
 *      int tiempo_rafaga;
 *      int memoria_solicitada;
 *      struct Proceso *next;
 *  } Proceso;
 * @endcode
 *
 * En esta estructura se define un PROCESO con un ID, tiempo de llegada, tiempo de ráfaga, memoria solicitada y un puntero al siguiente PROCESO.
 */
typedef struct Proceso
{
    int pid;
    int tiempo_llegada;
    int tiempo_rafaga;
    int memoria_solicitada;
    struct Proceso *next;
} Proceso;

/**
 * @struct Cola
 * @brief Estructura de una COLA.
 * @code
 *  typedef struct
 *  {
 *      Proceso *front;
 *      Proceso *rear;
 *  } Cola;
 * @endcode
 *
 * En esta estructura se define una COLA con un FRENTE y un FINAL.
 */
typedef struct
{
    Proceso *front; // FRENTE de la cola.
    Proceso *rear;  // FINAL de la cola.
} Cola;

/**
 * @struct Gantt
 * @brief Estructura de un DIAGRAMA de GANTT.
 * @code
 *  typedef struct
 *  {
 *      int pid;
 *      int tiempo_inicio;
 *      int tiempo_final;
 *  } Gantt;
 * @endcode
 *
 * En esta estructura se define un DIAGRAMA de GANTT con un ID de proceso, tiempo de inicio y tiempo final.
 */
typedef struct
{
    int pid;           // ID del PROCESO.
    int tiempo_inicio; // Tiempo de INICIO.
    int tiempo_final;  // Tiempo de FINALIZACIÓN.
} Gantt;

/**
 * @brief Coloca un PROCESO a la COLA
 * @param cola Cola de PROCESOS.
 * @param proceso PROCESO a encolar.
 */
void enqueue(Cola *cola, Proceso *proceso);

/**
 * @brief Extrae un PROCESO de la COLA
 * @param cola Cola de PROCESOS.
 * @return Proceso* PROCESO extraído.
 */
Proceso *dequeue(Cola *cola);

#endif
