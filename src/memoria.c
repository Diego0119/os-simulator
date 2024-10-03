#include "../incs/memoria.h"

// aca se le deberia asignar memoria al so
void inicializar_memoria()
{
    BloqueMemoria memoria[TAMANO_MEMORIA];
    for (int i = 0; i < TAMANO_MEMORIA; i++)
    {
        memoria[i].tamaño = 1;            // bloques de 1 kb
        memoria[i].libre = 1;             // 1 es bloque libre
        memoria[i].proceso_asignado = -1; // nigun bloque tiene procesos asignados
    }
}

// se debe crear la funcion de asignar memoria