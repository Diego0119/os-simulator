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

void imprimir_memoria(BloqueMemoria *memoria, int cantidad_bloques)
{
    printf("Memoria del sistema operativo:\n");
    for (int i = 0; i < cantidad_bloques; i++)
    {
        fprintf(stdout, "Bloque %d - Tamaño %d - Estado %d\n", i, memoria[i].tamano, memoria[i].estado); // MENSAJE TEMPORAL.
    }
}

// implementacion basica de un first fit
void asignar_memoria_procesos(Cola cola, BloqueMemoria *memoria, int cantidad_bloques)
{
    // extrae el primer proceso que entro a la cola
    Proceso *proceso_extraido = malloc(sizeof(Proceso));
    proceso_extraido = dequeue(&cola);

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

// aca se deberia implementar la funcuon que ejecuta los proceso
// void ejecutar_procesos(Cola *cola, BloqueMemoria *memoria, int cantidad_bloques, int tamano_bloque)
// {
// }
