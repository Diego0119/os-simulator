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
    Proceso *proceso_extraido;
    while ((proceso_extraido = dequeue(cola)) != NULL)
    {
        int tamano_proceso = proceso_extraido->memoria_solicitada;
        int asignado = 0;
        int bloques_necesarios = 0; // Contador para los bloques adyacentes necesarios.
        int inicio_bloques = -1;    // Índice del primer bloque disponible.

        for (int i = 0; i < cantidad_bloques; i++)
        {
            if (memoria[i].estado == 1)
            {
                if (inicio_bloques == -1) // Primer BLOQUE LIBRE.
                    inicio_bloques = i;

                bloques_necesarios += memoria[i].tamano;

                if (bloques_necesarios >= tamano_proceso) // Suficiente MEMORIA para el PROCESO.
                {
                    // Asignar los BLOQUES.
                    for (int j = inicio_bloques; j <= i; j++)
                    {
                        memoria[j].estado = 0; // Bloque OCUPADO.
                        tamano_proceso -= memoria[j].tamano;
                        memoria[j].tamano = 0; // vaciar BLOQUE.
                    }

                    // Fragmentación interna en el último bloque asignado.
                    int fragmentacion_interna = -tamano_proceso; // Fragmentación que SOBRÓ.
                    if (fragmentacion_interna > 0)
                        fprintf(stdout, "Fragmentación interna: %d KB en bloque %d\n", fragmentacion_interna, i);

                    ejecutar_proceso(memoria, proceso_extraido, inicio_bloques);
                    asignado = 1;
                    break;
                }
            }
            else // BLOQUE OCUPADO, se reinicia la BÚSQUEDA.
            {
                bloques_necesarios = 0;
                inicio_bloques = -1;
            }
        }

        if (!asignado)
            fprintf(stderr, "No hay suficiente memoria adyacente para el proceso %d\n", proceso_extraido->pid);

        free(proceso_extraido); // Liberar la MEMORIA.
    }
}
