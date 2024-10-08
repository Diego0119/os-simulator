#define TAMANO_MEMORIA 1024 // en kb
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct bloque_memoria
{
    int tamaño;           // tamaño del bloque kb
    int estado;           // 1 libre, 0 ocupado
    int proceso_asignado; // puede ser -1 s no tiene proceso
};

typedef struct bloque_memoria BloqueMemoria; // tamaño fijo de memoria del sistema op

BloqueMemoria Memoria[TAMANO_MEMORIA]; // memoria total del so

struct proceso
{
    char nombre[20];
    int tiempo_ejecucion;
    int memoria_solicitada; // tamaño en kb
    int estado;             // 0 nuevo, 1 listo, 2 ejecutando, 3 bloqueado, 4 finalizado
};

typedef struct proceso Proceso;
typedef struct nodo Nodo;
typedef struct lista Lista;

struct lista
{
    Nodo *head;
};

struct nodo
{
    Proceso proceso;
    Nodo *next;
    Nodo *prev;
};

BloqueMemoria inicializar_memoria(void);

Nodo *asignar_memoria(Proceso *proceso, BloqueMemoria *memoria);

struct cola
{
    Nodo *front;
    Nodo *rear;
};

Proceso *crear_proceso(char *name, int tiempo_ejecucion, int memoria_solicitada);
void terminar_proceso(Proceso *proceso);
int esta_vacia(Lista lista);
