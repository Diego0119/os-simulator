#include "header.h"

Proceso *crear_proceso(int tiempo_ejecucion, int memoria_solicitada)
{
    Proceso *nuevo_proceso = malloc(sizeof(Proceso));
    int count = 0;
    // if (nuevo_proceso == NULL)
    // {
    //     printf("No se pudo asignar memoria para el proceso\n");
    //     return NULL;
    // }
    nuevo_proceso->pid = count;
    nuevo_proceso->tiempo_ejecucion = tiempo_ejecucion;
    nuevo_proceso->memoria_solicitada = memoria_solicitada;
    nuevo_proceso->estado = 0; // 0 es un nuevo proceso
    count++;

    return nuevo_proceso;
}
