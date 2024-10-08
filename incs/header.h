#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define TAMANO_MEMORIA 2048 // en kb
#define MAX_PROCESOS 10

typedef struct
{
    int tamaño;           // tamaño del bloque kb
    int estado;           // 1 libre, 0 ocupado
    int proceso_asignado; // puede ser -1 s no tiene proceso
} BloqueMemoria;          // bloque de memoria del sistema operativo

BloqueMemoria Memoria[TAMANO_MEMORIA]; // memoria total del so

typedef struct
{
    int pid;
    int tiempo_ejecucion;
    int memoria_solicitada; // tamaño en kb
    int estado;             // 0 nuevo, 1 listo, 2 ejecutando, 3 bloqueado, 4 finalizado
} Proceso;

Proceso procesos[MAX_PROCESOS];

typedef struct
{
    Proceso proceso;
    Nodo *next;
} Nodo;

Nodo *Front = NULL;
Nodo *Rear = NULL;

BloqueMemoria inicializar_memoria(void); // se deben crear bloques de memoria con tamaños distintos
Nodo *asignar_memoria(Proceso *proceso, BloqueMemoria *memoria, Nodo *Front);
Proceso *crear_proceso(char *name, int tiempo_ejecucion, int memoria_solicitada);
int esta_vacia(Nodo *Front);
void insertar(Proceso proceso, Nodo *Front);
Proceso extraer(Nodo *Front, Nodo *Rear);
