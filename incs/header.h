#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Estructura de un proceso.
typedef struct
{
    int pid;                // ID del proceso.
    int tiempo_rafaga;      // Tiempo de ejecución en segundos.
    int memoria_solicitada; // Memoria solicitada en KB.
} Proceso;

// Estructura de un bloque de memoria.
typedef struct BloqueMemoria
{
    int tamano;                 // Tamaño bloque de memoria.
    int estado;                 // 1 es bloque libre, 0 es bloque ocupado.
    struct BloqueMemoria *next; // Siguiente bloque de memoria.
} BloqueMemoria;

// Estructura de un nodo.
typedef struct Node
{
    Proceso *proceso;  // Proceso.
    struct Node *next; // Siguiente nodo.
} Node;

// Estructura de una cola.
typedef struct
{
    Node *front; // Frente de la cola.
    Node *rear;  // Final de la cola.
} Queue;

// Estructura de un bloque de Gantt.
typedef struct
{
    int id;            // ID del proceso.
    int tiempo_inicio; // Tiempo de inicio del proceso.
    int tiempo_fin;    // Tiempo de fin del proceso.
} Gantt;

// Funciones de memoria.
BloqueMemoria *inicializar_memoria(int);                 // Inicializa la memoria.
BloqueMemoria *asignar_memoria_ff(BloqueMemoria *, int); // Asigna memoria con el algoritmo First Fit.
void liberar_memoria(BloqueMemoria *);                   // Libera la memoria.

// Función de lectura de archivo.
void leer_entrada(const char *nombre_archivo, int *memoria_total, int *tamano_bloque, char *algoritmo_memoria, int *num_nucleos, char *algoritmo_planificacion, Queue *cola_lista);

// Funciones de impresión en forma de diagrama de gantt.
void imprimir_diagrama_gantt(Gantt *, int);

// Funciones de planificación.
// ACÁ VA EL PLANIFICADOR FIFO.

// Funciones de cola.
void insertar(Queue *, Proceso *); // Inserta un proceso en la cola.
Proceso *extraer(Queue *);         // Extrae un proceso de la cola.