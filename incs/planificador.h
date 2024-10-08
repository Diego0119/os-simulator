#include "./header.h"
// aca esta el planificador de procesos, el so planificara con FIFO inicialmente, el primer proceso que llega sera el primero
// que ejecute
// aca en el planificador debo implementar FIFO

// esto es una lista doblemente enlazada de un proceso

struct bloque_asignado
{
    Proceso proceso;
    Nodo *next;
    Nodo *prev;
};

// bloque asignado a un proceso
typedef struct bloque_asignado Lista; // sera lo que se pasara a las funciones que identificara a la lista completa

struct cola
{

    Nodo *front;
    Nodo *rear;
};

void insertar(Proceso proceso, Lista lista)
{
    Nodo *nuevo_nodo = malloc(sizeof(Nodo));
    nuevo_nodo->proceso = proceso;
    nuevo_nodo->next = NULL;

    if (esta_vacia(lista))
    {
    }
}

// void planificacion_del_sistema_operativo(Lista lista);