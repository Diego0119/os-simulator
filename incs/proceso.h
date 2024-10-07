

struct proceso
{
    char nombre[20];
    int tiempo_ejecucion;
    int memoria_solicitada; // tamaño en kb
    int estado;             // 0 nuevo, 1 listo, 2 ejecutando, 3 bloqueado, 4 finalizado
};

typedef struct proceso Proceso;

Proceso *crear_proceso(char *name, int tiempo_ejecucion, int memoria_solicitada);
void terminar_proceso(Proceso *proceso);
