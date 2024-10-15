#include "header.h"

void inicializar_bloques_memoria(BloqueMemoria *memoria, int cantidad_bloques, int tamano_bloque)
{
    // INICIALIZA los bloques de memoria.
    for (int i = 0; i < cantidad_bloques; i++)
    {
        memoria[i].tamano = tamano_bloque; // BLOQUE de MEMORIA de 128 KB.
        memoria[i].estado = 1;             // 1 bloque LIBRE, 0 bloque OCUPADO.

        fprintf(stdout, "Bloque %d - Tamaño %d - Estado %d\n", i, memoria[i].tamano, memoria[i].estado); // MENSAJE TEMPORAL.
    }
    fprintf(stdout, "Bloques inicializados CORRECTAMENTE.\n"); // MENSAJE TEMPORAL.
}

// EN PROCESO...
/*

// Inicializar la memoria.
BloqueMemoria *inicializar_memoria(int total_memoria, int tamano_bloque)
{
    // aca se debe calcular los bloques segun el tamaño de cada bloque
    int num_bloques = total_memoria / tamano_bloque; // calcula la cantidad maxima de bloques que se pueden crear
    BloqueMemoria *memoria = (BloqueMemoria *)malloc(num_bloques * sizeof(BloqueMemoria));

{
    BloqueMemoria *memoria = (BloqueMemoria *)malloc(sizeof(BloqueMemoria)); // Reserva memoria para el bloque.

    // Si no se pudo asignar memoria.
    if (memoria == NULL)
    {
        fprintf(stderr, "Error de asignación de memoria.\n");
        return NULL;
    }
    for (int i = 0; i < num_bloques; i++)
    {
        memoria[i].tamano = tamano_bloque;
        memoria[i].estado = 1;
        if (i < num_bloques - 1) // comprueba que haya un siguiente bloque
        {
            memoria[i].next = &memoria[i + 1]; // se enlaza al siguiente si es que hay siguiente
        }
        else
        {
            memoria[i].next = NULL; // el ultimo bloque de memoria del sistema operativo apunta a null
        }
    }
    fprintf(stdout, "Memoria inicializada: %d.\n"); // Mensaje temporal.

    return memoria; // Retornar el bloque de memoria.
}

// Asigna memoria con el algoritmo First Fit.
void asignar_memoria_ff(BloqueMemoria *memoria, int tamano, int memoria_solicitada)
{
    BloqueMemoria *actual = memoria;
    // Recorrer la memoria.
    int tamano_bloque = memoria->tamano;
    int i = 0;
    while (actual[i].next != 0)
    {
        // Si el bloque está libre y tiene el tamaño suficiente.
        if (actual[i].estado && actual[i].tamano >= memoria_solicitada)
        {
            // Partición de memoria si sobra espacio.
            // BloqueMemoria *nuevo_bloque = (BloqueMemoria *)malloc(sizeof(BloqueMemoria));
            // nuevo_bloque->tamano = actual[i].tamano - memoria_solicitada;
            // printf("nuevo_bloque->tamano %d\n", nuevo_bloque->tamano);
            // nuevo_bloque->estado = 0;
            // nuevo_bloque->next = actual[i].next;

            // actual->next = nuevo_bloque;
            // actual->tamano = memoria_solicitada;

            actual[i].estado = 0;
            actual[i].tamano -= memoria_solicitada; // registra que la celda de la memoria esta ocupada
            fprintf(stdout, "Memoria asignada.\n"); // Mensaje temporal.
            return;
            // return actual;
        }
        // este if valida que si se pide memoria y se necesita ocupar mas 1 un bloque de memoria
        // tambien valida si es que se esta en el ultimo espacio de memoria, por lo que no se puede pedir uno mas
        if (memoria_solicitada > actual[i].tamano && actual[i].estado && actual[i].next != NULL)
        {
            float bloques_necesarios = (float)memoria_solicitada / tamano_bloque;
            int bloques_para_calculo = (int)bloques_necesarios;
            while (bloques_necesarios > 0)
            {
                int nueva_memoria_disponible = memoria_solicitada - tamano_bloque;
                actual[i].estado = 0;
                actual[i].tamano = 0;
                bloques_necesarios--;
                i++;
            }
            actual[i - 1].tamano = (tamano_bloque * (bloques_para_calculo + 1)) - memoria_solicitada;

            return;
        }
        else
        {
            fprintf(stderr, "No hay suficiente memoria en el sistema operativo\n");
        }
        // actual = actual[i + 1].next;
        i++;
    }
    fprintf(stderr, "No hay suficiente memoria disponible para el proceso.\n"); // Mensaje temporal.
    // return NULL
}

// Libera la memoria del proceso.
void liberar_memoria(BloqueMemoria *bloque)
{
    fprintf(stdout, "Memoria liberada.\n");
    bloque->estado = 1;
}
*/
