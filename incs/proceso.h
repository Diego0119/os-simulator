

struct proceso
{
    char nombre[10];
    int tiempo_ejecucion;
    int memoria_solicitada;
    int estado;
};

typedef struct proceso Proceso;

Proceso *crear_proceso(char *name, int tiempo_ejecucion, int memoria_solicitada);
void terminar_proceso(Proceso *proceso);
