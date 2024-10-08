#include "proceso.h"
// aca esta el planificador de procesos, el so planificara con FIFO inicialmente, el primer proceso que llega sera el primero
// que ejecute
// aca en el planificador debo implementar FIFO

// esto es una lista doblemente enlazada de un proceso
typedef struct bloque_asignado BloqueAsignado;
struct bloque_asignado
{
    Proceso proceso;
    BloqueAsignado *siguiente;
    BloqueAsignado *atras;
};

// bloque asignado a un proceso
typedef struct bloque_asignado Lista; // sera lo que se pasara a las funciones que identificara a la lista completa

struct cola
{
    BloqueAsignado *front;
    BloqueAsignado *rear;
};