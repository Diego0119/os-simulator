#include "header.h"

void inicializar_bloques_memoria(BloqueMemoria *memoria, int cantidad_bloques, int tamano_bloque)
{
    // INICIALIZA los bloques de memoria.
    for (int i = 0; i < cantidad_bloques; i++)
    {
        memoria[i].tamano = tamano_bloque; // BLOQUE de MEMORIA de 128 KB.
        memoria[i].estado = 1;             // 1 bloque LIBRE, 0 bloque OCUPADO.
    }
    fprintf(stdout, "Bloques inicializados CORRECTAMENTE.\n"); // MENSAJE TEMPORAL.
}

// implementacion basica de un first fit
void asignar_memoria_procesos(Cola *cola, BloqueMemoria *memoria, int cantidad_bloques)
{

    Cola *temp_cola = malloc(sizeof(Cola));
    temp_cola = cola;
    // extrae el primer proceso que entro a la cola
    Proceso *proceso_extraido = malloc(sizeof(Proceso));
    while (temp_cola->front != NULL)
    {
        proceso_extraido = dequeue(temp_cola);

        if (proceso_extraido == NULL)
        {
            fprintf(stdout, "No hay procesos en la cola para asignar memoria.\n");
            return;
        }
        // guarda el tamaño del proceso extraido
        int tamano_proceso = proceso_extraido->memoria_solicitada;

        for (int i = 0; i < cantidad_bloques && tamano_proceso > 0; i++)
        {
            // verifica que el bloque esta libre
            if (memoria[i].estado == 1)
            {
                // si el tamaño del bloque es mas grande que la memoria requerida por el proceso, lo asigna
                if (memoria[i].tamano >= tamano_proceso)
                {
                    fprintf(stdout, "El proceso encontró un bloque de memoria libre con suficiente espacio\n");
                    memoria[i].tamano -= tamano_proceso;
                    memoria[i].estado = 0;

                    tamano_proceso = 0;
                    int fragmentacion_interna = memoria[i].tamano - tamano_proceso;
                    if (fragmentacion_interna > 0)
                    {
                        fprintf(stdout, "Fragmentacion interna: %d KB en el bloque %d\n", fragmentacion_interna, i);
                    }
                    ejecutar_proceso(memoria, proceso_extraido, i);

                    break;
                }
                // este else sirve cuando la memoria requerida por el proceso es mas grande que los bloques del sistema operativo
                // lo que hace es ocupar tantos bloques como sean necesarios para almacenar el proceso
                else
                {
                    tamano_proceso -= memoria[i].tamano;
                    memoria[i].tamano = 0;
                    memoria[i].estado = 0;
                    int fragmentacion_interna = memoria[i].tamano - tamano_proceso;
                    if (fragmentacion_interna > 0)
                    {
                        fprintf(stdout, "Fragmentacion interna: %d KB en el bloque %d\n", fragmentacion_interna, i);
                    }
                    ejecutar_proceso(memoria, proceso_extraido, i);
                }
            }
        }

        // validacion por si aun ocupando todos los bloques del sistema operativo no hay espacio
        if (tamano_proceso > 0)
        {

            fprintf(stderr, "No hay suficiente memoria disponible para asignar al proceso %d \n", proceso_extraido->pid);
        }
        else
        {
            fprintf(stdout, "Proceso %d asignado exitosamente\n", proceso_extraido->pid);
        }
        free(proceso_extraido);
    }
}
