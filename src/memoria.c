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
    int num_bloques = 2048 / 128;
    printf("Memoria del sistema operativo:\n");
    printf("-----------------------------------------------------------------------\n");

    for (int i = 0; i < num_bloques; i++)
    {
        if (i < num_bloques - 1)
        {
            printf("[estado: %d|tamano: %d|next: %d]-->[siguiente nodo]\n", memoria[i].estado, memoria[i].tamano, memoria[i].next);
        }
        else if (i = num_bloques - 1)
        {
            printf("[estado: %d|tamano: %d|next: %d]-->NULL\n", memoria[i].estado, memoria[i].tamano, memoria[i].next);
        }
    }
    printf("-----------------------------------------------------------------------\n");
}