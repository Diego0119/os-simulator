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
typedef struct Node
{
    Proceso *proceso;  // Proceso del nodo.
    struct Node *next; // Siguiente nodo.
};

// Estructura de una cola.
typedef struct
{
    struct Node *front; // Frente de la cola.
    struct Node *rear;  // Final de la cola.
} Queue;

BloqueMemoria *inicializar_memoria(int); // Inicializar la memoria.
void liberar_memoria(BloqueMemoria *);   // Liberar memoria.
BloqueMemoria *asignar_memoria(BloqueMemoria *memoria, int tamano);

int esta_vacia(Nodo *Front);
void insertar(Proceso proceso, Nodo *Front);
Proceso extraer(Nodo *Front, Nodo *Rear);
