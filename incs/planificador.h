#ifndef PLANIFICADOR_H
#define PLANIFICADOR_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// Estructura de un PROCESO. (PASA A SER UNA LISTA PORQUE LA MEMORIA SERÁ VISTA COMO ARREGLO).
typedef struct Proceso
{
    int pid;                // ID del proceso.
    int tiempo_llegada;     // Tiempo de LLEGADA en segundos.
    int tiempo_rafaga;      // Tiempo de EJECUCIÓN en segundos.
    int memoria_solicitada; // MEMORIA solicitada en KB.
    struct Proceso *next;   // Siguiente PROCESO.
} Proceso;

// Estructura de una COLA.
typedef struct
{
    Proceso *front; // FRENTE de la cola.
    Proceso *rear;  // FINAL de la cola.
} Cola;

// Estructura de la carta GANTT
typedef struct
{
    int pid;           // ID del PROCESO.
    int tiempo_inicio; // Tiempo de INICIO.
    int tiempo_final;  // Tiempo de FINALIZACIÓN.
} Gantt;

// Prototipos de funciones de planificación
void enqueue(Cola *cola, Proceso *proceso);
Proceso *dequeue(Cola *cola);

#endif // PLANIFICADOR_H
