#include "header.h"

// Inicializar la memoria.
BloqueMemoria *inicializar_memoria(int total_memoria)
{
    BloqueMemoria *memoria = (BloqueMemoria *)malloc(sizeof(BloqueMemoria));
    memoria->tamano = total_memoria;            // Tamaño de la memoria.
    memoria->estado = 1;                        // Bloque libre.
    memoria->next = NULL;                       // No hay siguiente bloque.
    fprintf(stdout, "Memoria inicializada.\n"); // Mensaje temporal.
    return memoria;                             // Retornar el bloque de memoria.
}

// Liberar memoria.
void liberar_memoria(BloqueMemoria *bloque)
{
    fprintf(stdout, "Memoria liberada.\n"); // Mensaje temporal.
    bloque->estado = 1;                     // Bloque libre.
}

// Asignar memoria.
BloqueMemoria *asignar_memoria_ff(BloqueMemoria *memoria, int tamano)
{
    BloqueMemoria *actual = memoria;
    // Recorrer la memoria.
    while (actual != NULL)
    {
        // Si el bloque está libre y tiene el tamaño suficiente.
        if (actual->estado && actual->tamano >= tamano)
        {
            // Partición de memoria si sobra espacio.
            if (actual->tamano > tamano)
            {
                BloqueMemoria *nuevo_bloque = (BloqueMemoria *)malloc(sizeof(BloqueMemoria));
                nuevo_bloque->tamano = actual->tamano - tamano;
                nuevo_bloque->estado = 1;
                nuevo_bloque->next = actual->next;
                actual->next = nuevo_bloque;
                actual->tamano = tamano;
            }
            actual->estado = 0;
            fprintf(stdout, "Memoria asignada.\n"); // Mensaje temporal.
            return actual;
        }
        actual = actual->next;
    }
    fprintf(stderr, "No hay suficiente memoria disponible para el proceso.\n"); // Mensaje temporal.
    return NULL;
}

// EN PROCESO...
void insertar(Proceso proceso, Nodo *Front)
{
    Nodo *nuevo_nodo = malloc(sizeof(Nodo));
    if (nuevo_nodo == NULL)
    {
        printf("Error de asignación de memoria\n");
        return;
    }
    nuevo_nodo->proceso = proceso;
    nuevo_nodo->next = NULL;

    if (esta_vacia(Front))
    {
        Front = nuevo_nodo;
        Rear = nuevo_nodo;
    }
    else
    {
        Rear->next = nuevo_nodo;
        Rear = nuevo_nodo;
    }
}

Proceso extraer(Nodo *Front, Nodo *Rear)
{
    if (!esta_vacia(Front))
    {
        Proceso proceso_extraido = Front->proceso;
        Nodo *temp_nodo = Front;
        if (Front == Rear)
        {
            Front = NULL;
            Rear = NULL;
        }
        else
        {
            Front = Front->next;
        }
        free(temp_nodo);
        return proceso_extraido;
    }
    else
    {
        printf("La cola de procesos esta vacia\n");
    }
}
