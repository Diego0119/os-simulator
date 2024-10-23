#ifndef MEMORIA_H
#define MEMORIA_H

#define MAX_PROCESOS 100

#include "planificador.h"

// Estructura de un BLOQUE de MEMORIA.
typedef struct
{
    int tamano; // Tamaño BLOQUE de memoria.
    int estado; // 1 es bloque LIBRE, 0 es bloque OCUPADO.
} BloqueMemoria;

// Funciones de MEMORIA FF (First Fit).
void inicializar_bloques_memoria(BloqueMemoria *, int, int);                  // Inicializar los BLOQUES de MEMORIA.
void asignar_memoria_procesos(Cola *, BloqueMemoria *, int);                  // Asignar MEMORIA a los PROCESOS para la EJECUCIÓN.
void asignar_bloque_proceso(BloqueMemoria *, Proceso *, int *, int);          // Asignar un BLOQUE de MEMORIA a un PROCESO.
void verificar_fragmentacion(BloqueMemoria *, int);                           // Verificar la FRAGMENTACIÓN INTERNA.
void manejar_proceso(BloqueMemoria *, Proceso *, int, Gantt *, int *, int *); // Manejar el PROCESO.
void ejecutar_proceso(BloqueMemoria *, Proceso *, int);                       // Simula la ejecución de un proceso de un BLOQUE de MEMORIA.
void liberar_memoria(BloqueMemoria *, int);                                   // Liberar la MEMORIA de un PROCESO.

#endif // MEMORIA_H
