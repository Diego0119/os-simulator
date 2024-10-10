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
    fprintf(stdout, "Memoria inicializada: %d.\n"); // Mensaje temporal.

    return memoria; // Retornar el bloque de memoria.
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
    int i = 0;
    // printf("-----------------------------------------------------------------------\n");
    // for (int i = 0; i < 16; i++)
    // {
    //     // cada bloque es de 128 kb, y se esta intentando crear un proceso de 120 kb
    //     // por lo que si debiese dejar pero esta fallando
    //     printf("Espacios de memoria disponibles:\n");
    //     printf("actual[i].estado: %d \n", actual[i].estado);
    //     printf("actual[i].tamano: %d \n", actual[i].tamano);
    //     printf("actual[i].next: %d \n", actual[i].next);
    // }
    // printf("-----------------------------------------------------------------------\n");

    while (actual[i].next != 0)
    {
        // Si el bloque está libre y tiene el tamaño suficiente.
        if (actual[i].estado && actual[i].tamano >= memoria_solicitada)
        {
            printf("Entro al primer if, por lo que el estado esta desocupado y el espacio de memoria es mas grande de lo que se requiere\n");
            // Partición de memoria si sobra espacio.
            if (actual[i].tamano > memoria_solicitada)
            {
                printf("Entro al segundo if, por lo que el tamaño del bloque actual es mas grande que el requerido\n");
                BloqueMemoria *nuevo_bloque = (BloqueMemoria *)malloc(sizeof(BloqueMemoria));
                nuevo_bloque->tamano = actual->tamano - memoria_solicitada;
                nuevo_bloque->estado = 1;
                nuevo_bloque->next = actual->next;
                actual->next = nuevo_bloque;
                actual->tamano = memoria_solicitada;
            }
            actual[i].estado = 0;
            fprintf(stdout, "Memoria asignada.\n"); // Mensaje temporal.
            // return actual;
        }
        actual = actual[i + 1].next;
        i++;
    }
    // fprintf(stderr, "No hay suficiente memoria disponible para el proceso.\n"); // Mensaje temporal.
    // return NULL
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

void imprimir_memoria(BloqueMemoria *memoria)
{
    printf("Memoria del sistema operativo:\n");
    printf("-----------------------------------------------------------------------\n");

    for (int i = 0; i < 16; i++)
    {
        printf("memoria[i].estado: %d\n", memoria[i].estado);
        printf("memoria[i].tamano: %d\n", memoria[i].tamano);
    }
    printf("-----------------------------------------------------------------------\n");
}