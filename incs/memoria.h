

// los bloques de memoria sera una lista enlazada, aun no se si simple o doble
struct bloque_memoria
{
    int tamaño;
    int libre;
    BloqueMemoria *bloque_siguiente;
};

typedef struct bloque_memoria BloqueMemoria;
