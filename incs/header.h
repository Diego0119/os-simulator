// Librerías.
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// Estructura de un proceso. (PASA A SER UNA LISTA PORQUE LA MEMORIA SERÁ VISTA COMO ARREGLO).
typedef struct Proceso
{
    int pid;                // ID del proceso.
    int tiempo_llegada;     // Tiempo de llegada en segundos.
    int tiempo_rafaga;      // Tiempo de ejecución en segundos.
    int memoria_solicitada; // Memoria solicitada en KB.
    struct Proceso *next;   // Siguiente proceso.
} Proceso;

// Estructura de un bloque de memoria. (PASA A SER VISTA COMO UNA MEMORIA DE ARREGLO, HECHA DE BLOQUES).
typedef struct
{
    int tamano; // Tamaño bloque de memoria.
    int estado; // 1 es bloque libre, 0 es bloque ocupado.
} BloqueMemoria;

// Estructura de una cola.
typedef struct
{
    Proceso *front; // Frente de la cola.
    Proceso *rear;  // Final de la cola.
} Cola;

// Estructura de la CARTA GANTT.
typedef struct
{
    int id;
    int tiempo_llegada;
    int tiempo_termino;
} Gantt;

// Funciones auxiliares.
void leer_entrada(const char *, int *, int *, char *, char *, Cola *); // Leer la entrada del archivo.
void asignar_valores_procesos(int, int, int, int, Cola *);             // Asignar valores a los procesos.
void imprimir_memoria(BloqueMemoria *memoria, int cantidad_bloques);   // Imprimir la memoria.

// Funciones memoria.
void inicializar_bloques_memoria(BloqueMemoria *, int, int); // Inicializar bloques de memoria.

// Funciones planificador.
void enqueue(Cola *cola, Proceso *proceso);                                                                   // Poner a la COLA un PROCESO.
void planificador_fifo(Cola *cola_procesos, BloqueMemoria *memoria, int cantidad_bloques, int tamano_bloque); // Planificador FIFO.

void imprimir_cola_procesos(Cola *cola);
void asignar_memoria_procesos(Cola *cola, BloqueMemoria *memoria, int cantidad_bloques);
Proceso *dequeue(Cola *cola);
void planificador_sjf(Cola *cola_procesos, BloqueMemoria *memoria, int cantidad_bloques);
void ejecutar_proceso(BloqueMemoria *, Proceso *, int);
