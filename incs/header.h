// Librerías.
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// Estructura de un proceso. (PASA A SER UNA LISTA PORQUE LA MEMORIA SERÁ VISTA COMO ARREGLO).
typedef struct Proceso
{
    int pid;                // ID del proceso.
    int tiempo_llegada;     // Tiempo de LLEGADA en segundos.
    int tiempo_rafaga;      // Tiempo de EJECUCIÓN en segundos.
    int memoria_solicitada; // MEMORIA solicitada en KB.
    struct Proceso *next;   // Siguiente PROCESO.
} Proceso;

// Estructura de un bloque de memoria. (PASA A SER VISTA COMO UNA MEMORIA DE ARREGLO, HECHA DE BLOQUES).
typedef struct
{
    int tamano; // Tamaño BLOQUE de memoria.
    int estado; // 1 es bloque LIBRE, 0 es bloque OCUPADO.
} BloqueMemoria;

// Estructura de una cola.
typedef struct
{
    Proceso *front; // FRENTE de la cola.
    Proceso *rear;  // FINAL de la cola.
} Cola;

// Funciones AUXILIARES para las funciones de MEMORIA y PLANIFICACIÓN.
void leer_entrada(const char *, int *, int *, char *, char *, Cola *); // LEER la entrada del ARCHIVO.
void asignar_valores_procesos(int, int, int, int, Cola *);             // Asignar VALORES a los PROCESOS.
void imprimir_cola_procesos(Cola *);                                   // Imprimir la COLA de PROCESOS.
void imprimir_memoria(BloqueMemoria *, int);                           // Imprimir los BLOQUES de MEMORIA INICIALIZADOS.

// Funciones de MEMORIA FF (First Fit).
void inicializar_bloques_memoria(BloqueMemoria *, int, int); // Inicializar los BLOQUES de MEMORIA.
void asignar_memoria_procesos(Cola *, BloqueMemoria *, int); // Asignar MEMORIA a los PROCESOS para la EJECUCIÓN.
void ejecutar_proceso(BloqueMemoria *, Proceso *, int);      // Simula la ejecución de un proceso de un BLOQUE de MEMORIA.
void liberar_memoria(BloqueMemoria *, int);                  // Liberar la MEMORIA de un PROCESO.

// Funciones del PLANIFICADOR FIFO.
void enqueue(Cola *, Proceso *); // Poner a la COLA un PROCESO.
Proceso *dequeue(Cola *);        // Sacar de la COLA un PROCESO.
