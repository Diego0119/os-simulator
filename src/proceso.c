// aca se deberian crear los procesos
#include "../incs/header.h"
// aca se creara el struct proceso
Proceso *crear_proceso(char *name, int tiempo_ejecucion, int memoria_solicitada)
{

    Proceso *nuevo_proceso = malloc(sizeof(Proceso));

    // if (nuevo_proceso == NULL)
    // {
    //     printf("No se pudo asignar memoria para el proceso\n");
    //     return NULL;
    // }

    strcpy(nuevo_proceso->nombre, name);
    nuevo_proceso->tiempo_ejecucion = tiempo_ejecucion;
    nuevo_proceso->memoria_solicitada = memoria_solicitada;
    nuevo_proceso->estado = 0; // 0 es un nuevo proceso

    return nuevo_proceso;
}
