#define TAMANO_MEMORIA 1024 // en kb

// sera para representar la lista de procesos en memoria
// los bloques de memoria sera una lista enlazada, aun no se si simple o doble
struct bloque_memoria
{
    int tamaño;           // tamaño del bloque kb
    int libre;            // 1 libre, 0 ocupado
    int proceso_asignado; // puede ser -1 s no tiene proceso
};

typedef struct bloque_memoria BloqueMemoria; // tamaño fijo de memoria del sistema op

BloqueMemoria Memoria[TAMANO_MEMORIA]; // memoria total

struct bloque_asignado
{
    int inicio; // indice
    int tamaño; // porte en kb del espacio asignado
    BloqueAsignado *siguiente;
    BloqueAsignado *atras;
};

typedef struct bloque_asignado BloqueAsignado; // bloque asignado a un proceso

void inicializar_memoria();