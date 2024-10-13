#include "header.h"

// Inicializa la memoria de un bloque.
BloqueMemoria *inicializar_memoria(int total_memoria)
{
    BloqueMemoria *memoria = (BloqueMemoria *)malloc(sizeof(BloqueMemoria)); // Reserva memoria para el bloque.

    // Si no se pudo asignar memoria.
    if (memoria == NULL)
    {
        fprintf(stderr, "Error de asignación de memoria.\n");
        return NULL;
    }

    memoria->tamano = total_memoria;
    memoria->estado = 1;
    memoria->next = NULL;

    fprintf(stdout, "Memoria inicializada.\n");

    return memoria;
}

// Asigna memoria con el algoritmo First Fit.
BloqueMemoria *asignar_memoria_ff(BloqueMemoria *memoria, int tamano)
{
    BloqueMemoria *actual = memoria;

    // Recorre la memoria hasta encontrar un bloque libre con el tamaño solicitado.
    while (actual != NULL)
    {
        // Si el bloque está libre y tiene el tamaño solicitado.
        if (actual->estado && actual->tamano >= tamano)
        {
            // Si el bloque tiene un tamaño mayor al solicitado, se divide en dos bloques.
            if (actual->tamano > tamano)
            {
                BloqueMemoria *nuevo_bloque = (BloqueMemoria *)malloc(sizeof(BloqueMemoria));
                nuevo_bloque->tamano = actual->tamano - tamano;
                nuevo_bloque->estado = 1;
                nuevo_bloque->next = actual->next;
                actual->next = nuevo_bloque;
                actual->tamano = tamano;
                fprintf(stdout, "Memoria asignada.\n");
            }
            fprintf(stdout, "Memoria asignada.\n");
            actual->estado = 0;
            return actual;
        }
        fprintf(stdout, "Memoria no asignada. Pasando al siguiente bloque.\n");
        actual = actual->next;
    }
    return NULL;
}

// Libera la memoria del proceso.
void liberar_memoria(BloqueMemoria *bloque)
{
    fprintf(stdout, "Memoria liberada.\n");
    bloque->estado = 1;
}