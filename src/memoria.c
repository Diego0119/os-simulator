// EN PROCESO...
/*
#include "header.h"

// Inicializar la memoria.
BloqueMemoria *inicializar_memoria(int total_memoria, int tamano_bloque)
{
    // aca se debe calcular los bloques segun el tamaño de cada bloque
    int num_bloques = total_memoria / tamano_bloque; // calcula la cantidad maxima de bloques que se pueden crear
    BloqueMemoria *memoria = (BloqueMemoria *)malloc(num_bloques * sizeof(BloqueMemoria));

    if (memoria == NULL)
    {
        fprintf(stdout, "Error al asignar memoria!\n");
        exit(EXIT_FAILURE);
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
// lo cambie a void porque simplemente deberia insertar un proceso en el bloque de memoria
// otras funciones deben ser las encargadas de devolver el proceso
void asignar_memoria_ff(BloqueMemoria *memoria, int proceso_id, int tiempo_llegada, int memoria_solicitada)
{
    BloqueMemoria *actual = memoria;
    // Recorrer la memoria.
    while (actual != NULL)
    {
        // Si el bloque está libre y tiene el tamaño suficiente.
        if (actual->estado && actual->tamano >= memoria_solicitada)
        {
            // Partición de memoria si sobra espacio.
            if (actual->tamano > memoria_solicitada)
            {
                BloqueMemoria *nuevo_bloque = (BloqueMemoria *)malloc(sizeof(BloqueMemoria));
                nuevo_bloque->tamano = actual->tamano - memoria_solicitada;
                nuevo_bloque->estado = 1;
                nuevo_bloque->next = actual->next;
                actual->next = nuevo_bloque;
                actual->tamano = memoria_solicitada;
            }
            actual->estado = 0;
            fprintf(stdout, "Memoria asignada.\n"); // Mensaje temporal.
            // return actual;
        }
        actual = actual->next;
    }
    fprintf(stderr, "No hay suficiente memoria disponible para el proceso.\n"); // Mensaje temporal.
    // return NULL;
}

// EN PROCESO...
void insertar(Proceso proceso, Node *Front, Node *Rear)
{
    Node *nuevo_nodo = malloc(sizeof(Node));
    if (nuevo_nodo == NULL)
    {
        printf("Error de asignación de memoria\n");
        return;
    }
    nuevo_nodo->proceso = &proceso;
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

Proceso extraer(Node *Front, Node *Rear)
{
    if (!esta_vacia(Front))
    {
        Proceso proceso_extraido = *Front->proceso;
        Node *temp_nodo = Front;
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
        return *Front->proceso;
    }
}

int esta_vacia(Node *Front)
{
    return Front == NULL;
}
*/