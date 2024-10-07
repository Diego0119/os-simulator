#include "./incs/proceso.h"
#include "./incs/memoria.h"
#include "./incs/planificador.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define TAMANO_MEMORIA 1024

int main()
{
    BloqueMemoria memoria[TAMANO_MEMORIA];
    inicializar_memoria(memoria);

    FILE *archivo = fopen("./entrada.txt", "r");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    char nombre_proceso[20];
    int tiempo_ejecucion;
    int memoria_solicitada;

    while (fscanf(archivo, "%s %d %d", nombre_proceso, &tiempo_ejecucion, &memoria_solicitada) != EOF)
    {

        Proceso *proceso = crear_proceso(nombre_proceso, tiempo_ejecucion, memoria_solicitada);

        if (proceso != NULL)
        {
            printf("Proceso creado: %s, Tiempo de ejecución: %d, Memoria solicitada: %d KB\n",
                   proceso->nombre, proceso->tiempo_ejecucion, proceso->memoria_solicitada);
        }
        BloqueAsignado *bloque_asignado = asignar_memoria(proceso, memoria, memoria);
        if (bloque_asignado == NULL)
        {
            printf("No se pudo asignar memoria al proceso\n");
        }
        else
        {
            printf("Memoria asignada al proceso %s\n", proceso->nombre);
        }

        free(proceso);
    }

    // printf("Proceso cargado:\n");
    // printf("Nombre: %s\n", proceso->nombre);
    // printf("Tiempo de ejecucion: %d\n", proceso->tiempo_ejecucion);
    // printf("Memoria solicitada: %d KB\n", proceso->memoria_solicitada);

    return 0;
}
