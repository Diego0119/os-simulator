// aca esta el planificador de procesos, el so planificara con FIFO inicialmente, el primer proceso que llega sera el primero
// que ejecute
// aca en el planificador debo implementar FIFO

// esto es una lista doblemente enlazada de un proceso
struct bloque_asignado
{
    Proceso proceso;
    BloqueAsignado *siguiente;
    BloqueAsignado *atras;
};

typedef struct bloque_asignado BloqueAsignado; // bloque asignado a un proceso

struct cola
{
    BloqueAsignado *front;
    BloqueAsignado *rear;
};