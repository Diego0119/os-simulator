#include "header.h"

// Imprimir el diagrama de gantt
void imprimir_diagrama_gantt(Gantt *diagrama_gantt, int contador_gantt)
{
    printf("Diagrama de Gantt:\n");
    for (int i = 0; i < contador_gantt; i++)
    {
        printf("Proceso %d: %d - %d\n", diagrama_gantt[i].id, diagrama_gantt[i].tiempo_inicio, diagrama_gantt[i].tiempo_fin);
    }
}