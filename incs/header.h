#include <string.h>
#include <stdlib.h>
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

// Funciones auxiliares.
void leer_entrada(const char *, int *, int *, char *, char *, Cola *); // Leer la ENTRADA del ARCHIVO.
void asignar_valores_procesos(int, int, int, int, Cola *);             // Asignar VALORES a los PROCESOS.

// Funciones memoria.
void inicializar_bloques_memoria(BloqueMemoria *, int, int); // Inicializar BLOQUES de MEMORIA.

// Funciones planificador.
void enqueue(Cola *, Proceso *);                           // Poner a la COLA un PROCESO.
Proceso *dequeue(Cola *);                                  // Sacar de la COLA un PROCESO.
void planificador_fifo(Cola *, BloqueMemoria *, int, int); // Planificador FIFO.

// EN PROCESO...
// BloqueMemoria *inicializar_memoria(int, int); // Inicializar la memoria.
// void liberar_memoria(BloqueMemoria *);        // Liberar memoria.
// void asignar_memoria_ff(BloqueMemoria *, int, int, int);
// int esta_vacia(Node *Front);
// void insertar(Proceso proceso, Node *Front, Node *Rear);
// Proceso extraer(Node *Front, Node *Rear);
