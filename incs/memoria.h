

struct bloque_memoria
{
    int tamaño;
    int libre;
    BloqueMemoria *bloque_siguiente;
};

typedef struct bloque_memoria BloqueMemoria;
