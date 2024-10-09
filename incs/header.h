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
typedef struct
{
    int tamano;                 // Tamaño bloque de memoria.
    int estado;                 // 1 es bloque libre, 0 es bloque ocupado.
    struct BloqueMemoria *next; // Siguiente bloque de memoria.
} BloqueMemoria;

// Estructura de un nodo.
typedef struct
{
    Proceso *proceso;  // Proceso del nodo.
    struct Node *next; // Siguiente nodo.
} Node;

// Estructura de una cola.
typedef struct
{
    struct Node *front; // Frente de la cola.
    struct Node *rear;  // Final de la cola.
} Queue;

BloqueMemoria *inicializar_memoria(int, int); // Inicializar la memoria.
void liberar_memoria(BloqueMemoria *);        // Liberar memoria.
void *asignar_memoria(BloqueMemoria *, int, int, int);

int esta_vacia(Node *Front);
void insertar(Proceso proceso, Node *Front, Node *Rear);
Proceso extraer(Node *Front, Node *Rear);
BloqueMemoria *leer_entrada(void);
