#include "auxiliar.h"

void inicializar_bloques_memoria(BloqueMemoria *memoria, int cantidad_bloques, int tamano_bloque)
{
    // INICIALIZA los bloques de memoria.
    for (int i = 0; i < cantidad_bloques; i++)
    {
        memoria[i].tamano = tamano_bloque; // BLOQUE de MEMORIA de 128 KB.
        memoria[i].estado = 1;             // 1 bloque LIBRE, 0 bloque OCUPADO.
    }
}

void asignar_memoria_procesos(Cola *cola, BloqueMemoria *memoria, int cantidad_bloques)
{
    // ASIGNA la MEMORIA a los PROCESOS para la EJECUCIÓN.
    Cola *temp_cola = malloc(sizeof(Cola));
    temp_cola = cola;
    Proceso *proceso_extraido = malloc(sizeof(Proceso));

    // INICIALIZA el DIAGRAMA de GANTT.
    Gantt diagrama_gantt[MAX_PROCESOS];
    int indice = 0, tiempo_global = 0;

    // MIENTRAS la COLA de PROCESOS NO esté VACÍA.
    while (temp_cola->front != NULL)
    {
        // EXTRAE el PROCESO de la COLA.
        proceso_extraido = dequeue(temp_cola);

        // SI NO hay PROCESOS en la COLA.
        if (proceso_extraido == NULL)
        {
            fprintf(stdout, "No hay procesos en la cola para asignar memoria.\n");
            return;
        }

        manejar_proceso(memoria, proceso_extraido, cantidad_bloques, diagrama_gantt, &tiempo_global, &indice);
        free(proceso_extraido);
    }

    imprimir_gantt(diagrama_gantt, indice);
    generar_archivo_gantt(diagrama_gantt, indice, "gantt.eps");
}

void manejar_proceso(BloqueMemoria *memoria, Proceso *proceso_extraido, int cantidad_bloques, Gantt *diagrama_gantt, int *tiempo_global, int *indice)
{
    int tiempo_inicio = *tiempo_global;
    int tamano_proceso = proceso_extraido->memoria_solicitada;

    // SI el TAMAÑO del PROCESO es MAYOR a 2048 KB (total memoria).
    if (tamano_proceso > 2048)
    {
        fprintf(stderr, "No hay suficiente memoria disponible para asignar al PROCESO %d, pasando al siguiente PROCESO.\n\n", proceso_extraido->pid);
        return;
    }

    // Asignación de MEMORIA a los PROCESOS.
    for (int i = 0; i < cantidad_bloques && tamano_proceso > 0; i++)
    {
        // Si el BLOQUE está LIBRE.
        if (memoria[i].estado == 1)
        {
            asignar_bloque_proceso(memoria, proceso_extraido, &tamano_proceso, i);
        }
    }

    *tiempo_global += proceso_extraido->tiempo_rafaga;
    registrar_tiempos(diagrama_gantt, proceso_extraido->pid, tiempo_inicio, proceso_extraido->tiempo_rafaga, indice);
    fprintf(stdout, "Proceso %d EJECUTADO EXITOSAMENTE.\n\n", proceso_extraido->pid);
}

void asignar_bloque_proceso(BloqueMemoria *memoria, Proceso *proceso, int *tamano_proceso, int i)
{
    // Si el tamaño de memoria del PROCESO alcanza en un solo BLOQUE hace la signación COMPLETA del BLOQUE, si no, toma más de uno y lo asigna PARCIALMENTE.
    if (memoria[i].tamano >= *tamano_proceso)
    {
        fprintf(stdout, "El proceso %d usó MEMORIA hasta el BLOQUE %d\n", proceso->pid, i);

        // Se le asigna la MEMORIA requerida por el PROCESO al bloque de memoria, la MEMORIA pasa a estar OCUPADA y el tamaño del PROCESO queda en 0.
        memoria[i].tamano -= *tamano_proceso;
        memoria[i].estado = 0;
        *tamano_proceso = 0;

        verificar_fragmentacion(memoria, i);
        ejecutar_proceso(memoria, proceso, i);
    }
    else
    {
        // Si el tamaño de la memoria del PROCESO es menor al tamaño del BLOQUE, se asigna la MEMORIA PARCIALMENTE, la MEMORIA pasa a estar OCUPADA y el tamaño del BLOQUE queda en 0.
        *tamano_proceso -= memoria[i].tamano;
        memoria[i].tamano = 0;
        memoria[i].estado = 0;

        fprintf(stdout, "Proceso %d en EJECUCIÓN, bloque (%d)\n", proceso->pid, i);
        ejecutar_proceso(memoria, proceso, i);
        verificar_fragmentacion(memoria, i);
    }
}

void verificar_fragmentacion(BloqueMemoria *memoria, int i)
{
    // Calcula la FRAGMENTACIÓN INTERNA.
    int fragmentacion_interna = memoria[i].tamano;

    // Si el tamaño de la memoria del PROCESO es mayor a 0, hay fragmentación interna.
    if (fragmentacion_interna > 0)
        fprintf(stdout, "FRAGMENTACIÓN INTERNA: %d KB en el BLOQUE %d\n", fragmentacion_interna, i);
}

void ejecutar_proceso(BloqueMemoria *memoria, Proceso *proceso, int posicion)
{
    // Simula la EJECUCIÓN de un PROCESO de un BLOQUE de MEMORIA.
    sleep(proceso->tiempo_rafaga);
    liberar_memoria(memoria, posicion);
}

void liberar_memoria(BloqueMemoria *memoria, int posicion)
{
    // Libera la MEMORIA de un PROCESO asignandole el TAMAÑO inicial y el estado 1 (LIBRE).
    memoria[posicion].estado = 1;
    memoria[posicion].tamano = 128;
}
